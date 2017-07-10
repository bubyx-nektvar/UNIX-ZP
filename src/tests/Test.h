#ifndef TEST_H_
#define TEST_H_

#define TEST
#ifdef TEST
#include <exception>
#include <cstddef>
#include <vector>

class assert_exception :public std::exception {

};

template<typename T>
void assert_vector_array(std::vector<T> vec, T arr[], size_t arr_size);
//testovaci metoda volana z main

#define T1
#ifdef T1
void test1();
#endif

#endif // !TESTING


#endif // !TEST_H_


