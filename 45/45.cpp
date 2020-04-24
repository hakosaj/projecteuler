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
#include <unordered_map>

using std::cout;
using std::endl;
using std::vector;
using std::string;

bool isTriangle(int i) {
	float tri=(-1+sqrt(1+8*i))/2;
	return (ceil(tri)==floor(tri));
}
bool isPentagonal(int i) {
	float pen=(1+sqrt(1+24*i))/6;
	return (ceil(pen)==floor(pen));
}
bool isHexagonal(int i) {
	float hex=(1+sqrt(1+8*i))/4;
	return (ceil(hex)==floor(hex));
}

int nextTriangle(int t) {
	int n=(-1+sqrt(1+8*t))/2;
	return (n+1)*(n+2)/2;

}

int main() {
	auto start_time = std::chrono::high_resolution_clock::now();


	bool found=false;
	int t=40756;

	while (!found) {
			if (isPentagonal(t)) {
				if(isHexagonal(t)) {
					cout<<t<<endl;
					found=true;
				}
			}
			t++;
	}
	

















	auto end_time = std::chrono::high_resolution_clock::now();
	cout <<"Elapsed: "<< std::chrono::duration_cast<std::chrono::seconds>(end_time - start_time).count() << ".";
	cout << std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count() << " seconds." <<endl;

}