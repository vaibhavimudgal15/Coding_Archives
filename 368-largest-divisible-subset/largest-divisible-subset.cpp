class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end()); // Step 1: Sort to simplify divisibility checks

        vector<int> count(n);  // DP: count[i] = length of largest subset starting at i
        vector<int> nextt(n);  // Backtracking: nextt[i] = next index in the subset chain

        int maxi = 0;          // Index of the largest subset start

        // Step 2: DP from the end to the beginning
        for (int i = n - 1; i >= 0; i--) {
            count[i] = 1;      // Base case: each element is a subset of size 1
            nextt[i] = -1;     // -1 indicates end of the subset

            // Step 3: Check all larger elements for valid division
            for (int j = i + 1; j < n && n - j + 1 > count[i]; j++) {
                if (nums[j] % nums[i] != 0) continue;

                if (count[j] + 1 > count[i]) {
                    count[i] = count[j] + 1;
                    nextt[i] = j; // Store the next element in the chain
                }
            }

            // Step 4: Track the global maximum
            if (count[maxi] < count[i]) {
                maxi = i;
            }
        }

        // Step 5: Backtrack to reconstruct the subset
        vector<int> answer;
        int i = maxi;
        while (i != -1) {
            answer.push_back(nums[i]);
            i = nextt[i];
        }

        return answer;
    }
};