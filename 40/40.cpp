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
    
	vector<char> numberString;
	numberString.push_back(0);
	for (int i=1;i<1100000;i++) {
		for (const auto &a: std::to_string(i)) {
			numberString.push_back(a);
		}
	}
	cout<<numberString[8]<<endl;
	cout<<numberString[10]<<endl;
	cout<<numberString[100]<<endl;
	cout<<numberString[1000]<<endl;
	cout<<numberString[10000]<<endl;
	cout<<numberString[100000]<<endl;
	cout<<"\n";
	
	auto end_time = std::chrono::high_resolution_clock::now();
	cout <<"Elapsed: "<< std::chrono::duration_cast<std::chrono::seconds>(end_time - start_time).count() << ".";
	cout << std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count() << " seconds." <<endl;




}