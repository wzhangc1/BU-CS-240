#
# Specifiy the target
all:	ZhangCenWilliams-wzhangc1-Hello

# Specify the object files that the target depends on
# Also specify the object files needed to create the executable
ZhangCenWilliams-wzhangc1-Hello: Hello_Class.o ZhangCenWilliams-wzhangc1-Hello.o
	g++  ZhangCenWilliams-wzhangc1-Hello.o Hello_Class.o  -o ZhangCenWilliams-wzhangc1-Hello.exe

# Specify how the object files should be created from source files
ZhangCenWilliams-wzhangc1-Hello.o:	ZhangCenWilliams-wzhangc1-Hello.cpp
	g++ -c ZhangCenWilliams-wzhangc1-Hello.cpp
	
Hello_Class.o:	Hello_Class.cpp
	g++ -c Hello_Class.cpp

# Specify the object files and executables that are generated
# and need to be removed to re-compile the whole thing
clean:
	rm -f *.o ZhangCenWilliams-wzhangc1-Hello.exe
