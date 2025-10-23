CXX := g++
CXXFLAGS := -g -Wall --std=c++11
VALGRIND := valgrind --tool=memcheck --leak-check=yes

OBJS=wire.o stack.o llrec.o llrec-test.o

all: llrec-test

llrec-test: $(OBJS)
	$(CXX) $(CXXFLAGS) $(DEFS) -o $@ $(OBJS)

#-----------------------------------------------------
# ADD target(s) to build your llrec-test executable
#-----------------------------------------------------

llrec-test.o: llrec-test.cpp llrec.h stack.h heap.h
	$(CXX) $(CXXFLAGS) $(DEFS) -o $@ -c llrec-test.cpp

llrec.o: llrec.cpp llrec.h 
	$(CXX) $(CXXFLAGS) $(DEFS) -o $@ -c llrec.cpp

stack.o: stack.cpp stack.h 
	$(CXX) $(CXXFLAGS) $(DEFS) -o $@ -c stack.cpp

heap.o: heap.cpp heap.h
	$(CXX) $(CXXFLAGS) $(DEFS) -o $@ -c heap.cpp


clean:
	rm -f *.o rh llrec-test *~

.PHONY: clean 