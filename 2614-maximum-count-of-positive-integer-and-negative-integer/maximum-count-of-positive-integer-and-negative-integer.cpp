#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int neg = 0, n = nums.size();

        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) continue;
            else if (neg == 0 && nums[i] > 0) return n - i;
            else if (nums[i] < 0) neg++;
            else if (nums[i] > 0) return max(neg, n - i);
        }

        return max(neg, 0);
    }
};