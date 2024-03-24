#ifndef __CONTEXT_H__
#define __CONTEXT_H__

#include <ordered_map>

// for each parameter, declared variable, we create a new VAR object
class VAR{
public:
  VAR();
  ~VAR();
  std::string name;
}

// for each block, we create a new Blk object
// a block is a sequence of statements
// a block can contain other blocks
class Blk{
public:
	Blk();
	~Blk();
	std::ordered_map<std::string, VAR> variables; // map of variables
	std::vector<Blk> blocks; // vector of blocks
	// rules for checking the block
	// for example, check if the variable is declared
	// check if the variable is initialized
	// check if the variable is used
	// check if the variable is assigned
	// check if the variable is in the scope
	// check if the variable is in the frame
}

// when there is a new fuction, we create a new frame
class Frame{
public:
  Frame();
  ~Frame();
  std::string name; // name of the function
  std::ordered_map<std::string, VAR> parameters; // map of variables

	// there are many checking functions for each new frame
	// for example, check if the variable is declared
	// check if the function is already declared
	// check if the function returns types
}

// Context is a class that holds the current state of the program.
class Context{
public:
	Context();
	~Context();
	std::ordered_map<std::string, Frame> funcs;
	// rules for checking the function

};

#endif