BASE = ass5_21CS10014_21CS30032

a.out: lex.yy.o $(BASE).tab.o $(BASE)_translator.o
	g++ lex.yy.o $(BASE).tab.o $(BASE)_translator.o -lfl

$(BASE)_translator.o: $(BASE)_translator.cxx $(BASE)_translator.h
	g++ -c $(BASE)_translator.h
	g++ -c $(BASE)_translator.cxx

lex.yy.o: lex.yy.c
	g++ -c lex.yy.c

$(BASE).tab.o: $(BASE).tab.c
	g++ -c $(BASE).tab.c

lex.yy.c: $(BASE).l $(BASE).tab.h $(BASE)_translator.h
	flex $(BASE).l

$(BASE).tab.c: $(BASE).y
	bison -dtv $(BASE).y

$(BASE).tab.h: $(BASE).y
	bison -dtv $(BASE).y

test :a.out
	mkdir -p ./output_test_codes

	./a.out < test_codes/ass5_21CS10014_21CS30032_test1.c > output_test_codes/ass5_21CS10014_21CS30032_quads1.out

	@echo "\nTest outputs generated and written to ./test-outputs.\n"


clean:
	rm lex.yy.c $(BASE).tab.c $(BASE).tab.h lex.yy.o $(BASE).tab.o $(BASE)_translator.o  $(BASE).output a.out  $(BASE)_translator.h.gch output_test_codes/*_quads*.out
