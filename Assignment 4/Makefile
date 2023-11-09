output.txt: a.out ass4_21CS10014_21CS30032_test.c
	./a.out < ass4_21CS10014_21CS30032_test.c > output.txt

a.out: lex.yy.o y.tab.o ass4_21CS10014_21CS30032.o
	cc lex.yy.o y.tab.o ass4_21CS10014_21CS30032.o -lfl

lex.yy.o: lex.yy.c
	cc -c lex.yy.c

y.tab.o: y.tab.c
	cc -c y.tab.c

ass4_21CS10014_21CS30032.o: ass4_21CS10014_21CS30032.c
	cc -c ass4_21CS10014_21CS30032.c

lex.yy.c: ass4_21CS10014_21CS30032.l y.tab.h
	flex ass4_21CS10014_21CS30032.l

y.tab.c: ass4_21CS10014_21CS30032.y
	bison -dty ass4_21CS10014_21CS30032.y

y.tab.h: ass4_21CS10014_21CS30032.y
	bison -dty ass4_21CS10014_21CS30032.y

ass.c:
	touch ass4_21CS10014_21CS30032.c

clean:
	rm output.txt a.out lex.yy.* y.tab.* ass4_21CS10014_21CS30032.o

out:
	rm a.out lex.* y.* ass4_21CS10014_21CS30032.o