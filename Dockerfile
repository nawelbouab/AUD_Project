FROM ubuntu:14.04


RUN apt-get update && apt-get install -y software-properties-common && apt-get install -y gcc
COPY . /

ENTRYPOINT ./graphsearch $0 $1