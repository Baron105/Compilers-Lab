output.txt: a.out ass3_test.c
	./a.out < ass3_test.c > output.txt

a.out: lex.yy.c ass3.o
	cc -Wall lex.yy.c ass3.o -lfl

lex.yy.c: ass3.l
	flex ass3.l

ass3.o: ass3.c
	cc -Wall -c ass3.c

clean:
	rm a.out lex.yy.c output.txt ass3.o