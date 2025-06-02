class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> candies(n, 1);
        
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;
        for (int i = 0; i < n; ++i) {
            minHeap.push({ratings[i], i});
        }

        while (!minHeap.empty()) {
            auto [rating, i] = minHeap.top();
            minHeap.pop();

        
            if (i > 0 && ratings[i] > ratings[i - 1]) {
                candies[i] = max(candies[i], candies[i - 1] + 1);
            }

        
            if (i < n - 1 && ratings[i] > ratings[i + 1]) {
                candies[i] = max(candies[i], candies[i + 1] + 1);
            }
        }

        return accumulate(candies.begin(), candies.end(), 0);
    }
};