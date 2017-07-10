#ifndef TEMPORARY_SUBSEQUENCE_DATA_H_
#define TEMPORARY_SUBSEQUENCE_DATA_H_

class TemporarySubsequenceData;
#include "base.h"

class TemporarySubsequenceData
{
public:
	TemporarySubsequenceData(BaseNumberType val,Index i)
		:value(val),index(i),length(1),next_index(-1),inside_next_index(-1)
	{ }
	TemporarySubsequenceData(BaseNumberType len, BaseNumberType val,Index act,Index next,Index vector_next)
		:length(len), value(val),index(act),next_index(next),inside_next_index(vector_next)
	{  }
	BaseNumberType value;
	BaseNumberType length;
	Index index;
	Index next_index;
	Index inside_next_index;
};

#endif // !TEMPORARY_SUBSEQUENCE_DATA_H_

