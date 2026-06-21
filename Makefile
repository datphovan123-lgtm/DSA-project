CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra

TARGET = hospital.exe
SRC = app/main.cpp

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

run: $(TARGET)
	.\$(TARGET)

clean:
	del /f /q $(TARGET)

rebuild: clean all