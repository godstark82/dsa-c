#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        long long count = 0;

        // Maps to count occurrences of A[i] - i and A[i] + i
        unordered_map<int, long long> diffMap;
        unordered_map<int, long long> sumMap;

        for (int i = 0; i < n; i++) {
            int diff = a[i] - i; // A[i] - i
            int sum = a[i] + i;  // A[i] + i
            
            // Count valid triplets for A[i] - i
            count += diffMap[diff]; // Count how many times this diff has been seen
            diffMap[diff]++; // Increment the count for this diff
            
            // Count valid triplets for A[i] + i
            count += sumMap[sum]; // Count how many times this sum has been seen
            sumMap[sum]++; // Increment the count for this sum
        }

        cout << count << endl;
    }

    return 0;
}
