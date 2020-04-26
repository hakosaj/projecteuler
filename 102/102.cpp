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



void printVector(vector<int> a) {
	for (const auto &n: a) {
		cout<<n<<",";
	}
	cout<<"\n";
}

vector<int> readFile() {

    std::ifstream myfile;
    myfile.open("triangles.txt");

    if(!myfile) {
        std::cerr<<"Cant open!";
        std::exit(1);
    }

	string delimiter=",";
	vector<int> coords;
    size_t pos=0;
    string token;

	    while (getline(myfile,token))
   		{
			   std::stringstream ss(token);
			       while (ss.good()) { 
						string substr; 
						getline(ss, substr, ','); 
						coords.push_back(std::stoi(substr)); 
    					}	 
				
    	} 

    
myfile.close();
return coords;

	
}

int main() {
	auto start_time = std::chrono::high_resolution_clock::now();
	vector<int> coords = readFile();
	vector<int> x;
	vector<int> y;
	bool xl=true;
	for (int s:coords) {
		if (xl) {
			x.push_back(s);
			xl=false;
		}else {
			y.push_back(s);
			xl=true;
		}
		
	}
	int tot=0;
	for (int i=0; i<x.size();i+=3) {
		float p1x=x[i];
		float p2x=x[i+1];
		float p3x=x[i+2];
		float p1y=y[i];
		float p2y=y[i+1];
		float p3y=y[i+2];

		float alpha = ((p2y - p3y)*( -p3x) + (p3x - p2x)*(-p3y)) /
        ((p2y - p3y)*(p1x - p3x) + (p3x - p2x)*(p1y - p3y));
		float beta = ((p3y - p1y)*(-p3x) + (p1x - p3x)*(-p3y)) /
       ((p2y - p3y)*(p1x - p3x) + (p3x - p2x)*(p1y - p3y));
		float gamma = 1.0f - alpha - beta;

		if (alpha>0 && beta>0 && gamma>0) {
			tot++;
		}
	}

	cout<<tot<<endl;
	auto end_time = std::chrono::high_resolution_clock::now();
	cout <<"Elapsed: "<< std::chrono::duration_cast<std::chrono::seconds>(end_time - start_time).count() << ".";
	cout << std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count() << " seconds." <<endl;




}