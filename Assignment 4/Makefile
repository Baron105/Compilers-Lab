output.txt: a.out ass_test.c
	./a.out < ass_test.c > output.txt

a.out: lex.yy.o y.tab.o ass.o
	cc lex.yy.o y.tab.o ass.o -lfl

lex.yy.o: lex.yy.c
	cc -c lex.yy.c

y.tab.o: y.tab.c
	cc -c y.tab.c

ass.o: ass.c
	cc -c ass.c

lex.yy.c: ass.l y.tab.h
	flex ass.l

y.tab.c: ass.y
	bison -dty ass.y

y.tab.h: ass.y
	bison -dty ass.y

ass.c:
	touch ass.c

clean:
	rm output.txt a.out lex.yy.* y.tab.* ass.o

out:
	rm a.out lex.* y.* ass.o