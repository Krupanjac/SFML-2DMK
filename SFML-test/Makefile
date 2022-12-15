CXX		  := g++
CXX_FLAGS := -Wall -Wextra -std=c++17 -ggdb -pthread

BIN		:= bin
SRC		:= src
INCLUDE	:= include
SFML_DLL_LIB := C:\Users\arsen\Documents\LIBS\SFML-2.5.1\bin
SFML_INCLUDE := C:\Users\arsen\Documents\LIBS\SFML-2.5.1\include
SFML_LIB := C:\Users\arsen\Documents\LIBS\SFML-2.5.1\lib
LIB		:= lib

LIBRARIES	:= -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lsfml-audio -lopengl32 -lfreetype -lwinmm -lgdi32 
EXECUTABLE	:= main


all: $(EXECUTABLE)

run: clean all exec
	clear
	./$(EXECUTABLE)

$(EXECUTABLE): $(SRC)/*.cpp
	$(CXX) $(CXX_FLAGS) -I"$(INCLUDE)" -I"$(SFML_INCLUDE)" -DSFML_STATIC -L"$(LIB)" -L"$(SFML_LIB)" -L"$(SFML_DLL_LIB)" $^ -o $@ $(LIBRARIES)

clean:
	del $(EXECUTABLE).exe

exec:
	$(EXECUTABLE).exe