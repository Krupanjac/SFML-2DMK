CXX		  := g++
CXX_FLAGS := -Wall -Wextra -std=c++17 -ggdb -pthread

BIN		:= bin
SRC		:= src
INCLUDE	:= include
SFML_INCLUDE := C:\Users\arsen\Documents\LIBS\SFML-2.5.1\include
SFML_LIB := C:\Users\arsen\Documents\LIBS\SFML-2.5.1\lib
LIB		:= lib

LIBRARIES	:= -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lopengl32 -lfreetype -lwinmm -lgdi32 -mwindows
EXECUTABLE	:= main


all: $(BIN)/$(EXECUTABLE)

run: clean all
	clear
	./$(BIN)/$(EXECUTABLE)

$(BIN)/$(EXECUTABLE): $(SRC)/*.cpp
	$(CXX) $(CXX_FLAGS) -I"$(INCLUDE)" -I"$(SFML_INCLUDE)" -DSFML_STATIC -L"$(LIB)" -L"$(SFML_LIB)" $^ -o $@ $(LIBRARIES)

clean:
	-rm $(BIN)/*
