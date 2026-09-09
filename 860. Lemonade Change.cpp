class Solution {
public:
   bool lemonadeChange(vector<int>& bills) {
    int fiveCnt = 0, tenCnt = 0;
    for (auto bill : bills) {
        if (bill == 5)
            fiveCnt++;
        else if (bill == 10) {
            tenCnt++;
            fiveCnt--;
        } else {
            if (tenCnt) {
                tenCnt--;
                fiveCnt--;
            } else
                fiveCnt -= 3;
        }
        if (fiveCnt < 0)
            return false;
    }
    return true;
}
};
