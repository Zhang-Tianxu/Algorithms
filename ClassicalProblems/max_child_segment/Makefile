cc = gcc
cpp = g++
objects = divide_and_conquer.out  dynamic_programming.out
tester = tester.cpp

edit: $(objects)
	echo "done"

divide_and_conquer.out : $(tester)
	$(cpp) -o divide_and_conquer.out divide_and_conquer.cpp $(tester)

dynamic_programming.out : $(tester)
	$(cpp) -o dynamic_programming.out dynamic_programming.cpp $(tester)

clean :
	rm $(objects)
