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
#include <ostream>

using std::ostream;
using std::cout;
using std::endl;
using std::vector;
using std::string;

int gcd(int m, int n) {
    while (m%n != 0) {
        int oldm = m;
        int oldn = n;

        m = oldn;
        n = oldm%oldn;
    }

    return n;
}

class Fraction {
    public:

    long long num;
    long long den;
    Fraction(long long top, long long bottom) {
        num = top;
        den = bottom;
    }

    Fraction operator +(Fraction otherFrac) {
        long long newnum = num*otherFrac.den + den*otherFrac.num;
        long long newden = den*otherFrac.den;
        long long common = gcd(newnum, newden);

        return Fraction(newnum/common,newden/common);
    }

    friend ostream& operator<<(ostream& stream, const Fraction& fraction);
};

ostream & operator<<(ostream& stream, const Fraction& fraction) {
    stream<<fraction.num<<"/"<<fraction.den;

    return stream;
}

int main() {	
	auto start_time = std::chrono::high_resolution_clock::now();
	
	int commonDenom=2;
	Fraction previous=Fraction(0,1);
	Fraction t = Fraction(2,1);

	for (int i=0;i<100;i++) {
		previous=t+previous;
		previous = Fraction(previous.den,previous.num);
		cout<<Fraction(1,1)+previous<<endl;


	}


    
	auto end_time = std::chrono::high_resolution_clock::now();
	cout <<"\nElapsed: "<< std::chrono::duration_cast<std::chrono::seconds>(end_time - start_time).count() << ".";
	cout << std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count() << " seconds." <<endl;




}