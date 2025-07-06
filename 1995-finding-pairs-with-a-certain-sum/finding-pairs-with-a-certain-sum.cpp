class FindSumPairs {
public:
    vector<int> nums1;
    vector<int> nums2;
    unordered_map<int, int> mp1;
    unordered_map<int, int> mp2;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        this->nums1 = nums1;
        this->nums2 = nums2;
        for (auto it : nums1)
        {
            mp1[it]++;
        }
        for (auto it : nums2)
        {
            mp2[it]++;
        }
    }
    
    void add(int index, int val) {
        mp2[nums2[index]]--;
        nums2[index] += val;
        mp2[nums2[index]]++;
    }
    
    int count(int tot) {
        int cnt = 0;
        for (auto& it : mp1)
        {
            int temp = tot - it.first;
            if (mp2[temp] != 0)
            {
                cnt += it.second * mp2[temp];
            }
        }
        return cnt;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */