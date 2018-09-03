#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,h;
    cin>>n>>h;
    pair<int,int> a[n];
    for(int i=0; i<n; i++)
    {
        cin>>a[i].first;
        a[i].second=i;
    }
    if(n==2){
        cout<<0<<endl<<"2 2"<<endl;
        return 0;
    }
    sort(a,a+n);
    int mn=a[0].first+a[1].first;
    int mx=a[n-1].first+a[n-2].first;
    int mx1=max(mx,a[0].first+a[n-1].first+h);
    int mn1=min(mn+h,a[1].first+a[2].first);
    if(mx1-mn1<mx-mn)
    {
        cout<<mx1-mn1<<endl;
        for(int i=0; i<n; i++)
        {
            if(a[0].second==i)
                cout<<1<<" ";
            else
                cout<<2<<" ";
        }
    }
    else
    {
        cout<<mx-mn<<endl;
        for(int i=0; i<n; i++)
            cout<<2<<" ";
    }
    return 0;
}
