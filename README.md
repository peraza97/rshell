# INSTALLATION
git clone https://github.com/peraza97/rshell.git

 cd rshell

git checkout hw2

make

./bin/rshell

# Introduction
The purpose of this program is to simulate the behavior of a shell using C++. The program itself will analyze user input to determine what commands it will need to execute. To implement this, we will use several different classes that all derive from the same Shell base class. These classes will be used to interpret commands with connectors and then execute those commands with execvp(). Since execvp() ends the process upon its completion, it will use the system call fork() so that the program will be able to complete the commands without ending. Similarly to the shell, the program will be able to run multiple commands sequentially as long as they are appropriately separated by connectors. The program will continue to take in input and respond accordingly until the user enters the exit command.

#ALGORITHM
In order to execute multiple commands, we build a tree that will recursively run execvp on all commands given. We build this tree by first taking the input and then change the input into a vector in post fix notation

eg. ls || git status turns into ls git status ||

this allows us to then use this postfix notation to then build a tree.

# Known Bugs
Currently, we are unable to account for precedence with parenthesis. In addition, we are unable to account for piping, or redirection in our Shell.
