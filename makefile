
CXX=g++

OBJECTS=main.o socklisten.o sockqueue.o

snoopy: $(OBJECTS)
	$(CXX) -o snoopy $(OBJECTS)

main.o: main.cpp defines.h
	$(CXX) -c main.cpp -o main.o 

socklisten.o: socklisten.cpp socklisten.h
	$(CXX) -c socklisten.cpp -o socklisten.o 

sockqueue.o: sockqueue.cpp sockqueue.h
	$(CXX) -c sockqueue.cpp -o sockqueue.o 


.PHONY: clean
clean:
	rm *.o snoopy
