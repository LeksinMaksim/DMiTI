# Компилятор
CXX = g++
# Флаги компиляции
CXXFLAGS = -std=c++20 -Wall -g

# Директории
BUILD_DIR = build
INTEGER_DIR = ../Integer
NATURAL_DIR = ../NaturalNumbers
RATIONAL_DIR = ../Rationals
POLYNOMIAL_DIR = ../Polynomials

# Пути включения заголовочных файлов
INCLUDES = -I. \
	-I$(INTEGER_DIR) \
	-I$(INTEGER_DIR)/Functions \
	-I$(INTEGER_DIR)/Source \
	-I$(NATURAL_DIR) \
	-I$(NATURAL_DIR)/Functions \
	-I$(NATURAL_DIR)/Source \
	-I$(RATIONAL_DIR) \
	-I$(RATIONAL_DIR)/Functions \
	-I$(RATIONAL_DIR)/Source \
	-I$(POLYNOMIAL_DIR) \
	-I$(POLYNOMIAL_DIR)/Functions \
	-I$(POLYNOMIAL_DIR)/Source

# Исходные файлы
SOURCES = main.cpp \
	$(wildcard $(INTEGER_DIR)/Source/*.cpp) \
	$(wildcard $(INTEGER_DIR)/Functions/*/*.cpp) \
	$(wildcard $(NATURAL_DIR)/Source/*.cpp) \
	$(wildcard $(NATURAL_DIR)/Functions/*/*.cpp) \
	$(wildcard $(RATIONAL_DIR)/Source/*.cpp) \
	$(wildcard $(RATIONAL_DIR)/Functions/*/*.cpp) \
	$(wildcard $(POLYNOMIAL_DIR)/Source/*.cpp) \
	$(wildcard $(POLYNOMIAL_DIR)/Functions/*/*.cpp)

# Получаем список объектных файлов
OBJECTS = $(SOURCES:%.cpp=$(BUILD_DIR)/%.o)

# Имя исполняемого файла
TARGET = $(BUILD_DIR)/program

# Основная цель
all: prepare $(TARGET)

# Подготовка директорий
prepare:
	@mkdir -p $(BUILD_DIR)
	@mkdir -p $(BUILD_DIR)/$(INTEGER_DIR)/Source
	@mkdir -p $(BUILD_DIR)/$(INTEGER_DIR)/Functions
	@mkdir -p $(BUILD_DIR)/$(NATURAL_DIR)/Source
	@mkdir -p $(BUILD_DIR)/$(NATURAL_DIR)/Functions
	@mkdir -p $(BUILD_DIR)/$(RATIONAL_DIR)/Source
	@mkdir -p $(BUILD_DIR)/$(RATIONAL_DIR)/Functions
	@mkdir -p $(BUILD_DIR)/$(POLYNOMIAL_DIR)/Source
	@mkdir -p $(BUILD_DIR)/$(POLYNOMIAL_DIR)/Functions
	@for dir in $(INTEGER_DIR)/Functions/*/; do \
		mkdir -p $(BUILD_DIR)/$$dir; \
	done
	@for dir in $(NATURAL_DIR)/Functions/*/; do \
		mkdir -p $(BUILD_DIR)/$$dir; \
	done
	@for dir in $(RATIONAL_DIR)/Functions/*/; do \
		mkdir -p $(BUILD_DIR)/$$dir; \
	done
	@for dir in $(POLYNOMIAL_DIR)/Functions/*/; do \
		mkdir -p $(BUILD_DIR)/$$dir; \
	done

# Компиляция программы
$(TARGET): $(OBJECTS)
	@echo "Linking..."
	@$(CXX) $(OBJECTS) -o $(TARGET)

# Правило компиляции главного файла
$(BUILD_DIR)/main.o: main.cpp
	@echo "Compiling main.cpp..."
	@$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

# Правило компиляции файлов Integer
$(BUILD_DIR)/$(INTEGER_DIR)/Source/%.o: $(INTEGER_DIR)/Source/%.cpp
	@echo "Compiling $<..."
	@$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

$(BUILD_DIR)/$(INTEGER_DIR)/Functions/%.o: $(INTEGER_DIR)/Functions/%.cpp
	@echo "Compiling $<..."
	@$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

# Правило компиляции файлов NaturalNumbers
$(BUILD_DIR)/$(NATURAL_DIR)/Source/%.o: $(NATURAL_DIR)/Source/%.cpp
	@echo "Compiling $<..."
	@$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

$(BUILD_DIR)/$(NATURAL_DIR)/Functions/%.o: $(NATURAL_DIR)/Functions/%.cpp
	@echo "Compiling $<..."
	@$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

# Правило компиляции файлов Rationals
$(BUILD_DIR)/$(RATIONAL_DIR)/Source/%.o: $(RATIONAL_DIR)/Source/%.cpp
	@echo "Compiling $<..."
	@$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

$(BUILD_DIR)/$(RATIONAL_DIR)/Functions/%.o: $(RATIONAL_DIR)/Functions/%.cpp
	@echo "Compiling $<..."
	@$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

# Правило компиляции файлов Polynomials
$(BUILD_DIR)/$(POLYNOMIAL_DIR)/Source/%.o: $(POLYNOMIAL_DIR)/Source/%.cpp
	@echo "Compiling $<..."
	@$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

$(BUILD_DIR)/$(POLYNOMIAL_DIR)/Functions/%.o: $(POLYNOMIAL_DIR)/Functions/%.cpp
	@echo "Compiling $<..."
	@$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

# Очистка
clean:
	@echo "Cleaning..."
	@rm -rf $(BUILD_DIR)

# Запуск программы
run: all
	@echo "Running..."
	@./$(TARGET)

# Отладка Makefile
debug:
	@echo "Sources: $(SOURCES)"
	@echo "Objects: $(OBJECTS)"
	@echo "Includes: $(INCLUDES)"

.PHONY: all clean run debug prepare
