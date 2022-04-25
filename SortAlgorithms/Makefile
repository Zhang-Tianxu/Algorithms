cc = gcc
cpp = g++
objects = BubbleSort.out MergeSort.out HeapSort.out \
		  InsertSort.out QuikSort.out SelectSort.out \
		  Test.out
tester = SortTester.cpp

edit: $(objects)
	echo "done"

BubbleSort.out : $(tester)
	$(cpp) -o BubbleSort.out BubbleSort.cpp $(tester)

MergeSort.out:
	$(cpp) -o MergeSort.out MergeSort.cpp $(tester)

HeapSort.out:
	$(cpp) -o HeapSort.out HeapSort.cpp

InsertSort.out:
	$(cpp) -o InsertSort.out InsertSort.cpp

QuikSort.out:
	$(cpp) -o QuikSort.out QuikSort.cpp


SelectSort.out:
	$(cpp) -o SelectSort.out SelectSort.cpp

Test.out:
	$(cpp) -o Test.out Test.cpp

clean :
	rm $(objects)
