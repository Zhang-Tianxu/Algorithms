cc = gcc
cpp = g++
objects = dynamic_programming.out
tester = tester.cpp

edit: $(objects)
	echo "done"

dynamic_programming.out : $(tester)
	$(cpp) -o dynamic_programming.out dynamic_programming.cpp $(tester)

clean :
	rm $(objects)
