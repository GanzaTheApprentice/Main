CC = gcc
CFLAGS = -Wall -Werror -Wextra
FLAG = --coverage
CFILE = smartCalc.c
OFILE = smartCalc.o
OS := $(shell uname -s)

all: clean install test

smartCalc.o:
	$(CC) $(CFLAGS) -c smartCalc.c -o smartCalc.o

test: smartCalc.o
ifeq ($(OS), Darwin)
	$(CC) $(CFLAGS) -c test.c -o test.o
	$(CC) $(CFLAGS) test.o smartCalc.o -o test -lcheck
	./test
else
	$(CC) $(CFLAGS) -c test.c -o test.o
	$(CC) $(CFLAGS) test.o smartCalc.o -o test -lcheck -lsubunit -lrt -lpthread -lm
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

dvi:
	chmod +x dvi.sh
	sh dvi.sh
	open documentation.md

build:
	mkdir build
	cd ./build/ && qmake6 ../smartCalc.pro && make

install: build
	mkdir $(HOME)/Desktop/installedSmartCalc
	cp -rf build/smartCalc.app $(HOME)/Desktop/installedSmartCalc/
	rm -rf build

uninstall:
	rm -rf  $(HOME)/Desktop/installedSmartCalc

dist:
	rm -rf $(HOME)/Desktop/smartCalc.zip
	mkdir smartCalc
	mkdir smartCalc/src
	cp *.c *.cpp *.ui *.pro *.pro.user *.sh Makefile smartCalc/src/
	zip smartCalc.zip smartCalc/src/*
	mv smartCalc.zip $(HOME)/Desktop
	rm -rf smartCalc

clean:
	rm -rf $(HOME)/Desktop/smartCalc.zip *tion.md *.cfg *.o  *.gc* report *.a test libsmartCalc lsmartCalc test.info build-smartCalc-Desktop_x86_darwin_generic_mach_o_64bit-Debug

cpp:
	cp ../materials/linters/CPPLINT.cfg CPPLINT.cfg
	python3 ../materials/linters/cpplint.py --extensions=c *.c smartCalc.h
	cppcheck --enable=all --suppress=missingIncludeSystem *.c smartCalc.h
	rm -rf CPPLINT.cfg
ifeq ($(OS), Darwin)
	CK_FORK=no leaks --atExit -- ./test
else
	valgrind --quiet ./test
endif
