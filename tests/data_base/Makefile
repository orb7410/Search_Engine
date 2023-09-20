CXX=g++
CC=$(CXX)

CFLAGS = -pedantic -Wall -Werror
CFLAGS += -ggdb
LDLIBS =  -ljsoncpp
CXXFLAGS = $(CFLAGS) -std=c++17

CPPFLAGS = -DDEBUG
CPPFLAGS += -I$(INCLUDES_DIR)

INCLUDES_DIR = ../../inc
SOURCES_DIR = ../../src

OBJECTS = utest.o $(SOURCES_DIR)/word_index.o $(SOURCES_DIR)/word_page.o $(SOURCES_DIR)/data_base.o $(SOURCES_DIR)/link_data.o $(SOURCES_DIR)/string_utils.o


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
