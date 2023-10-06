/********************SLIDING WINDOW MAXIMUM****************/
#include<bits/stdc++.h>
using namespace std;
// BRUTE FORCE APPROACH
// Time complexity: O(n*n)
// Space complexity: O(k)
  vector<int> maxSlidingWindow1(vector<int>& nums, int k) {
        vector<int>ans;
        int i=0;
        int n=nums.size();
        int t=0;
        while(i<n){
            i=t;
            int j=0;
            int maxi=INT_MIN;
            while(j<k){
                maxi=max(maxi,nums[i]);
                i++;
                j++;
                if(i>=n){
                    break;
                }
            }
            ans.push_back(maxi);
            t++;
        }
        return ans;
    }
// BETTER SOLUTION 
// TC: O(n)
// SC: O(k)
vector<int> maxSlidingWindow2(vector<int>& nums, int k) {
        vector<int>ans;
        deque<int>dq;
        int i=0,j=0;
        int n=nums.size();
        if(k>n){
            sort(nums.begin(),nums.end());
            ans.push_back(nums[nums.size()-1]);
        }
        while(i<n){
            while(dq.size()!=0&&dq.back()<nums[i]){
                dq.pop_back();
            }
            dq.push_back(nums[i]);
            if(i-j+1<k){
                i++;
            }
            else if(i-j+1==k){
                ans.push_back(dq.front());
                if(dq.front()==nums[j]){
                    dq.pop_front();
                }
                i++;
                j++;
            }
        }
        return ans;
    }