#include <bits/stdc++.h>

using namespace std;

int main()
{
    int step,mod;
    while(cin>>step>>mod)
    {
        if(__gcd(step,mod)==1)
            cout<<setw(10)<<step<<setw(10)<<mod<<string(4,' ')<<"Good Choice"<<endl<<endl;
        else
            cout<<setw(10)<<step<<setw(10)<<mod<<string(4,' ')<<"Bad Choice"<<endl<<endl;
    }
    return 0;
}
