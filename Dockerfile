# This Dockerfile is only for learning purpose
#
# You can build it locally by:
# $> docker build --tag cpython:local .
#
# And you can run a container as follows:
# $> docker run -it --rm cpython:local
#
FROM python:3-alpine

RUN apk add -u gcc musl-dev python3-dev

RUN pip install ipython

COPY . /cpython

WORKDIR /cpython

CMD ["/bin/sh"]
