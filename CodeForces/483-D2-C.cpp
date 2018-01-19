#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;
    int f=1,l=1;
    cout<<l;
    for(int i=k;i>=1;i--){
        l+=f*i;
        cout<<" "<<l;
        f*=-1;
    }
    for(int i=k+2;i<=n;i++)
        cout<<" "<<i;
    return 0;
}
