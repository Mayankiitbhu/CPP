#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define speed ios_base :: sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define mod 1000000007
typedef pair<int,int> pii;
struct sub
{
    int strt;int end;int credit;
};
bool comp(sub &a,sub &b)
{
    return a.end<b.end;
}
int search(sub *a,int x)
{
    int lo=0,hi=x-1,mid;
    while (lo <= hi) 
    { 
        int mid = (lo + hi) / 2; 
        if (a[mid].end <= a[x].strt) 
        { 
            if (a[mid + 1].end <= a[x].strt) 
                lo = mid + 1; 
            else
                return mid; 
        } 
        else
            hi = mid - 1; 
    } 
  
    return -1; 
}
int main() 
{
    speed
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> s(n);
        vector<int> f(n);
        vector<int> c(n);
        int i;
        vector<int> ans(n);
        for(i=0;i<n;i++)
        cin>>s[i];
        for(i=0;i<n;i++)
        {
            cin>>f[i];
            f[i]+=s[i];
        }
        for(i=0;i<n;i++)
        {
            cin>>c[i];
            //ans[i]=c[i];
        }
        sub *a=new sub[n];
        for(i=0;i<n;i++)
        {
            a[i].strt=s[i];
            a[i].end=f[i];
            a[i].credit=c[i];
        }
        sort(a,a+n,comp);
        int temp,pos;
        ans[0]=a[0].credit;
        for(i=1;i<n;i++)
        {
            temp=a[i].credit;
            pos=search(a,i);
            if(pos!=-1)
            temp+=ans[pos];
            ans[i]=max(ans[i-1],temp);
        }
        int val=0;
        for(i=0;i<n;i++)
        val=max(val,ans[i]);
        cout<<val<<"\n";
        //cout<<ans[n-1]<<"\n";
    }
	return 0;
}
 
