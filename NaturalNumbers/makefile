CXX = g++
CXXFLAGS = -std=c++20 -Wall -Wextra -O2

TARGET = main
SRCS = main.cpp NaturalNumbers.cpp ADD_1N_N.cpp MUL_NN_N.cpp MUL_Nk_N.cpp COM_NN_D.cpp ADD_NN_N.cpp NZER_N_B.cpp MUL_ND_N.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)