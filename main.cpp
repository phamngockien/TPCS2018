/// Created by Pham Ngoc Kien on 9/20/2018.
//
// SNU-ID: 2018-36543
//
// Homework 01
//
// In this homework we will write several simple functions for vector calculation,
// using the vector object from the standard template library (STL)
// in the std (standard) namespace.
#include <iostream>
#include <vector>
//include header file vec_functions here to call all of its functions for the test
#include "vec_functions.hpp"

//create a function to print vector.
//referenced from Mr. Erik Sevre
void print_vec(const std::vector<double> &vec) {

    for (const auto v : vec) {
        std::cout << v << ' ';
    }
    std::cout << '\n';
}
//main function try to test 4 functions before writing the test function
int main() {
    // create 2 vectors
  std::vector<double> a {1.0,2.0,3.0,4.0,5.0};
  std::vector<double> b {1.0,2.0,3.0,4.0,5.0};
      //recall the sum 2 vectors function
      auto result=sum(a,b);
      //print the two initial vectors and the sum vector
      print_vec(a);
      print_vec(b);
      print_vec(result);
      //recall the dot product function
      auto dot_product=dot(a,b);
      //print the dot product of two vectors
      std::cout<<dot_product<<std::endl;
      //recall a vector of linearly spaced values
      //start value is 1, stop value is 6, number of points is 12
      auto lin_vec=linspace(1,6,11);
      //print the result
      print_vec(lin_vec);
      //recall the integration function with
      // vector x = vector a; veotor y = vector b;
      auto integral=integrate(a,b);
      std::cout<<"the integral (area under y) for two vectors x and y (y = f(x)) is: " <<integral<<std::endl;
}