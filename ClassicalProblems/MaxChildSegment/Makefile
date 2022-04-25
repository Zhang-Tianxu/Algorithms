cc = gcc
cpp = g++
objects = DivideAndConquer.out  DynamicProgramming.out
tester = Tester.cpp

edit: $(objects)
	echo "done"

DivideAndConquer.out : $(tester)
	$(cpp) -o DivideAndConquer.out DivideAndConquer.cpp $(tester)

DynamicProgramming.out : $(tester)
	$(cpp) -o DynamicProgramming.out DynamicProgramming.cpp $(tester)

clean :
	rm $(objects)
