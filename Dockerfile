FROM --platform=linux/amd64 debian:bookworm-slim

ARG COMPILER=sparc-elf-4.4.2
ARG FILE_NAME=build

RUN dpkg --add-architecture i386 && \
    apt-get update && \
    apt-get install -y bzip2 libc6:i386 libncurses5:i386 libstdc++6:i386

WORKDIR /usr/local/bin/

COPY ./vendor/$COMPILER.tar.bz2 .

RUN tar -xjf $COMPILER.tar.bz2 &&\
    chmod +x ./$COMPILER/bin/sparc-elf-g++

WORKDIR /code/
COPY ./src .

RUN /usr/local/bin/$COMPILER/bin/sparc-elf-g++ -o $FILE_NAME main.cpp

CMD [ "/bin/sh", "-c", "/usr/local/bin/sparc-elf-4.4.2/bin/sparc-elf-g++" ]