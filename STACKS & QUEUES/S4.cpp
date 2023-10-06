//This Pdf contain the code related to next greater and next smaller..
#include<bits/stdc++.h>
using namespace std;
/****************NEXT GREATER TO RIGHT (NGR)**************************/
void next_Greater_To_Right(int n, int arr[], vector<int>&ans){
        stack<int>s; // using IMPLICIT stack
        for(int i=n-1;i>=0;i--){
            if(s.size()==0){
                ans.push_back(-1);
            }
            else if(s.size()>0&&s.top()>arr[i]){
                ans.push_back(s.top());
            }
            else if(s.size()>0&&s.top()<=arr[i]){
                while(s.size()>0&&s.top()<=arr[i]){
                  s.pop();
                }
                if(s.size()==0){
                    ans.push_back(-1);
                }
                else {
                    ans.push_back(s.top());
                }
            }
            s.push(arr[i]);
        }
    reverse(ans.begin(),ans.end());
}
/*******************************************************************/
 /*************************NEXT GREATER TO LEFT (NGL)*********************/
 void next_Greater_To_Left(int n,int arr[],vector<int>&ans){
       stack<int>s; // using IMPLICIT stack
        for(int i=0;i<n;i++){
            if(s.size()==0){
                ans.push_back(-1);
            }
            else if(s.size()>0&&s.top()>arr[i]){
                ans.push_back(s.top());
            }
            else if(s.size()>0&&s.top()<=arr[i]){
                while(s.size()>0&&s.top()<=arr[i]){
                  s.pop();
                }
                if(s.size()==0){
                    ans.push_back(-1);
                }
                else {
                    ans.push_back(s.top());
                }
            }
            s.push(arr[i]);
        }
 }
 /*******************************************************************/
//******************NEXT SMALLER TO RIGHT (NSR)***************************//
void next_Smaller_To_right(int n, int arr[],vector<int>&ans){
     stack<int>s;
    for(int i=n-1;i>=0;i--){
        if(s.size()==0){
            ans.push_back(-1);
        }
        else if(s.size()>0&&s.top()<arr[i]){
            ans.push_back(s.top());
        }
        else if(s.size()>0&&s.top()>=arr[i]){
            while(s.size()>0&&s.top()>=arr[i]){
                s.pop();
            }
            if(s.size()==0){
                ans.push_back(-1);
            }
            else {
                ans.push_back(s.top());
            }
        }
        s.push(arr[i]);
    }
    reverse(ans.begin(),ans.end());
}
/***********************************************************/
//*******************NEXT SMALLER TO LEFT (NSL)***********************//
void next_Smaller_To_Left(int n,int arr[],vector<int>&ans){
    stack<int>s;
    for(int i=0;i<n;i++){
        if(s.size()==0){
            ans.push_back(-1);
        }
        else if(s.size()>0&&s.top()<arr[i]){
            ans.push_back(s.top());
        }
        else if(s.size()>0&&s.top()>=arr[i]){
            while(s.size()>0&&s.top()>=arr[i]){
                s.pop();
            }
            if(s.size()==0){
                ans.push_back(-1);
            }
            else {
                ans.push_back(s.top());
            }
        }
        s.push(arr[i]);
    }
}
/************************************************************/
// Time Complexity: O(n)
// Auxiliary Space: O(n)
/********************************************************/
// for circular
    vector<int> nextGreaterElements_Circular(vector<int>& arr) {
      
         stack<int>st;
         int n=arr.size();
           vector<int>ans;
         for(int i=2*n-1;i>=0;i--){
            if(st.size()==0&&i<n){
                 ans.push_back(-1);
             }
             else if(st.size()>0&& st.top()>arr[i%n]&&i<n){
                 ans.push_back(st.top());
             }
             else if(st.size()>0&& st.top()<=arr[i%n]){
                 while(st.size()>0&& st.top()<=arr[i%n]){
                     st.pop();
                 }
                 if(st.size()==0&&i<n){
                    ans.push_back(-1);
                 }
                 else if(st.size()!=0&&i<n){
                     ans.push_back(st.top());
                 }
             }
             st.push(arr[i%n]);
         }
         reverse(ans.begin(),ans.end());
         return ans;
    }
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int>ans;
    //next_Greater_To_Right(n,arr,ans);
    // next_Greater_To_Left(n,arr,ans);
    // next_Smaller_To_right(n,arr,ans);
    next_Smaller_To_Left(n,arr,ans);
     for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
   return 0;
}