#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <omp.h>
#include <fstream>
#include <string>
#include <sstream>
#include <iterator>

using std::string;
using std::vector;


int main() {

    int c=0;
    string n = {"0123456789"};

    while (c<1000000-1) {

        
        
         std::next_permutation(n.begin(),n.end());
         c++;
    }
    std::cout<< "c is: "<< c << std::endl;
    std::cout << n << std::endl;








    
}