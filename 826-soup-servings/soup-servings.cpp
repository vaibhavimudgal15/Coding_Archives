class Solution {
public:
    unordered_map<int, unordered_map<int, double>> memo;
    
    double soupServings(int n) {
        if (n >= 4800) return 1.0;
        return solve((n + 24) / 25, (n + 24) / 25);
    }
    
private:
    double solve(int a, int b) {
        if (a <= 0 && b <= 0) return 0.5;
        if (a <= 0) return 1.0;
        if (b <= 0) return 0.0;
        if (memo[a].count(b)) return memo[a][b];
        
        double result = 0.25 * (
            solve(max(0, a - 4), max(0, b - 0)) +
            solve(max(0, a - 3), max(0, b - 1)) +
            solve(max(0, a - 2), max(0, b - 2)) +
            solve(max(0, a - 1), max(0, b - 3))
        );
        
        return memo[a][b] = result;
    }
};