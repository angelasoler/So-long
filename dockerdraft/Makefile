NAME=solong

BUILD=docker build -t ${NAME} .

RUN=docker run -it --privileged --name=${NAME} \
	--mount type=bind,source=${PWD},target=/solong \
	-e DISPLAY=${DISPLAY} -v /tmp/.X11-unix:/tmp/.X11-unix:ro \
	${NAME} bash

EXEC=docker exec -ti ${NAME} bash

RM_IMAGE=docker image rm ${NAME}

RM_CONT=docker rm ${NAME}

all: image

run: build
	$(RUN)

build:
	xhost +
	$(BUILD)

start: 
	docker start ${NAME}

image: 
	$(EXEC)

#comando *xhost +" => Access (connections to the X server) is granted to everyone, even if they aren't on the list (i.e., access control is turned off)
#make => starta o container q já foi criado e executa
#make run => senão existe o container ainda, cria e roda, se já existe só roda.