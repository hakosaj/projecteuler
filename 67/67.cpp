#include <iostream>
#include <vector>
#include <cmath>
#include <bits/stdc++.h> 


using std::cout;
using std::endl;
using std::vector;
using std::string;







int maxSumPath(vector<vector<int>> &A) {

  int memo[A.size()];
  int n=A.size()-1; 

  for (int i=0;i<A[n].size();i++)
    memo[i]=A[n][i];


  for (int i=A.size()-2;i>=0;i--)
    for(int j=0;j<A[i+1].size()-1;j++) {
      memo[j]=A[i][j]+std::max(memo[j],memo[j+1]);
    }

    return memo[0];




}


vector<int> fileRead(string filename) {

    std::ifstream myfile;
    myfile.open(filename);

    if(!myfile) {
        std::cerr<<"Cant open!";
        std::exit(1);
    }

    string line;

    std::vector<int>   data;
    while(std::getline(myfile, line))
    {
        std::stringstream  lineStream(line);

        int value;
        while(lineStream >> value)
        {
            data.push_back(value);
        }
    }

    return data;
}

int main() {


vector<int> lista = fileRead("p067_triangle.txt");


vector<vector<int>> vectors;


int offset=0;
for (int r=0;r<100;r++ ) {
  vector<int> thisone;
    for(int s=0;s<=r;s++) {
      thisone.push_back(lista[s+r+offset]);

  }
  vectors.push_back(thisone);
  offset+=r;
}

cout<<maxSumPath(vectors);






}
