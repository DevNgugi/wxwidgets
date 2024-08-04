CXX = g++
CXXFLAGS = `wx-config --cxxflags`
LDFLAGS = `wx-config --libs`
TARGET = my_wxwidgets_app

all: $(TARGET)

$(TARGET): main.cpp
	$(CXX) $(CXXFLAGS) -o $(TARGET) main.cpp $(LDFLAGS)

clean:
	rm -f $(TARGET)
