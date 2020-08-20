/*
Lucifer is the only human whi has defeated RA-ONE in a computer game ..
RA-One is after lucifer for revenge and G-One is there to protect him ...
All thi G-One and Ra-one Nonsense has disturbed lucifers life..
He wants to get Rid of Ra-One and kill him . He found that Ra-One can be killed only by throwing Lucifer number of weapons at him.
Lucifer number  shares the some properties of Ra-One Numbers numbers and G-One Numbers
Any number is LUCIFER NUMBER  if the Difference between Sum of digits at even location and Sum of digits at odd location is prime number .. For eg... for 20314210 is lucifer number
digits at odd location 0,2,1,0
digits at even location 1,4,3,2
diff = (1+4+3+2)-(0+2+1+0)=10-3  = 7 ..... a prime number.
Lucifer has access to a Warehouse which has lots of weapons ..
He wants to know in how many ways can he kill him.
Can you help him?

Input
First line will have a number 't' denoting the number of test cases.
each of the following t lines will have 2 numbers 'a' , 'b'
Output
Print single number per test case, depicting the count of Lucifer numbers in the range a,b inclusive.
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
lli dp[20][2][100][100];// index, tight ,oddsum,evensum
int prms[29] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109};

bool check(int  odd,int even,int len)
{
   //cout<<" check "<<odd<<" "<<even<<endl;
 int x;
 if(len%2==1)
 x=odd-even;
 else x=even-odd;
 if(x<0)
  return 0;
 for(int i=0;i<29;i++)
  if(prms[i]==x)
  {
    return 1;
  }
  
 return 0;
}


int ch(string s)
 {
   int od=0,ev=0;
   for(int i=0;i<s.length();i++)
    {
      if(i%2==0)
      ev+=s[i]-'0';
      else od+=s[i]-'0';
    
    }
     //cout<<" sp check "<<od<<" "<<ev<<endl;
      return check(od,ev,s.length());
 }
 
 
int solve(int idx,int tight,int ods,int evs,string s,int n)
 {
   //cout<<" idx "<<idx<<" tight "<<tight<<" ods "<<ods<<" evs "<<evs<<endl;
      if(idx>=n)
      return check(ods,evs,n);
      else if(dp[idx][tight][ods][evs]!=-1)
      return dp[idx][tight][ods][evs];
      
      else if(tight==1)
        {
         int ret=0;
         for(int i=0;i<=s[idx]-'0';i++)
            {
             int  od=ods,ev=evs;
             if(idx%2==1)  od+=i;
             else ev+=i;
             if(i==s[idx]-'0')
              {
                ret+= solve(idx+1,1,od,ev,s,n);
               
        }
        else
        ret+=solve(idx+1,0,od,ev,s,n);
    }
    dp[idx][tight][ods][evs]=ret;
    return ret;
         
    }
    else
    {
     int ret=0;
     
         for(int i=0;i<=9;i++)
            {
                int  od=ods,ev=evs;
             if(idx%2==1)  od+=i;
             else ev+=i;
        ret+=solve(idx+1,0,od,ev,s,n);
    }
    dp[idx][tight][ods][evs]=ret;
    return ret;
    }
      
      
 }
 
 
 int main()
  {
    int t;
     cin>>t;
     while(t--)
      {
       memset(dp,-1,sizeof dp);
        string a,b;
         cin>>a>>b;
          int ans1=solve(0,1,0,0,b,b.length());
          memset(dp,-1,sizeof dp);
   int ans2=solve(0,1,0,0,a,a.length());
          if(ch(a)) ans1++;
         // cout<<ans1<<" "<<ans2<<endl;
           cout<<ans1-ans2<<endl;
         
   }
  }
