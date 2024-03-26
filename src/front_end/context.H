#ifndef __CONTEXT_H__
#define __CONTEXT_H__

#include <map>
#include <string>
#include <vector>

enum type_enum {INT=0, DOUB, BOOL, VOID, FUN, UNDEFINED};
std::string to_string(type_enum t);

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
  Frame(std::string name): name(name), returnType(UNDEFINED) {}
  ~Frame() = default;
  std::string name; // name of the function
  std::map<std::string, CVAR> parameters; // map of CVARiables
  type_enum returnType; // return type of the function

  std::vector<std::pair<std::string, type_enum> > args; // save the arguments of the function
  
  // chcek if the argument is declared
  bool isExistArg(const std::string& name);

  void addArg(const std::string& name, type_enum type){
	args.push_back(std::make_pair(name, type));
  }

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

	std::string currentFrameName;

	Frame & currentFrame(){
		return funcs["main"];
	}

	void addFrame(const std::string& name){
		Frame frame(name);
		funcs[name] = frame;
	}
	Frame & getFrame(const std::string& name){
		return funcs[name];
	}

	bool isExistFunction(const std::string& name){
		return funcs.find(name) != funcs.end();
	}

};

extern Context globalContext;

#endif