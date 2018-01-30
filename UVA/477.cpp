#include <bits/stdc++.h>

using namespace std;
struct circle{
double x,y,r;
int idx;
};
struct rectengle{
double x1,y1,x2,y2;
int idx;
};
struct point{
double x,y;
};
bool chheckinCircle(point p,circle c){
return (p.x-c.x)*(p.x-c.x)+(p.y-c.y)*(p.y-c.y)<c.r*c.r;
}
bool checkinRectengle(point p,rectengle r){
return p.y>r.y2&&p.y<r.y1&&p.x>r.x1&&p.x<r.x2;
}
int main()
{
   // freopen("out.txt","w",stdout);
    int i=1;
    char c;
    double x1,y1,x2,y2;
    vector<circle> cc;
    vector<rectengle> rr;
    while(cin>>c&&c!='*'){
       // cout<<i<<endl;
        if(c=='c'){
            cin>>x1>>y1>>x2;
            cc.push_back(circle{x1,y1,x2,i});
        }
        else{
            cin>>x1>>y1>>x2>>y2;
            rr.push_back(rectengle{x1,y1,x2,y2,i});
        }
        i++;
    }
    point p;
    int k=1;
    while(cin>>p.x>>p.y&&(p.x!=9999.9&&p.y!=9999.9)){
        vector<int> v;
        for(int i=0;i<cc.size();i++){
            if(chheckinCircle(p,cc[i]))
                v.push_back(cc[i].idx);
        }
        for(int i=0;i<rr.size();i++){
            if(checkinRectengle(p,rr[i]))
                  v.push_back(rr[i].idx);
        }
        if(!v.size())
            cout<<"Point "<<k<<" is not contained in any figure"<<endl;
        else {
            sort(v.begin(),v.end());
            for(int i=0;i<v.size();i++)
                cout<<"Point "<<k<<" is contained in figure "<<v[i]<<endl;
        }
        k++;
    }
    return 0;
}
