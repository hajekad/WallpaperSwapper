PROG		:= WaSp

CXX 		:= g++

LD_FLAGS 	:= -Wall --pedantic -std=c++23
CXX_FLAGS	:= $(LD_FLAGS) -c

OUT			:= err

OBJS 		:= main.o wallpaperController.o *Exception.o
 
output: $(OBJS)
	$(CXX) $(LD_FLAGS) -o $(PROG) $(OBJS)

%.o: src/*/%.cpp
	$(CXX) $(CXX_FLAGS) $<

doc: doc src/*.hpp
	doxygen Doxyfile

run: $(PROG)
	./$(PROG)

compile:
	make -j 8

all:
	compile
	doc

opendoc: doc
	firefox doc/index.html

count:
	wc -l src/.cpp
	wc -l src/.hpp

valgrind: compile
	valgrind -s --leak-check=full --track-origins=yes ./$(PROG) 2> $(OUT)

clean:
	rm -f *.o $(PROG)
	rm -f err
	rm -rf doc
	rm -rf .vscode