#include <bits/stdc++.h>

using namespace std;
#define PI 2*acos(0.0)
int main()
{
    int n;
    cin>>n;
    pair<int,int> p[n];
    pair<double,pair<double,int> > ans[n];
    for(int i=0;i<n;i++){
        cin>>p[i].first>>p[i].second;
        double theta=atan2(p[i].second,p[i].first);
        if(theta<0)
            theta+=2*PI;
        ans[i].first=theta;
        ans[i].second.first=p[i].first*p[i].first+p[i].second*p[i].second;
        ans[i].second.second=i;
    }
    sort(ans,ans+n);
    for(int i=0;i<n;i++){
        int idx=ans[i].second.second;
        cout<<p[idx].first<<" "<<p[idx].second<<endl;
    }
    return 0;
}
