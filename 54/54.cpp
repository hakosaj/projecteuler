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

int checkMultiplies(vector<int> values) {
	//Check multiples
	std::map<int,int> counts;

	for (auto val: values) {
		if (counts.count(val)==0) {
			counts.insert({val,1});
		}
		else {
			counts[val]++;
		}

	}
	vector<int> cts;
	for (auto c: counts) {
		cts.push_back(c.second);
	}

	//ascending
	std::sort(cts.begin(),cts.end(),std::greater<int>());

	if (cts[0]==4) {
		cout<<"quads"<<endl;
		return 7;
	}

	else if (cts[0]==3 && cts[1]==2) {
		cout<<"full house"<<endl;
		return 6;
	}

	else if (cts[0]==3 && cts[1]==1 && cts[2]==1) {
		cout<<"threeoffakind"<<endl;
		return 3;
	}

	else if (cts[0]==2 && cts[1]==2 && cts[2]==1) {
		cout<<"two pairs"<<endl;
		return 2;
	}

	else if (cts.size()==4) {
		cout<<"pair"<<endl;
		return 1;
	}
	else {
		cout<<"no multiplies"<<endl;
		return 0;
	}
}

bool isStraight(vector<int> values) {
	std::sort(values.begin(),values.end());
	for(auto a:values) {
		//cout<<a<<endl;
	}
	int diff=abs(values[0]-values[4]);
	if (diff==4){
		return true;
	}else {
	return false;
	}



}

int highestCard(vector<string> hand) {
	
	vector<int> values;
	for (auto card: hand) {
		values.push_back(cardValue[card[0]]);
	}
	std::sort(values.begin(),values.end());
	cout<<"Highest card: "<<values[4]<<endl;
	return values[4];

}

int calculateHandValue(vector<string> hand) {
	vector<std::pair<int, char>> cards;
	vector<int> values;
	vector<int> suits;
	std::set<int> suitSet;
	std::copy(suitSet.begin(),suitSet.end(),std::back_inserter(suits));
	int handValue=0;

	for (auto card: hand) {
		cards.push_back(std::make_pair(cardValue[card[0]],char(card[1])));
		values.push_back(cardValue[card[0]]);
		suits.push_back(char(card[1]));
	}
	handValue+=checkMultiplies(values);
	bool isFlush=false;
	if (suitSet.size()==1) {
		isFlush=true;
	}
	bool straight=false;
	straight= isStraight(values);

	if(isFlush&&isStraight) {
		cout<<"Straight flush"<<endl;
		handValue+=8;
	}if(isFlush) {
		cout<<"Flush"<<endl;
		handValue+=5;
	}if(straight) {
		cout<<"Straight"<<endl;
		handValue+=4;
	}

	if(handValue==0) {
		cout<<"no hand, highest card"<<endl;
	}
	//cout<<"Hand value: "<<handValue<<endl;
	return handValue;
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
	cout<<"Hand 1: "<<endl;
	int handv1=calculateHandValue(hands[0]);
	int handm1=highestCard(hands[0]);
	cout<<"\nHand 2: "<<endl;
	int handv2=calculateHandValue(hands[1]);
	int handm2=highestCard(hands[1]);


	





	auto end_time = std::chrono::high_resolution_clock::now();
	cout <<"Elapsed: "<< std::chrono::duration_cast<std::chrono::seconds>(end_time - start_time).count() << ".";
	cout << std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count() << " seconds." <<endl;




}