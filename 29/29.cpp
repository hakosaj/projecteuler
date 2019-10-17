#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <omp.h>
#include <set>
#include <chrono>


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
    //cout<<"\n";
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
vector<int> multiply(vector<int> digits, int n){

    for (int i=0;i<digits.size();i++) {

        digits[i]*=n;
    }

    return scaleToBaseN(digits,10);

}

template <typename T>
std::vector<T>& operator +=(std::vector<T>& vector1, const std::vector<T>& vector2) {
    vector1.insert(vector1.end(), vector2.begin(), vector2.end());
    return vector1;
}

int main(int argc, char **argv) {
    auto start_time = std::chrono::high_resolution_clock::now();
    int al=100;
    int bl=100;
    vector<vector<int>> members;
    

    #pragma omp parallel 
    {
    vector<vector<int>> membersp;
    #pragma omp for schedule(static,1)
    for (int a=2;a<al+1;a++) {
        for (int b=2;b<bl+1;b++) {
            vector<int> digits={a};
            for (int m=1;m<b;m++) {
                    digits=multiply(digits,a);
                }
                membersp.push_back(digits);
    }

            
        }


    #pragma omp critical
    {
        members+=membersp;
    }
        

    }





    int dist=0;
    vector<vector<int>> membcpy=members;
    
    for (int a=0;a<members.size();a++) {
        for (int b=0;b<members.size();b++) {
            if (a==b){
                continue;
            }else if (members[a]==members[b]) {
                members.erase(members.begin()+a);
                }else {
                    dist++;
                }
            }
        }
        


    cout<<"\n"<<members.size()<<endl;


    auto end_time = std::chrono::high_resolution_clock::now();

   	cout << std::chrono::duration_cast<std::chrono::seconds>(end_time - start_time).count() << ".";
	cout << std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count() <<" seconds. \n";
    



}

