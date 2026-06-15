class Solution {
public:
    int maxDepth(string s) {
        string c;
        int res = 0;
        int cur = 0;
        for(auto c:s){
            if(c == '('){
                cur++;
            }else if(c == ')'){
                cur--;
            }
            res = max(cur, res);
        }
return res;
    }
};
