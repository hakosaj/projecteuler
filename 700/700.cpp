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

int main() {
	auto start_time = std::chrono::high_resolution_clock::now();
    



	long long eulercoin = 1504170715041707;
	long long modulo = 4503599627370517;
	long long smallest=eulercoin;
	long long sum=0;

	for (long i=1;i<10000;i++) {
		long long current=eulercoin*i % modulo;
		if (current<smallest) {
			smallest=current;
			cout<<current<<endl;
			sum+=current;
		}
	}

	cout<<sum<<endl;


	
	auto end_time = std::chrono::high_resolution_clock::now();
	cout <<"Elapsed: "<< std::chrono::duration_cast<std::chrono::seconds>(end_time - start_time).count() << ".";
	cout << std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count() << " seconds." <<endl;




}