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

using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::set;


bool isPrime(long n) 
{
    if(n<=1) return false;
    if(n<=3) return true;


    if (n%2==0 || n%3==0) return false;

    for (long i=5;i*i<=n;i=i+6) {
        if (n%i==0 || n%(i+2)==0)
            return false;
    }
    return true;


}

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


	if (std::accumulate(digits.begin(),digits.end(),0) == 0) {
		return {0};
	}else {
    	return digits;
	}

}


vector<int> trimToLastDigits(vector<int> digits, int d) {
	if (d>digits.size()) {
		d=digits.size();
	}
	std::reverse(digits.begin(),digits.end());
	vector<int>::const_iterator first = digits.begin() +digits.size()-d;
	vector<int>::const_iterator last = digits.begin() +digits.size();
	vector<int> newVec(first, last);
	std::reverse(newVec.begin(),newVec.end());
	return newVec;
}

void printVector(vector<int> digits) {

    std::reverse(digits.begin(),digits.end());
    cout<<"\n";
    for (int i: digits  ) {
        cout<<i;
    }

    cout<<"\n";
    //cout<<"sum: "<< std::accumulate(digits.begin(),digits.end(),0);


}

vector<int> toDigits(long n) {
	long temp=n;
	vector<int> digits;
	int i=1;

	while (temp>0) {
		digits.push_back(temp%10);
		temp=temp-temp%10;
		temp=temp/10;
		i++;
	}

	return digits;


}


long toInt(vector<int> digits) {
	long res=0;
	int i=0;
	for (const auto &a: digits) {
		res+=(long)a*pow(10,i);
		i++;
	}

	return res;
}

vector<int> multiply(vector<int> digits, int n){

    for (int i=0;i<digits.size();i++) {

        digits[i]*=n;
    }

    return scaleToBaseN(digits,10);

}


int main() {
	auto start_time = std::chrono::high_resolution_clock::now();
	int sm=0;
	#pragma omp parallel for
	for (int i=11;i<1000000;i+=2) {
		if (isPrime(i)) {
			auto digits = toDigits(i);
			auto digits2 = digits;
			bool leftPrime=true;
			bool rightPrime=true;

			while (digits.size()>1) {
				digits.erase(digits.begin());
				if (!isPrime(toInt(digits))) {
					leftPrime=false;

				}
			}
			while (digits2.size()>1) {
				digits2.erase(digits2.end()-1);
				if (!isPrime(toInt(digits2))) {
					rightPrime=false;
				}
			}

			if (rightPrime && leftPrime) {
				cout<<i<<endl;
				sm+=i;
			}

			}
		}



	cout<<sm<<endl;




	
	auto end_time = std::chrono::high_resolution_clock::now();
	cout <<"Elapsed: "<< std::chrono::duration_cast<std::chrono::seconds>(end_time - start_time).count() << ".";
	cout << std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count() << " seconds." <<endl;




}