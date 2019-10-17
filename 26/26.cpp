#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <sstream>

using std::cout;
using std::endl;
using std::vector;
using std::ostringstream;



int main(int argc, char **argv) {
    for (int i=2;i<10;i++) {
        double a=1.0*i;
        double b=(1.0/a);
        ostringstream ss;
        ss<<(b);
        std::string s(ss.str());
        s=s.erase(0,2);

        if(s.length()>3) {
        cout<<s.length()<< " ja ";
        cout<<s<<endl;
        }

    }





}