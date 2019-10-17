#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <omp.h>


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

bool hasTwoCandidates(vector<int> nums,int siz, int i) {
    int l=0;
    int r=siz-1;


    while (l<r) {
        if (nums[l]+nums[r]==i) {
            cout<<"Candidates: "<< nums[l] <<" and "<<nums[r]<< " equal to " << i << endl;  
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


    vector<int> abundantNumbers;
    for (int i=1;i<28123;i++) {
        if (getDivisorSum(i)>i){
            abundantNumbers.push_back(i);
        }
    }


    int start=0;
    int end=abundantNumbers.size();

    for (int i=24;i<28123;i++) {

        if(hasTwoCandidates(abundantNumbers,end,i)) {
            //cout<<i<<endl;
            start+=i;
        }     



    }

cout<<start<<endl;

}