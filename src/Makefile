GCC=gcc
CFLAGS=-std=c11 -Wall -Werror -Wextra -lm
LIBNAME=s21_decimal.a
TEST_FLAGS=-lcheck -lm -lsubunit -g
SRCS=arithmetic/*.c banc_round/*.c compare_big_decimal/*.c compare_decimal/*.c conv/*.c operation_big_decimal/*.c operation_decimal/*.c others/*.c
EXCLUDES='tests/|compare_big_decimal/|arithmetic/arithmetic_help.c|conv/s21_big_decimal_to_decimal.c|conv/s21_decimal_to_big_decimal*.c|operation_big_decimal/|operation_decimal/|banc_round/' 

all: $(LIBNAME)

test: clean 
	$(GCC) tests/*test.c ${CFLAGS} $(SRCS) $(TEST_FLAGS) -o test
	@./test
	@rm test

$(LIBNAME): $(OBJS)
	$(GCC) -c $(CFLAGS) $(SRCS)
	ar rcs $(LIBNAME) *.o
	ranlib $(LIBNAME)
	mkdir -p objects/
	mv *.o objects/

rebuild: clean $(LIBNAME)

build: ${SRCS} main.c
	@${GCC} $^ -lm
	./a.out

clean:
	@rm -rf objects test *.out report *.a *.gcno *.o

clang:
	@clang-format -i *.h
	@clang-format -i */*.c
	@clang-format -n */*.c
	@clang-format -i tests/*.c tests/*.h
	@clang-format -n tests/*.c tests/*.h

gcov_report: clean tests/*.c 
	@mkdir -p report
	$(GCC) --coverage tests/*.c ${CFLAGS} $(SRCS) $(TEST_FLAGS) -o report/test
	./report/test
	@gcovr --html-details -o report/report.html --exclude=${EXCLUDES}
	@xdg-open report/report.html