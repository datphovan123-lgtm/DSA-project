CXX = g++
CXXFLAGS = -std=c++17

all:
	$(CXX) $(CXXFLAGS) app/main.cpp -o hospital.exe

run:
	hospital.exe

clean:
	del hospital.exe