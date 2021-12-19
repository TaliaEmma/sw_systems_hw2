
all: task_3

task_3: stringProg.c
	gcc -Wall  stringProg.c -o  stringProg

	
	
.PHONY: clean
clean:
	rm -rf stringProg
