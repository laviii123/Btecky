#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, INT_MAX - 1);
    dp[0] = 0;
    for (int coin : coins) {
        for (int i = coin; i <= amount; i++) {
            dp[i] = min(dp[i], dp[i - coin] + 1);
        }
    }
    return dp[amount] == INT_MAX - 1 ? -1 : dp[amount];
}

int main() {
    int amount, n;
    cout << "Enter the target amount: ";
    cin >> amount;
    cout << "Enter the number of coin denominations: ";
    cin >> n;
    vector<int> coins(n);
    cout << "Enter coin denominations: ";
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    int minCoins = coinChange(coins, amount);
    if (minCoins == -1) {
        cout << "It's not possible to make the target amount with given denominations." << endl;
    } else {
        cout << "Minimum number of coins needed: " << minCoins << endl;
    }
    return 0;
}
