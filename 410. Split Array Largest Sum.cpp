class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(),0);
        int ans = high;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(isdividable(nums,mid,k)){
                ans= mid;
                high = mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
    bool isdividable(vector<int>& nums,int MaxSum, int k){
        int count = 1;
        int currentSum = 0;
        for (int num:nums){
            currentSum+=num;
            if(currentSum>MaxSum){
                count++;
                currentSum = num;
                if(count>k)return false;
            }
        }
return true;
    }
};
