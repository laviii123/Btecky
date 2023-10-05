//Find largest rectangle in histogram 
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> nsl(n),psl(n);
        
        stack<int> s;
        
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && heights[s.top()]>=heights[i]){
                s.pop();
            }
            nsl[i] = s.empty() ? n : s.top();
            s.push(i);
        }
        
        while(!s.empty()){
            s.pop();
        }
        
        for(int i=0;i<n;i++){
            while(!s.empty() && heights[s.top()]>=heights[i]){
                s.pop();
            }
            psl[i] = s.empty() ? -1: s.top();
            s.push(i);
        }
        
        int ans = INT_MIN;
        for(int i=0;i<n;i++){
            ans = max(ans,(nsl[i]-psl[i]-1)*(heights[i]));
        }
        
        return ans;
    }
};
