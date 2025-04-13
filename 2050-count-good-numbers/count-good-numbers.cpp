#define mod 1000000007
class Solution {
public:
long long helper(long long n,long long k){
    if(k==0)return 1;
    if(k%2==0){
        long long ans=helper(n,k/2)%mod;
        return (ans%mod)*(ans%mod);
    }
     long long ans=helper(n,k-1)%mod;
        return (ans*n)%mod;
}
    int countGoodNumbers(long long n) {
       if(n%2==0){
           long long e=n/2;
           return (helper(5,e)%mod)*(helper(4,e)%mod)%mod;
       }
       long long e=n/2;
       return (helper(5,e+1)%mod)*(helper(4,e)%mod)%mod;
    }
};