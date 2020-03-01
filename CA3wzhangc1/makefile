#
# Specifiy the target
all:	Driver

# Specify the object files that the target depends on
# Also specify the object files needed to create the executable
Driver: LLC.o	Driver.o
	g++  LLC.o	Driver.o	-o Driver.exe

# Specify how the object files should be created from source files
LLC.o:		LLC.cpp
		g++ -c LLC.cpp

Driver.o:	Driver.cpp
		g++ -c Driver.cpp

# Specify the object files and executables that are generated
# and need to be removed to re-compile the whole thing
clean:
	rm -f *.o Driver.exe
