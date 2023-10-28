Question -

Maximize Score





You are given an array nums of n positive integers and an integer k. Initially, you start with a score of 1. You have to maximize your score by applying the following operation at most k times:

Choose any non-empty subarray nums[l, ..., r] that you haven't chosen previously.
Choose an element x of nums[l, ..., r] with the highest prime score. If multiple such elements exist, choose the one with the smallest index.
Multiply your score by x.
Here, nums[l, ..., r] denotes the subarray of nums starting at index l and ending at the index r, both ends being inclusive.

The prime score of an integer x is equal to the number of distinct prime factors of x. For example, the prime score of 300 is 3 since 300 = 2 * 2 * 3 * 5 * 5.

Return the maximum possible score after applying at most k operations. Since the answer may be large, return it modulo 109 + 7.


Example 1:

Input: nums = [8,3,9,3,8], k = 2
Output: 81
Explanation: To get a score of 81, we can apply the following operations:
- Choose subarray nums[2, ..., 2]. nums[2] is the only element in this subarray. Hence, we multiply the score by nums[2]. The score becomes 1 * 9 = 9.
- Choose subarray nums[2, ..., 3]. Both nums[2] and nums[3] have a prime score of 1, but nums[2] has the smaller index. Hence, we multiply the score by nums[2]. The score becomes 9 * 9 = 81.
It can be proven that 81 is the highest score one can obtain.
Example 2:

Input: nums = [19,12,14,6,10,18], k = 3
Output: 4788
Explanation: To get a score of 4788, we can apply the following operations: 
- Choose subarray nums[0, ..., 0]. nums[0] is the only element in this subarray. Hence, we multiply the score by nums[0]. The score becomes 1 * 19 = 19.
- Choose subarray nums[5, ..., 5]. nums[5] is the only element in this subarray. Hence, we multiply the score by nums[5]. The score becomes 19 * 18 = 342.
- Choose subarray nums[2, ..., 3]. Both nums[2] and nums[3] have a prime score of 2, but nums[2] has the smaller index. Hence, we multipy the score by nums[2]. The score becomes 342 * 14 = 4788.
It can be proven that 4788 is the highest score one can obtain.
 

Constraints:

1 <= nums.length == n <= 10^5
1 <= nums[i] <= 10^5
1 <= k <= min(n * (n + 1) / 2, 10^9)





Solution :-


class Solution {
    static int MOD = (int)1e9 + 7;
    class MyNum {
        int value;
        int left;
        int right;
        int idx;
        int score;
        MyNum(int v, int l, int r, int i, int s) {
            this.value = v;
            this.left = l;
            this.right = r;
            this.idx = i;
            this.score = s;
        }
    }
    int score(int x) {
        int count = 0;
        if (x % 2 == 0) {
            count++;
            while (x % 2 == 0) {
                x /= 2;
            }
        }

        for (int i = 3; i <= Math.sqrt(x); i += 2) {
            if (x % i == 0) {
                count++;
                while (x % i == 0) {
                    x /= i;
                }
                if (x == 1) {
                    return count;
                }
            }
        }

        if (x > 2) {
            count++;
        }

        return count;
    }
    long power(int x, int p) {
        if (p == 0) {
            return 1;
        }
        long ans = 1;
        if ((p & 1) == 1) {
            ans = x;
        }
        long res = power(x, p >> 1);
        res = (res * res) % MOD;
        ans = (ans * res) % MOD;
        return ans;
    }

    public int maximumScore(List<Integer> nums, int k) {
        int n = nums.size();
        MyNum[] d = new MyNum[n];
        
        for (int i = 0; i < n; i++) {
            d[i] = new MyNum(nums.get(i), i + 1, n - i, i, score(nums.get(i)));
        }

        Stack<Integer> s = new Stack<>();
        for (int i = 0; i < n; i++) {
            while (!s.isEmpty() && d[s.peek()].score < d[i].score) {
                int idx = s.pop();
                d[idx].right = i - idx;
            }
            s.push(i);
        }
        s.clear();
        
        for (int i = n - 1; i >= 0; i--) {
            while (!s.isEmpty() && d[s.peek()].score <= d[i].score) {
                int idx = s.pop();
                d[idx].left = idx - i;
            }
            s.push(i);
        }

         
        Arrays.sort(d, (a, b) -> {
            
            return b.value - a.value;
        });
        /
        long ans = 1L;
        for (int i = 0; i < n && k > 0; i++) {
            int ops = d[i].right * d[i].left;
            int realOps = Math.min(k, ops);
            k -= realOps;
            ans = ans * power(d[i].value, realOps) % MOD;
        }
        return (int) ans;
    }
}
