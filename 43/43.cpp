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
#include <list>

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


	std::list<int> primes={2,3,5,7,11,13,17};
    
	vector<int> lex2 = toDigits(9876543210);
	
	long long sums=0;
	#pragma omp parallel 
	{
	long ownsum=0;
	#pragma omp for schedule(static,1)
	for (int i=0;i<10;i++) {
		vector<int> lex=lex2;
		std::swap(lex[0],lex[i]);
		std::sort(lex.begin()+1,lex.end());
		
		
		while (std::next_permutation(lex.begin()+1,lex.end())) {

			int p=0;
			int divcount=0;
			auto it=primes.begin();
			for(int i=1;i<8;i++) {
				
			
				vector<int> div(lex.end()-3-i,lex.end()-i);
				if (toInt(div)%*it==0) {
					divcount++;

				}
				p++;
				it++;
				

			}
			
			if(divcount==7) {
				long fg=toInt(lex);
				cout<<"Here: "<<fg<<endl;
				ownsum+=fg;
			}

			}
	}
	#pragma omp critical
	{
		sums+=ownsum;
	}
	}

cout<<sums<<endl;

	
	auto end_time = std::chrono::high_resolution_clock::now();
	cout <<"Elapsed: "<< std::chrono::duration_cast<std::chrono::seconds>(end_time - start_time).count() << ".";
	cout << std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count() << " seconds." <<endl;




}