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
#include <unordered_map>
#include <set>

using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::set;

void printVector(vector<long> a) {
	for (const auto &n: a) {
		cout<<n<<",";
	}
	cout<<"\n";

}
vector<long> primeFactors(long n)
{
	vector<long> factors;
	while (n%2==0) {
		factors.push_back(2);
		n=n/2;
	}
    for (long i = 3; i <= sqrt(n); i = i + 2)  
    {  
        while (n % i == 0)  
        {  
            factors.push_back(i);  
            n = n/i;  
        }  
    }  

	if (n>2) {
		factors.push_back(n);
	}
	return factors;
}

bool isPrime(int n) 
{
    if(n<=1) return false;
    if(n<=3) return true;


    if (n%2==0 || n%3==0) return false;

    for (int i=5;i*i<=n;i=i+6) {
        if (n%i==0 || n%(i+2)==0)
            return false;
    }
    return true;


}

int nextPrime(int n) {
	while ( true) {
		n++;
		if (isPrime(n)) {
			return n;
		}

	}
}

vector<long> uniques(vector<long> a) {
	set<long> s(a.begin(),a.end());
	a.assign(s.begin(),s.end());
	return a;
}


int main() {
	auto start_time = std::chrono::high_resolution_clock::now();



	for (int i=3;i<100000;i+=2) {
		if (!isPrime(i)) {
			//is composite. Start from the first prime and the square of 1
			int primeComponent =1;
			int squareComponent =1;

			bool found=false;
			while (primeComponent<i-2 && !found) {
				
				
				while (primeComponent+2*squareComponent*squareComponent<i) {
					squareComponent++;
				}
				if (primeComponent+2*squareComponent*squareComponent==i) {
					found=true;
				}
				primeComponent=nextPrime(primeComponent);
				squareComponent=1;
			
			
			}
			if (!found) {
				cout<<i<<endl;
			}

		}
	}



	
	auto end_time = std::chrono::high_resolution_clock::now();
	cout <<"Elapsed: "<< std::chrono::duration_cast<std::chrono::seconds>(end_time - start_time).count() << ".";
	cout << std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count() << " seconds." <<endl;




}