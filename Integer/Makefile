CXX = clang++
CXXFLAGS = -g --debug -Wall -Wshadow -Wextra -Weffc++ -std=c++17

TARGET = main
SRCS = main.cpp Integer.cpp MUL_ZM_Z.cpp 
OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
