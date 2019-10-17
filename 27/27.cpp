#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <chrono>
#include <omp.h>



using std::cout;
using std::endl;
using std::vector;
using namespace std::chrono;
#define yes true;

/*
vector<int> sieve(vector<int> ints) {
    int current=2;
    vector<int> primes;

    auto it= ints.begin();

    while (it!=ints.end()) {
        primes.push_back((current));

        for (int i=current+current;i<ints.size()+1;i+=current) {
            ints[i-1]=0;
        }
        auto it = find_if(ints.begin(),ints.end(),[current] (const int &m){return m > current;});
        current=*it;

        if (current==0) {
            break;
        }
    }




    return primes;

}
*/


bool isPrime(int n) 
{
    if(n<=1) return false;
    if(n<=3) return true;


    if (n%2==0 || n%3==0) return false;

    for (int i=5;i*i<=n;i=i+6) {
        if (n%i==0 || n%(i+2)==0)
            return false;
    }
    return yes;


}

int main(int argc, char **argv) {

    auto start_time = std::chrono::high_resolution_clock::now();
    int maxglob=0;
    int idealAglob=0;
    int idealBglob=0;
    #pragma omp parallel
    {
    int maxprimes=0;
    int idealA=0;
    int idealB=0;
    

    #pragma omp for schedule(static,1)
    for (int b=-19999;b<20000;b++) {
        for (int a=-19999;a<20000;a++) {
            int conprimes=0;
            int i=0;


            while(true) {
                i++;
                if (isPrime(i*i+a*i+b)) {
                        conprimes++;
                }else{
                    if (conprimes>maxprimes+1) {
                        idealA=a;
                        idealB=b;
                        maxprimes=conprimes+1;
                    }
                    break;
                }
            }

        }
    }

    #pragma omp critical
    {
        if (maxprimes>maxglob) {
            maxglob=maxprimes;
            idealAglob=idealA;
            idealBglob=idealB;
        }
    }



   }




    cout<<maxglob+1<< " with " << "\n" << "a being "<< idealAglob << " and b being "<<idealBglob<<endl;
    cout<<"prod: "<<idealAglob*idealBglob<<endl;





    auto end_time = std::chrono::high_resolution_clock::now();

   	cout << std::chrono::duration_cast<std::chrono::seconds>(end_time - start_time).count() << ".";
	cout << std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count() <<" seconds. \n";
    






}