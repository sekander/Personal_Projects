SRC_DIRS ?= ../src

SRCS := $(shell find $(SRC_DIRS) -name *.cpp -or -name *.c -or -name *.s -or -name *.o)

CC = g++ -std=c++17

#COMPILER_FLAGS specifies the additional compilation options we're using
# -w suppresses all warnings
COMPILER_FLAGS = -w -Weffc++ 

#LINKER_FLAGS specifies the libraries we're linking against
LINKER_FLAGS = -lGL -lGLU -ldl -lglfw -lbox2d -ltinyxml -lpthread -lfreetype -ltmxlite 

#OBJ_NAME specifies the name of our exectuable
OBJ_NAME = smart_engine

#This is the target that compiles our executable
all : $(OBJS)
	$(CC) $(SRCS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o ../$(OBJ_NAME)

