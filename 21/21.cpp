#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <omp.h>


using std::cout;
using std::endl;
using std::vector;

int getDivisorSum(int n) {
    int counter=0;
    for (int i=1;i<(n/2)+1;i++)
        if(n%i==0) {
            counter+=i;
        }

    return counter;


}

int isAmicable(int n) {

    int r=getDivisorSum(n);
    if (r!=n) {
        if (getDivisorSum(r)==n) {
            cout<< "Amicable pair: "<<n << " and " << r <<endl; 
            return true;
        }
    }
    return false;

}


int main(int argc, char** argv) {

    int limit=std::stoi(argv[1]);

    vector<int> numbers;
    for (int i=1;i<=limit;i++) {
        numbers.push_back(i);
    }
    int amicableSum=0;
    for (int i: numbers) {
        if (isAmicable(i)) {
            numbers.erase(std::remove(numbers.begin(),numbers.end(),i),numbers.end());
            numbers.erase(std::remove(numbers.begin(),numbers.end(),getDivisorSum(i)),numbers.end());
            amicableSum+=(i+getDivisorSum(i));
        }
    }
cout<<"Sum: "<<amicableSum << endl;



}
