class Solution {
public:
    int maximumInvitations(vector<int>& favorite) {
        // Intuition :Since each node will have only one outdegree, so it will
        // have a cycle . If the cycle length is 2 it will generally act as
        // chain and more such chains can be added so thus we add chain length
        // And finally we find the length of total chains and cycle chain max
        // length ....
        int n = favorite.size();
        vector<int> indegree(n, 0);
        vector<int> chain(n, 0);
        vector<bool> vis(n, false);
        for (int i : favorite) {
            indegree[i]++;
        }
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (!indegree[i]) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int front = q.front();
            q.pop();
            vis[front] = true;
            int next = favorite[front];
            chain[next] = chain[front] + 1;
            if (--indegree[next] == 0) {
                q.push(next);
            }
        }

        int maxCycle = 0, total = 0;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                int c = i, len = 0;
                while (!vis[c]) {
                    vis[c] = true;
                    c = favorite[c];
                    len++;
                }
                if (len == 2) {
                    total += (2 + chain[i] + chain[favorite[i]]);
                } else {
                    maxCycle = max(maxCycle, len);
                }
            }
        }
        return max(total, maxCycle);
        //Overall Time Complexity :O(N)
        //Space COmplexity :O(N)
    }
};