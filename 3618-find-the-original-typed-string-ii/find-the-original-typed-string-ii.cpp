class Solution {
public:
    int possibleStringCount(string s, int k) {
        int n = s.length();
        const int MOD = 1e9 + 7;

        vector<int> groupCounts;   // Stores count of consecutive characters
        int currentCount = 0;
        char currentChar = s[0];

        // Group consecutive characters and store their frequencies
        for (int i = 0; i < n; i++) {
            if (s[i] != currentChar) {
                groupCounts.push_back(currentCount);
                currentChar = s[i];
                currentCount = 0;
            }
            currentCount++;
        }
        groupCounts.push_back(currentCount);  // Push the last group count

        // Calculate the product of all group counts
        long long totalWays = 1;
        for (auto count : groupCounts) {
            totalWays = (totalWays * count) % MOD;
        }

        // If we already have enough distinct character groups
        if (groupCounts.size() >= k) {
            return totalWays;
        }

        // We need to add (k - 1 - current group count) extra characters
        int requiredExtra = k - 1 - groupCounts.size();

        // DP array: dp[i] = number of ways to distribute i extra picks
        vector<long long> dp(k + 1, 0);
        dp[0] = 1;

        // Dynamic Programming + Prefix sum optimization
        for (auto count : groupCounts) {
            vector<long long> prefix(k + 1, 0);

            for (int i = 0; i <= requiredExtra; i++) {
                prefix[i + 1] = (prefix[i + 1] + dp[i]) % MOD;
                prefix[min(k, i + count)] = (prefix[min(k, i + count)] - dp[i] + MOD) % MOD;
            }

            // Convert prefix diff to prefix sum
            for (int i = 1; i <= requiredExtra; i++) {
                prefix[i] = (prefix[i] + prefix[i - 1]) % MOD;
            }

            // Update dp with new values
            for (int i = 0; i <= requiredExtra; i++) {
                dp[i] = (dp[i] + prefix[i]) % MOD;
            }
        }

        // Subtract invalid combinations (where same group is used multiple times)
        for (int i = 0; i <= requiredExtra; i++) {
            totalWays = (totalWays - dp[i] + MOD) % MOD;
        }

        return totalWays;
    }
};