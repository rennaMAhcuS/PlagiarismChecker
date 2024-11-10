# INSTRUCTIONS:
# For the first time, run
# `docker build . -t copycatchers && docker run -it -v .:/home/Loki/plagiarism_checker --name=NP-MOS --network=bridge --hostname=Midgard copycatchers:latest`
# To use the docker container, run
# `docker start -ai NP-MOS`
# NOTE: To use gdb and sanitizers properly, you should run it on native architecture.

FROM ubuntu:24.04

ENV USERNAME=Loki
ENV TERM=xterm-256color
ENV DEBIAN_FRONTEND=interactive

RUN apt-get update && apt-get full-upgrade -y
RUN apt-get install -y clang llvm libc++-dev libclang-dev lld gdb make sudo wget
RUN bash -c "$(wget https://gef.blah.cat/sh -O -)"

RUN useradd -ms /bin/bash ${USERNAME} && \
    echo "${USERNAME}:huffman" | chpasswd && \
    usermod -aG sudo ${USERNAME}

USER ${USERNAME}

WORKDIR /home/${USERNAME}/plagiarism_checker

RUN echo "\
    leak:llvm\n\
    leak:_fetchInitializingClassList\n\
    leak:__Balloc_D2A" >> ~/.lsan.supp

RUN echo "\
    export CXX=clang++\n\
    export CC=clang\n\
    export CXXFLAGS='-std=c++20 -g -pthread -Wall -Wshadow -Wuninitialized -Wtype-limits'\n\
    export CFLAGS='-std=c17 -g -pthread -Wall -Wpedantic -Wshadow -Wuninitialized -Wtype-limits'\n\
    export LDFLAGS='-fuse-ld=lld'\n\
    export CSTRICT='-fsanitize=address,undefined,leak,bounds -Werror'\n\
    export CTHREAD='-fsanitize=thread,undefined,bounds -Werror'\n\
    export LSAN_OPTIONS=suppressions=${HOME}/.lsan.supp\n\n\
    alias ..='cd ..'" >> ~/.bashrc

CMD ["bash"]
