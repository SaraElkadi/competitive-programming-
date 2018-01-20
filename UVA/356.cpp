#include <bits/stdc++.h>

using namespace std;

int main()
{
    // freopen("out.txt","w",stdout);
    int n;
    bool f=0;
    while(cin>>n)
    {
        if(f)
            cout<<endl;
        f=1;
        int enter=0,board=0;
        double t=(double)(2.0*n-1.0)/2.0,s,e;
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                s=sqrt((i-1)*(i-1)+(j-1)*(j-1));
                e=sqrt(i*i+j*j);
                if(e<=t)
                {
                    enter++;
                }
                else if(t>s&&t<e)
                {
                    board++;
                }
            }
        }
        cout<<"In the case n = "<<n<<", "<<board*4<<" cells contain segments of the circle."<<endl<<"There are "<<enter*4<<" cells completely contained in the circle."<<endl;

    }

    return 0;
}
