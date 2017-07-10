#ifndef TEST_H_
#define TEST_H_

#define TEST
#ifdef TEST

#include "FileStructure.h"
class assert_exception :public exception {

};
void assert_vector_array(vector<BaseNumberType> vec, BaseNumberType arr[], size_t arr_size);
//testovaci metoda volana z main

#define T1
#ifdef T1
void test1();
#endif

#endif // !TESTING


#endif // !TEST_H_


