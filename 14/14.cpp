#include <bits/stdc++.h>




int collatz (long n, int depth) {
    depth +=1;
        if (n%2==0) {collatz(n/2,depth);}
        else if(n==1) {return depth;}
        else {collatz(3*n +1,depth);}

}



int collatzPrint (long n, int depth) {
    std::cout << n << "->";
    depth +=1;
        if (n%2==0) {collatzPrint(n/2,depth);}
        else if(n==1) {return depth;}
        else {collatzPrint(3*n +1,depth);}
    


}


int main() 

{

    
    
    std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();

    int deep=0;
    long highest=0;
    for (int i=1;i<1000000;i++) {
        long a=collatz(i,0);
        if (a>deep) {deep=a; highest=i;}
    }



    std::cout << "Depth: "<< deep << std::endl;
    std::cout << "Integer: " << highest << std::endl;


    std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);

    std::cout <<"\n" << "It took me " << time_span.count()*1000 << " milliseconds.";
    std::cout << std::endl;

    return 0;
}