#include <bits/stdc++.h>

void printDigits(std::vector<int> digits) {
    for (auto it=digits.begin();it!=digits.end();it++){
        std::cout << *it << " ";
    }
    std::cout<< "\n";

}


std::vector<int> normalizeDigits(std::vector<int> digits, int base) {

    for (int i=0;i<digits.size();i++) {
        if(digits[i]>=10) {
            digits[i]-=10;
            try 
            {
                digits.at(i+1)+=1;
            }
            catch (const std::out_of_range& oor) {
                digits.push_back(1);
            }

            
        }
    }
    return digits;
}


int main(int argc, char **argv) 

{    
    
    std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();


    std::vector<int> digits;
    digits.push_back(2);


    int multiplier=2;
    int base=10;
    int power=std::stoi(argv[1]);
    int digitsum=0;

    for (int i=0;i<power-1;i++) {
        std::for_each(digits.begin(),digits.end(),[multiplier](int &n){n*=multiplier;});
        digits=normalizeDigits(digits,base);
        while (std::any_of(digits.begin(),digits.end(), [](int i){return i>9;})) {
            digits=normalizeDigits(digits,base);
             }

    }


    printDigits(digits);
    for (auto& n : digits)
        digitsum+=n;
        
    std::cout << "Digitsum: " << digitsum << std::endl;
        


    


    std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);

    std::cout <<"\n" << "It took me " << time_span.count()*1000 << " milliseconds.";
    std::cout << std::endl;

    return 0;
}