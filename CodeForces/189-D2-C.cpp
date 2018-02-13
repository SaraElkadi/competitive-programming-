#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,cnt=0;
    cin>>n;
    int a[n],b;
    vector<int> v;
    for(int i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i=0; i<n; i++)
    {
        scanf("%d",&b);
        v.push_back(b);
    }
    int idx=0;
    for(int i=0;i<n;i++){
        auto it=find(v.begin()+idx,v.end(),a[i]);
        if(it==v.end())
            break;
        idx=it-v.begin()+1;
        cnt++;
    }
    printf("%d",n-cnt);
    return 0;
    }
