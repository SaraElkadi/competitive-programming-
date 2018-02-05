#include <bits/stdc++.h>

using namespace std;
#define PI acos(-1.0)
#define EPS 1e-6
struct point{
double x,y;};
double dis(point p1,point p2){
return (p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y);
}
bool isSquare(point p1, point p2, point p3, point p4)
{
    if((fabs(p1.x-p2.x)<EPS&&fabs(p1.y-p2.y)<EPS)||(fabs(p1.x-p3.x)<EPS&&fabs(p1.y-p3.y)<EPS)||(fabs(p1.x-p4.x)<EPS&&fabs(p1.y-p4.y)<EPS)||(fabs(p3.x-p2.x)<EPS&&fabs(p3.y-p2.y)<EPS)||(fabs(p4.x-p2.x)<EPS&&fabs(p4.y-p2.y)<EPS)||(fabs(p3.x-p4.x)<EPS&&fabs(p4.y-p3.y)<EPS))
        return 0;
    double d2 = dis(p1, p2);
    double d3 = dis(p1, p3);
    double d4 = dis(p1, p4);
    if (fabs(d2-d3)<EPS && fabs(2*d2-d4)<EPS)
    {
        double d = dis(p2, p4);
        return (fabs(d-dis(p3, p4))<EPS && fabs(d-d2)<EPS);
    }
     if (fabs(d3-d4)<EPS && fabs(2*d3-d2)<EPS)
    {
        double d = dis(p2, p3);
        return (fabs(d-dis(p2, p4))<EPS&& fabs(d-d3)<EPS);
    }
    if (fabs(d2-d4)<EPS && fabs(2*d2-d3)<EPS)
    {
        double d = dis(p2, p3);
        return (fabs(d-dis(p3, p4))<EPS && fabs(d-d2)<EPS);
    }
    return false;
}
point rotate_point(double cx,double cy,double angle,point p)
{
  double s = sin(angle/180*PI);
  double c = cos(angle/180*PI);
  p.x -= cx;
  p.y -= cy;
  double xnew = p.x * c - p.y * s;
  double ynew = p.x * s + p.y * c;
  p.x = xnew + cx;
  p.y = ynew + cy;
  return p;
}
int main()
{
    int n;
    cin>>n;
    while(n--){
        int x[4],y[4],a[4],b[4];
        for(int i=0;i<4;i++){
            cin>>x[i]>>y[i]>>a[i]>>b[i];
        }
        int ans=20;
        for(int k1=0;k1<4;k1++){
            for(int k2=0;k2<4;k2++){
                for(int k3=0;k3<4;k3++){
                    for(int k4=0;k4<4;k4++){
                       point p1=rotate_point(a[0],b[0],k1*90,point{x[0],y[0]});
                       point p2=rotate_point(a[1],b[1],k2*90,point{x[1],y[1]});
                       point p3=rotate_point(a[2],b[2],k3*90,point{x[2],y[2]});
                       point p4=rotate_point(a[3],b[3],k4*90,point{x[3],y[3]});
                        if(isSquare(p1,p2,p3,p4)){
                        ans=min(ans,k1+k2+k3+k4);
                        }
                    }
                }
            }
        }
        if(ans==20)
            cout<<-1<<endl;
        else
            cout<<ans<<endl;
    }
    return 0;
}
