WARNING = -Wall -Wshadow --pedantic
ERROR = -Wvla -Werror
GCC = gcc -std=c11 -g $(WARNING) $(ERROR) 

SRCS = main.c str.c
OBJS = $(SRCS:%.c=%.o)

str: $(OBJS) 
	$(GCC) $(OBJS) -o str

.c.o: 
	$(GCC) -c $*.c 

testall: test1 test2 test3 test4 test5 test6 test7 test8 test9

test1: str
	./str inputs/input1 copy > output1
	diff output1 expected_outputs/output1

test2: str
	./str inputs/input2 copy > output2
	diff output2 expected_outputs/output2

test3: str
	./str inputs/input3 copy > output3
	diff output3 expected_outputs/output3

test4: str
	./str inputs/input4 join > output4
	diff output4 expected_outputs/output4

test5: str
	./str inputs/input5 join > output5
	diff output5 expected_outputs/output5

test6: str
	./str inputs/input6 join > output6
	diff output6 expected_outputs/output6

test7: str
	./str inputs/input7 split > output7
	diff output7 expected_outputs/output7

test8: str
	./str inputs/input8 split > output8
	diff output8 expected_outputs/output8

test9: str
	./str inputs/input9 split > output9
	diff output9 expected_outputs/output9

leak: str
	valgrind ./str inputs/input1 copy
	valgrind ./str inputs/input4 join
	valgrind ./str inputs/input9 split 

clean: # remove all machine generated files
	rm -f str *.o output*