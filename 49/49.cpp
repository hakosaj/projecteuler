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
#include <unordered_set>
#include <unistd.h>


using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::set;
using std::unordered_set;

#define uset unordered_set


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


vector<int> toDigits(long a) {
    vector<int>digs;
    do {
        int digit = a % 10;
        digs.push_back(digit);
        a /= 10;
    } while (a > 0);

    std::reverse(digs.begin(),digs.end());
    return digs;
}

uset<int> toDigitSet(vector<int> digits) {
	return uset<int>(digits.begin(),digits.end());
}


int main() {
	auto start_time = std::chrono::high_resolution_clock::now();


	vector<int> primes=vector<int>();
	for (int i=10000;i<100000;i++) {
		if(isprime(i)) {
			primes.push_back(i);
		}

	}
	
	//First prime to digits and sort. Then try finding another prime with the same digits. If reach end, then next starting prime.
	#pragma omp parallel for schedule(static,1)
	for (int j=0;j<primes.size();j++) {
		int firstprime = primes[j];
		auto firstdigs=toDigits(firstprime);
		std::sort(firstdigs.begin(),firstdigs.end());

		for(int i=j+1;i<primes.size();i++) {
			int secondprime = primes[i];
			auto seconddigs=toDigits(secondprime);
			std::sort(seconddigs.begin(),seconddigs.end());
			if (seconddigs==firstdigs) {
				for(int k=i+1;k<primes.size();k++) {
					int thirdprime = primes[k];
					if (thirdprime-secondprime == secondprime-firstprime) {
						auto thirddigs=toDigits(thirdprime);
						std::sort(thirddigs.begin(),thirddigs.end());
						if (seconddigs==thirddigs) {
								cout<<"Palindrome triplet: "<<firstprime<<","<<secondprime<<","<<thirdprime<<endl;
							}
					}
				}
			}

		}
		
		

	}




    
	auto end_time = std::chrono::high_resolution_clock::now();
	cout <<"Elapsed: "<< std::chrono::duration_cast<std::chrono::seconds>(end_time - start_time).count() << ".";
	cout << std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count() << " seconds." <<endl;




}