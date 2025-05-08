struct Node {
    int time;
    bool state;
    int i;
    int j;

    bool operator>(const Node& other) const {
        return time > other.time;
    }
};
class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size(), m = moveTime[0].size();
        priority_queue<Node, vector<Node>, greater<Node>> pq;
        pq.push({0,0,0,0});
        vector<vector<int>> time(n, vector<int>(m, INT_MAX));
        time[0][0] = 0;
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, -1, 0, 1};
        while(!pq.empty()){
            auto it = pq.top();
            int t = it.time;
            int r = it.i;
            int c = it.j;
            int altTime = it.state;
            pq.pop();
            for(int i = 0; i < 4; i++){
                int delrow = r + drow[i];
                int delcol = c + dcol[i];
                if(delrow >= 0 && delrow < n && delcol >= 0 && delcol < m){
                    int mTime = moveTime[delrow][delcol];
                    int newTime = max(mTime+1+altTime, t+1+altTime);
                    if(newTime < time[delrow][delcol]){
                        time[delrow][delcol] = newTime;
                        pq.push({newTime, !altTime, delrow, delcol});
                    }
                }
            }
        }
        return time[n-1][m-1];
    }
};