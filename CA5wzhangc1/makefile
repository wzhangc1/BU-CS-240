#
# Specifiy the target
all:	Driver

# Specify the object files that the target depends on
# Also specify the object files needed to create the executable
Driver: 	Graph.o		Time.o		Driver.o
	g++	Graph.o		Time.o		Driver.o	-o Driver.exe

# Specify how the object files should be created from source files
Graph.o:	Graph.cpp
		g++ -g -c Graph.cpp

Time.o:		Time.cpp
		g++ -g -c Time.cpp

Driver.o:	Driver.cpp
		g++ -g -c Driver.cpp

# Specify the object files and executables that are generated
# and need to be removed to re-compile the whole thing
clean:
	rm -f *.o Driver.exe
