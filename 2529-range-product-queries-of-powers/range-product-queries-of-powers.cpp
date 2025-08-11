class Solution {
private:
    static const int MOD = 1000000007;
    
    long long modPow(long long base, long long exp) {
        long long result = 1;
        base %= MOD;
        while (exp > 0) {
            if (exp & 1) {
                result = (result * base) % MOD;
            }
            base = (base * base) % MOD;
            exp >>= 1;
        }
        return result;
    }
    
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> exponents;
        int bit_position = 0;
        
        while (n > 0) {
            if (n & 1) {
                exponents.push_back(bit_position);
            }
            n >>= 1;
            bit_position++;
        }
        
        vector<long long> prefix(exponents.size() + 1, 0);
        for (int i = 0; i < exponents.size(); i++) {
            prefix[i + 1] = prefix[i] + exponents[i];
        }
        
        vector<int> answers;
        for (auto& query : queries) {
            int left = query[0];
            int right = query[1];
            
            long long exp_sum = prefix[right + 1] - prefix[left];
            
            int result = modPow(2, exp_sum);
            answers.push_back(result);
        }
        
        return answers;
    }
};