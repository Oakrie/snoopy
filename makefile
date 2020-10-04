
CXX=g++

OBJECTS=main.o socklisten.o

sniffer: $(OBJECTS)
	$(CXX) -o sniffer $(OBJECTS)

main.o: main.cpp defines.h
	$(CXX) -c main.cpp -o main.o 

socklisten.o: socklisten.cpp socklisten.h
	$(CXX) -c socklisten.cpp -o socklisten.o 


.PHONY: clean
clean:
	rm *.o sniffer
