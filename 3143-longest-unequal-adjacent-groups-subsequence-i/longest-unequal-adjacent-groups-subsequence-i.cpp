class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups)
    {
        //time complexity: O(n)
        //space complexity: O(n): due to vector 'ans'

        int i;
        vector<string> ans;

        //inserting the 1st string of vector 'words'
        ans.push_back(words[0]);
        for(i=1;i<groups.size();i++)
        {
            //if 'current binary-number' is not equal to its 'previous binary-number', insert it to vector 'ans'
            if(groups[i]!=groups[i-1])
                ans.push_back(words[i]);
        }    
        return ans;
    }
};