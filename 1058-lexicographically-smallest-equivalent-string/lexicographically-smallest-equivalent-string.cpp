#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // parent[i] will hold the representative (root) of character 'a' + i
    vector<int> parent;

    // Find with path compression
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    // Union by choosing the lexicographically smaller root as the new parent
    void unite(int a, int b) {
        int ra = find(a);
        int rb = find(b);
        if (ra == rb) return;
        if (ra < rb) {
            parent[rb] = ra;
        } else {
            parent[ra] = rb;
        }
    }

    string smallestEquivalentString(string s1, string s2, string baseStr) {
        // Initialize DSU for 26 lowercase letters
        parent.resize(26);
        for (int i = 0; i < 26; ++i) {
            parent[i] = i;
        }

        // Merge equivalent characters
        for (int i = 0; i < (int)s1.size(); ++i) {
            int x = s1[i] - 'a';
            int y = s2[i] - 'a';
            unite(x, y);
        }

        // Build result by mapping each character in baseStr to its group root
        string ans = baseStr;
        for (int i = 0; i < (int)baseStr.size(); ++i) {
            int idx = baseStr[i] - 'a';
            int root = find(idx);
            ans[i] = char(root + 'a');
        }
        return ans;
    }
};