#include <bits/stdc++.h>

using namespace std;

int main()
{
    int s,m;
    while(cin>>s>>m){
        if(__gcd(s,m)==1)
            cout<<setw(10)<<s<<setw(10)<<m<<"    "<<"Good Choice\n\n";
        else
            cout<<setw(10)<<s<<setw(10)<<m<<"    "<<"Bad Choice\n\n";
    }
    return 0;
}
