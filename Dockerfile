FROM ubuntu:22.04
ENV DEBIAN_FRONTEND=noninteractive
RUN apt-get update && apt-get install -y \
    tzdata \
    build-essential \
    g++ \
    cmake \
    qtbase5-dev \
    qtchooser \
    qttools5-dev-tools \
    libgl1-mesa-glx \
    libx11-dev \
    libxext6 \
    libxrender-dev \
    && apt-get clean
ENV DISPLAY=host.docker.internal:0.0
WORKDIR /my-app
COPY my-app/ /my-app/
RUN mkdir build
RUN cd build && cmake .. && make
CMD ["./build/ui"]
