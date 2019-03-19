# This is a Dockerfile to build a Docker image for
# Operating Systems.

# We will start from a base Ubuntu 18.04
FROM ubuntu:18.04

# Create non-root user, install dependencies, install Anaconda
RUN apt-get update --fix-missing && \
    apt-get install -y build-essential tmux git gdb wget && \
    useradd -m -s /bin/bash student && \
    wget --quiet https://repo.anaconda.com/miniconda/Miniconda3-latest-Linux-x86_64.sh -O anaconda.sh && \
    mkdir -p /opt && \
    sh ./anaconda.sh -b -p /opt/conda && \
    rm anaconda.sh && \
    ln -s /opt/conda/etc/profile.d/conda.sh /etc/profile.d/conda.sh && \
    chown -R student /opt && \
    echo ". /opt/conda/etc/profile.d/conda.sh" >> /home/student/.bashrc && \
    echo "conda activate base" >> /home/student/.bashrc && \
    git clone https://github.com/longld/peda.git /home/student/peda && \
    chown -R student /home/student/peda && \
    echo "source ~/peda/peda.py" >> /home/student/.gdbinit && \
    chown -R student /home/student/.gdbinit

RUN apt-get install -y nano

RUN apt-get install -y openjdk-8-sdk
RUN apt-get install -y qemu && \
    git clone https://github.com/linhbngo/xv6-public.git /home/student/xv6 && \
    echo "add-auto-load-safe-path /home/student/xv6/.gdbinit" >> /home/student/.gdbinit && \
    chown -R student /home/student/xv6 && \
    chown -R student /home/student/.gdbinit
    
USER student
ENV PATH "/bin:/usr/bin:$PATH"
WORKDIR "/home/student"
CMD ["/bin/bash"]
# test
