# This is a Dockerfile to build a Docker image for
# Operating Systems.

# We will start from a base Ubuntu 18.04
FROM ubuntu:18.04

ENV PATH /opt/conda/bin:$PATH

RUN apt-get update --fix-missing

RUN apt-get install -y build-essential

RUN apt-get install -y tmux

RUN apt-get install -y git gdb

RUN git clone https://github.com/longld/peda.git ~/peda && echo "source ~/peda/peda.py" >> ~/.gdbinit

CMD ["/bin/bash"]
