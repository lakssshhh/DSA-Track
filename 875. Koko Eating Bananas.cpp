class Solution {
public:
       bool canFinish(const vector<int>&piles, int h, int k){
        long long hours = 0;
        for (int pile: piles){
            hours += pile/k;
            if(pile % k !=0) hours ++;
            if(hours > h)return false;
        }
        return hours <=h;
       }


    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1 ; 
        int high =  *max_element(piles.begin(), piles.end());
        int ans = INT_MAX;
        while(low <= high){
            int mid = (low + high)/2;
            if(canFinish(piles,h,mid)){
                ans = mid ;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
       
        return ans;
    }
};
