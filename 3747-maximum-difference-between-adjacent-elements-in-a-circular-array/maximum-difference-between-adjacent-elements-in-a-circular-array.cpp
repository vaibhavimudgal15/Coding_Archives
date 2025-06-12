class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int maxDiff = INT_MIN, curr;
        int n = nums.size();

        for(int i = 0; i < n; i++) {
            curr = abs(nums[i % n] - nums[(i+1) % n]);
            
            maxDiff = max(maxDiff, curr);
        }

        return maxDiff;
    }
};