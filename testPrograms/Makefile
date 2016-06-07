
all: bounceTest

bounceTest: bounceTest.c Makefile
	clang -ggdb3 -O0 -std=c99 -Wall -Werror -o bounceTest bounceTest.c -lcs -lm
	
clean:
	rm -f *.o core bounceTest
