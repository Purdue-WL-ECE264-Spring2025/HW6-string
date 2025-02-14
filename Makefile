WARNING = -Wall -Wshadow --pedantic
ERROR = -Wvla -Werror
GCC = gcc -std=c11 -g $(WARNING) $(ERROR) 

SRCS = main.c stringm.c
OBJS = $(SRCS:%.c=%.o)

stringm: $(OBJS) 
	$(GCC) $(OBJS) -o stringm

.c.o: 
	$(GCC) -c $*.c 

testall: stringm
	./stringm -1

test1: stringm
	./stringm 1

test2: stringm
	./stringm 2

test3: stringm
	./stringm 3

# TODO: put the ones that have memory allocation here
leak: str
	valgrind ./stringm 1

clean: # remove all machine generated files
	rm -f stringm *.o
	