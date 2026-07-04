class Solution {
public:
 const long long MOD = 1e9 + 7;
 long long myPow(long long x, long long n) {
        if(n==0) return 1;
        if(n%2==0){
            return myPow(x*x%MOD, n/2);
        }
        else{
            return x*myPow(x, n-1)% MOD;
        }
    }
    int countGoodNumbers(long long n) {
    long long even = (n + 1) / 2; 
    long long odd = n / 2;       

    return (myPow(5, even) * myPow(4, odd)) % MOD;
}
};
