//////////negatives allowed
typedef pair<int,int> pii;
class Solution {
public:
    
    int shortestSubarray(vector<int>& a, int k) 
    {
        int n=a.size(),i;
        if(n==1 && a[0]==k)
            return 1;
        if(n==1 && a[0]!=k)
            return -1;
        
        vector<int> v(n+1,0);
        int sum=0;
        for(i=0;i<n;i++)
        {
            v[i+1]=v[i]+a[i];
        }
        deque<int>dq;
        int ans=INT_MAX;
        for(i=0;i<=n;i++)
        {
            while(!dq.empty() && v[i]-v[dq.front()]>=k)
            {
                ans=min(ans,i-dq.front());
                dq.pop_front();
            }
            while(!dq.empty() && v[i]-v[dq.back()]<=0)
                dq.pop_back();
            
            dq.push_back(i);
        }
        
        return ans==INT_MAX?-1:ans;
       
    }
};
