/*
*In this problem you will be given two integers i j, you have to find the number of palindromic numbers between i and j (inclusive).
*/
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define LL long long
using namespace std;
 
int a[20],t[20];
LL dp[20][20][2];
LL dfs (int len, int cur, int s, int fp) // len digits, cur palindrome place to start, s meets, fp Is there a limit.
{
    if(!cur)
        return s;
    if(!fp && dp[len][cur][s] != -1)
        return dp[len][cur][s];
    int n = fp?a[cur]:9;
    LL res = 0;
    for(int i=0;i<=n;i++)
    {
        t[cur] = i;
        if(len == cur && i == 0)
            res += dfs(len-1,cur-1,s,fp&&i==n);
        else if(s && cur <= (len+1)/2)
            res += dfs(len,cur-1,t[len-cur+1]==i,fp&&i==n);
        else
            res += dfs(len,cur-1,s,fp&&i==n);
    }
    if(!fp)
        dp[len][cur][s] = res;
    return res;
}
LL sum(LL x)
{
    int len = 0;
    while(x)
    {
        a[++len] = x % 10;
        x /= 10;
    }
    return dfs(len,len,1,1);
}
 
int main(void)
{
    int T;
 cin>>T;
    memset(dp,-1,sizeof(dp));
    int cas = 1;
    while(T--)
    {
        LL a,b;
        cin>>a>>b;
        if(a > b)
            swap(a,b);
        printf("Case %d: %lld\n",cas++,sum(b) - sum(a-1));
    }
 
    return 0;
}
