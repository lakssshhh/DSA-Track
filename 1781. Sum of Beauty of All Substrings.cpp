class Solution {
public:
int ans = 0;
    int beautySum(string s) {
        for(int i = 0; i<s.length();i++){
            map<char,int>mp;
            for(int j =i; j<s.length();j++){
                mp[s[j]]++;
                int leastfreq = INT_MAX;
                int mostfreq = INT_MIN;
                for(auto it:mp){
                    leastfreq = min(leastfreq,it.second);
                    mostfreq = max(mostfreq, it.second);

                }
                ans+= mostfreq-leastfreq;
            }
        }
        return ans;
    }
};
