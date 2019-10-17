#include <iostream>
#include <vector>
#include <cmath>
#include <bits/stdc++.h> 


using std::cout;
using std::endl;
using std::vector;






struct Node
{
    int data;
    Node *left, *right;

    Node(int data)
    {
        this->data = data;
        this->left=this->right=nullptr;
    }

};



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


int main() {

const vector<int> lista{75,95,64,17,47,82,18,35,87,10,20,4,82,47,65,19,1,23,75,3,34,88,02,77,73,07,63,67,99,65,4,28,06,16,70,92,41,41,26,56,83,40,80,70,33,41,48,72,33,47,32,37,16,94,29,53,71,44,65,25,43,91,52,97,51,14,70,11,33,28,77,73,17,78,39,68,17,57,91,71,52,38,17,14,91,43,58,50,27,29,48,63,66,4,68,89,53,67,30,73,16,69,87,40,31,4,62,98,27,23,9,70,98,73,93,38,53,60,4,23,1};

vector<vector<int>> vectors;


int offset=0;
for (int r=0;r<15;r++ ) {
  vector<int> thisone;
    for(int s=0;s<=r;s++) {
      cout<<lista[s+r+offset]<<" ";
      thisone.push_back(lista[s+r+offset]);

  }
  vectors.push_back(thisone);
  cout<<"\n";
  offset+=r;
}

cout<<maxSumPath(vectors);






}
