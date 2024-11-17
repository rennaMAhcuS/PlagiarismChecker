# Plagiarism Checker - CS293 Project 2024

A Plagiarism Checker!

[**Source**](https://github.com/SuperSat001/CS293-Project-2024) - contains the problem statement and the required files.

## Instructions to use the `Dockerfile`

For the first time, run

```sh
docker build . --tag copycatchers
docker run --interactive --tty --volume .:/home/Loki/plagiarism_checker --name=NP-MOS --network=bridge --hostname=Midgard copycatchers:latest
```

To use the docker container, run

```sh
docker start --attach --interactive NP-MOS
```
