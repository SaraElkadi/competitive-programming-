#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n,m,k,w=0;
    cin>>n>>m>>k;
    if(n>m)
        swap(n,m);
    if(k>m+n-2)
        cout<<-1;
    else if(k>=m)
        cout<<n/(k-m+2);
    else if(k>=n)
        cout<<n*(m/(k+1));
    else
        cout<<max(n*(m/(k+1)),m*(n/(k+1)));
    return 0;
}
