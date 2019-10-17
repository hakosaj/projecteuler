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



vector<int> multiply(vector<int> digits, int n){

    for (int i=0;i<digits.size();i++) {

        digits[i]*=n;
    }

    return scaleToBaseN(digits,10);

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
int main(int argc, char **argv) {

    vector<int> digits;
    //Reverse order for digits!
    digits={1};
    for (int i=std::stoi(argv[1]);i>=1;i--) {

        digits=multiply(digits,i);
    
    }
    printVector(digits);
    






}