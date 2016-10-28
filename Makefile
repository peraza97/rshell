
COMPILE = g++
FLAGS =-Wall  -Werror  -ansi -pedantic

all:
	mkdir -p ./bin
	$(COMPILE) $(FLAGS) ./src/main.cpp -o ./bin/rshell

main:
	$(COMPILE) $(FLAGS) ./src/main.cpp

Connector:
	$(COMPILE) $(FLAGS) ./src/Connector.cpp

Cmd:
	$(COMPILE) $(FLAGS) ./src/Cmd.cpp

And:
		$(COMPILE) $(FLAGS) ./src/And.cpp

Or:
	$(COMPILE) $(FLAGS) ./src/Or.cpp

Semi:
	$(COMPILE) $(FLAGS) ./src/Semi.cpp

Exit:
	$(COMPILE) $(FLAGS) ./src/Exit.cpp

clean:
	rm -rf ./bin
