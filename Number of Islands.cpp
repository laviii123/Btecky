#include<iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
  private: 
  void bfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>>&grid) {
    
      // mark it visited
      vis[row][col] = 1; 
      queue<pair<int,int>> q;
      // push the node in queue
      q.push({row, col}); 
      int n = grid.size(); 
      int m = grid[0].size(); 
      
      // until the queue becomes empty
      while(!q.empty()) {
          int row = q.front().first; 
          int col = q.front().second; 
          q.pop(); 
          
          // traverse in the neighbours and mark them if its a land 
          for(int delrow = -1; delrow<=1;delrow++) {
            
              for(int delcol = -1; delcol <= 1; delcol++) {
                
                  int nrow = row + delrow; 
                  int ncol = col + delcol; 
                
                  // neighbour row and column is valid, and is an unvisited land
                  if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m 
                  && grid[nrow][ncol] == '1' && !vis[nrow][ncol]) {
                      vis[nrow][ncol] = 1; 
                      q.push({nrow, ncol}); 
                  }
              }
          }
      }
  }

  public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
      
        int n = grid.size(); 
        int m = grid[0].size(); 
        // create visited array and initialise to 0
        vector<vector<int>> vis(n, vector<int>(m, 0)); 
        int cnt = 0; 
      
        for(int row = 0; row < n ; row++) {
            for(int col = 0; col < m ;col++) {
                // if not visited and is a land
                if(!vis[row][col] && grid[row][col] == '1') {
                    cnt++; 
                    bfs(row, col, vis, grid); 
                }
            }
        }
        return cnt; 
    }
};

int main() {
   
    vector<vector<char>> grid
    {
        {'0', '1', '1', '1', '0', '0', '0'},
        {'0', '0', '1', '1', '0', '1', '0'}
    };

        
    Solution obj;
    cout << obj.numIslands(grid) << endl;
        
    return 0;
}
