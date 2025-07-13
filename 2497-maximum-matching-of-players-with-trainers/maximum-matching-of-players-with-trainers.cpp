class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& p, vector<int>& t) {
        //p->players  ,t->trainers
        sort(p.begin(),p.end());
        sort(t.begin(),t.end());
        int i=0;
        int j=0;
        int count=0;
        while(i<p.size() && j<t.size()){
            if(p[i]<=t[j]){
                count++;
                i++;
                j++;
            }
            else{
                j++;
            }
        }
        return count;
    }
};