# update:
# [+] remove bnfc stage, and use the generated Makefile 
# as a reference to generate our own Makefile.

CC = g++ -std=c++11 -g
CCFLAGS = -W -Wall \
	-Wno-unused-parameter \
	-Wno-unused-function \
	-Wno-unneeded-internal-declaration

# run with DEBUG flag: make DEBUG=1
ifdef DEBUG
	CCFLAGS += -DDEBUG
endif

# llvm config
LLVM_CC_CONFIG = `llvm-config --cxxflags` -fexceptions
LLVM_LD_CONFIG = `llvm-config --ldflags --libs --system-libs`


BUILD_DIR := build
SRC_DIR := src

PARSER_DIR := parser
TYPECHECKER_DIR := typechecker
LLVM_DIR := llvm
X86_DIR := x86Backend
COMMON_DIR := common


PARSER_DIR_H_FILES := $(wildcard $(SRC_DIR)/$(PARSER_DIR)/*.H)
PARSER_DIR_CC_FILES := $(wildcard $(SRC_DIR)/$(PARSER_DIR)/*.C)
PARSER_DIR_OBJS := $(patsubst $(SRC_DIR)/$(PARSER_DIR)/%.C, $(BUILD_DIR)/$(PARSER_DIR)/%.o, $(PARSER_DIR_CC_FILES))

TYPECHECKER_DIR_H_FILES := $(wildcard $(SRC_DIR)/$(TYPECHECKER_DIR)/*.H)
TYPECHECKER_DIR_CC_FILES := $(wildcard $(SRC_DIR)/$(TYPECHECKER_DIR)/*.C)
TYPECHECKER_DIR_OBJS := $(patsubst $(SRC_DIR)/$(TYPECHECKER_DIR)/%.C, $(BUILD_DIR)/$(TYPECHECKER_DIR)/%.o, $(TYPECHECKER_DIR_CC_FILES))

LLVM_DIR_H_FILES := $(wildcard $(SRC_DIR)/$(LLVM_DIR)/*.H)
LLVM_DIR_CC_FILES := $(wildcard $(SRC_DIR)/$(LLVM_DIR)/*.C)
LLVM_DIR_OBJS := $(patsubst $(SRC_DIR)/$(LLVM_DIR)/%.C, $(BUILD_DIR)/$(LLVM_DIR)/%.o, $(LLVM_DIR_CC_FILES))

COMMON_DIR_H_FILES := $(wildcard $(SRC_DIR)/$(COMMON_DIR)/*.H)
COMMON_DIR_CC_FILES := $(wildcard $(SRC_DIR)/$(COMMON_DIR)/*.C)
COMMON_DIR_OBJS := $(patsubst $(SRC_DIR)/$(COMMON_DIR)/%.C, $(BUILD_DIR)/$(COMMON_DIR)/%.o, $(COMMON_DIR_CC_FILES))

X86_DIR_H_FILES := $(wildcard $(SRC_DIR)/$(X86_DIR)/*.H)
X86_DIR_CC_FILES := $(wildcard $(SRC_DIR)/$(X86_DIR)/*.C)
X86_DIR_OBJS := $(patsubst $(SRC_DIR)/$(X86_DIR)/%.C, $(BUILD_DIR)/$(X86_DIR)/%.o, $(X86_DIR_CC_FILES))

HEADERS := $(PARSER_DIR_H_FILES) \
		   $(TYPECHECKER_DIR_H_FILES) \
		   $(LLVM_DIR_H_FILES) \
		   $(X86_DIR_H_FILES) \
		   $(COMMON_DIR_H_FILES)

OBJS := $(PARSER_DIR_OBJS) \
		$(TYPECHECKER_DIR_OBJS) \
		$(LLVM_DIR_OBJS) \
		$(X86_DIR_OBJS) \
		$(COMMON_DIR_OBJS)

# debug 
# run with DEBUG flag: make DEBUG=1
ifdef DETAIL
$(info "PARSER_DIR_OBJS:"$(PARSER_DIR_OBJS))
$(info "TYPECHECKER_DIR_OBJS:"$(TYPECHECKER_DIR_OBJS))
$(info "LLVM_DIR_OBJS:"$(LLVM_DIR_OBJS))
$(info "X86_DIR_OBJS:"$(X86_DIR_OBJS))
$(info "COMMON_DIR_OBJS:"$(COMMON_DIR_OBJS))
endif



CC_INCLUDES := -I$(SRC_DIR) \
			   -I$(SRC_DIR)/$(PARSER_DIR) \
			   -I$(SRC_DIR)/$(TYPECHECKER_DIR) \
			   -I$(SRC_DIR)/$(LLVM_DIR) \
			   -I$(SRC_DIR)/$(X86_DIR) \
			   -I$(SRC_DIR)/$(COMMON_DIR)

.PHONY : clean all

all: clean jlc

clean:
	rm -rf $(BUILD_DIR)/*
	rm -rf jlc
	mkdir -p $(BUILD_DIR)
	mkdir -p $(BUILD_DIR)/$(PARSER_DIR)
	mkdir -p $(BUILD_DIR)/$(TYPECHECKER_DIR)
	mkdir -p $(BUILD_DIR)/$(LLVM_DIR)
	mkdir -p $(BUILD_DIR)/$(X86_DIR)
	mkdir -p $(BUILD_DIR)/$(COMMON_DIR)


# generate the object files
$(BUILD_DIR)/$(COMMON_DIR)/%.o: $(SRC_DIR)/$(COMMON_DIR)/%.C $(HEADERS) 
	$(CC) $(CCFLAGS) $(CC_INCLUDES) -c $< -o $@;

$(BUILD_DIR)/$(PARSER_DIR)/%.o: $(SRC_DIR)/$(PARSER_DIR)/%.C $(HEADERS)
	$(CC) $(CCFLAGS) $(CC_INCLUDES) -c $< -o $@;

# special c flag for Lexer.o
$(BUILD_DIR)/$(PARSER_DIR)/Lexer.o : $(SRC_DIR)/$(PARSER_DIR)/Lexer.C $(SRC_DIR)/$(PARSER_DIR)/Bison.H 
	$(CC) $(CCFLAGS) -Wno-sign-conversion $(CC_INCLUDES) -c $< -o $@;

$(BUILD_DIR)/$(TYPECHECKER_DIR)/%.o: $(SRC_DIR)/$(TYPECHECKER_DIR)/%.C $(HEADERS)
	$(CC) $(CCFLAGS) $(CC_INCLUDES) -c $< -o $@;

$(BUILD_DIR)/$(LLVM_DIR)/%.o: $(SRC_DIR)/$(LLVM_DIR)/%.C $(HEADERS)
	$(CC) $(CCFLAGS) $(CC_INCLUDES) $(LLVM_CC_CONFIG) -c $< -o $@;

$(BUILD_DIR)/$(X86_DIR)/%.o: $(SRC_DIR)/$(X86_DIR)/%.C $(HEADERS)
	$(CC) $(CCFLAGS) $(CC_INCLUDES) $(LLVM_CC_CONFIG) -c $< -o $@;

# this target is used to generate the jlc executable, 
# output to the root directory directly.
jlc: $(OBJS) $(SRC_DIR)/jlc.cpp
	@echo "Building jlc..."
	$(CC) $(CCFLAGS) $(LLVM_CC_CONFIG) \
		$(CC_INCLUDES) $(OBJS) $(SRC_DIR)/jlc.cpp $(LLVM_LD_CONFIG) -o jlc 

# remove this target, because we just need to generate it once,
# thus, we generate it manually.
# also we have to modify the generated files to make it work.
# complie .Cf files
FLEX = flex
FLEX_OPTS = -Pjavalette_
BISON = bison
BISON_OPTS = -t -pjavalette_

CF_FILE=$(SRC_DIR)/Javalette.cf
generate_parser:
	@echo "clean the parser directory..."
	rm -rf $(SRC_DIR)/$(PARSER_DIR)/*
	@echo "Generating parser..."
	bnfc -m --cpp $(CF_FILE) -o $(SRC_DIR)/$(PARSER_DIR)
	@echo "Generating parser done."

	@echo "generate the Lexer.C and Parser.C files..."
	cd $(SRC_DIR)/$(PARSER_DIR) && \
	${FLEX} ${FLEX_OPTS} -oLexer.C Javalette.l && \
	${BISON} ${BISON_OPTS} Javalette.y \
		-o Parser.C
	# remove the Test.C file
	rm -f $(SRC_DIR)/$(PARSER_DIR)/Test.C