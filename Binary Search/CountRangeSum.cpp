class BIT{
private:
    int n;
    vector<int> arr;
    int getNext(int idx){
        return idx + (idx & (-idx));
    }
    int getParent(int idx){
        return idx & (idx-1);
    }
public:
    BIT(int _n):n(_n), arr(_n+1){
        arr[0] = 0;
        for(int idx = 0; idx < n; ++idx){
            addValue(idx, 1);
        }

    }
    void addValue(int idx, int val){
        ++idx;
        while(idx < arr.size()){
            arr[idx] += val;
            idx = getNext(idx);                
        }
    }
    int getSum(int idx){
        ++idx;
        int sum = 0;
        while(idx > 0){
            sum += arr[idx];
            idx = getParent(idx);
        }
        return sum;
    }
};
//Time O(NlogN), Space O(N)
int countRangeSum(vector<int>& nums, int lower, int upper){
    vector<long long> sum(nums.size()+1, 0);
    for(int i = 0; i < nums.size(); ++i){
        sum[i+1] = sum[i]+nums[i];
    }
    vector<long long> A(sum.begin(), sum.end());
    sort(A.begin(), A.end());       
    BIT tree(A.size());
    int count = 0;
    for(const auto &x : sum){
        int idx = lower_bound(A.begin(), A.end(), x)-A.begin();
        int lowerIdx = lower_bound(A.begin(), A.end(), x+lower)-A.begin();
        int upperIdx = upper_bound(A.begin(), A.end(), x+upper)-A.begin()-1;
        tree.addValue(idx, -1);
        count += tree.getSum(upperIdx)-tree.getSum(lowerIdx-1);
    }
    return count;
}
