CXX = clang++
CXXFLAGS = -g --debug -Wall -Wshadow -Werror -Wextra -Weffc++ -Wconversion -std=c++17

TARGET = main
SRCS = main.cpp NaturalNumbers.cpp NZER_N_B.cpp MUL_Nk_N.cpp 
OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
