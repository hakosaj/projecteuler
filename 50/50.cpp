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
#include <chrono>
#include <cstring>
#include <set>
#include <unistd.h>

using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::set;


bool isprime(int n) 
{ 
    if (n <= 1) 
        return false; 
    if (n <= 3) 
        return true; 
  
    if (n % 2 == 0 || n % 3 == 0) 
        return false; 
  
    for (int i = 5; i * i <= n; i = i + 6) 
        if (n % i == 0 || n % (i + 2) == 0) 
            return false; 
  
    return true; 
} 




int main() {
	auto start_time = std::chrono::high_resolution_clock::now();


	//cumulative sums seuraavaksi
	vector<int> primes=vector<int>();
	vector<int> primesums=vector<int>();
	primesums.push_back(0);
	for (int i=2;i<1000000;i++) {
		if (isprime(i)) {
			primes.push_back(i);
			primesums.push_back(i+primesums[primesums.size()-1]);
		}
	}

	int globfor=0;
	int globlong=0;
	#pragma omp parallel
	{
	int forWhich=0;
	int longest=0;
	#pragma omp for schedule(static,1)
	for (auto const& target:primes) {
		bool found=false;
		for (int i=0;i<primes.size();i++) {
			for (int j=i+1;j<primes.size();j++) {
				int mid=primesums[j]-primesums[i];
				if (mid>target ){
					break;
				}

				if (mid==target) {
					found=true;
					if (longest<j-i) {
						longest=j-i;
						forWhich=target;
					}

				}
				if (found) {break;}

		}
		if(found) {
			break;
		}
	}
}

//Parallel secton
	#pragma omp critical
	{
		if (longest>globlong) {
			globlong=longest;
			globfor=forWhich;
		}
	}

	}

	cout<<globfor<<" with a length of "<<globlong<<" primes."<<endl;

    
	auto end_time = std::chrono::high_resolution_clock::now();
	cout <<"Elapsed: "<< std::chrono::duration_cast<std::chrono::seconds>(end_time - start_time).count() << ".";
	cout << std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count() << " seconds." <<endl;




}