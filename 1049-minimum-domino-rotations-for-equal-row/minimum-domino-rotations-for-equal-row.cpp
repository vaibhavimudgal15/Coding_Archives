class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        vector<int>cnta(7,0),cntb(7,0),same(7,0);
        for(int i=0;i<tops.size();i++){
            cnta[tops[i]]++;
            cntb[bottoms[i]]++;
            if(tops[i]==bottoms[i])same[tops[i]]++;
        }
        for(int i=1;i<=6;i++){
            if(cnta[i]+cntb[i]-same[i]==tops.size())return min(cnta[i],cntb[i])-same[i];
        }
        return -1;
    }
};