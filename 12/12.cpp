#include <bits/stdc++.h>
#include <chrono>


#define foreach for_each







int countDivisorsNaiveSqrt(long int n) {
    long int a = (int)std::sqrt(n);
    int divisors =0;
    for (int i=1; i < a; i++) {

        if (n%i==0) {
            if (n/i == i) {
                divisors++;

            }
            else {
                divisors +=2;
            }
        }
    }

 return divisors;
}



int main()
{
    std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();


long int triangle=0;
int divisors1=0;
int divisors2=0;
/*
int i=1;

while (divisors<500){

    triangle +=i;
    divisors=countDivisorsNaiveSqrt(triangle);
    i++;

}*/



for (long i=1; i<1000000000000;i+=2)
{
        triangle += i+i-1;

        #pragma omp task
        {
            divisors1 =countDivisorsNaiveSqrt(triangle);
        }

        #pragma omp task
        {
            divisors2=countDivisorsNaiveSqrt(triangle+i+1);
        }
        
        

    if (divisors1  >500) {
        std::cout << triangle << std::endl;
        break;
    }
        if (divisors2  >500) {
        std::cout << triangle+i+1 << std::endl;
        break;
    }
}







    
    std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();

  std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);

  std::cout << "It took me " << time_span.count()*1000 << " milliseconds.";
  std::cout << std::endl;
return 0;
}