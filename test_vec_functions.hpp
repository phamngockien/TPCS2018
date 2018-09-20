/// Created by Pham Ngoc Kien on 9/20/2018.
//
// SNU-ID: 2018-36543
//
// Homework 01 - test vector functions (part 05)
//
// This function is to run the test of the four functions for vector calculation,
// using the vector object from the standard template library (STL)
// in the std (standard) namespace.
#include <iostream>
#include <vector>
//include header file vec_functions here to call all of its functions for the test
#include "vec_functions.hpp"
//include this line to create a function to integrate another function
#include <functional>

// definition of header file
#ifndef UNTITLED_TEST_VEC_FUNCTIONS_HPP
#define UNTITLED_TEST_VEC_FUNCTIONS_HPP

//create a function called "print_vec" to print vector.
//referenced from Mr. Erik Sevre
void print_vec(const std::vector<double> &vec) {
//this for loop uses another syntax, for (declaration : range) statement
// This kind of for loop iterates over all the elements in range,
// where declaration declares some variable able to take the value of an element in this range.
//so this loop print all elements of vector vec separating by a space
    for (const auto v : vec) {
        std::cout << v << ' ';
    }
    //after for loop the next thing will be printed in a new line
    std::cout << '\n';
}

//Homework 01-part05
//this is a function to test part 01
//test the function to sum the 2 vectors
bool test_f1() {
    //assume that we have 2 vectors a and b with the double type
    std::vector<double> a={1,2,3,4,5,6};
    std::vector<double> b={10,10,10,10,10,10};
    //the sum of these two vectors is a vector add_vec
    std::vector<double> add_vec={11,12,13,14,15,16};
    //call function sum to add 2 vectors a and b
    auto sum_vec=sum(a,b);
    //create a bool variable to test the true or false of function
    bool test=true;
        //if an element of calculated vector sum_vec is smaller or bigger than
        // the limit [add_vec[i]-10^-8,add_vec[i]+10^-8]
        // with an acceptable tolerance is 10^-8 then test failed
        //this for loop is to do the task
        for (int i = 0; i <a.size() ; ++i) {
            if(sum_vec[i] > add_vec[i]+1e-8 || sum_vec[i] < add_vec[i]-1e-8){
            return false;
            }
        }
}

//test part 02
//this is a function to test part 02
//test the function to calculate the dot product of the 2 vectors
bool test_f2() {
    //assume that we have 2 vectors a and b with the double type
    std::vector<double> a={1,2,3};
    std::vector<double> b={1,0,1};
    //the dot product of these two vectors is a number dot_product with value of 4
    double dot_product=4;
    //call function dot to calculate the dot product of 2 vectors a and b
    auto dot_vec=dot(a,b);
    //if the calculated dot product value  is smaller or bigger than
    // the limit [dot_product-10^-8,dot_product+10^-8]
    // with an acceptable tolerance is 10^-8 then test failed
    //create a bool variable to test the true or false of function
    bool test=true;
    if(dot_vec > dot_product+1e-8 || dot_vec < dot_product-1e-8){
        return false;
    }
}

//test part 03
//this is a function to test part 03
//test the function to generate a vector of linearly spaced values
bool test_f3() {
    //assume that we have vector a have 6 elements from 1 to 6
    // with the linear space is 1.
    std::vector<double> a={1,2,3,4,5,6};
    //call function linspace to generate a vector of linearly spaced values
    // with the start and stop values are 1 and 6, respectively
    // the number of values is 6
    auto lin_vec=linspace(1,6,6);
    //if each generated values  is smaller or bigger than
    // the limit [true value-10^-8,true value+10^-8]
    // with an acceptable tolerance is 10^-8 then test failed
    // true values is the corresponding values in vector a
    //create a bool variable to test the true or false of function
    bool test=true;
    //this for loop is to do the task
    for (int i = 0; i <a.size() ; ++i) {
        if(lin_vec[i] > a[i]+1e-8 || lin_vec[i] < a[i]-1e-8){
            return false;
        }
    }
}

//test part 04
//this is a function to test part 04
//test the function to compute the integral (area under y) for two vectors x and y (y = f(x))
bool test_f4() {
    //assume that we have 2 vectors x and y with the double type
    std::vector<double> x={1,2,3,4,5};
    std::vector<double> y={1,2,3,4,5};
    //the the integral (area under y) for two vectors x and y (y = f(x)) is 12
    //with the function is y=f(x)=x.
    double int_true=12;
    //call function integrate to compute the integral (area under y) for two vectors x and y
    auto integral=integrate(x,y);
    //if the integral value  is smaller or bigger than
    // the limit [int_true-10^-8,int_true+10^-8]
    // with an acceptable tolerance is 10^-8 then test failed
    //create a bool variable to test the true or false of function
    bool test=true;
    if(integral > int_true+1e-8 || integral < int_true-1e-8){
        return false;
    }
}

// Todo Reference from Mr. Erik Sevre
// Run tests on a function and named input
bool run_test(
        std::function<bool(void)> fnc,
        std::string function_name)
{
    //create boolean variable val to get the true or false from test functions above
    bool val = fnc();
    //if val is true then the test of the considering function is OK (passed)
    //if it is false then the test of the considering function is XX (failed)
    if (val){
        std::cout << "[OK] : test of function PASSED -> " << function_name << '\n';
    } else {
        std::cout << "[XX] : test of function FAILED -> " << function_name << '\n';
    }
    return val;
}
//this function is to run all the tests by calling the function run_test above
//here we have 4 function test_f1 to test_f4
void run_all_tests() {
    //create an empty vector results to contain the test results from 4 function test_f1 to test_f4
    std::vector<bool> results;
    //insert the results of each test function into vector results
    results.push_back( run_test(test_f1, "test f1") );
    results.push_back( run_test(test_f2, "test f2") );
    results.push_back( run_test(test_f3, "test f3") );
    results.push_back( run_test(test_f4, "test f4") );
    // create a variable to assume that all the tests are passed.
    // this means that no one of the tests is failed
    bool one_is_false = false;
    // this for loop consider each element of vector results and load it into parameter r
    for (auto r : results) {
        //if r is false then this test is false, so one test of the 4 tests is false
        // the one_is_false variable is true for this condition
        if (!r) { one_is_false = true; }
    }
    // if no one of the tests is false, the one_is_false variable is false
    // then print out "all tests passed"
    // or else print out "there was a failure" from the 4 tests
    if (!one_is_false) {
        std::cout << "all tests passed \n";
    } else {
        std::cout << "There was a failure \n";
    }
}
//end of header file
#endif //UNTITLED_TEST_VEC_FUNCTIONS_HPP
