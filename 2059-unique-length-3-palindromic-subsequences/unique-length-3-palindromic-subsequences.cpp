class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.length();

        vector<pair<int , int>> indices(26 , {-1 , -1});
        for (int i = 0; i < n; i++) {
            char ch = s[i];
            int idx = ch - 'a';

            if (indices[idx].first == -1) indices[idx].first = i;
            indices[idx].second = i;
        }

        int res = 0;
        for (int i = 0; i < 26; i++) {
            int leftIdx = indices[i].first;
            int rightIdx = indices[i].second;

            if (leftIdx == -1) continue;

            unordered_set<char> st;
            for (int mid = leftIdx + 1; mid <= rightIdx - 1; mid++) {
                st.insert(s[mid]);
            }
            res += st.size();
        }
        return res;
    }
};