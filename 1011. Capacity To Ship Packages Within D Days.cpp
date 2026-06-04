class Solution {
public:
    int iscap(vector<int>& weights,int mid){
        int day = 1,load = 0;
        int w = 0;
        for(auto w:weights){
            if(load+w>mid){
                day++;
                load = w;
            }
            else{
                load+=w;
            }
           

        } return day;}
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        while(low<=high){
            int mid = (low+high)/2;
            int noofdays = iscap(weights,mid);
            if(noofdays<=days){
                high = mid-1;
            }
            else{
            low = mid+1;
            }
        }
        return low;
    }
};
