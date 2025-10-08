class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {

        sort(potions.begin(),potions.end());

        vector<int> ans;
        for(auto x: spells)
        {
            long long minval=success/x;
            if(success%x) minval++;

            auto it = lower_bound(potions.begin(),potions.end(),minval);
            int cnt = potions.end()-it;
            ans.push_back(cnt);
        }

        return ans;
        
    }
};