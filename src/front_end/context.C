#include "context.H"

std::string to_string(type_enum t) {
  switch(t) {
    case INT: return "int";
    case DOUB: return "double";
    case BOOL: return "bool";
    case VOID: return "void";
    case FUN: return "fun";
    case CHAR: return "char";
    case STRING: return "string";
    case UNDEFINED: return "undefined";
  }
  return "unknown";
}


bool Frame::isExistArg(const std::string& name){
	for(const auto & arg : args){
	  if(arg.first == name){
		return true;
	  }
	}
	return false;
} 