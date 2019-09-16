INC_DIR = include
SRC = src
TARGET = tShop
UI = tUI

all: $(TARGET) $(UI)

$(TARGET): main.o clothes.o clothesCatalog.o order.o lineItem.o history.o customer.o tShop.o customerTracker.o utility.o
ifeq (${OS}, Windows_NT) 
	g++ -o $(TARGET) main.o clothes.o clothesCatalog.o order.o lineItem.o history.o customer.o tShop.o customerTracker.o utility.o -lgtest
else
	g++ -o $(TARGET) main.o clothes.o clothesCatalog.o order.o lineItem.o history.o customer.o tShop.o customerTracker.o utility.o -lgtest -lpthread
endif

$(UI): mainWindow.o clothes.o clothesCatalog.o order.o lineItem.o history.o customer.o tShop.o customerTracker.o utility.o
ifeq (${OS}, Windows_NT) 
	g++ -o $(UI) mainWindow.o clothes.o clothesCatalog.o order.o lineItem.o history.o customer.o tShop.o customerTracker.o utility.o -lgtest
else
	g++ -o $(UI) mainWindow.o clothes.o clothesCatalog.o order.o lineItem.o history.o customer.o tShop.o customerTracker.o utility.o -lgtest -lpthread
endif

mainWindow.o: mainWindow.cpp
	g++ -std=gnu++0x -c mainWindow.cpp

main.o: main.cpp
	g++ -std=gnu++0x -c main.cpp

clothes.o: $(INC_DIR)/clothes.h $(SRC)/clothes.cpp
	g++ -std=gnu++0x -c $(SRC)/clothes.cpp

clothesCatalog.o: $(INC_DIR)/clothesCatalog.h $(SRC)/clothesCatalog.cpp
	g++ -std=gnu++0x -c $(SRC)/clothesCatalog.cpp

order.o: $(INC_DIR)/order.h $(SRC)/order.cpp
	g++ -std=gnu++0x -c $(SRC)/order.cpp

lineItem.o: $(INC_DIR)/lineItem.h $(SRC)/lineItem.cpp
	g++ -std=gnu++0x -c $(SRC)/lineItem.cpp

history.o: $(INC_DIR)/history.h $(SRC)/history.cpp
	g++ -std=gnu++0x -c $(SRC)/history.cpp

customer.o: $(INC_DIR)/customer.h $(SRC)/customer.cpp
	g++ -std=gnu++0x -c $(SRC)/customer.cpp

tShop.o: $(INC_DIR)/tShop.h $(SRC)/tShop.cpp
	g++ -std=gnu++0x -c $(SRC)/tShop.cpp

customerTracker.o: $(INC_DIR)/customerTracker.h $(SRC)/customerTracker.cpp
	g++ -std=gnu++0x -c $(SRC)/customerTracker.cpp

utility.o: $(INC_DIR)/utility.h $(SRC)/utility.cpp
	g++ -std=gnu++0x -c $(SRC)/utility.cpp

clean:	
ifeq (${OS}, Windows_NT) 
	del *.o *.exe
else
	rm -f *.o $(TARGET)
endif