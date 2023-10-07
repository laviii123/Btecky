class Solution {
public:
    int integerBreak(int n) {
        int result = 0;
        for(int k = 2; k <= n; k++){
            int mi = n / k;
            int rest = n % k;
            int temps = 1;
            for(int i = 0; i < k; i++){
                if(rest){
                    temps *= (mi + 1);
                    rest--;
                }
                else temps *= mi;
            }
            result = max(result, temps);
        }
        return result;
    }
};
