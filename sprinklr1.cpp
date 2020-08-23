#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define speed ios_base :: sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define mod 1000000007
typedef pair<int,int> pii;
bool isvalid(vector<int> v,int d,int val)
{
    int n=v.size(),i;
    vector<int> temp;
    for(i=0;i<n;i++)
    {
        if(v[i]<=val)
        {
            temp.push_back(i);
            v[i]=0;
        }
    }
    vector<ll>ans(n+1,0);
    for(i=0;i<temp.size();i++)
    {
        ll x=max(0,temp[i]-d);
        ll y=min(n,temp[i]+d+1);
        ans[x]-=val;
        ans[y]+=val;
    }
    v[0]=v[0]+ans[0];
    for(i=1;i<n;i++)
    {
        ans[i]+=ans[i-1];
        v[i]=v[i]+ans[i];
    }
    for(i=0;i<n;i++)
    if(v[i]>0)
    return false;
    return true;
    
}
int main() 
{
    speed
    int t;
    cin>>t;
    while(t--)
    {
        int n,d;
        cin>>n>>d;
        vector<int> v(n);
        int i,lo=INT_MAX,hi=INT_MIN;
        for(i=0;i<n;i++)
        {
            cin>>v[i];
            lo=min(lo,v[i]);
            hi=max(hi,v[i]);
        }
        int mid;
        while(lo<=hi)
        {
            mid=(lo+hi)/2;
            //cout<<mid<<"\n";
            bool c=isvalid(v,d,mid);
            //cout<<c<<"\n";
            if(c)
            {
                hi=mid-1;
            }
            else
            lo=mid+1;
        }
        cout<<lo<<"\n";
        
    }
	return 0;
}
 
