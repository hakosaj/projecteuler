#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <omp.h>
#include <fstream>
#include <string>
#include <unordered_set>
#include <sstream>
#include <iterator>
#include <chrono>
#include <cstring>
#include <unordered_map>

using std::cout;
using std::endl;
using std::vector;
using std::string;


bool isprime(int n) 
{ 
    if (n <= 1) 
        return false; 
    if (n <= 3) 
        return true; 
  
    if (n % 2 == 0 || n % 3 == 0) 
        return false; 
  
    for (int i = 5; i * i <= n; i = i + 6) 
        if (n % i == 0 || n % (i + 2) == 0) 
            return false; 
  
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

vector<int> toDigits(int n) {
	int temp=n;
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
vector<int> addVectors(vector<int> a, vector<int> b) {
	vector<int> add;
	if (a.size()>b.size()) {
		add=a;
		for (int i=0;i<b.size();i++) {
			add[i]+=b[i];
			add=scaleToBaseN(add,10);
		}

	}else {
		add=b;
		for (int i=0;i<a.size();i++) {
			add[i]+=a[i];
			add=scaleToBaseN(add,10);
		}

	}

	return add;
}

vector<int> multiply(vector<int> digits, int n){

    for (int i=0;i<digits.size();i++) {

        digits[i]*=n;
    }

    return scaleToBaseN(digits,10);

}

vector<int> multiplyVectors(vector<int> digits1, vector<int> digits2) {

	int tens=0;
	vector<int> multiplied={0};
	for (const auto &a: digits1) {
			multiplied=addVectors(multiplied,multiply(digits2,a*pow(10,tens)));
			multiplied=scaleToBaseN(multiplied,10);

			tens++;
	}

	return multiplied;

}

vector<int> powerWithTrim(vector<int> digits, int p, int lastDigits) {
	vector<int> base = digits;
	for (int i=1;i<p;i++) {
		digits=trimToLastDigits(multiplyVectors(digits,base),lastDigits);
	}
	return digits;
}

vector<int> power(vector<int> digits, int p) {
	vector<int> base = digits;
	for (int i=1;i<p;i++) {
		digits=multiplyVectors(digits,base);
		digits=scaleToBaseN(digits,10);
		printVector(digits);
	}
	return digits;
}

long digitCount(vector<int> base) {
	return std::accumulate(base.begin(),base.end(),0);
}

template <typename T>
void print( T a)
{
   cout<<a<<endl;
}

template <typename N>
N getReverseInt(N value) {
    N resultNumber = 0;
    for (N i = value; i != 0;) {
        N d = i / 10;
        resultNumber = (resultNumber - d) * 10 + i;
        i = d;
    }
    return resultNumber;
}

		std::unordered_set<int> checks{85,89,145,42,20,4,16,37,58};

bool squaredSums(long long number) {
	long long sm=0;
	if(checks.count(number)) {
		return true;
	}
	if(number==1) {
		return false;
	}

	for (int i=0;i<(int)std::floor(log(number))+1;i++) {
		long long temp=0;

		auto a1=number%(long)pow(10,i+1);
		auto a2=number%(long)pow(10,i);

		temp+=(long)pow(a1,2);
		temp-=2*a2*a1;
		temp+=(long)pow(a2,2);
		sm+=(temp/(long)(pow(10,2*i)));
	}
	return squaredSums(sm);

}
int main() {	


	auto start_time = std::chrono::high_resolution_clock::now();
	int counter=0;


		for(long i=1;i<568;i++) {
			if (squaredSums(i)) {
				checks.insert(i);
				counter++;
			}
		}
	#pragma omp parallel
	{
		int owncounter=0;
		#pragma omp for
		for(long i=568;i<10000000;i++) {
			if (squaredSums(i)) {
				owncounter++;
			}
		}
	#pragma omp critical
	{
		counter+=owncounter;
	}


	}
	print<int>(counter);
	
    
	auto end_time = std::chrono::high_resolution_clock::now();
	cout <<"\nElapsed: "<< std::chrono::duration_cast<std::chrono::seconds>(end_time - start_time).count() << ".";
	cout << std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count() << " seconds." <<endl;




}