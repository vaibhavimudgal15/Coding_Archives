class Solution {
public:
    int totalMoney(int n) {
        int weeks = n / 7;
        int days = n % 7;

        int total = 28 * weeks + 7 * (weeks * (weeks - 1)) / 2;

        int start = weeks + 1;
        total += (2 * start + (days - 1)) * days / 2;

        return total;
    }
};