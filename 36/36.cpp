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

using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::pair;





vector<long> toDigits(long a) {
    vector<long>digs;
    do {
        long digit = a % 10;
        digs.push_back(digit);
        a /= 10;
    } while (a > 0);

    std::reverse(digs.begin(),digs.end());
    return digs;
}
vector<long> toBinaryDigits(long a) {
    vector<long>digs;
    do {
        long digit = a % 2;
        digs.push_back(digit);
        a /= 2;
    } while (a > 0);


    std::reverse(digs.begin(),digs.end());
    return digs;
}

bool isPalindrome(vector<long> digits) {
	if (digits.size()==0 || digits.size()==1) {
		return true;
	}
	if (digits.back()==digits[0]){
		digits.pop_back();
		digits.erase(digits.begin());
		return isPalindrome(digits);
	}
	return false;

}



int main() {
	auto start_time = std::chrono::high_resolution_clock::now();
	int counter=0;
	#pragma omp parallel for schedule(auto)
	for (long i=0;i<1000000;i++) {
		if (isPalindrome(toDigits(i))) {
			if (isPalindrome(toBinaryDigits(i))) {
				cout<<i<<endl;
				counter+=i;
			}
		}
	}

cout<<"Count: "<<counter<<endl;








    
	auto end_time = std::chrono::high_resolution_clock::now();
	cout <<"Elapsed: "<< std::chrono::duration_cast<std::chrono::seconds>(end_time - start_time).count() << ".";
	cout << std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count() << " seconds." <<endl;




}