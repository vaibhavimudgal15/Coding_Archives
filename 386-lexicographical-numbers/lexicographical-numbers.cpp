class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> res;
        res.reserve(n);
        int curr = 1;
        for(int i = 0; i < n; ++i) {
            res.push_back(curr);
            if(curr * 10 <= n) {
                curr *= 10;
            } else {
                if(curr >= n) curr /= 10;
                curr += 1;
                while(curr % 10 == 0) curr /= 10;
            }
        }
        return res;
    }
};