#include <bits/stdc++.h>

using namespace std;
long long solve(long long n)
{
    if(n<10)
        return n;
    long long x=n%10,y=0,res=n/10+9;
    while(n)
    {
        y=n%10;
        n/=10;
    }
    if(y>x)
        res--;
    return res;
}
int main()
{
    long long a,b;
    cin>>a>>b;
    cout<<solve(b)-solve(a-1)<<endl;
    return 0;
}
