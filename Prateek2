#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// program for finding the distinct number of ways to reach bottom right corner of grid with obstacles

int maze(int n,int m,vector<vector<int>>&grid,vector<vector<int>>&dp){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i>0 && j>0 && grid[i][j]==-1){
                dp[i][j]=0;
                continue;
            }
            if(i==0 && j==0){
                dp[i][j]=1;
                continue;
            }

            int up=0;
            int left=0;

            if(i>0){
                up=dp[i-1][j];
            }
            if(j>0){
                left=dp[i][j-1];
            }

            dp[i][j]=up+left;
        }
    }
    return dp[n-1][m-1];
}

int uniquepaths(vector<vector<int>>&grid,int n,int m){
    vector<vector<int>>dp(n,vector<int>(m,-1));
    return maze(n,m,grid,dp);
}

int main(){
    int n,m;
    //Rows
    cin>>n;
    //Columns
    cin>>m;
    vector<vector<int>>grid(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }

    int ans=uniquepaths(grid,n,m);
    cout<<ans<<endl;
    return 0;
}
