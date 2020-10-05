
CXX=g++
COPT= -lpthread

OBJECTS=main.o socklisten.o sockqueue.o queuereader.o threadlist.o

snoopy: $(OBJECTS)
	$(CXX) -o snoopy $(OBJECTS) $(COPT) 

main.o: main.cpp defines.h
	$(CXX) -c main.cpp -o main.o 

socklisten.o: socklisten.cpp socklisten.h
	$(CXX) -c socklisten.cpp -o socklisten.o $(COPT) 

sockqueue.o: sockqueue.cpp sockqueue.h
	$(CXX) -c sockqueue.cpp -o sockqueue.o 

queuereader.o: queuereader.cpp queuereader.h
	$(CXX) -c queuereader.cpp -o queuereader.o $(COPT) 

threadlist.o: threadlist.cpp threadlist.h
	$(CXX) -c threadlist.cpp -o threadlist.o $(COPT) 

.PHONY: clean
clean:
	rm *.o snoopy
