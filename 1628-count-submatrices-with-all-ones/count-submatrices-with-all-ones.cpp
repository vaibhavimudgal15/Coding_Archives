class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size(), ans = 0;
        vector<int> height(n);
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                height[j] = mat[i][j] == 0? 0: height[j] + 1;
                int minHeight = height[j];
                for(int k = j; k >= 0 && minHeight > 0; k--) {
                    minHeight = min(minHeight, height[k]);
                    ans += minHeight;
                }
            }
        }
        return ans;
    }
};