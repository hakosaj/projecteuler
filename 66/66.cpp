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





bool isSquare(long double x) 
{   
  long double sr = sqrt(x); 
  return ((sr - floor(sr)) == 0); 
} 

long solve(long D) {
	bool solved=false;
	for (int i=1;i<3000;i++) {
		for (int j=1;j<3000;j++) {
			if(i*i-(D*j*j)==1) {
				cout<<"Solved:solution "<<i<<" , "<<j<<endl;
				solved=true;
			}
			if (solved) {
				break;
			}
		}
		if (solved) {
			break;
		}
	}
	return 0;

}



long factorial(long n) {
	long t=1;
	while (n>1) {
		t*=n;
		n--;
	}
	return t;
}



int main() {
	auto start_time = std::chrono::high_resolution_clock::now();



	//No solutions for postive ints when D is square
	int Dlimit=1000;
	vector<int> Ds = vector<int>();

	//for (int i=1; i<=Dlimit;i++) {
	//	if (!isSquare((double)i)) {
	//		Ds.push_back(i);
	//}
	//}
	//#pragma omp parallel for schedule(auto)
	//for (auto const& d: Ds) {
	//	solve(d);
	//}

	#pragma omp parallel for schedule(auto)
	for (int i=0;i<20500;i++) {
		for (int j=0;j<40500;j++) {
			double a=pow((i*123.143545/5.4357658)/34.545445245,3.4);
		}
	}











    
	auto end_time = std::chrono::high_resolution_clock::now();
	cout <<"Elapsed: "<< std::chrono::duration_cast<std::chrono::seconds>(end_time - start_time).count() << ".";
	cout << std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count() << " seconds." <<endl;




}