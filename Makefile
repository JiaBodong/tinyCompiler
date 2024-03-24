# update:
# [+] remove bnfc stage, and use the generated Makefile 
# as a reference to generate our own Makefile.

CC = g++ -std=c++11 -g
CCFLAGS = --ansi -W -Wall -Wsign-conversion \
	-Wno-unused-parameter \
	-Wno-unused-function \
	-Wno-unneeded-internal-declaration \
	${CC_OPTS}

FLEX = flex
FLEX_OPTS = -Pjavalette_

BISON = bison
BISON_OPTS = -t -pjavalette_

BUILD_DIR := build
SRC_DIR := src
FRONT_END_DIR := $(SRC_DIR)/front_end


FRONT_END_DIR_CC_FILES := $(wildcard $(FRONT_END_DIR)/*.C)
# FRONT_END_DIR_cc_FILES will be like: 
# src/front_end/Absyn.C src/front_end/Buffer.C ...

FRONT_END_DIR_H_FILES := $(wildcard $(FRONT_END_DIR)/*.H)
# FRONT_END_DIR_H_FILES will be like:
# src/front_end/Absyn.H src/front_end/Buffer.H ...

# generate the object files under the build directory
FRONT_END_DIR_OBJS := $(patsubst $(FRONT_END_DIR)/%.C, $(BUILD_DIR)/%.o, $(FRONT_END_DIR_CC_FILES))
# FRONT_END_DIR_OBJS will be like:
# build/Absyn.o build/Buffer.o ...

UTILS_DIR := $(SRC_DIR)/utils
UTILS_DIR_H_FILES := $(wildcard $(UTILS_DIR)/*.h)
UTILS_DIR_CC_FILES := $(wildcard $(UTILS_DIR)/*.cpp)
UTILS_DIR_OBJS := $(patsubst $(UTILS_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(UTILS_DIR_CC_FILES))

HEADERS := $(FRONT_END_DIR_H_FILES) $(UTILS_DIR_H_FILES)

OBJS := $(FRONT_END_DIR_OBJS) $(UTILS_DIR_OBJS)

CC_INCLUDES := -I$(FRONT_END_DIR) -I$(UTILS_DIR)

.PHONY : clean all

all: TestJavalette jlc

clean:
	mkdir -p $(BUILD_DIR)
	rm -rf $(BUILD_DIR)/*
	rm jlc


run_parser_test: TestJavalette
	./$(BUILD_DIR)/TestJavalette test/parser/test_1.jl

# generate the object files
$(BUILD_DIR)/%.o: $(FRONT_END_DIR)/%.C $(HEADERS) 
# special c flag for Lexer.o
	if [ $* = "Lexer" ]; then \
		$(CC) $(CCFLAGS) -Wno-sign-conversion $(CC_INCLUDES) -c $< -o $@;\
	else \
		$(CC) $(CCFLAGS) $(CC_INCLUDES) -c $< -o $@; \
	fi
	
# test .o files
# test: $(OBJS)
# 	@echo $(OBJS)

TestJavalette: $(OBJS) $(SRC_DIR)/Test.cpp 
	@echo "Linking TestJavalette..."
	$(CC) $(OBJS) $(SRC_DIR)/Test.cpp $(CC_INCLUDES) -o $(BUILD_DIR)/TestJavalette

# this target is used to generate the jlc executable, 
# output to the root directory directly.
jlc: $(OBJS) $(SRC_DIR)/jlc.cpp
	@echo "Building jlc..."
	$(CC) $(OBJS) $(SRC_DIR)/jlc.cpp $(CC_INCLUDES) -o jlc

# remove this target, because we just need to generate it once,
# thus, we generate it manually.
# also we have to modify the generated files to make it work.
# complie .Cf files
CF_FILE := $(wildcard $(SRC_DIR)/Javalette.Cf)
generate_parser:
	bnfc -m --cpp $(CF_FILE) -o $(BUILD_DIR)
	cd $(BUILD_DIR) && make
	cd -