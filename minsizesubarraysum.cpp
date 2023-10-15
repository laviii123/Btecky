#include <bits/stdc++.h>
using namespace std;


class Solution{
public:
    int minSubArrayLen(int target, vector<int>& nums){
        int n = nums.size();
        int i = 0;
        int j = 0;
        int sum = 0;
        int minlen = INT_MAX;
        while(j < n){
            sum += nums[j];
            while(sum >= target){
                minlen = min(minlen, j - i + 1);
                sum -= nums[i];
                i++;
            }
            j++;
        }
        return minlen == INT_MAX ? 0 : minlen;
    }
};

class Solution1{
public:
    int minSubArrayLen(int target, vector<int>& nums1){
        

        int n = nums1.size();
        int i = 0;
        int j = n - 1;
        int mid;
        int sum;
        int minlen = INT_MAX;
        while(i <= j){
            mid = i + (j - i) / 2;
            sum = sumofsubarray(nums1, mid, n - 1);
            if(sum >= target){
                minlen = min(minlen, mid);
                j = mid - 1;
            }
            else{
                i = mid + 1;
            }
        }
        return minlen == INT_MAX ? 0 : minlen;
    }
private:
    int sumofsubarray(vector<int>& nums1, int i, int j){
        int sum = 0;
        for(int k = i; k <= j; k++){
            sum += nums1[k];
        }
        return sum;
    }
};
int main(
)
{
    Solution s1;
    vector<int> nums1 = {2, 3, 1, 2, 4, 3};
    int target = 7;
    cout<<s1.minSubArrayLen(target, nums1)<<endl;
    return 0;
}

