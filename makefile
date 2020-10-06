
CXX=g++
COPT= -lpthread
SRC= ./srcs
BUILD = ./build
HOME = .
OBJECTS=main.o snoopylistener.o snoopyqueue.o snoopyreader.o threadable.o

snoopy: $(OBJECTS)
	cd $(BUILD)
	$(CXX) -o snoopy $(OBJECTS) $(COPT)
	mv snoopy $(HOME) 

main.o: $(SRC)/main.cpp $(SRC)/defines.h
	$(CXX) -c $(SRC)/main.cpp -o $(SRC)/main.o 
	mv $(SRC)/main.o $(BUILD)

snoopylistener.o: $(SRC)/snoopylistener.cpp $(SRC)/snoopylistener.h
	$(CXX) -c $(SRC)/snoopylistener.cpp -o $(SRC)/snoopylistener.o $(COPT) 
	mv $(SRC)/snoopylistener.o $(BUILD)

snoopyqueue.o: snoopyqueue.cpp snoopyqueue.h
	$(CXX) -c $(SRC)/snoopyqueue.cpp -o $(SRC)/snoopyqueue.o 
	mv $(SRC)/snoopyqueue.o $(BUILD)

snoopyreader.o: $(SRC)/snoopyreader.cpp $(SRC)/snoopyreader.h
	$(CXX) -c $(SRC)/snoopyreader.cpp -o $(SRC)/snoopyreader.o $(COPT) 
	mv $(SRC)/snoopyreader.o $(BUILD)

threadable.o: $(SRC)/threadable.cpp $(SRC)/threadable.h
	$(CXX) -c $(SRC)/threadable.cpp -o $(SRC)/threadable.o $(COPT) 
	mv $(SRC)/threadable.o $(BUILD)

.PHONY: clean
clean:
	rm *.o snoopy
