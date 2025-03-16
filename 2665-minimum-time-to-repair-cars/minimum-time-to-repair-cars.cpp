class Solution {
public:
    int n;
    
    // Function to check if all cars can be repaired within a given time
    bool CheckAllCarRepairPossible(vector<int>& ranks, long long time, int cars) {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += sqrt(time / ranks[i]); // Cars repaired by current mechanic
            if (sum >= cars) return true; // Early stopping condition
        }
        return false;
    }

    long long repairCars(vector<int>& ranks, int cars) {
        long long left = 0;
        long long right = *max_element(ranks.begin(), ranks.end()) * (long long)cars * cars;
        n = ranks.size();
        long long ans = right;

        // Binary search on time
        while (left <= right) {
            long long mid = left + (right - left) / 2;
            if (CheckAllCarRepairPossible(ranks, mid, cars)) {
                ans = mid;  // Possible answer found
                right = mid - 1;  // Try to minimize time
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }
};