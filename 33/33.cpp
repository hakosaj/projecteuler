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
set<int> toDigitSet(int n) {
	int temp=n;
	set<int> digits;
	int i=1;

	while (temp>0) {
		digits.insert(temp%10);
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

vector<int> power(vector<int> digits, int p, int lastDigits) {
	vector<int> base = digits;
	for (int i=1;i<p;i++) {
		digits=trimToLastDigits(multiplyVectors(digits,base),lastDigits);
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





int main() {
	auto start_time = std::chrono::high_resolution_clock::now();

	//luodaan kaikki muotoa abbc-olevat 
	//löydettävä ne, joilla ab/bc==a/c
	vector<vector<int>> all;
	for (int d=1;d<10;d++) {
		for (int a=1;a<10;a++) {
			for (int b=1;b<10;b++) {
				vector<int> digs ={a,d,d,b};
				double o = (double)10*a+d;
				double n = (double)10*d+b;

				if (abs(o/n ==((double)a/(double)b)) && o/n<1.0) {
					cout<<o<<","<<n<<","<<(double)a<<","<<(double)b<<endl;
				}

				}
			}
		}


	
	auto end_time = std::chrono::high_resolution_clock::now();
	cout <<"Elapsed: "<< std::chrono::duration_cast<std::chrono::seconds>(end_time - start_time).count() << ".";
	cout << std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count() << " seconds." <<endl;




}