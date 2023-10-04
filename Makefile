DOCKER_IMAGE_NAME = vending-machine-image
COMPILER_CONTAINER_NAME = vending-machine-container

.PHONY: build
build: clean
	docker build -t $(DOCKER_IMAGE_NAME) $(if $(COMPILER), --build-arg COMPILER=$(COMPILER)) $(if $(FILE_NAME), --build-arg FILE_NAME=$(FILE_NAME)) .

.PHONY: compile
compile: build
	docker run --name $(COMPILER_CONTAINER_NAME) $(DOCKER_IMAGE_NAME)

.PHONY: copy
copy: compile
	docker cp $(COMPILER_CONTAINER_NAME):/CODE/$(FILE_NAME) /build/

.PHONY: clean
clean:
	docker rm $(COMPILER_CONTAINER_NAME) || true
	docker rmi $(DOCKER_IMAGE_NAME) || true

.PHONY: all
all: copy

.PHONY: help
help:
	@echo "Available targets:"
	@echo "  build       - Build the Docker image. (make build COMPILER=sparc-elf-4.4.2-1.0.52 FILE_NAME=build)"
	@echo "  compile     - Compile the source code using the Docker container"
	@echo "  copy        - Copy the compiled output to /build"
	@echo "  clean       - Remove the Docker container and image"
	@echo "  all         - Build, compile, and copy (default target)"