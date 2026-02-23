#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    long long total = 0;
    for(int bit = 0; bit < 32; bit++) {
        long long ones = 0;
        for(int i = 0; i < n; i++) {
            if(arr[i] & (1LL << bit)) {
                ones++;
            }
        }
        long long zeros = n - ones;
        total += ones * zeros * 2;
    }
    cout << total;
    return 0;
}
