#include <bits/stdc++.h>
using namespace std;

// NGE without Stack O(1)-> S.C.

//Function to find the next greater element for each element of the array.
vector<long long> nextLargerElement(vector<long long> nums, int n)
{
  // Your code here
  vector<long long> result(n, -1);

  long long max_element = nums[n - 1]; // initialize the maximum element as the last element

  for (long long i = n - 2; i >= 0; i--)
  {
    if (nums[i] >= max_element)
    {
      max_element = nums[i]; // update the maximum element if the current element is greater
    }
    else
    {
      int j = i + 1;
      while (j < n && nums[i] >= nums[j])
      {
        j++;
      }
      if (j < n && nums[i] < nums[j])
      {
        result[i] = nums[j]; // update the result vector with the next greater element
      }
    }
  }
  return result;
}



//    Returns the index of Next Greater element
vector<int> n_g_e(vector<int> &nums)
{
  stack<int> st;
  vector<int> ans;
  ans.push_back(-1);
  st.push(nums.size() - 1);
  int n = nums.size();

  for (int i = n - 2; i >= 0; i--)
  {
    //  iska matlab he ki muje next small chahiye tha pr muje grater milra h previous me, to hm pop() krdege...
    while (!st.empty() && nums[i] >= nums[st.top()])
    {
      st.pop();
    }

    if (st.empty())
    {
      ans.push_back(-1);
    }

    else
    {
      ans.push_back(st.top());
    }

    st.push(i);
  }

  reverse(ans.begin(), ans.end());

  for (int i = 0; i < ans.size(); i++)
  {
    cout << ans[i] << " ";
  }

  return ans;
}
