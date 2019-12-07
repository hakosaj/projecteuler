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
#include <unordered_set>

using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::unordered_set;





int main() {
	auto start_time = std::chrono::high_resolution_clock::now();

	vector<long> pentagons = vector<long>();
	unordered_set<long> pentagons2 = unordered_set<long>();
	unordered_set<long> tried= unordered_set<long>();


	auto pentagonal  = [] (long a)-> long{ return (a*(3*a-1))/2; };

	
	for (long i=1;i<10001;i++) {
		long a = pentagonal(i);
		pentagons.push_back(a);
		pentagons2.insert(a);
	}


	long mindiff=__INT_MAX__;
	long m1;
	long m2;
	#pragma omp parallel for schedule(static,1)
	for (int i=0;i<10000;i++) {
		for (int j=0;j<10000;j++) {
				long p1=pentagons[i];
				long p2=pentagons[j];

				if (pentagons2.count(p1+p2)) {
					if (pentagons2.count(abs(p1-p2))) {
						if (mindiff>abs(p1-p2)) {
							mindiff=abs(p1-p2);
							if (p2==0) {
							}
							m1=p1;
							m2=p2;
						}
					}
			 }

		}
	}
	
	cout<<"Mindiff: "<<mindiff<<endl;
	cout<<"With pentagonals: "<<m1 <<" , "<<m2<<endl;








    
	auto end_time = std::chrono::high_resolution_clock::now();
	cout <<"Elapsed: "<< std::chrono::duration_cast<std::chrono::seconds>(end_time - start_time).count() << ".";
	cout << std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count() << " seconds." <<endl;




}