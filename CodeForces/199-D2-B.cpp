#include <bits/stdc++.h>

using namespace std;
typedef pair<double,double> point;
#define X first
#define Y second
bool interset(point c1,point c2,double r1,double r2)
{
    double disX=c1.X-c2.X;
    double disY=c1.Y-c2.Y;
    double rsum=r1+r2;
    double rdiff=r1-r2;
    return ((disX*disX+disY*disY<rsum*rsum)&&(!(disX*disX+disY*disY<=rdiff*rdiff)));
}
int main()
{
    point c1,c2;
    int r1,R1,r2,R2;
    cin>>c1.X>>c1.Y>>r1>>R1>>c2.X>>c2.Y>>r2>>R2;
   int ans=0;
    int f1=1,f2=1;
    for(int i=r1;i<=R1;i++){
        if(interset(c1,c2,i,r2))
            f1=0;
        if(interset(c1,c2,i,R2))
            f2=0;
    }
    ans=f1+f2;
     f1=1,f2=1;
    for(int i=r2;i<=R2;i++){
        if(interset(c1,c2,r1,i))
            f1=0;
        if(interset(c1,c2,R1,i))
            f2=0;
    }
    ans+=f1+f2;
    cout<<ans;
    return 0;
}
