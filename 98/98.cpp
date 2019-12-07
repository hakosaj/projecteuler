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

using std::cout;
using std::endl;
using std::vector;
using std::string;


vector<vector<string>> readFile() {


vector<vector<string>> data;
  std::ifstream infile( "data.txt" );
  while (infile)
  {
    string s;
    if (!getline( infile, s )) break;

    std::istringstream ss( s );
    vector <string> record;

    while (ss)
    {
      string s;
      if (!getline( ss, s, ',' )) break;
      record.push_back( s );
    }

    data.push_back( record );
  }

	return data;
}



vector<long> primes=vector<long>{2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101};
vector<char> characters = vector<char>{'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};



  std::unordered_map<char,long> createLettermap() {
  	std::unordered_map<char,long> lettermap= std::unordered_map<char,long>();

	  for(int a=0;a<characters.size();a++) {
		  lettermap.insert({characters[a],primes[a]});
	  }
	return lettermap;
  } 


long long hash(string word,std::unordered_map<char,long> lettermap) {
	long long hashvalue=1;
	auto w2=word.substr(1,string::npos);
	w2.pop_back();
	for (char& c:w2) {
		hashvalue*=lettermap.at(c);

	}
	return hashvalue;

}


int main() {
	auto start_time = std::chrono::high_resolution_clock::now();
  	std::unordered_map<long long,vector<string>> hashes=std::unordered_map<long long,vector<string>>();

  auto lettermap = createLettermap();

  auto data=readFile();
  vector<string> strings= vector<string>();
  
  for(auto const& d: data) {
	  for(auto const& e: d) {
		  strings.push_back(e);
		  long long hashv=hash(e,lettermap);
		  //if in the map
		  if (hashes.count(hashv)) {
			  vector<string> old = hashes.at(hashv);
			  old.push_back(e);
			  hashes.insert({hashv,old});

		  }else {
			  hashes.insert({hashv,vector<string>{e}});
		  }
	  }
  }

  for (auto const& x : hashes)
	{
		cout<<x.first<<": ";
		for(auto const& a:x.second) {
			cout<<a<<", ";
		}

	cout<<"\n";
	}








    
	auto end_time = std::chrono::high_resolution_clock::now();
	cout <<"Elapsed: "<< std::chrono::duration_cast<std::chrono::seconds>(end_time - start_time).count() << ".";
	cout << std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count() << " seconds." <<endl;




}