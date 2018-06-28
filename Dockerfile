FROM gcc
ADD . /code
WORKDIR /code
RUN gcc --std=gnu11 fileWriter.c -o fileWriter
CMD ["./fileWriter"]
