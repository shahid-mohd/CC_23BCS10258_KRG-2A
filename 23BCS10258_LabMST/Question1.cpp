#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());
        while (low < high) {
            int mid = (low + high) / 2;
            long long operations = 0;
            for (int balls : nums) {
                operations += (balls - 1) / mid;
            }
            if (operations <= maxOperations) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};

int main() {
    int n, maxOperations;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    cin >> maxOperations;
    Solution sol;
    int result = sol.minimumSize(nums, maxOperations);
    cout << result << endl;
    return 0;
}
