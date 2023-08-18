a.out: main.o libass2_21CS10014.a
	cc main.o -L. -lass2_21CS10014

main.o: main.c myl.h
	cc -Wall -c main.c

libass2_21CS10014.a: ass2_21CS10014.o
	ar -rcs libass2_21CS10014.a ass2_21CS10014.o

ass2_21CS10014.o: ass2_21CS10014.c myl.h
	cc -Wall -c ass2_21CS10014.c

clean:
	rm a.out main.o libass2_21CS10014.a ass2_21CS10014.o