#ifndef TESTING_H_
#define TESTING_H_

#define TEST

#ifdef TEST

#include <exception>

template<typename T> class AssertFailException
	:std::exception{
private:
	T expected;
	T found;
public:
	AssertFailException(T expected, T found) {
		this->expected = expected;
		this->found = found;
	}
};

namespace Assert {
	template<typename T> void equals(T expected, T found) {
		if (expected != found)throw new AssertFailException(expected, found);
	}

};

#endif // TEST

#endif // !TESTING_H_
|