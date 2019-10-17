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



int countRecursion(int coins[],int uniques, int n) {

	if (n==0)
		return 1;


	if (n<0)
		return 0;


	if (uniques<=0 && n >=1)
		return 0;


	return countRecursion(coins,uniques-1,n)+countRecursion(coins,uniques,n-coins[uniques-1]);



}



int count(int coins[],int uniques, int n) {


	int table[n+1];
	std::memset(table,0,sizeof(table));


	table[0]=1;


	for(int i=0;i<uniques;i++) {
		for(int j=coins[i];j<=n;j++) {
			table[j]+=table[j-coins[i]];
		}

	}

	return table[n];


}

int main() {
	auto start_time = std::chrono::high_resolution_clock::now();

	int n=200;
	int S[]={1,2,5,10,20,50,100,200};
	int uniques=8;

	int solutions=count(S,uniques,n);












    
	auto end_time = std::chrono::high_resolution_clock::now();
	cout <<"Elapsed: "<< std::chrono::duration_cast<std::chrono::seconds>(end_time - start_time).count() << ".";
	cout << std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count() << " seconds." <<endl;

	cout<<"Different ways: "<< solutions<<endl;



}