#include<iostream>
#include<thread>
#include<chrono>
#include<algorithm>
using namespace std::chrono;
using namespace std;
typedef unsigned long long ull;
ull oddSum=0;
ull evenSum=0;

void findeven(ull start,ull end)
{
    for(ull i=start; i<=end; i++)
    {
        if(i%2==0)
            evenSum+=i;
    }
}

void findodd(ull start,ull end)
{
    for(ull i=start; i<=end; i++ )
    {
        if(i%2==1)
            oddSum+=i;
    }
}

int main()
{
    ull start=0;
    ull end=1900000000;
    auto starttime=high_resolution_clock::now();

   // std::thread t1(findeven,start,end);
    //std::thread t2(findodd,start,end);
    //t1.join();
    //t2.join();

    findeven(start,end);
    findodd(start,end);
    auto stoptime=high_resolution_clock::now();
    auto duration=duration_cast<seconds>(stoptime-starttime);

    cout<<"Sums are: "<<endl<<evenSum;
    cout<<endl<<oddSum;
    cout<<endl<<duration.count();//18 seconds without threads
    return 0;
}
