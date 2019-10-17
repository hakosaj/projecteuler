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

using std::cout;
using std::endl;
using std::vector;
using std::string;







int main() {
	auto start_time = std::chrono::high_resolution_clock::now();



	int days[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
	int daysSum=365;

	int daysLeaped[12]=  {31,29,31,30,31,30,31,31,30,31,30,31};
	int daysLeapedSum=366;


	string dayName[7] = {"Mon","Tue","Wed","Thu","Fri","Sat","Sun"};
	string months[12] = {"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
		int week=0;
		int sol=0;
	for (int years=1901;years<1202000;years++) {
		bool leap=false;

		if ( (years%4==0 && years%100!=0) || (years%100==0 && years%400 == 0)) {
			leap =true;
		}
		for (int month=0; month<12; month++) {

			auto daysUsed = leap ? daysLeaped: days;
			for (int day=0;day<daysUsed[month];day++) {

				week++;
				if (week>6){
					week=0;
				}

				if (week==6 && day==0){
				//cout<<"Day: "<<day+1<<" "<<dayName[week]<<" of "<<months[month]<<". Year is then "<< years << endl;
				sol++;
				}



			}



		}	




	}










    
	auto end_time = std::chrono::high_resolution_clock::now();
	cout <<"Elapsed: "<< std::chrono::duration_cast<std::chrono::seconds>(end_time - start_time).count() << ".";
	cout << std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count() << " seconds." <<endl;
	cout<<sol<<endl;




}