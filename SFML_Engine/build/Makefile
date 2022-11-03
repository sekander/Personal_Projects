SRC_DIRS ?= ../src
#OBJ_DIRS ?= ../src/obj_code/glad.o

#OBJS specifies which files to compile as part of the project
SRCS := $(shell find $(SRC_DIRS) -name *.cpp -or -name *.c -or -name *.s)
#OBJS := $(SRCS:%=$(BUILD_DIR)/%.o) glad.o
#OBJS := $(SRCS:%=$(BUILD_DIR)/%.o) $(OBJ_DIRS) 
#OBJS = main.cpp game.cpp resource_manager.cpp sprite_renderer.cpp texture.cpp shader.cpp Orthographic_camera.cpp glad.o

#OBJS = main.cpp include/game.cpp  
#CC specifies which compiler we're using
CC = g++ -std=c++17

#COMPILER_FLAGS specifies the additional compilation options we're using
# -w suppresses all warnings
COMPILER_FLAGS = -w

#LINKER_FLAGS specifies the libraries we're linking against
LINKER_FLAGS = -lGL -lGLU -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lsfml-network -lbox2d -ltinyxml -ltmxlite 

#OBJ_NAME specifies the name of our exectuable
OBJ_NAME = SFML_game_engine 

#This is the target that compiles our executable
all : $(OBJS)
	$(CC) $(SRCS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o ../$(OBJ_NAME)

