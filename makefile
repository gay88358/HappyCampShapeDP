INC_DIR = include
SRC = src
TARGET = shape

all: $(TARGET) 

$(TARGET): main.o shape.o rectangle.o circle.o square.o triangle.o point.o shapePrinter.o
ifeq (${OS}, Windows_NT) 
	g++ -o $(TARGET) main.o shape.o rectangle.o circle.o square.o triangle.o point.o shapePrinter.o -lgtest
else
	g++ -o $(TARGET) main.o shape.o rectangle.o circle.o square.o triangle.o point.o shapePrinter.o -lgtest -lpthread
endif

main.o: main.cpp
	g++ -std=gnu++0x -c main.cpp

shape.o: $(INC_DIR)/shape.h $(SRC)/shape.cpp
	g++ -std=gnu++0x -c $(SRC)/shape.cpp

rectangle.o: $(INC_DIR)/rectangle.h $(SRC)/rectangle.cpp
	g++ -std=gnu++0x -c $(SRC)/rectangle.cpp

circle.o: $(INC_DIR)/circle.h $(SRC)/circle.cpp
	g++ -std=gnu++0x -c $(SRC)/circle.cpp

square.o: $(INC_DIR)/square.h $(SRC)/square.cpp
	g++ -std=gnu++0x -c $(SRC)/square.cpp

shapePrinter.o: $(INC_DIR)/shapePrinter.h $(SRC)/shapePrinter.cpp
	g++ -std=gnu++0x -c $(SRC)/shapePrinter.cpp

# composite.o: $(INC_DIR)/composite.h $(SRC)/composite.cpp
# 	g++ -std=gnu++0x -c $(SRC)/composite.cpp

# shapeFormatter.o: $(INC_DIR)/shapeFormatter.h $(SRC)/shapeFormatter.cpp
# 	g++ -std=gnu++0x -c $(SRC)/shapeFormatter.cpp

# xmlShapeFormatter.o: $(INC_DIR)/xmlShapeFormatter.h $(SRC)/xmlShapeFormatter.cpp
# 	g++ -std=gnu++0x -c $(SRC)/xmlShapeFormatter.cpp

# plainTextShapeFormatter.o: $(INC_DIR)/plainTextShapeFormatter.h $(SRC)/plainTextShapeFormatter.cpp
# 	g++ -std=gnu++0x -c $(SRC)/plainTextShapeFormatter.cpp

triangle.o: $(INC_DIR)/triangle.h $(SRC)/triangle.cpp
	g++ -std=gnu++0x -c $(SRC)/triangle.cpp

point.o: $(INC_DIR)/point.h $(SRC)/point.cpp
	g++ -std=gnu++0x -c $(SRC)/point.cpp

clean:	
ifeq (${OS}, Windows_NT) 
	del *.o *.exe
else
	rm -f *.o $(TARGET)
endif