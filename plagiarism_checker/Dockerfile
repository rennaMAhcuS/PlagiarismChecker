# INSTRUCTIONS
# For the first time, run
# docker build . -t plagiarism_checker && docker run -v .:~/plagiarism_checker --name=CopyCatchers --network=bridge --hostname=CopyCatchers plagiarism_checker:latest
# docker start -ai CopyCatchers
# NOTE: To use gdb and sanitizers properly, you should run it on native architecture.

FROM --platform=linux/amd64 ubuntu:24.04

ENV TZ=Asia/Kolkata

ENV $TERM=xterm-256color
ENV DEBIAN_FRONTEND=interactive

RUN apt-get update && apt-get full-upgrade -y
RUN apt-get install -y clang llvm libc++-dev libclang-dev lld gdb make wget
RUN bash -c "$(wget https://gef.blah.cat/sh -O -)"

RUN echo "\
    leak:llvm\n\
    leak:_fetchInitializingClassList\n\
    leak:__Balloc_D2A" >> /root/.lsan.supp

RUN echo "\
    export CXX=clang++\n\
    export CC=clang\n\
    export CXXFLAGS='-std=c++20 -g -pthread -Wall -Wshadow -Wuninitialized -Wtype-limits'\n\
    export CFLAGS='-std=c17 -g -pthread -Wall -Wpedantic -Wshadow -Wuninitialized -Wtype-limits'\n\
    export LDFLAGS='-fuse-ld=lld'\n\
    export CSTRICT='-fsanitize=address,undefined,leak,bounds -Werror'\n\
    export CTHREAD='-fsanitize=thread,undefined,bounds -Werror'\n\
    export LSAN_OPTIONS=suppressions=/root/.lsan.supp\n" >> ~/.bashrc

WORKDIR /root/plagiarism_checker

CMD ["/bin/bash"]
