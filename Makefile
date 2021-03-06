
COMPILE = g++
FLAGS =-Wall  -Werror  -ansi -pedantic

OBJS = ./bin/Shell.o ./bin/Cmd.o ./bin/Exit.o ./bin/Cd.o ./bin/Test.o  ./bin/Connector.o ./bin/And.o ./bin/Or.o ./bin/Semi.o

all: ./src/main.cpp $(OBJS)
	$(COMPILE) $(FLAGS) -g ./src/main.cpp $(OBJS) -o ./bin/rshell

./bin/Shell.o: ./src/Shell.h ./src/Shell.cpp
	mkdir -p ./bin
	$(COMPILE) $(FLAGS) -c ./src/Shell.cpp -o ./bin/Shell.o

./bin/Cmd.o: ./src/Shell.h ./src/Cmd.h ./src/Cmd.cpp
	$(COMPILE) $(FLAGS) -c ./src/Cmd.cpp -o ./bin/Cmd.o

./bin/Exit.o: ./src/Shell.h ./src/Exit.h ./src/Exit.cpp
	$(COMPILE) $(FLAGS) -c ./src/Exit.cpp -o ./bin/Exit.o

./bin/Cd.o: ./src/Cmd.h ./src/Cd.h ./src/Cd.cpp
	$(COMPILE) $(FLAGS) -c ./src/Cd.cpp -o ./bin/Cd.o

./bin/Test.o: ./src/Shell.h ./src/Test.h ./src/Test.cpp
	$(COMPILE) $(FLAGS) -c ./src/Test.cpp -o ./bin/Test.o

./bin/Connector.o: ./src/Shell.h ./src/Connector.h ./src/Connector.cpp
	$(COMPILE) $(FLAGS) -c ./src/Connector.cpp -o ./bin/Connector.o

./bin/And.o: ./src/Connector.h ./src/And.h ./src/And.cpp
		$(COMPILE) $(FLAGS) -c ./src/And.cpp -o ./bin/And.o

./bin/Or.o: ./src/Connector.h ./src/Or.h ./src/Or.cpp
	$(COMPILE) $(FLAGS) -c ./src/Or.cpp -o ./bin/Or.o

./bin/Semi.o: ./src/Connector.h ./src/Semi.h ./src/Semi.cpp
	$(COMPILE) $(FLAGS) -c ./src/Semi.cpp -o ./bin/Semi.o


clean:
	rm -rf ./bin/
