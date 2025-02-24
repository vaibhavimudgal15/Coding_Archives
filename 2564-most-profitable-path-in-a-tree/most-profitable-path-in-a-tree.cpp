class Solution {
public:
    bool bobDfs(int pre, int cur, vector<vector<int>> &g, vector<int> &bobPath) {
        if (cur == 0) {
            bobPath.push_back(cur);
            return true;
        }
        for (auto &x: g[cur]) {
            if (x == pre) continue;
            if (bobDfs(cur, x, g, bobPath)) {
                bobPath.push_back(cur);
                return true;
            }
        }
        return false;
    }

    int ans = INT_MIN;
    void aliceDfs(int pre, int cur, int total, int step, vector<int> &bobPath, vector<vector<int>> &g, vector<int> &amount) {
        if (cur != 0 && g[cur].size() == 1) {
            ans = max(ans, total);
            return;
        }
        for (auto &x: g[cur]) {
            if (x == pre) continue;
            if (step + 1 < bobPath.size() && bobPath[step + 1] == x) {
                total += amount[x] / 2;
            } else {
                total += amount[x];
            }
            int record = 0;
            if (step + 1 < bobPath.size()) {
                record = amount[bobPath[step + 1]];
                amount[bobPath[step + 1]] = 0;
            }
            aliceDfs(cur, x, total, step + 1, bobPath, g, amount);
            if (step + 1 < bobPath.size()) {
                amount[bobPath[step + 1]] = record;
            }
            if (step + 1 < bobPath.size() && bobPath[step + 1] == x) {
                total -= amount[x] / 2;
            } else {
                total -= amount[x];
            }
        }
    }

    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = amount.size();
        vector<vector<int>> g(n);
        for (auto &x: edges) {
            g[x[0]].push_back(x[1]);
            g[x[1]].push_back(x[0]);
        }

        vector<int> bobPath;
        bobDfs(-1, bob, g, bobPath);
        reverse(bobPath.begin(), bobPath.end());
        
        amount[bobPath[0]] = 0;
        aliceDfs(-1, 0, amount[0], 0, bobPath, g, amount);
        return ans;
    }
};