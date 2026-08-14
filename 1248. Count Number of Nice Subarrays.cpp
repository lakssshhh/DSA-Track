class Solution {
public:
 int atMostK(vector<int>& nums, int k) {
        int l=0;
        int ans =0;
        int oddCnt =0;
        for (int r = 0; r < nums.size(); r++){
         if(nums[r] % 2 != 0)
            oddCnt++;
        while(oddCnt > k) {
            if(nums[l] % 2 != 0)
                oddCnt--;
            l++;
        }
        ans = ans+(r-l+1);
        }
        return ans;
        } 
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMostK(nums, k) - atMostK(nums, k - 1);
    }
};
