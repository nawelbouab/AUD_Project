FROM ubuntu:14.04

COPY . /
RUN apt-get update && apt-get install -y software-properties-common && apt-get install -y gcc

ENTRYPOINT ./graphsearch $0 $1