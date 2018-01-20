#include <bits/stdc++.h>

using namespace std;
double EPS=1e-2;
struct point
{
    double x,y;
    point()
    {
        x=y=0;
    }
    point(double _x,double _y):x(_x),y(_y) {}
};
struct vec
{
    double x, y;
    vec(double _x, double _y) : x(_x), y(_y) {}
};
vec toVec(point a, point b)
{
    return vec(b.x - a.x, b.y - a.y);
}
vec scale(vec v, double s)
{
    return vec(v.x * s, v.y * s);
}
point translate(point p, vec v)
{
    return point(p.x + v.x , p.y + v.y);
}
double dist(point p1,point p2)
{
    return  hypot(p1.x - p2.x, p1.y - p2.y);
}
double dot(vec a, vec b)
{
    return (a.x * b.x + a.y * b.y);
}
double norm_sq(vec v)
{
    return v.x * v.x + v.y * v.y;
}
double distToLine(point p, point a, point b, point &c)
{
    vec ap = toVec(a, p), ab = toVec(a, b);
    double u = dot(ap, ab) / norm_sq(ab);
    c = translate(a, scale(ab, u));
    return dist(p, c);
}

double distToLineSegment(point p, point a, point b, point &c)
{
    vec ap = toVec(a, p), ab = toVec(a, b);
    double u = dot(ap, ab) / norm_sq(ab);
    if (u < 0.0)
    {
        c = point(a.x, a.y);
        return dist(p, a);
    }
    if (u > 1.0)
    {
        c = point(b.x, b.y);
        return dist(p, b);
    }
    return distToLine(p, a, b, c);
}
int main()
{
    double xm,ym,x,y;
    int n;
    while(cin>>xm>>ym)
    {
        double mn=100000000000;
        point p=point(xm,ym),p1;
        cin>>n;
        point pp[n+1];
        for(int i=0; i<=n; i++)
        {
            cin>>x>>y;
            pp[i]=point(x,y);
        }
        for(int i=0; i<n; i++)
        {
            double d=distToLineSegment(p,pp[i],pp[i+1],p1);
            if(d<mn)
            {
                mn=d;
                x=p1.x;
                y=p1.y;
            }
        }
        cout<<fixed<<setprecision(4)<<x<<endl<<y<<endl;
    }
    return 0;
}
