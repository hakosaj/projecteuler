#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <omp.h>
#include <fstream>
#include <string>
#include <unordered_set>
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


bool isprime(int n) 
{ 
    if (n <= 1) 
        return false; 
    if (n <= 3) 
        return true; 
  
    if (n % 2 == 0 || n % 3 == 0) 
        return false; 
  
    for (int i = 5; i * i <= n; i = i + 6) 
        if (n % i == 0 || n % (i + 2) == 0) 
            return false; 
  
    return true; 
}

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
    for (int i: digits  ) {
        cout<<i<<",";
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

vector<int> powerWithTrim(vector<int> digits, int p, int lastDigits) {
	vector<int> base = digits;
	for (int i=1;i<p;i++) {
		digits=trimToLastDigits(multiplyVectors(digits,base),lastDigits);
	}
	return digits;
}

vector<int> power(vector<int> digits, int p) {
	vector<int> base = digits;
	for (int i=1;i<p;i++) {
		digits=multiplyVectors(digits,base);
		digits=scaleToBaseN(digits,10);
		printVector(digits);
	}
	return digits;
}

long digitCount(vector<int> base) {
	return std::accumulate(base.begin(),base.end(),0);
}

template <typename T>
void print( T a)
{
   cout<<a<<endl;
}


vector<string> split(string s, string delimiter) {
	size_t pos = 0;
	vector<string> splitt;
	std::string token;
	while ((pos = s.find(delimiter)) != std::string::npos) {
    token = s.substr(0, pos);
	splitt.push_back(token);
    s.erase(0, pos + delimiter.length());
	}
	splitt.insert(splitt.begin(),s);
	return splitt;
}

vector<int> splitInts(string s, string delimiter) {
	size_t pos = 0;
	vector<int> splitt;
	std::string token;
	while ((pos = s.find(delimiter)) != std::string::npos) {
    token = s.substr(0, pos);
	splitt.push_back(std::stoi(token));
    s.erase(0, pos + delimiter.length());
	}
	splitt.push_back(std::stoi(s));
	return splitt;
}


string eraseChar(string myText, string del) {
	myText.erase(remove_if(myText.begin(), myText.end(), isspace), myText.end());
	return myText;
}


template <typename F>
vector<F> readfile(string filename) {
  string myText;
  vector<F> contents;

  std::fstream fileToRead(filename, std::ios::in);

  while (std::getline(fileToRead, myText)) {
	  vector<int> line;
	  //Remove spaces
	  myText=eraseChar(myText,"ta");
      //Replace all dashes with 0
	  std::replace( myText.begin(), myText.end(), '-', '0');
	  line=splitInts(myText,",");
		contents.push_back(line);
	}

  fileToRead.close();
  return contents;
}

struct Node {
  int id;
};
struct Edge {
  int weight;
  int id;
  Node v1;
  Node v2;
} ;

struct Graph{
	int totalVertices;
	int totalEdges;
	std::unordered_map<int,Edge> edges;
	std::unordered_map<int,Node> vertices;
	std::unordered_map<Node,vector<int>
};
inline bool operator<(const Edge& lhs, const Edge& rhs)
{
  return lhs.id < rhs.id;
}
inline bool operator<(const Node& lhs, const Node& rhs)
{
  return lhs.id < rhs.id;
}


int totalWeight(Graph g) {
	int l=0;
	for (const auto &a:g.edges) {
		l+=a.second.weight;
	}
	return l;

}
int Prim(Graph G) {
	Node start=G.vertices[0].second;
	std::unordered_map<int,int> prim;

	for (const auto b&:G.vertices) {
		cout<<"Vertex: "<<b.second

	}
}

int main() {	


	auto start_time = std::chrono::high_resolution_clock::now();
	int counter=0;
	auto contents=readfile<vector<int>>("test.csv");
	Graph G;
	G.totalVertices=contents.size();
	for (int i=0;i<G.totalVertices;i++) {
		Node n;
		n.id=i;
		G.vertices.insert(std::pair<int,Node>(i,n));
	}

	int edges=0;
	int a=1;
	int edgeids=0;
	for (int g=0;g<contents.size();g++) {
		for (int v=0;v<a;v++) {

		//If edge exists, we add it
		if (contents[g][v]) {
			edges++;
			Edge a;
			a.weight=contents[g][v];
			a.id=edgeids;
			edgeids++;
			a.v1=G.vertices[g];
			a.v2=G.vertices[v];
			G.edges.insert(std::pair<int,Edge>(edgeids,a));
		};
		}
		a++;
	}
	print(edges);
	G.totalEdges=edges;

	print(totalWeight(G));




	auto end_time = std::chrono::high_resolution_clock::now();
	cout <<"\nElapsed: "<< std::chrono::duration_cast<std::chrono::seconds>(end_time - start_time).count() << ".";
	cout << std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count() << " seconds." <<endl;




}