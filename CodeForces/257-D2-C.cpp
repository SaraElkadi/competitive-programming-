#include <bits/stdc++.h>
#define PI acos(-1.0)

using namespace std;
const int MAX=100005;
#define EPS 1e-8
double ang[MAX];
int main()
{
   int n,x,y;
   cin>>n;
   for(int i=0;i<n;i++){
    cin>>x>>y;
    ang[i]=atan2(y,x);
   }
   sort(ang,ang+n);
   double ans=ang[n-1]-ang[0];
   for(int i=0;i<n-1;i++){
    ans=min(ans,2*PI-(ang[i+1]-ang[i]));
   }
   cout<<fixed<<setprecision(15)<<ans/PI*180;
    return 0;
}
