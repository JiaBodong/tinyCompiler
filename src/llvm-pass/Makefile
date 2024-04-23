LLVM_CONFIG ?= llvm-config

CXXFLAGS := $(shell $(LLVM_CONFIG) --cxxflags)
LDFLAGS := $(shell $(LLVM_CONFIG) --ldflags --libs all)

TARGET = BaseRegAlloc.so
SRCS = BaseRegAlloc.C

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) -shared -fPIC $(SRCS) -o $(TARGET) $(LDFLAGS)

.PHONY: clean
clean:
	rm -f $(TARGET)
