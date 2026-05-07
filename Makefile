CXX = g++
CXXFLAGS = -Wall -std=c++11

PROGRAMS = programs
HEADERS = headers
SOURCE = source
OBJ = obj
BIN = bin

TARGET = $(BIN)/FleetProject

OBJECTS = $(OBJ)/main.o $(OBJ)/vehicle.o $(OBJ)/car.o $(OBJ)/truck.o

all: $(OBJ) $(BIN) $(TARGET)

$(OBJ):
	mkdir -p $(OBJ)

$(BIN):
	mkdir -p $(BIN)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

$(OBJ)/main.o: $(PROGRAMS)/main.cpp $(HEADERS)/vehicle.h $(HEADERS)/car.h $(HEADERS)/truck.h
	$(CXX) $(CXXFLAGS) -c $(PROGRAMS)/main.cpp -o $(OBJ)/main.o

$(OBJ)/vehicle.o: $(SOURCE)/vehicle.cpp $(HEADERS)/vehicle.h
	$(CXX) $(CXXFLAGS) -c $(SOURCE)/vehicle.cpp -o $(OBJ)/vehicle.o

$(OBJ)/car.o: $(SOURCE)/car.cpp $(HEADERS)/car.h $(HEADERS)/vehicle.h
	$(CXX) $(CXXFLAGS) -c $(SOURCE)/car.cpp -o $(OBJ)/car.o

$(OBJ)/truck.o: $(SOURCE)/truck.cpp $(HEADERS)/truck.h $(HEADERS)/vehicle.h
	$(CXX) $(CXXFLAGS) -c $(SOURCE)/truck.cpp -o $(OBJ)/truck.o

run: all
	./$(TARGET)

clean:
	rm -rf $(OBJ)/*.o $(TARGET)



