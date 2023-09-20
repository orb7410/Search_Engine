CXX=g++
CC=$(CXX)

CFLAGS = -pedantic -Wall -Werror
CFLAGS += -ggdb
CXXFLAGS = $(CFLAGS) -std=c++17

CPPFLAGS = -DDEBUG
CPPFLAGS += -I$(INCLUDES_DIR)

INCLUDES_DIR = ../../inc
SOURCES_DIR = ../../src

OBJECTS = utest.o $(SOURCES_DIR)/validator.o 


TARGET = utest

all: $(TARGET)

$(TARGET) : $(OBJECTS)

utest : $(SOURCE)

check : $(TARGET)
	@./$(TARGET) -v

recheck: clean check

clean:
	@$(RM) -f ./$(TARGET) $(OBJECTS)


.PHONY : make clean check recheck all
