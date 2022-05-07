CC = gcc
CFLAGS = -Wall -Werror -Wextra
FLAG = --coverage
CFILE = s21_matrix.c
OFILE = s21_matrix.o
OS := $(shell uname -s)

all: clean s21_matrix.a test

s21_matrix.o:
	$(CC) $(CFLAGS) -c s21_matrix.c -o s21_matrix.o

s21_matrix.a: $(OFILE)
	ar rcs s21_matrix.a $(OFILE)
	cp s21_matrix.a libs21_matrix
	cp s21_matrix.a ls21_matrix

test: s21_matrix.a
ifeq ($(OS), Darwin)
	$(CC) $(CFLAGS) -c test.c -o test.o
	$(CC) $(CFLAGS) test.o s21_matrix.a -o test -lcheck
	./test
else
	$(CC) $(CFLAGS) test.c s21_matrix.a -o test -lcheck -lsubunit -lrt -lpthread -lm
	./test
endif

gcov:
ifeq ($(OS), Darwin)
	$(CC) $(CFLAGS) $(FLAG) $(CFILE) test.c -o test -lcheck
else
	$(CC) $(CFLAGS) $(FLAG) $(CFILE) test.c -o test -lcheck -lsubunit -lrt -lpthread -lm
endif

gcov_report: clean gcov
	./test
	lcov -t “test” -o test.info -c -d .
	genhtml -o report test.info
ifeq ($(OS), Darwin)
	open report/index.html
else
	x-www-browser report/index.html
endif

clean:
	rm -rf *.cfg *.o  *.gc* report *.a test libs21_matrix ls21_matrix test.info

cpp:
	cp ../materials/linters/CPPLINT.cfg CPPLINT.cfg
	python3 ../materials/linters/cpplint.py --extensions=c *.h *.c
	cppcheck --enable=all --suppress=missingIncludeSystem *.c *.h
	rm -rf CPPLINT.cfg
ifeq ($(OS), Darwin)
	CK_FORK=no leaks --atExit -- ./test
else
	valgrind --quiet ./test
endif

