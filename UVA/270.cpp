#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> point;
point points[705],v;
#define x first
#define y second
int gcd(int a,int b)
{
    if(b==0)
        return a;
    return gcd(b,a%b);
}
void normal(point p0,point p1,point &v)
{
    v.x=p1.x-p0.x;
    v.y=p1.y-p0.y;
    int a=gcd(abs(v.x),abs(v.y));
    v.x/=a;
    v.y/=a;
    if(v.x<0) v.x*=-1,v.y*=-1;
}
int solve(int n)
{
    int mx=0;
    if(n<3)
        return n;
    while(n-->2)
    {
        map<int,int> mp;
        for(int i=0; i<n; i++)
        {
            normal(points[n],points[i],v);
            mp[v.x*1000000+v.y]++;
            if(mp[v.x*1000000+v.y]>mx)
                mx=mp[v.x*1000000+v.y];
        }
    }
    return mx+1;
}
int main()
{
    int n,t;
    bool f=0;
    string s;
    cin>>t;
    getline(cin,s);
    getline(cin,s);
    while(t--)
    {
        if(f)
            cout<<endl;
        f=1;
        getline(cin,s);
        int n=0;
        while(s.size())
        {
            istringstream ss(s);
            ss>>points[n].x>>points[n].y;
            n++;
            if(cin.eof()) break;
            getline(cin,s);
        }
        cout<<solve(n)<<endl;
    }
    return 0;
}
