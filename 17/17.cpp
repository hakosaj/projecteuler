#include <bits/stdc++.h>
#include <omp.h>


int main(int argc, char **argv) 

{    
    
    std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();



    int last=std::stoi(argv[1]);
    int lettercount=0;



    std::map<int, std::string> lc;
    lc[0]="";
    lc[1]="one";
    lc[2]="two";
    lc[3]="three";
    lc[4]="four";
    lc[5]="five";
    lc[6]="six";
    lc[7]="seven";
    lc[8]="eight";
    lc[9]="nine";
    lc[10]="ten";
    lc[11]="eleven";
    lc[12]="twelve";
    lc[13]="thirteen";
    lc[14]="fourteen";
    lc[15]="fifteen";
    lc[16]="sixteen";
    lc[17]="seveteen";
    lc[18]="eighteen";
    lc[19]="nineteen";
    lc[20]="twenty";
    lc[30]="thirty";
    lc[40]="forty";
    lc[50]="fifty";
    lc[60]="sixty";
    lc[70]="seventy";
    lc[80]="eighty";
    lc[90]="ninety";
    lc[100]="hundred";
    lc[1000]="thousand";

    int ones;
    int tens;
    int hundreds;
    std::string ta = " and ";
    for(int i=1;i<=last;i++) {


        if(i==1000) {lettercount+=(lc[1000].length()+3);}

        else if (i<20) {
            lettercount+=lc[i].length();
            //std::cout<<lc[i]<< " "<< lc[i].length() <<std::endl;
        }


        else if(i<100) {
            tens = i-i%10;
            ones= i%10;
            lettercount +=lc[tens].length();
            lettercount +=lc[ones].length();
            //std::cout<<lc[tens]<< " "<< lc[tens].length() <<std::endl;
            //std::cout<<lc[ones]<< " "<< lc[ones].length() <<std::endl;

        }


        else if (i<1000000000) {
            hundreds = (i-i%100)/100;
            int a=i-hundreds*100;

            if (i%100==0) {

               // std::cout<< "i is: " << i << " "<< lc[hundreds]<< " " << lc[100] << std::endl;
                lettercount +=lc[hundreds].length();
                lettercount +=lc[100].length();
            }
            

            else if (a<20) {


                //std::cout<< "i is: " << i << " "<< lc[hundreds]<< " "
                // << lc[100] << ta <<lc[a] << std::endl;
                 lettercount+=lc[hundreds].length();
                 lettercount+=lc[100].length();
                 lettercount+=ta.length();
                 lettercount+=lc[a].length();
            }
            else{

            tens=a-i%10;
            ones=a%10;
            //std::cout<< "i is: " << i << " "<< lc[hundreds]<< " "
             //<< lc[100] << ta <<lc[tens] << " "<< lc[ones] << std::endl;

            lettercount+=lc[hundreds].length();
            lettercount+=lc[100].length();
            lettercount+=ta.length();
            lettercount+=lc[tens].length();
            lettercount+=lc[ones].length();
            }
        }
    }






    std::cout << "This many: " << lettercount << std::endl;
    std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);

    std::cout <<"\n" << "It took me " << time_span.count()*1000 << " milliseconds.";
    std::cout << std::endl;

    return 0;
}