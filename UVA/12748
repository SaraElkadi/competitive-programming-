#include <bits/stdc++.h>

using namespace std;
struct circle
{
    double x,y,r;
};
struct point
{
    double x,y;
};
bool chheckinCircle(point p,circle c)
{
    return (p.x-c.x)*(p.x-c.x)+(p.y-c.y)*(p.y-c.y)<=c.r*c.r;
}
int main()
{
    int t,n,y,k=1;
    cin>>t;
    while(t--)
    {
        cout<<"Case "<<k++<<":"<<endl;
        cin>>n>>y;
        circle c[n];
        point p;
        for(int i=0; i<n; i++)
        {
            cin>>c[i].x>>c[i].y>>c[i].r;
        }
        for(int i=0; i<y; i++)
        {
            cin>>p.x>>p.y;
            bool f=0;
            for(int j=0; j<n; j++)
            {
                if(chheckinCircle(p,c[j]))
                {
                    f=1;
                    break;
                }
            }
            if(f)
                cout<<"Yes"<<endl;
            else
                cout<<"No"<<endl;
        }
    }

    return 0;
}
