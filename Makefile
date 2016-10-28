COMPILE = g++
FLAGS = -Werror -Wall -ansi

OBJS = Cmd.o Exit.o And.o Or.o Semi.o

all: ./src/main.cpp $(OBJS)
	mkdir -p ./bin
	$(COMPILE) $(FLAGS) ./src/main.cpp $(OBJS) -o ./bin/rshell

Cmd.o: ./src/Shell.h ./src/Cmd.h ./src/Cmd.cpp
	$(COMPILE) $(FLAGS) -c ./src/Cmd.cpp

Exit.o: ./src/Shell.h ./src/Exit.h ./src/Exit.cpp
	$(COMPILE) $(FLAGS) -c ./src/Exit.cpp

And.o: ./src/Connector.h ./src/And.h ./src/And.cpp
		$(COMPILE) $(FLAGS) -c ./src/And.cpp

Or.o: ./src/Connector.h ./src/Or.h ./src/Or.cpp
	$(COMPILE) $(FLAGS) -c ./src/Or.cpp

Semi.o: ./src/Connector.h ./src/Semi.h ./src/Semi.cpp
	$(COMPILE) $(FLAGS) -c ./src/Semi.cpp

clean:
	rm -rf *.o
	rm -rf ./bin
