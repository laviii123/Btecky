#include<bits/stdc++.h>
using namespace std;
// ROTTING ORANGES
int minTimeToRot(vector<vector<int>>& grid, int n, int m)
{
        queue<pair<pair<int,int>,int>>q;
        vector<vector<int>>vis(n,vector<int>(m,0));
        int cntFresh=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j]=2;                   
                }
                if(grid[i][j]==1){
                    cntFresh++;
                }
            }
        }
        int drow[4]={-1,1,0,0};
        int dcol[4]={0,0,-1,1};
        int time=0;
        int cnt=0;
        while(q.size()>0){
            auto it= q.front();
            int r= it.first.first;
            int c=it.first.second;
            int tm=it.second;
            q.pop();
            time=max(time,tm);
            for(int i=0;i<4;i++){
                int nr= r+ drow[i];
                int nc= c+ dcol[i];
                if(nr>=0&&nr<n&&nc>=0&&nc<m&&grid[nr][nc]==1&&vis[nr][nc]!=2){
                    q.push({{nr,nc},tm+1});
                    vis[nr][nc]=2;
                    cnt++;
                }
            }
        }
       if(cnt!=cntFresh){
           return -1;
       }
       return time;
}