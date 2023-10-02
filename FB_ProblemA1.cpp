#include<bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    for(int t = 1; t <= T; t++) {
        int S, D, K;
        cin >> S >> D >> K;
        int total_buns = 2 * (S + D);
        int total_cheese_and_patties = S + 2 * D;
        if(total_buns >= K + 1 && total_cheese_and_patties >= K) {
            cout << "Case #" << t << ": YES" << endl;
        } else {
            cout << "Case #" << t << ": NO" << endl;
        }
    }
    return 0;
}
