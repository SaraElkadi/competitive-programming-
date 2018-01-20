#include <bits/stdc++.h>

using namespace std;

int main()
{
    double x1,x2,x3,x4,y1,y2,y3,y4;
    while(cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4){
        if((x3==x1)&&(y3==y1)){
            cout<<fixed<<setprecision(3)<<x4+x2-x1<<" "<<y4+y2-y1<<endl;
            continue;
        }
        if((x2==x3)&&(y2==y3)){
            cout<<fixed<<setprecision(3)<<x4-x2+x1<<" "<<y4-y2+y1<<endl;
            continue;
        }
        if(((x4==x1)&&(y4==y1))||((x4==x2)&&(y4==y2))){
            swap(x3,x4);
            swap(y3,y4);
        if((x3==x1)&&(y3==y1)){
            cout<<fixed<<setprecision(3)<<x4+x2-x1<<" "<<y4+y2-y1<<endl;
            continue;
        }
        if((x2==x3)&&(y2==y3)){
            cout<<fixed<<setprecision(3)<<x4-x2+x1<<" "<<y4-y2+y1<<endl;
            continue;
        }
        }
    }
    return 0;
}
