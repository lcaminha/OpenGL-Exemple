CC=g++
DEBUG=-g
OPT=-O0 -std=gnu++11
WARN=-Wall -fexceptions
OpenGLLIB=-lGL -lGLEW -lSDL2

PTHREAD=-pthread
CCFLAGS=$(DEBUG) $(OPT) $(WARN) $(PTHREAD)

LD=g++
LDFLAGS=$(PTHREAD) $(OpenGLLIB) -export-dynamic

SOURCES=$(wildcard src/**/*.cpp src/*.cpp)
OBJECTS=$(patsubst %.cpp,%.o,$(SOURCES))

TARGET=build/libOpenGL
SO_TARGET=$(patsubst %.bin,%.so,$(TARGET))

all: COMPILER

COMPILER:$(SOURCES) # $(OBJECTS)
	$(CC) -o $@ $(OBJECTS) $(CCFLAGS)

$(SOURCES): 
	$(CC) -c $< $(OBJECTS) $(LDFLAGS)



all: main
	$(LD) -o $(TARGET) $(OBJS) $(LDFLAGS)
main: includes
	$(CC) -c $(CCFLAGS) src/main.cpp $(OpenGLLIB) -o build/obj/main.o
includes:
	$(CC) -c $(CCFLAGS) src/include/Display.cpp $(OpenGLLIB) -o build/obj/include/Display.o
clean:
	rm -f build/bin/* build/obj/*.o build/obj/include/*.o
.PHONY: all clean

run: all
	./${TARGET}
