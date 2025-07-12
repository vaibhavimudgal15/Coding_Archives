class Solution {
public:
    vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
        return DFS(n, min(firstPlayer, secondPlayer), max(firstPlayer, secondPlayer));
    }
    vector<int> DFS(int n, int left, int right){
        if (left + right == n + 1)
            return {1, 1};
        if (n == 3 || n == 4)
            return {2, 2};
        if (left - 1 > n - right){
            int temp = n + 1 - left;
            left = n + 1 - right;
            right = temp;
        }
        int nextRound = (n + 1) / 2;
        int minRound = n, maxRound = 1;
        if (right * 2 <= n + 1){
            int preL = left - 1;
            int gap = right - left - 1;
            for (int i = 0; i <= preL; i++){
                for (int j = 0; j <= gap; j++){
                    auto res = DFS(nextRound, i + 1, i + j + 2);
                    minRound = min(minRound, 1 + res[0]);
                    maxRound = max(maxRound, 1 + res[1]);

                }
            }
        } else {
            int preR = n + 1 - right;
            int preL = left - 1;
            int mid = preR - left - 1;
            int innerGap = right - preR - 1;
            for (int i = 0; i <= preL; i++){
                for (int j = 0; j <= mid; j++){
                    int pos1 = i + 1;
                    int pos2 = i + j + 1 + (innerGap + 1) / 2 + 1;
                     auto res = DFS(nextRound, pos1, pos2);
                    minRound = min(minRound, 1 + res[0]);
                    maxRound = max(maxRound, 1 + res[1]);
                }
            }
        }
        return {minRound, maxRound};

    }
};