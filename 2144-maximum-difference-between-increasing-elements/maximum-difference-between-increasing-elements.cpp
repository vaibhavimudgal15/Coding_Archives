class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int ans = -1;
        for(int j = 0; j < n; j++) {
            if(j > i && nums[j] > nums[i]) {
                int diff = nums[j] - nums[i];
                ans = max(ans, diff);
            } else {
                i = j;
            }
        }
        return ans;
    }
};