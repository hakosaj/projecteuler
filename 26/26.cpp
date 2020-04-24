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







int main() {
	auto start_time = std::chrono::high_resolution_clock::now();

	double g = 1.0/7;
	for (int i=0;i<20;i++) {
		g*=10;
		cout<<std::floor(g)<<endl;
		g-=std::floor(g);
		if (g==0) {
			break;
		}
	}
		








    
	auto end_time = std::chrono::high_resolution_clock::now();
	cout <<"Elapsed: "<< std::chrono::duration_cast<std::chrono::seconds>(end_time - start_time).count() << ".";
	cout << std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count() << " seconds." <<endl;




}