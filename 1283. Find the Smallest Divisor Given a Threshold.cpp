class Solution {
public:
    int sumofD(vector<int>& nums,int mid){
        int sum = 0;
        for(auto num:nums){
        sum +=(num + mid - 1) / mid;
        }
        return sum;
    }


    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1 ;
        int high = *max_element(nums.begin(), nums.end());
        int ans = -1;
        while(low<=high){
            int mid = (low+high)/2;
            if(sumofD(nums,mid)<=threshold){
                ans = mid;
                high =mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};
