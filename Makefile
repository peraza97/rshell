COMPILE = g++
FLAGS = -Werror -Wall -ansi


all: 
	mkdir -p ./bin
	$(COMPILE) $(FLAGS) ./src/main.cpp -o ./bin/rshell
main:
	$(COMPILE) $(FLAGS) ./src/main.cpp

Shell:
	$(COMPILE) $(FLAGS) -c ./src/Shell.cpp

Connector:
	$(COMPILE) $(FLAGS) -c ./src/Connector.cpp

Cmd:
		$(COMPILE) $(FLAGS) -c ./src/Cmd.cpp

Exit:
		$(COMPILE) $(FLAGS) -c ./src/Exit.cpp

And:
		$(COMPILE) $(FLAGS) -c ./src/And.cpp

Or:
	$(COMPILE) $(FLAGS) -c ./src/Or.cpp

Semi:
	$(COMPILE) $(FLAGS) -c ./src/Semi.cpp

clean:
	rm -rf ./bin
