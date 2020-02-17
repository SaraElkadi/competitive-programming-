#include <bits/stdc++.h>

using namespace std;

class data
{
public:
    int d,m,y;
    data(int day,int month,int year)
    {
        d=day;
        m=month;
        y=year;
    }
    bool operator ==(const data& other){
      return d==other.d&&m==other.m&&y==other.y;
    }
};

data next(data today)
{
    data tomorrow=today;
    int d=today.d,m=today.m,y=today.y;
    if(m==2&&((d==28&&y%4!=0)||(d==29&&y%4==0)))
    {
        tomorrow.m=3;
        tomorrow.d=1;
    }
    else if(d==30&&(m==2||m==4||m==6||m==9||m==11))
    {
        tomorrow.m++;
        tomorrow.d=1;
    }
    else if(d==31&&(m==1||m==3||m==5||m==7||m==8||m==10||m==12))
    {
        if(m==12)
        {
            tomorrow.m=1;
            tomorrow.d=1;
            tomorrow.y++;
        }
        else
        {
            tomorrow.m++;
            tomorrow.d=1;
        }
    }
    else
    {
        tomorrow.d++;
    }
    return tomorrow;
}

int main()
{
    int n;
    int ans,d,m,y,preVal,val;
    while(cin>>n&&n)
    {
        int ans=0,cnt=0;
        cin>>d>>m>>y>>preVal;
        data today(d,m,y);
        n--;
        while(n--)
        {
            cin>>d>>m>>y>>val;
            data tomorrow(d,m,y);
            if(next(today)==tomorrow)
            {
                ans+=(val-preVal);
                cnt++;
            }
            today=tomorrow;
            preVal=val;
        }
        cout<<cnt<<" "<<ans<<endl;
    }

    return 0;
}
