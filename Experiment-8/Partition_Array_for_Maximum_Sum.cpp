class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n, 0);
        for (int i = 0; i < n; i++) {
            int maxi = 0;
            for (int len = 1; len <= k && i - len + 1 >= 0; len++) {
                maxi = max(maxi, arr[i - len + 1]);
                if (i - len >= 0)
                    dp[i] = max(dp[i], dp[i - len] + maxi * len);
                else
                    dp[i] = max(dp[i], maxi * len);
            }
        }
        return dp[n - 1];
    }
};
