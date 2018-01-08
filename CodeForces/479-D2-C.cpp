#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,k=0;
    cin>>n;
    pair<int,int> p[n];
    for(int i=0;i<n;i++)
        cin>>p[i].first>>p[i].second;
    sort(p,p+n);
    for(int i=0;i<n;i++){
        if(p[i].second>=k)
            k=p[i].second;
        else
            k=p[i].first;
    }
    cout<<k;
    return 0;
}
