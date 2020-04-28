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

vector<vector<string>> readFile() {

    std::ifstream myfile;
    myfile.open("smallpoker.txt");

    if(!myfile) {
        std::cerr<<"Cant open!";
        std::exit(1);
    }

	string delimiter=" ";
	vector<vector<string>> hands;
    size_t pos=0;
    string token;

	    while (getline(myfile,token))
		{
			vector<string> hand1;
			vector<string> hand2;
			int i=0;
			std::stringstream ss(token);
			while (ss.good()) { 
				string substr; 
				getline(ss, substr, ' '); 
				i++;
				if (i>5) {
					hand2.push_back(substr);
				}else {
					hand1.push_back(substr);
				}
			}
			hands.push_back(hand1);
			hands.push_back(hand2);
		}	 
	myfile.close();
	return hands;
	
}

//Map of cards to values
std::map<char,int> cardValue = {
	{'1',1},
	{'2',2},
	{'3',3},
	{'4',4},
	{'5',5},
	{'6',6},
	{'7',7},
	{'8',8},
	{'9',9},
	{'T',10},
	{'J',11},
	{'Q',12},
	{'K',13},
	{'A',14},
};


int calculateHandValue(vector<string> hand) {
	vector<std::pair<int, char>> cards;
	for (auto card: hand) {
		cout<<"Suit is "<<char(card[1])<<" and value is "<<cardValue[card[0]]<<endl;
		cards.push_back(std::make_pair(cardValue[card[0]],char(card[1])));
	}


	return 0;
}


int main() {
	auto start_time = std::chrono::high_resolution_clock::now();
	auto hands=	readFile();

	for (auto hand: hands) {
		for (string s:hand) {
			//cout<<s<<" ";
		}
		//cout<<"\n";

	}

	calculateHandValue(hands[0]);

	





	auto end_time = std::chrono::high_resolution_clock::now();
	cout <<"Elapsed: "<< std::chrono::duration_cast<std::chrono::seconds>(end_time - start_time).count() << ".";
	cout << std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count() << " seconds." <<endl;




}