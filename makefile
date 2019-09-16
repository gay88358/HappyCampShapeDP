INC_DIR = include
SRC = src
TARGET = tshop

all: $(TARGET) 

$(TARGET): main.o shape.o
ifeq (${OS}, Windows_NT) 
	g++ -o $(TARGET) main.o shape.o  -lgtest
else
	g++ -o $(TARGET) main.o shape.o  -lgtest -lpthread
endif

main.o: main.cpp
	g++ -std=gnu++0x -c main.cpp

shape.o: $(INC_DIR)/shape.h $(SRC)/shape.cpp
	g++ -std=gnu++0x -c $(SRC)/shape.cpp

clean:	
ifeq (${OS}, Windows_NT) 
	del *.o *.exe
else
	rm -f *.o $(TARGET)
endif