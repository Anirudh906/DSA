class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //(n - k + 1)th element or (n - k)
        
        int l = 0, r = nums.size() - 1;
        int n = nums.size();
        while(l <= r){
            int p = partition(nums, l, r);
            if(p == (n - k)){
                return nums[p];
            }
            else if(p < (n - k)){
                l = p + 1;
            }else{
                r = p - 1;
            }
        }
           return -1;           
 }
    //lomuto
    int partition(vector<int>&nums, int l, int r){
        int i = l - 1;
        int pivot = r; //pivot index
        
        for(int j = l; j <= r - 1; j++){
            if(nums[j] < nums[pivot]){
                i++;
                swap(nums[j], nums[i]);
            }
            
        }
        swap(nums[i + 1], nums[pivot]);
        return i + 1;
    }
};