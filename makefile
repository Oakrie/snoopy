
CXX=g++
COPT= -lpthread
SRC= ./srcs
BUILD = ./build
HOME = .
OBJECTS=$(SRC)/main.o \
		$(SRC)/snoopylistener.o \
		$(SRC)/snoopyqueue.o \
		$(SRC)/snoopyreader.o \
		$(SRC)/threadable.o \
		$(SRC)/snoopy.o

snoopy: $(OBJECTS)
	$(CXX) -o snoopy $(OBJECTS) $(COPT)
	mv $(SRC)/*.o snoopy $(BUILD) 

main.o: $(SRC)/main.cpp $(SRC)/defines.h
	$(CXX) -c $(SRC)/main.cpp -o $(SRC)/main.o 

snoopylistener.o: $(SRC)/snoopylistener.cpp $(SRC)/snoopylistener.h
	$(CXX) -c $(SRC)/snoopylistener.cpp -o $(SRC)/snoopylistener.o $(COPT) 

snoopyqueue.o: $(SRC)/snoopyqueue.cpp $(SRC)/snoopyqueue.h
	$(CXX) -c $(SRC)/snoopyqueue.cpp -o $(SRC)/snoopyqueue.o 

snoopyreader.o: $(SRC)/snoopyreader.cpp $(SRC)/snoopyreader.h
	$(CXX) -c $(SRC)/snoopyreader.cpp -o $(SRC)/snoopyreader.o $(COPT) 

threadable.o: $(SRC)/threadable.cpp $(SRC)/threadable.h
	$(CXX) -c $(SRC)/threadable.cpp -o $(SRC)/threadable.o $(COPT) 

snoopy.o: $(SRC)/snoopy.cpp $(SRC)/snoopy.h
	$(CXX) -c $(SRC)/snoopy.cpp -o $(SRC)/snoopy.o $(COPT) 

.PHONY: clean
clean:
	rm $(BUILD)/*.o $(BUILD)/snoopy