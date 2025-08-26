class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& rects) {
        int maxD = 0;
        int maxA = 0;

        for (auto &rect : rects) {
            int x = rect[0];
            int y = rect[1];
            int d = x * x + y * y;
            int a = x * y;

            if (d == maxD) {
                maxA = max(maxA, a);
                continue;
            }

            if (d > maxD) {
                maxD = d;
                maxA = a;
            }
        }

        return maxA;
    }
};