INC_DIR = include
SRC = src
TARGET = drink
PSHELL = ui

all: $(TARGET) $(PSHELL)

$(TARGET): main.o drink.o drinkLineItem.o order.o reader.o customer.o observer.o drinkShop.o orderLineItem.o
ifeq (${OS}, Windows_NT) 
	g++ -o $(TARGET) main.o drink.o drinkLineItem.o order.o reader.o customer.o observer.o drinkShop.o orderLineItem.o -lgtest
else
	g++ -o $(TARGET) main.o drink.o drinkLineItem.o order.o reader.o customer.o observer.o drinkShop.o orderLineItem.o -lgtest -lpthread
endif

$(PSHELL): mainUi.o drink.o drinkLineItem.o order.o reader.o customer.o observer.o drinkShop.o orderLineItem.o
ifeq (${OS}, Windows_NT) 
	g++ -o $(PSHELL) mainUi.o drink.o drinkLineItem.o order.o reader.o customer.o observer.o drinkShop.o orderLineItem.o -lgtest
else
	g++ -o $(PSHELL) mainUi.o drink.o drinkLineItem.o order.o reader.o customer.o observer.o drinkShop.o orderLineItem.o -lgtest -lpthread
endif

mainUi.o: mainUi.cpp
	g++ -std=gnu++0x -c mainUi.cpp

main.o: main.cpp
	g++ -std=gnu++0x -c main.cpp

drink.o: $(INC_DIR)/drink.h $(SRC)/drink.cpp
	g++ -std=gnu++0x -c $(SRC)/drink.cpp

reader.o: $(INC_DIR)/reader.h $(SRC)/reader.cpp
	g++ -std=gnu++0x -c $(SRC)/reader.cpp

customer.o: $(INC_DIR)/customer.h $(SRC)/customer.cpp
	g++ -std=gnu++0x -c $(SRC)/customer.cpp

observer.o: $(INC_DIR)/observer.h $(SRC)/observer.cpp
	g++ -std=gnu++0x -c $(SRC)/observer.cpp

order.o: $(INC_DIR)/order.h $(SRC)/order.cpp
	g++ -std=gnu++0x -c $(SRC)/order.cpp

drinkLineItem.o: $(INC_DIR)/drinkLineItem.h $(SRC)/drinkLineItem.cpp
	g++ -std=gnu++0x -c $(SRC)/drinkLineItem.cpp

orderLineItem.o: $(INC_DIR)/orderLineItem.h $(SRC)/orderLineItem.cpp
	g++ -std=gnu++0x -c $(SRC)/orderLineItem.cpp

drinkShop.o: $(INC_DIR)/drinkShop.h $(SRC)/drinkShop.cpp
	g++ -std=gnu++0x -c $(SRC)/drinkShop.cpp

clean:	
ifeq (${OS}, Windows_NT) 
	del *.o *.exe
else
	rm -f *.o $(TARGET)
endif