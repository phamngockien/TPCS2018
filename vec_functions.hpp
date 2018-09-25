/// Created by Pham Ngoc Kien on 9/20/2018.
//
// SNU-ID: 2018-36543
//
// Homework 01
// The codes here have been uploaded to https://github.com/phamngockien/TPCS2018/commits/master
// In this homework we will write several simple functions for vector calculation,
// using the vector object from the standard template library (STL)
// in the std (standard) namespace.
#include <iostream>
#include <vector>
// definition of header file
#ifndef UNTITLED_VEC_FUNCTIONS_HPP
#define UNTITLED_VEC_FUNCTIONS_HPP

//Homework 01-part01
//this function will calculate the sum of two vectors
//function to sum 2 vectors a and b called "sum"
// with input is the two vectors a and b having the same size
std::vector<double> sum(const std::vector<double> &a,
                        const std::vector<double> &b)
{
    // create result vector with the size of vector a
    std::vector<double> result(a.size());
    // this for loop is to push each sum of elements of vectors a and b into result vector, respectively.
    for (int i = 0; i < a.size(); ++i)
    {
        result[i]= a[i] + b[i];
    }
    // return the result
    return result;
}

//Homework 01-part02
// this function will calculate the dot product of two vectors
//function to do this task called "dot"
// with input is the two vectors a and b having the same size
double dot(const std::vector<double> &a,
           const std::vector<double> &b)
{
    // create result variable to calculate the dot product
    double result=0;
    // this for loop is to calculate the dot product
    // which is the sum of all multiples a[i]*b[i] of two vectors a and b
    for (int i = 0; i < a.size(); ++i)
    {
        result += a[i] * b[i];
    }
    // return the result
    return result;
}

//Homework 01-part03
// this function will generate a vector of linearly spaced values
//function to do this task called "linspace"
// with input is the start, stop values and the number of values of the result vector.
const std::vector<double> linspace(const double &start,
                                   const double &stop,
                                   const int &num_points)
{
    //create the result vector named "lin_vec"
    std::vector<double> lin_vec(num_points);
    //this loop is to generate a vector of linearly spaced values
    //with the step size = (stop value - start value)/(number of values - 1)
    for (int i = 0; i < num_points; ++i)
    {
        lin_vec[i]=start+i*(stop-start)/(num_points-1);
    }
    //return the result vector
    return lin_vec;
}

//Homework 01-part04
// this function will compute the integral (area under y) for two vectors x and y (y = f(x))
//function to do this task called "integrate"
// with input is the two vectors x and y having the same size
double integrate(const std::vector<double> &x,
                 const std::vector<double> &y)
{
    //create variable integral to store the result
    double integral=0;
    //this loop is to integrate the two vectors by using trapezoidal rule
    //which using the average height of each interval to compute the area of each interval.
    //And just sum up all the interval areas
    for (int i = 1; i <x.size(); ++i)
    {
        integral+=(x[i]-x[i-1])*(y[i]+y[i-1])/2;
    }
    // return the result
    return integral;
}

//end of header file
#endif //UNTITLED_VEC_FUNCTIONS_HPP
