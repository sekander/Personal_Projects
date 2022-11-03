#OBJS specifies which files to compile as part of the project
OBJS = game.cpp game_map.cpp OpenGL.cpp MapLayer.cpp resource_manager.cpp sprite_renderer.cpp texture.cpp shader.cpp entity.cpp entity_manager.cpp Lines.cpp Orthographic_camera.cpp glad.o

#CC specifies which compiler we're using
CC = g++

#COMPILER_FLAGS specifies the additional compilation options we're using
# -w suppresses all warnings
COMPILER_FLAGS = -w

#LINKER_FLAGS specifies the libraries we're linking against
LINKER_FLAGS = -lGL -lGLU -ldl -lglfw -lbox2d -ltmxlite 

#OBJ_NAME specifies the name of our exectuable
OBJ_NAME = openGL_engine

#This is the target that compiles our executable
all : $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)

