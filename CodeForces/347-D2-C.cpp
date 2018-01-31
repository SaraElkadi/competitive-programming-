#include <bits/stdc++.h>

using namespace std;
int gcd(int a,int b)
{
    if(b==0)return a;
    return gcd(b,a%b);
}
int main()
{
    int n,g=0;
    cin>>n;
    int a[n],mx=0;
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
        mx=max(mx,a[i]);
        g=gcd(g,a[i]);
    }
    if((mx/g-n)%2)
        cout<<"Alice";
    else
        cout<<"Bob";
    return 0;
}
