#include <bits/stdc++.h>





long long combi(int n,int k)
{
    long long ans=1;
    k=k>n-k?n-k:k;
    int j=1;
    for(;j<=k;j++,n--)
    {
        if(n%j==0)
        {
            ans*=n/j;
        }else
        if(ans%j==0)
        {
            ans=ans/j*n;
        }else
        {
            ans=(ans*n)/j;
        }
    }
    return ans;
}

int main() 

{

    
    
    std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();




    long long int r = combi(40,20);
    std::cout << r << std::endl;


    std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);

    std::cout <<"\n" << "It took me " << time_span.count()*1000 << " milliseconds.";
    std::cout << std::endl;

    return 0;
}