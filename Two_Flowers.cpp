/*
Chef Go has planted a flower field — a grid with n rows and m columns. In each cell of this grid, a single flower is planted; let's denote the type of the flower
planted in cell (i,j) by ai,j.

Today, Chef Go is going to make a new menu with two dishes: Tom Yum Goong and Tom Kha Kai. He needs to pick as many flowers as possible to decorate the 
dishes and make them look attractive. Each dish can only be decorated with flowers of a single type, so he can only pick flowers of one type or two
different types. Also, Chef Go wants the flowers he picks to form one connected area, so that he can finish his job quickly. A connected
area is a set of cells such that we can move from any cell to any other cell in this set by only moving between side-adjacent cells from the set.

Help Chef Go find the size of the largest connected area in his flower field which contains at most two types of flowers
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF64 = ll(1e18);
const int maxn=2000;
int mat[maxn+1][maxn+1];
int size1[maxn*maxn+1];
int n,m,c;
int visited[maxn+1][maxn+1];
int reps[maxn+1][maxn+1];
int who[maxn*maxn], siz[maxn*maxn];
map<int,int> m1;
map<pair<int,int>,int> m2;
int ans=0;
int findWho(int v) {
      return v == who[v] ? v : who[v] = findWho(who[v]);
    }
bool safe(int i,int j)
{
	if(i>=0 && j>=0 && i<n && j<m)
		return(1);
	return(0);
}

void dfs(int i,int j,int rep)
{	//cout<<i<<" "<<j<<"\n";
reps[i][j]=rep;
size1[rep]++;
	int x[]={1,-1,0,0};
	int y[]={0,0,1,-1};
	for(int k=0;k<4;++k)
	{
		if(safe(i+x[k],j+y[k]))
		{
			if(visited[i+x[k]][j+y[k]]==0 && mat[i+x[k]][j+y[k]]==mat[i][j])
			{
				visited[i+x[k]][j+y[k]]=1;
				
				dfs(i+x[k],j+y[k],rep);


			}
		}
	}
}
bool validate(int x1,int x2,int x3,int x4,int y1,int y2,int y3,int y4)
{
	int xr=1;
	xr&=(mat[x1][y1]!=mat[x2][y2]);
	xr&=(mat[x1][y1]!=mat[x3][y3]);
	xr&=(mat[x1][y1]!=mat[x4][y4]);
	xr&=(mat[x2][y2]!=mat[x3][y3]);
	xr&=(mat[x2][y2]!=mat[x4][y4]);
	xr&=(mat[x4][y4]!=mat[x3][y3]);
	return(xr);

}
int main()
{
#ifndef ONLINE_JUDGE
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
//long long tt = clock();
#endif
cin>>n>>m;
int i,j;
for(i=0;i<n;++i)
{
	for(j=0;j<m;++j)
		scanf("%d",&mat[i][j]);
}
memset(visited,0,sizeof(visited));
memset(reps,0,sizeof(reps));
memset(size1,0,sizeof(size1));
c=1;

for(i=0;i<n;++i)
{
	for(j=0;j<m;++j)
	{
		if(visited[i][j]==0)
		{
			visited[i][j]=1;
			dfs(i,j,c);
			++c;
		}
	}
}

/*for(i=0;i<n;++i)
{
	for(j=0;j<m;++j)
	{
		cout<<reps[i][j]<<" ";
	}
	cout<<"\n";
}*/
for(i=1;i<=c;++i)
{
	siz[i]=size1[i];
	who[i]=i;
	ans=max(ans,siz[i]);
}
int x1[]={1,-1,0,0};
int y1[]={0,0,1,-1};
int k;
map<pair<int,int>,vector<pair<int,int>>> edge;
for(i=0;i<n;++i)
{
	for(j=0;j<m;++j)
	{
		for(k=0;k<4;++k)
		{
			int x=i+x1[k],y=j+y1[k];
			if(safe(x,y))
			{
				if(mat[x][y]>mat[i][j])
				{
					edge[make_pair(mat[i][j],mat[x][y])].push_back(make_pair(reps[i][j],reps[x][y]));
				}
			}
		}
	}
}

for(auto vec:edge)
{vector<int> change;
	for(auto it:vec.second)
	{
		int x=it.first,y=it.second;
		/*if(vec.first.first==1 && vec.first.second==2)
			cout<<x<<" "<<y<<"\n";*/
		change.push_back(x);
		change.push_back(y);
		int xx=findWho(x),yy=findWho(y);
		if(xx==yy)
			continue;
		if(xx<yy)
			swap(xx,yy);
		
		 who[xx] = yy;
		 
         siz[yy] += siz[xx];
		ans=max(ans,siz[yy]);

	}
	
	
	for(auto it:change)
	{
		siz[it]=size1[it];
		who[it]=it;
	}
}

cout<<ans<<"\n";


return(0);
}
