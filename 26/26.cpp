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
#include <map>

using std::map;
using std::cout;
using std::endl;
using std::vector;
using std::string;





string fractionToDecimal(int numr, int denr) 
{ 
	string res; // Initialize result 

	map <int, int> mp; 
	mp.clear(); 

	int rem = numr%denr; 

	while ( (rem!=0) && (mp.find(rem) == mp.end()) ) 
	{ 
		mp[rem] = res.length(); 
		rem = rem*10; 
		int res_part = rem / denr; 
		res += std::to_string(res_part); 
		rem = rem % denr; 
	} 

	return (rem == 0)? "" : res.substr(mp[rem]); 
} 



int main() {
	auto start_time = std::chrono::high_resolution_clock::now();

	int maxl=0;
	string maxs;
	int maxd=0;
	for (int i=1;i<1000;i++) {
		string s=fractionToDecimal(1,i);
		if (s.length()>maxl) {
			maxl=s.length();
			maxs=s;
			maxd=i;
		}
	}	
	cout<<"Longest is the number 1/"<<maxd<<" with a decimal expansion "<<maxs<<" of length "<<maxl<<endl;








    
	auto end_time = std::chrono::high_resolution_clock::now();
	cout <<"Elapsed: "<< std::chrono::duration_cast<std::chrono::seconds>(end_time - start_time).count() << ".";
	cout << std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count() << " seconds." <<endl;




}