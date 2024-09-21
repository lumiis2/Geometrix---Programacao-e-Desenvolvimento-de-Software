TARGET = main
TESTS_TARGET = main_testes
CC = g++
CXXFLAGS = -Wall -O0 -std=c++17 -g --coverage

LUA = /usr/include/lua5.3
LINK = -lsfml-graphics -lsfml-window -lsfml-system -ltgui -llua5.3

SOURCES := $(wildcard src/*.cpp src/*/*.cpp)
OBJECTS := $(SOURCES:src/%.cpp=build/%.o)
TESTS := $(wildcard tests/*.cpp src/*/*.cpp)
TESTS_OBJECTS := $(TESTS:tests/%.cpp=build/%.o)
INCLUDES := $(addprefix -I,$(wildcard include/*))
INCLUDES := $(INCLUDES) -I$(LUA)

$(TARGET): $(OBJECTS)
	$(CC) $(CXXFLAGS) $(INCLUDES) $(OBJECTS) -o $(TARGET) $(LINK) 

$(OBJECTS): build/%.o: src/%.cpp
	@mkdir -p $(@D)
	$(CC) $(CXXFLAGS) $(INCLUDES) -c $< -o $@ $(LINK)

tests: $(OBJECTS) $(TESTS_OBJECTS)
	$(CC) $(CXXFLAGS) $(INCLUDES) $(TESTS_OBJECTS) -o ./tests/$(TESTS_TARGET) $(LINK)

run: $(TARGET)
	./$(TARGET)

clear:
	rm -rf build
	rm -f $(TARGET)