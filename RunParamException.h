#ifndef RUN_PARAM_EXCEPTION_H_
#define RUN_PARAM_EXCEPTION_H_
#include <exception>

class RunParamException : std::exception
{
public:
	RunParamException();
	~RunParamException();
};

#endif // !RUN_PARAM_EXCEPTION_H_
