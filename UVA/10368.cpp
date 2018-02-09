#include <bits/stdc++.h>

using namespace std;
long long gcd(long long a,long long b){
if(!b)
    return 0;
if(a>=2*b)
    return 1;
return gcd(b,a%b)+1;
}
int main()
{
    long long a,b;
    while(cin>>a>>b&&(a||b)){
        if(a<b)
            swap(a,b);
        int k=gcd(a,b);
        if(k%2)
            cout<<"Stan wins"<<endl;
        else
            cout<<"Ollie wins"<<endl;
    }
    return 0;
}
