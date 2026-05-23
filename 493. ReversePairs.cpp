class Solution {
public:
    int rev_pair = 0;

void merge(int start, int mid, int end, vector<int>& nums){
    int left_size = mid - start + 1;
    int right_size = end - mid;
    vector<int> left(left_size);
    vector<int> right(right_size);

    for(int i = 0; i < left_size; i++){
        left[i] = nums[start + i];
    }
    for(int i = 0; i < right_size; i++){
        right[i] = nums[mid + 1 + i];
    }
    int m = 0;
    for(int i = 0; i < left_size; i++){
        while(m < right_size && left[i] > (long long)2 * right[m]){
            m++;
        }
        rev_pair += m;
    }

    int i = 0, j = 0, k = start;
    while(i < left_size && j < right_size){
        if(left[i] > right[j]){
            nums[k++] = right[j++];
        }
        else{
            nums[k++] = left[i++];
        }
    }
    while(i < left_size){
        nums[k++] = left[i++];
    }
    while(j < right_size){
        nums[k++] = right[j++];
    }
}

void mergesort(int start, int end, vector<int>& nums){
    if(start >= end)
        return;
    int mid = start + (end - start) / 2;
    mergesort(start, mid, nums);
    mergesort(mid + 1, end, nums);
    merge(start, mid, end, nums);
}

int reversePairs(vector<int>& nums) {
    rev_pair = 0;
    mergesort(0, nums.size() - 1, nums);
    return rev_pair;
}

};
