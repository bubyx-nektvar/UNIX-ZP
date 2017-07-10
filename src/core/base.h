#ifndef BASE_H_
#define BASE_H_
#include <sstream>
#include <string>
#include <memory>

typedef long BaseNumberType;//must be signed
typedef long Index;//must be signed
typedef unsigned long Index_u;
typedef unsigned long Version;//cislo oznacujici verzi
typedef std::string Hash;

template<typename T>
T fromString(std::string input) {
	stringstream s(input);
	T x;
	s >> x;
	return x;
}

#endif
