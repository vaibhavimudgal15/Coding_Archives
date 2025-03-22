class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<bool> visited(n, false);
        
        for (auto &it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        int ans = 0;
        queue<int> q;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                vector<int> otherComps;
                q.push(i);
                visited[i] = true;

                while (!q.empty()) {
                    int node = q.front();
                    q.pop();
                    otherComps.push_back(node);

                    for (int neighbor : adj[node]) {
                        if (!visited[neighbor]) {
                            visited[neighbor] = true;
                            q.push(neighbor);
                        }
                    }
                }
                bool gotIt = true;
                int size = otherComps.size();
                for (int node : otherComps) {
                    if (adj[node].size() != size - 1) {
                        gotIt = false;
                        break;
                    }
                }

                if (gotIt) ans++;
            }
        }
        
        return ans;
    }
};