output.txt: a.out ass3_21CS10014_21CS30032_test.c
	./a.out < ass3_21CS10014_21CS30032_test.c > output.txt

a.out: lex.yy.c ass3_21CS10014_21CS30032.o
	cc lex.yy.c ass3_21CS10014_21CS30032.o -lfl

lex.yy.c: ass3_21CS10014_21CS30032.l
	flex ass3_21CS10014_21CS30032.l

ass3_21CS10014_21CS30032.o: ass3_21CS10014_21CS30032.c
	cc -c ass3_21CS10014_21CS30032.c

ass3_21CS10014_21CS30032.c:
	touch ass3_21CS10014_21CS30032.c

clean:
	rm a.out lex.yy.c output.txt ass3_21CS10014_21CS30032.o