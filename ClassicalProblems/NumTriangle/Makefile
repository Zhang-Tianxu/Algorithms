cc = gcc
cpp = g++
objects = DynamicProgramming.out
tester = Tester.cpp

edit: $(objects)
	echo "done"

DynamicProgramming.out : $(tester)
	$(cpp) -o DynamicProgramming.out DynamicProgramming.cpp $(tester)

clean :
	rm $(objects)
