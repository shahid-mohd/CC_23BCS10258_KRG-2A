#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;

long long maxSumSquares(vector<int>& nums, int k) {
    int count[32] = {0};
    for (int num : nums) {
        for (int b = 0; b < 32; b++) {
            if ((num >> b) & 1) {
                count[b]++;
            }
        }
    }
    long long result = 0;
    for (int i = 0; i < k; i++) {
        long long curr = 0;
        for (int b = 0; b < 32; b++) {
            if (count[b] > 0) {
                curr |= (1LL << b);
                count[b]--;
            }
        }
        result = (result + (curr * curr) % MOD) % MOD;
    }
    return result;
}

int main() {
    int n, k;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    cin >> k;
    cout << maxSumSquares(nums, k) << endl;
    return 0;
}
