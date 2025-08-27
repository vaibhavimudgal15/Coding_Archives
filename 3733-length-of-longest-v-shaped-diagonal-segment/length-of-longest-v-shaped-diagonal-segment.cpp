int dy[4] = {1,1,-1,-1};
int dx[4] = {-1,1,1,-1};
int dp[501][501][4][2][2];
class Solution {
public:
    int f(int i,int j,int dir,int cond,int turn,vector<vector<int>> &grid,int n,int m){
        int ans = 0;
        if(dp[i][j][dir][cond][turn] != -1) return dp[i][j][dir][cond][turn];
        int nx = i + dx[dir];
        int ny = j + dy[dir];
        if(nx < n && nx >= 0 && ny < m && ny >= 0 && grid[nx][ny] == 2*cond){
            ans = max(ans,1+f(nx,ny,dir,1-cond,turn,grid,n,m));
        }
        if(turn > 0){
            int next = (dir+1)%4;
            ans = max(ans,f(i,j,next,cond,turn-1,grid,n,m));
        }
        return dp[i][j][dir][cond][turn] = ans;
    }
    int lenOfVDiagonal(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        memset(dp,-1,sizeof(dp));
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j] == 1){
                    for(int dir = 0;dir<4;dir++){
                        ans = max(ans,1+f(i,j,dir,1,1,grid,n,m));
                    }
                    // ans = max(ans,f(i,j,1,grid));
                }
            }
        }
        return ans;
    }
};