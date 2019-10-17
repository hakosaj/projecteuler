#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <numeric>


using std::cout;
using std::endl;
using std::vector;


vector<int> scaleToBaseN(vector<int> digits, int N) {

        for( int a=0;a<digits.size();a++) {

            if(digits[a]>=N) {
                int shift=(digits[a]-digits[a]%N)/N;

                digits[a]=digits[a]-(digits[a]-digits[a]%N);

                if (a!=digits.size()-1) {
                    digits[a+1]+=shift;
                }else {
                    digits.push_back(shift);
                }
            }

        }

    return digits;

}




void printVector(vector<int> digits) {

    std::reverse(digits.begin(),digits.end());
    cout<<"\n";
    for (int i: digits  ) {
        cout<<i;
    }
    cout<<"\n";
    cout<<"sum: "<< std::accumulate(digits.begin(),digits.end(),0);
}

vector<int> sumVectors(vector<int> a, vector<int> b) {
    vector<int>accumulator;
    a=scaleToBaseN(a,10);
    b=scaleToBaseN(b,10);
    for (int add1: a) {
        accumulator.push_back(add1);
    }
    for (int i=0;i< b.size();i++){
    accumulator[i]+=b[i];
    }
        
   return accumulator;
}


int main(int argc, char **argv) {

    vector<vector<int>> fibonacciSequence;
    //Reverse order for digits!
    fibonacciSequence.push_back({1});
    fibonacciSequence.push_back({1});
    int i=2;
    while(fibonacciSequence.back().size()<1000) {

    
        vector<int> digToAdd=sumVectors(fibonacciSequence[i-1],fibonacciSequence[i-2]);
        fibonacciSequence.push_back(digToAdd);
        fibonacciSequence.back()=scaleToBaseN(fibonacciSequence.back(),10);
        i++;
    }
    for (int i=0;i<fibonacciSequence.size();i++) {
        fibonacciSequence[i]=scaleToBaseN(fibonacciSequence[i],10);
    }
    cout<<fibonacciSequence.size() << " th member:";
    printVector(fibonacciSequence[fibonacciSequence.size()-1]);
    






}