class Solution {
public:
    bool isprime(int n){
        if(n == 2)return true;
            if(n == 1 || n % 2 == 0) return false;
            for(int i = 3 ; i <= sqrt(n) ; i+=2){
                if(n % i == 0){
                    return false;
                }
            }
            return true;
        }
    vector<int> closestPrimes(int left, int right) {
        vector<int>range;
        for(int j = left ; j <= right ; j++){
            if(isprime(j)){
                range.push_back(j);
            }
        }
        if(range.size() < 2){
            return {-1,-1};
        }
        vector<int>ans;
        int minele = INT_MAX;
        for(int k = 0 ; k < range.size() - 1 ; k++){
            if(range[k+1] - range[k] < minele){
                ans = {range[k],range[k+1]};
                minele = range[k+1] - range[k];
            }
        }
        return ans;
    }
};