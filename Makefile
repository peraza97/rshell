COMPILE = g++
FLAGS = -Werror -Wall -ansi

all:
	mkdir -p ./bin
	$(COMPILE) $(FLAGS) ./src/main.cpp -o ./bin/rshell
main:
	$(COMPILE) $(FLAGS) ./src/main.cpp

Cmd:
	$(COMPILE) $(FLAGS) ./src/Cmd.cpp

Exit:
	$(COMPILE) $(FLAGS) ./src/Exit.cpp

And:
		$(COMPILE) $(FLAGS) ./src/And.cpp

Or:
	$(COMPILE) $(FLAGS) ./src/Or.cpp

Semi:
	$(COMPILE) $(FLAGS) ./src/Semi.cpp

clean:
	rm -rf ./bin
