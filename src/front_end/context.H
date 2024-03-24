#ifndef __CONTEXT_H__
#define __CONTEXT_H__

#include <map>

// for each parameter, declared CVARiable, we create a new CVAR object
class CVAR{
public:
  CVAR() = default;
  ~CVAR() = default;
  std::string name;
};

// for each block, we create a new CBlk object
// a block is a sequence of statements
// a block can contain other blocks
class CBlk{
public:
	CBlk() = default;
	~CBlk() = default;
	std::map<std::string, CVAR> CVARiables; // map of CVARiables
	std::vector<CBlk> blocks; // vector of blocks
	// rules for checking the block
	// for example, check if the CVARiable is declared
	// check if the CVARiable is initialized
	// check if the CVARiable is used
	// check if the CVARiable is assigned
	// check if the CVARiable is in the scope
	// check if the CVARiable is in the frame
};

// when there is a new fuction, we create a new frame
class Frame{
public:
  Frame() = default;
  Frame(std::string name): name(name) {}
  ~Frame() = default;
  std::string name; // name of the function
  std::map<std::string, CVAR> parameters; // map of CVARiables

	// there are many checking functions for each new frame
	// for example, check if the CVARiable is declared
	// check if the function is already declared
	// check if the function returns types
};

// Context is a class that holds the current state of the program.
class Context{
public:
	Context() = default;
	~Context() = default;
	std::map<std::string, Frame> funcs;
	// rules for checking the function

	void addFrame(const std::string& name){
		Frame frame(name);
		funcs[name] = frame;
	}
};

#endif