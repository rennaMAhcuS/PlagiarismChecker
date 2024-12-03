# NOTE: To use gdb and sanitizers properly, you should run the executables on native architecture.

# Pulling the latest Ubuntu image and updating it
FROM ubuntu:latest
RUN apt-get update && apt-get full-upgrade -y

# Environment variables for the shell
ENV TERM=xterm-256color
ENV DEBIAN_FRONTEND=interactive
# Installing basic features
RUN apt-get install -y sudo wget

# Installing llvm libraries, the clang compiler, gdb and make
RUN apt-get install -y llvm libc++-dev clang libclang-dev lld gdb make
# Installation of GEF (GDB Enhanced Features)
RUN bash -c "$(wget https://gef.blah.cat/sh -O -)"

# Setting up creation of a new user, removing the default user, and switching to it
RUN userdel ubuntu && rm -rf /home/ubuntu
ENV USERNAME=Loki
RUN useradd -ms /bin/bash ${USERNAME} && \
echo "${USERNAME}:huffman" | chpasswd && \
usermod -aG sudo ${USERNAME}
USER ${USERNAME}

WORKDIR /home/${USERNAME}/plagiarism_checker

# The suppressions for the sanitize flag
RUN echo "\
leak:llvm\n\
leak:_fetchInitializingClassList\n\
leak:__Balloc_D2A" >> ~/.lsan.supp

# The default build birectory (not building in the src as we may have clutter/mount permission issues)
ENV BUILDDIR=/home/${USERNAME}/build

# C++ environment variables and custom aliases
RUN echo "\n\
export CXX=clang++\n\
export CC=clang\n\
export CXXFLAGS='-std=c++20 -g -pthread -Wall -Wshadow -Wuninitialized -Wtype-limits'\n\
export CFLAGS='-std=c17 -g -pthread -Wall -Wpedantic -Wshadow -Wuninitialized -Wtype-limits'\n\
export LDFLAGS='-fuse-ld=lld'\n\
export CSTRICT='-fsanitize=address,undefined,leak,bounds -Werror'\n\
export CTHREAD='-fsanitize=thread,undefined,bounds -Werror'\n\
export LSAN_OPTIONS=suppressions=$HOME/.lsan.supp\n\n\
alias ..='cd ..'\n\
alias rmbuild='rm -rf $BUILDDIR'" >> ~/.bashrc

CMD ["bash"]
