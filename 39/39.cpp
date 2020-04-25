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
#include <unordered_set>

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
	int globalmax=0;
	int globalmaxper=0;
    #pragma omp parallel
	{
	int max=0;
	int maxper=0;
	#pragma omp for schedule(static,1)
	for (int p=2;p<1000;p++){
		cout<<p<<endl;
		std::set<std::vector<int>> triples;

	
		for (int i=p;i>1;i--) {
			for (int j=1;j<i;j++) {
				for (int k=1;k<j;k++) {

					
					if ( i+j+k==p && (pow(i,2)+pow(j,2)-pow(k,2)==0 || pow(i,2)+pow(k,2)-pow(j,2)==0 || pow(j,2)+pow(k,2)-pow(i,2)==0)) {
						vector<int> d={i,j,k};
						std::sort(d.begin(),d.end());
						triples.insert(d);
					}

				}
			}

		}
		if (triples.size()>max) {
			maxper=p;
			max=triples.size();
		}
	}
	#pragma omp critical
	{
		if (max>globalmax) {
			globalmax=max;
			globalmaxper=maxper;
		}
	}
	}
	cout<<"This here: perimeter "<<globalmaxper<<" , triples " << globalmax<<endl;



	
	auto end_time = std::chrono::high_resolution_clock::now();
	cout <<"Elapsed: "<< std::chrono::duration_cast<std::chrono::seconds>(end_time - start_time).count() << ".";
	cout << std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count() << " seconds." <<endl;




}