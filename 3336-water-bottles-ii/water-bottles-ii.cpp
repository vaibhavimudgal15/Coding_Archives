class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int full = numBottles;
        int empty = 0;
        int ans = 0;
        int curEx = numExchange;

        while (full > 0) {
            ans += full;
            empty += full;
            full = 0;

            while (empty >= curEx) {
                empty -= curEx;
                full += 1;
                curEx += 1;
            }
        }
        return ans;
    }
};