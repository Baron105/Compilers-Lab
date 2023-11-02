a.out: main.o libass6.a
	cc main.o -L. -lass6

main.o: main.c myl.h
	cc -Wall -c main.c

libass6.a: ass6.o
	ar -rcs libass6.a ass6.o

ass6.o: ass6.c myl.h
	cc -Wall -c ass6.c

clean:
	rm a.out main.o libass6.a ass6.o