FROM gcc:10.4

ENV DEBIAN_FRONTEND "noninteractive"

RUN apt update && \
    apt dist-upgrade -y

RUN apt install -y make cmake python3-pip && \
    pip3 install conan

ENV PROJECT_DIR /project
ENV PROJECT_SOURCE_DIR ${PROJECT_DIR}/source_code
ENV PROJECT_BUILD_DIR ${PROJECT_DIR}/build

ADD src ${PROJECT_SOURCE_DIR}/src
ADD test ${PROJECT_SOURCE_DIR}/test
ADD CMakeLists.txt ${PROJECT_SOURCE_DIR}/CMakeLists.txt

RUN cmake -DCMAKE_BUILD_TYPE=Release -S ${PROJECT_SOURCE_DIR} -B ${PROJECT_BUILD_DIR}
WORKDIR ${PROJECT_BUILD_DIR}
RUN make

ENTRYPOINT ["./bin/algorithms_tests"]
