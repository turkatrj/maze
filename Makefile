CXX := g++
CXXFLAGS :=-Wall -Werror -Wextra -std=c++17
LDFLAGS := -lgtest -lgtest_main -pthread

VIEW_DIR := ./View
CONTROLLER_DIR := ./Controller
MODEL_DIR := ./Model
TESTS_DIR := ./Tests
BUILD_DIR := ./Build

SRC := ./*.cc

#SRC := $(wildcard $(VIEW_DIR)/*.cc) \
          #$(wildcard $(CONTROLLER_DIR)/*.cc) \
          #$(wildcard $(MODEL_DIR)/*.cc)
#HEADER := $(wildcard $(VIEW_DIR)/*.h) \
          #$(wildcard $(CONTROLLER_DIR)/*.h) \
          #$(wildcard $(MODEL_DIR)/*.h)
#UI := $(wildcard $(VIEW_DIR)/*.ui)
#TESTS := $(wildcard $(TESTS_DIR)/*.cc)

UNAME :=$(shell uname -s)

ifeq ($(UNAME),Linux)
	LDFLAGS += -lsubunit
	OPEN_CM=xdg-open
endif
ifeq ($(UNAME),Darwin)
	OPEN_CM=open
endif

.PHONY: all clean
all: clean install

install:
	mkdir -p $(BUILD_DIR)
	cmake -S . -B $(BUILD_DIR)
	make -C $(BUILD_DIR)
	./Build/Maze

uninstall:
	rm -rf $(BUILD_DIR)

clean:
	rm -rf *.a *.o *.out *.gch *.gcno *.gcna *.gcda *.info *.tgz *.user s21_test dist_maze/ $(BUILD_DIR)

dvi: 
	$(OPEN_CM) documentation.md

dist: clean
	mkdir dist_maze/
	cp Makefile *.txt $(SRC) $(HEADER) $(UI) dist_maze/
	tar -czvf s21_maze.tgz dist_maze/
	rm -rf dist_maze/

tests: clean
	$(CXX) $(CXXFLAGS) -o s21_test $(MODEL_DIR)/*.cc $(TESTS) $(LDFLAGS)
	./s21_test

valgrind: tests
	valgrind --tool=memcheck --leak-check=yes --leak-check=full -s ./s21_test

style:
	cp ../materials/linters/.clang-format .
	clang-format -n $(SRC) $(HEADER) $(TESTS)
	rm -rf .clang-format

edit_style:
	cp ../materials/linters/.clang-format .
	clang-format -i $(SRC) $(HEADER) $(TESTS)
	rm -rf .clang-format
