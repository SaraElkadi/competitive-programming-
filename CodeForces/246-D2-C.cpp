#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;
    int a[n];
    for(int i=0; i<n; i++)
        cin>>a[i];
    sort(a,a+n,greater<int>());
    int w=1;
    while(k)
    {

        for(int j=w-1; j<n&&k; j++)
        {
            cout<<w;
            for(int i=0; i<w-1&&k; i++)
                cout<<" "<<a[i];
            cout<<" "<<a[j]<<endl;
            k--;
        }
        w++;
    }
}
