class Solution {
public:
    int twoSum(vector<int> &nums, int strt, int t){
        int low = strt, high = nums.size() - 1;
        int sum = 0;
        while(low < high){
            if(nums[low] + nums[high] < t){
                sum += (high - low);
                low ++;
            }
            else{
                high--;
            }
            
        }
        
        return sum;
    }
    
    
    
    
    int threeSumSmaller(vector<int>& nums, int target) {
        if(nums.size() < 3) return 0;
        sort(nums.begin(), nums.end());
        int sum = 0;
        for(int i = 0; i <= nums.size() - 2; i++){

        sum += twoSum(nums, i + 1, target - nums[i]);
        }
        return sum;
    }
};