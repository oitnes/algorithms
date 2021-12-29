FROM ubuntu:latest

ENV DEBIAN_FRONTEND "noninteractive"

RUN apt-get update
RUN apt-get dist-upgrade -y

RUN apt-get install -y software-properties-common build-essential gcc g++ make cmake python3-pip
RUN pip3 install conan

ENV PROJECT_DIR /project
ENV PROJECT_SOURCE_DIR ${PROJECT_DIR}/source_code
ENV PROJECT_BUILD_DIR ${PROJECT_DIR}/build

ADD . ${PROJECT_SOURCE_DIR}/

RUN cmake -DCMAKE_BUILD_TYPE=Release -S ${PROJECT_SOURCE_DIR} -B ${PROJECT_BUILD_DIR}
WORKDIR ${PROJECT_BUILD_DIR}
RUN make

WORKDIR ${PROJECT_BUILD_DIR}/bin
CMD ["./algorithms_tests"]
