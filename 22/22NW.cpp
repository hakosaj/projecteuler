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

using std::cout;
using std::endl;
using std::vector;
using std::string;


    int main() {

    std::ifstream myfile;
    myfile.open("names.txt");

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
    


    std::sort(names.begin(),names.end());

    int total=0;
    for (int i=0;i<names.size();i++) {
         int score=0;
        for (char C:names[i]) {
            score+=(int)C-64;
        }
        total+=score*(i+1);
    }
    cout<<total<<endl;


    myfile.close();




}