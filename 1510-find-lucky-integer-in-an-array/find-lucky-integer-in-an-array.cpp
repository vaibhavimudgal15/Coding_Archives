class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> frequency;

        for (int num : arr) {
            frequency[num]++;
        }

        int result = -1;
        for (const auto& [num, count] : frequency) {
            if (num == count && num > result) {
                result = num;
            }
        }

        return result;
    }
};