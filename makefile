SOURCES := linkedlist.cpp main.cpp
OBJECTS := $(patsubst %.cpp,%.o,$(SOURCES))


all: comp run
comp:$(OBJECTS)
	@clear 
	@g++ $(OBJECTS) -o smd

linkedlist.o:
	@g++ -c linkedlist.cpp -o linkedlist.o -std=c++11

main.o:
	@g++ -c main.cpp -o main.o -std=c++11

linkedlist.dep:
	@g++ -c -MM linkedlist.cpp -MT "linkedlist.dep linkedlist.o" -o linkedlist.dep  -std=c++11

main.dep:
	@g++ -c -MM main.cpp -MT "main.dep main.o" -o main.dep -std=c++11
-include linkedlist.dep main.dep  -std=c++11
 
run:
	@./smd
	@ctags -R .
clean:
	rm smd *.o *.dep tags
