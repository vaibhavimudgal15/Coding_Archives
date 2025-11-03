class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size();
        vector<int> dp(n, 0);
        for(int i = 1; i < n; i++)
        {
            if(colors[i] == colors[i - 1])
            {
                dp[i] = dp[i - 1] + min(neededTime[i], neededTime[i - 1]);
                neededTime[i] = max(neededTime[i], neededTime[i - 1]);
            }
            else
            {
                dp[i] = dp[i - 1];
            }
        }
        return dp[n - 1];
    }
};