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
#include <set>

using std::set;
using std::cout;
using std::endl;
using std::vector;
using std::string;


    int main() {

    std::ifstream myfile;
    myfile.open("words.txt");

    if(!myfile) {
        std::cerr<<"Cant open!";
        std::exit(1);
    }


    
    string x;
    vector<string> names;
    myfile>>x;

    string delimiter=",";
    size_t pos=0;
    string token;

    while ((pos=x.find(delimiter))!=string::npos) {
        token=x.substr(0,pos);
        token.erase(std::remove(token.begin(),token.end(),'\"'),
                                token.end());

        names.push_back(token);
        x.erase(0,pos+delimiter.length());
    }
    
myfile.close();

    std::sort(names.begin(),names.end());


    set<int> triangles;

    int t=0;
    int g=1;
    while (t<300) {
        t=g*(g+1)/2;
        triangles.insert(t);
        g++;
    }

    int total=0;
    for (int i=0;i<names.size();i++) {
        int score=0;
        for (char C:names[i]) {
            score+=(int)C-64;
        }
        if (triangles.count(score)) {
            cout<<score<<" is a triangle"<<endl;
            total++;
        }

    }
    cout<<total<<endl;



}