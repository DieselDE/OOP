CXX = g++
CXXFLAGS = -Wall -Werror -std=c++17

SRCS = main.cpp Player.cpp Classes.cpp
OBJS = $(SRCS:.cpp=.o)
TARGET = a.exe

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)