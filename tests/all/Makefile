CXX= g++
CC = $(CXX)

CXXFLAGS  = -pedantic -Wall -Werror -Wextra
CXXFLAGS += -ggdb
CXXFLAGS += -std=c++17

LDLIBS = -ljsoncpp -lcurl -lcurlpp -lgumbo
LDFLAGS = -L/usr/local/lib

CPPFLAGS = -DDEBUG
CPPFLAGS = -I$(INCLUDES_DIR) -I$(CURL_INCLUDES_DIR)

INCLUDES_DIR = ../../inc
CURL_INCLUDES_DIR = /usr/local/include
SOURCES_DIR = ../../src

SOURCE := utest.cpp \
			$(SOURCES_DIR)/search_engine.cpp \
			$(SOURCES_DIR)/crawler.cpp \
			$(SOURCES_DIR)/web_page.cpp \
			$(SOURCES_DIR)/json_file_reader.cpp \
			$(SOURCES_DIR)/curlpp_downloader.cpp \
			$(SOURCES_DIR)/gumbo_parser.cpp \
			$(SOURCES_DIR)/data_base.cpp \
			$(SOURCES_DIR)/update_data.cpp \
			$(SOURCES_DIR)/word_index.cpp \
			$(SOURCES_DIR)/link_data.cpp \
			$(SOURCES_DIR)/string_utils.cpp \
			$(SOURCES_DIR)/word_page.cpp \
			$(SOURCES_DIR)/validator.cpp \
			$(SOURCES_DIR)/search.cpp \
			$(SOURCES_DIR)/query.cpp \
			$(SOURCES_DIR)/ui.cpp \
			$(SOURCES_DIR)/crawler_mannager.cpp

TARGET := utest

all: $(TARGET)

utest : $(SOURCE)

check : $(TARGET)
	@./$(TARGET) -v

recheck: clean check

clang_check: CXX = clang++
clang_check: check

clean:
	@$(RM) ./$(TARGET) *.o

vala: $(TARGET)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(TARGET)

hell: $(TARGET)
	valgrind  --tool=helgrind ./$(TARGET) 2> hell.txt

.PHONY : make clean check recheck all vala hell
