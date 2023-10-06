#include<bits/stdc++.h>
 using namespace std;
 /****************************LARGEST RACTANGLE IN HISTOGRAM***************************************/
 void index_NSR(int n,vector<int>& arr,vector<int>&v_nsr){
      stack<pair<int,int>>s_nsr;
    for(int i=n-1;i>=0;i--){
        if(s_nsr.size()==0){
            v_nsr.push_back(n);
        }
        else if(s_nsr.size()>0&&s_nsr.top().first<arr[i]){
            v_nsr.push_back(s_nsr.top().second);
        }
        else if(s_nsr.size()>0&&s_nsr.top().first>=arr[i]){
            while(s_nsr.size()>0&&s_nsr.top().first>=arr[i]){
                s_nsr.pop();
            }
            if(s_nsr.size()==0){
                v_nsr.push_back(n);
            }
            else {
                v_nsr.push_back(s_nsr.top().second);
            }
        }
        s_nsr.push({arr[i],i});
    }
    reverse(v_nsr.begin(),v_nsr.end());
}
void index_NSL(int n,vector<int>& arr,vector<int>&v_nsl){
    stack<pair<int,int>>s_nsl;
    for(int i=0;i<n;i++){
        if(s_nsl.size()==0){
            v_nsl.push_back(-1);
        }
        else if(s_nsl.size()>0&&s_nsl.top().first<arr[i]){
            v_nsl.push_back(s_nsl.top().second);
        }
        else if(s_nsl.size()>0&&s_nsl.top().first>=arr[i]){
            while(s_nsl.size()>0&&s_nsl.top().first>=arr[i]){
                s_nsl.pop();
            }
            if(s_nsl.size()==0){
                v_nsl.push_back(-1);
            }
            else {
                v_nsl.push_back(s_nsl.top().second);
            }
        }
        s_nsl.push({arr[i],i});
    }
}
 int largestRectangle(vector < int > & arr) {
   int n=arr.size();
        vector<int>v_nsr;
    vector<int>v_nsl;
    int diff[n];
    int i=0;
    index_NSR(n,arr,v_nsr);
    index_NSL(n,arr,v_nsl);
    // for(int i=0;i<n;i++){
        // cout<<v_nsr[i]<<" ";
    // }
    // cout<<endl;
    // for(int i=0;i<n;i++){
    //     // cout<<v_nsl[i]<<" ";
    // }
    // cout<<endl;
    while(i>=0 && i<n){
    diff[i]= v_nsr[i]-v_nsl[i]-1;
      i++;
    }
    int maxi=0,ans;
    for(int i=0;i<n;i++){
        ans= diff[i]*arr[i];
        if(maxi<=ans){
            maxi=ans;
        }
        else {
            maxi=maxi;
        }
    }
    return maxi;
 }