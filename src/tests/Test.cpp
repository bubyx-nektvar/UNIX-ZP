#include "Test.h"
#include "FileStructure.h"
#ifdef TEST
void assert_vector_array(vector<BaseNumberType> vec, BaseNumberType arr[], size_t arr_size)
{
	if (vec.size() == arr_size) {
		for (int i = 0; i < arr_size; ++i)
		{
			if (vec[i] != arr[i]) throw assert_exception();
		}
	}
	else throw assert_exception();
}
//testovaci metoda volana z main

#ifdef T1
void test1() {

	FileStructure<std::string> fs;
	fs.AppednChunk(string("Ahoj"));
	fs.AppednChunk(string("Jak je"));
	fs.AppednChunk(string("Ahoj"));
	fs.AppednChunk(string("Nevim co dal"));
	fs.AppednChunk(string("Nevim co dale"));
	fs.AppednChunk(string("Ahoj"));

	vector<std::string> newfile;
	newfile.push_back(string("Ahoj"));
	newfile.push_back(string("Aaa"));
	newfile.push_back(string("Ahoj"));
	newfile.push_back(string("Nevim co dal"));
	newfile.push_back(string("Blem"));
	newfile.push_back(string("Nevim co dale"));
	newfile.push_back(string("Ahoj"));
	newfile.push_back(string("Nevim co dal"));
	auto res = fs.GetReusableChunks(newfile);

	auto max = numeric_limits<BaseNumberType>::max();
	BaseNumberType arr[] = { 0,max,2,3,max,4,5,max };
	assert_vector_array(*res, arr, 8);

#endif
}

#endif
