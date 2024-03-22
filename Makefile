
BUILD_DIR := build
SRC_DIR := src

# complie .cf files
CF_FILE := $(wildcard $(SRC_DIR)/Javalette.cf)

Clean:
	rm -rf $(BUILD_DIR)/*

all:
	bnfc -m --c $(CF_FILE) -o $(BUILD_DIR)
	cd $(BUILD_DIR) && make
	cd -

run_parser_test:
	./$(BUILD_DIR)/TestJavalette test/parser/test_1.jl