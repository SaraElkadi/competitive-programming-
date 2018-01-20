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
struct line
{
    double a,b,c;
};
void pointsToLine(point p1,point p2,line &l)
{
    if(fabs(p1.x-p2.x)<EPS)
    {
        l.a=1.0;
        l.b=0.0;
        l.c=-p1.x;
    }
    else
    {
        l.a=-(double)(p1.y-p2.y)/(p1.x-p2.x);
        l.b=1.0;
        l.c=-(double)(l.a*p1.x)-p1.y;
    }
}
bool areParallel(line l1,line l2)
{
    return (fabs(l1.a-l2.a) < EPS) && (fabs(l1.b-l2.b) < EPS);
}
bool areIntersect(line l1, line l2, point &p)
{
    if (areParallel(l1, l2)) return false;
    p.x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);
    if (fabs(l1.b) > EPS) p.y = -(l1.a * p.x + l1.c);
    else p.y = -(l2.a * p.x + l2.c);
    return true;
}
int n,xs,xe,ys,ye,x1,x2,w,y2;
bool check(point p)
{
    return(p.x>=min(xs,xe)&&p.x<=max(xs,xe)&&p.y>=min(ys,ye)&&p.y<=max(ys,ye)&&p.x>=min(x1,x2)&&p.x<=max(x1,x2)&&p.y>=min(w,y2)&&p.y<=max(w,y2));
}
int main()
{
    cin>>n;
    while(n--)
    {
        cin>>xs>>ys>>xe>>ye>>x1>>w>>x2>>y2;
        point p1=point(x1,w);
        point p2=point(x1,y2);
        point p3=point(x2,y2);
        point p4=point(x2,w);
        point ps=point(xs,ys);
        point pe=point(xe,ye);
        line l,l1,l2,l3,l4;
        pointsToLine(ps,pe,l);
        pointsToLine(p1,p2,l1);
        pointsToLine(p2,p3,l2);
        pointsToLine(p3,p4,l3);
        pointsToLine(p4,p1,l4);
        point pp1,pp2,pp3,pp4;
        if((xs>=min(x1,x2)&&xs<=max(x1,x2)&&ys>=min(w,y2)&&ys<=max(w,y2))||(xe>=min(x1,x2)&&xe<=max(x1,x2)&&ye>=min(w,y2)&&ye<=max(w,y2)))
            cout<<"T"<<endl;
        else if((areIntersect(l,l1,pp1)&&check(pp1))||(areIntersect(l,l2,pp2)&&check(pp2))||(areIntersect(l,l3,pp3)&&check(pp3))||(areIntersect(l,l4,pp4)&&check(pp4)))
            cout<<"T"<<endl;
        else
            cout<<"F"<<endl;
    }
    return 0;
}
