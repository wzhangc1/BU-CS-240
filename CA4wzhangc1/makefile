#
# Specifiy the target
all:	Driver

# Specify the object files that the target depends on
# Also specify the object files needed to create the executable
Driver: 	Game.o	LLC.o	Player.o	PlayingCard.o	Tournament.o	Driver.o
	g++	Game.o	LLC.o	Player.o	PlayingCard.o	Tournament.o	Driver.o	-o Driver.exe

# Specify how the object files should be created from source files
Game.o:		Game.cpp
		g++ -c Game.cpp

LLC.o:		LLC.cpp
		g++ -c LLC.cpp

Player.o:	Player.cpp
		g++ -c Player.cpp

PlayingCard.o:	PlayingCard.cpp
		g++ -c PlayingCard.cpp

Tournament.o:	Tournament.cpp
		g++ -c Tournament.cpp

Driver.o:	Driver.cpp
		g++ -c Driver.cpp

# Specify the object files and executables that are generated
# and need to be removed to re-compile the whole thing
clean:
	rm -f *.o Driver.exe
