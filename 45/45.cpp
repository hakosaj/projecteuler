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
#include <unordered_map>

using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::set;



void printVector(vector<int> a) {
	for (const auto &n: a) {
		cout<<n<<",";
	}
	cout<<"\n";
}


long hexagonal(long n) {
	return n*(2*n-1);
}



bool isPentagonal(long long x) {
	unsigned long long r = (1+sqrt(1+(long long)24*x)/6);

	auto pent = r*(3*r-1)/2;
	return pent==x;


}


int main() {

	auto start_time = std::chrono::high_resolution_clock::now();

	for (int i=1;i<100000;i++) {
		if (isPentagonal(hexagonal(i))) {
			cout<<hexagonal(i)<<endl;

		}

	}
    




	
	auto end_time = std::chrono::high_resolution_clock::now();
	cout <<"Elapsed: "<< std::chrono::duration_cast<std::chrono::seconds>(end_time - start_time).count() << ".";
	cout << std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count() << " seconds." <<endl;




}