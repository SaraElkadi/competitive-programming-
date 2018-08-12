#include <bits/stdc++.h>

using namespace std;

int goal;
double P;

double pro(int rem,int r,int k)
{
    if(rem>=goal)
        return 1;
    if(!r)
        return 0;
    double ret=0;
    if(rem>=k)
    {
        ret+=(1-(P/100))*pro(rem-k,r-1,k*2);
        ret+=(P/100)*pro(rem+k,r-1,1);
    }
    return ret;
}

class TestBettingStrategy
{
public:
    double winProbability(int initSum, int goalSum, int rounds, int prob)
    {
        goal=goalSum;
        P=prob;
        return pro(initSum,rounds,1);
    }
};
