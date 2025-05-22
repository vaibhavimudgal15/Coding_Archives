class Solution {
public:
    int maxRemoval(vector<int>& n, vector<vector<int>>& queries) {
        priority_queue<int> availableQ;
        priority_queue<int, vector<int>, greater<int>> appliedQ;
        sort(queries.begin(), queries.end());
        int s = 0;
        int l = n.size();
        int k = queries.size();
        int sk = 0;
        for(int i = 0; i < l; i++){
            while(s < k and queries[s][0] == i){
                availableQ.push(queries[s][1]);
                s++; }
            n[i] -= appliedQ.size();
            while(n[i] > 0 and not availableQ.empty() and availableQ.top() >= i){
                sk++;
                appliedQ.push(availableQ.top());
                availableQ.pop();
                n[i]--;}
            if (n[i] > 0) return -1;
            while(not appliedQ.empty() and appliedQ.top() == i){
                appliedQ.pop(); }  }
        return k - sk;
    }
};