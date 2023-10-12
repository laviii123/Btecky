#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//Function for finding the states or nodes which are not involved in cycle
vector<int> findeventualsafe(int n,int m,vector<vector<int>>&edges){
    //Create an adjacency list;
    unordered_map<int,vector<int>>adj;
    for(auto it:edges){
        int u=it[0];
        int v=it[1];

        adj[u].push_back(v);
    }
    //Store the indegree of each node for using topological sort algorithm
    vector<int>indegree(n,0);
    for(auto it:adj){
        int node=it.first;
        for(auto x:adj[node]){
            indegree[x]++;
        }
    }
    queue<int>q;
    for(int i=0;i<n;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    vector<int>ans;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        ans.push_back(node);

        for(auto x:adj[node]){
            indegree[x]--;
            if(indegree[x]==0){
                q.push(x);
            }
        }
    }

    sort(ans.begin(),ans.end());
    return ans;
}

int main()
{
    int n,m,u,v,wt;
    //Input Number of nodes
    cin>>n;
    //Input the number of edges
    cin>>m;
    //Taking the input edges of the directed graph
    vector<vector<int>>edges;
    for(int i=0;i<m;i++){
        cin>>u;
        cin>>v;
        edges.push_back({u,v});
    }

    vector<int>ans=findeventualsafe(n,m,edges);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}
