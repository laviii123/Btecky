#include<bits/stdc++.h>
using namespace std;
/*******************SORT A STACK******************************/
void sortStack(stack<int> &s)
{
	vector<int>v;
	while(s.size()!=0){
		v.push_back(s.top());
		s.pop();
	}
    sort(v.begin(),v.end());
	for(int i=0;i<v.size();i++){
		s.push(v[i]);
	}
}
// Method 1. TC= O(1) SC: O(2*N)
class minStack
{
	stack<pair<int,int>> st;
	public:
		minStack() 
		{ }
		void push(int num)
		{    
			int mini;
		  if(st.size()==0){
          mini=num;
      }
			else {
         mini = min(st.top().second, num);
      }
      st.push({num,mini});
		}
		int pop()
		{
			if(st.size()==0){
				return -1;
			}
			int ans=st.top().first;
			st.pop();
			return ans;
		}
		int top()
		{
			if(st.size()==0){
				return -1;
			}
			int ans=st.top().first;
			return ans;
		}
		int getMin()
		{
			if(st.size()==0){
				return -1;
			}
			int ans=st.top().second;
			return ans;
		}
};
// Method 2. TC: O(1) SC: O(N)
class MinStack {
  stack < int > st;
   int mini;
  public:
    /** initialize your data structure here. */
    MinStack() {
      while (st.empty() == false) st.pop();
      mini = INT_MAX;
    }

  void push(int value) {
    int val=value;
    if (st.empty()) {
      mini = val;
      st.push(val);
    } else {
      if (val < mini) {
        st.push(2 *val - mini);
        mini = val;
      } else {
        st.push(val);
      }
    }
  }

  void pop() {
    if (st.empty()) return;
    int el = st.top();
    st.pop();

    if (el < mini) {
      mini = 2 * mini - el;
    }
  }

  int top() {
    if (st.empty()) return -1;

    int el = st.top();
    if (el < mini) return mini;
    return el;
  }

  int getMin() {
    return mini;
  }
};