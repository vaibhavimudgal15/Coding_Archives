class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        string s = "";
        k--; // Convert to 0-based index

        // Convert k to binary (least significant bit first)
        while (k) {
            s += (k & 1) + '0';
            k >>= 1;
        }

        int res = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1') {
                res += operations[i];  // Only apply shift if the bit is set
            }
        }

        return 'a' + res % 26;
    }
};