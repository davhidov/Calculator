TEST_FILES=s21_SmartCalc/graph.c s21_SmartCalc/input.c s21_SmartCalc/polish_to_rez.c s21_SmartCalc/polish.c s21_SmartCalc/stack.c
ifeq ($(shell uname -s), Linux)
	LFLAG += -lpthread -lrt -lm -lsubunit
endif

BUILD_DIR = ../build

all: clean dvi style test gcov_report dist install
	./../build/Calc
	make clean

install:
	[ -d $(BUILD_DIR) ] || mkdir -p $(BUILD_DIR)
	cd ../build && qmake ../src/s21_SmartCalc/Calc.pro
	make -C ../build/

uninstall: clean
	rm -Rf ../build/

dvi:
	open dvi.md

dist: uninstall clean
	tar -cf s21_SmartCalc.tar *

test: clean
	gcc -Wall -Wextra -Werror -std=c11 -D_GNU_SOURCE -g test.c $(TEST_FILES) -o test -lcheck $(LFLAG)
	rm -rf *.o *.a
	./test

gcov_report: clean
	gcc test.c $(TEST_FILES) -o gcov_report --coverage -lcheck $(LFLAG)
	./gcov_report
	rm -f test.gc*
	gcov *.gcno
	lcov -d . -o gcov_report.info -c
	genhtml -o report gcov_report.info
	open report/index.html

style:
	clang-format -style=Google -i test.c
	clang-format -style=Google -n test.c
	clang-format -style=Google -i s21_SmartCalc/*.c s21_SmartCalc/*.cpp s21_SmartCalc/*.h
	clang-format -style=Google -n s21_SmartCalc/*.c s21_SmartCalc/*.cpp s21_SmartCalc/*.h

rebuild: uninstall install

clean:
	rm -f *.gcno *.gcda *.info *.gcov 
	rm -f *.o *.a
	rm -rf report
	rm -f *.out
	rm -f test
	rm -rf test.dSYM
	rm -f gcov_report
	rm -f *.tar
	rm -rf ../build
