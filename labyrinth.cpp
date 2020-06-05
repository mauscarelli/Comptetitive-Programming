#include <bits/stdc++.h>
using namespace std;

int v[1001][1001], id;
char ch[1001][1001];
int x, y, maxi = 0, length = 0, r, c;
int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};

void dfs(int a,int b)
{
	v[a][b]=id;
	length++;
	if(length>maxi)
	{
		x=a;
		y=b;
		maxi=length;
	}
	for(int j=0;j<4;j++)
	{
		int cx = a + dx[j];
        int cy = b + dy[j];
        if(cx < 0 || cy < 0 || cx >= r || cy >= c || ch[cx][cy] == '#' || v[cx][cy]) continue;
        dfs(cx, cy);
	}
	v[a][b] = 0;
    length --;	
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&c,&r);
		for(int i=0;i<r;i++)
		{
			cin>>ch[i];
		}
		id++;
		length=0;maxi=0;
		for(int i=0;i<r;i++)
		{
			for(int j=0;j<c;j++)
			{
				if(ch[i][j]!='#')
				{
					dfs(i,j);
					i=r;
					break;
				}
			}	
		}
		id++;
		length = 0; maxi = 0;
        dfs(x, y);
        printf("Maximum rope length is %d.\r", maxi - 1);
	}
}