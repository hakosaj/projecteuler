#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <omp.h>
#include <chrono>


using std::cout;
using std::endl;
using std::vector;

int getDivisorSum(int n) {
    int counter=0;
    for (int i=1;i<(n/2)+1;i++)
        if(n%i==0) {
            counter+=i;
        }

    return counter;


}

bool hasTwoCandidates(std::vector<int> nums,int siz, int i) {
    int l=0;
    int r=siz-1;


    while (l<r) {
        if (nums[l]+nums[r]==i) {
            return 1;
        }
        else if (nums[l]+nums[r]<i) {
            l++;
        }else {
            r--;
        }
    }
    return 0;
}


int main(int argc, char** argv) {

	auto start_time = std::chrono::high_resolution_clock::now();


    std::vector<int> abundantNumbers;

    for (int i=1;i<=28120;i++) {
        if (getDivisorSum(i)>i){
            abundantNumbers.push_back(i);
        }
    }
    int start=0;
    int end=abundantNumbers.size();


    for (int i=24;i<=28123;i++) {

        if(!hasTwoCandidates(abundantNumbers,end,i)) {
            start+=i;
        }     

    }
	auto end_time = std::chrono::high_resolution_clock::now();
	cout <<"Elapsed: "<< std::chrono::duration_cast<std::chrono::seconds>(end_time - start_time).count() << ".";
	cout << std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count() << " seconds." <<endl;



std::cout<<start<<std::endl;

}