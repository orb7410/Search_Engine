

CXX=g++
CC=CXX

CFLAGS = -pedantic -Wall -Werror -pthread
CFLAGS += -g
CXXFLAGS = $(CFLAGS) -std=c++17

CPPFLAGS = -DDEBUG
CPPFLAGS += -I$(INCLUDES_DIR)

INCLUDES_DIR = ../../inc
SOURCES_DIR = ../../src

SOURCE = utest.cpp $(SOURCES_DIR)/update_data.cpp $(SOURCES_DIR)/web_page.cpp $(SOURCES_DIR)/validator.cpp $(SOURCES_DIR)/data_base.cpp 
TARGET =  utest

all: $(TARGET)

$(TARGET): $(SOURCE)

check : $(TARGET)
	@./$(TARGET) -v

recheck: clean check

clean:
	@$(RM) -f ./$(TARGET) *.o

vala: $(TARGET)
	valgrind --leak-check=yes --track-origins=yes ./$(TARGET)

hell: $(TARGET)
	valgrind  --tool=helgrind ./$(TARGET) 2> hell.txt

.PHONY : make clean check recheck all

make:
	@echo 'Attend a maker faire'
	@${TRUE}
	
	