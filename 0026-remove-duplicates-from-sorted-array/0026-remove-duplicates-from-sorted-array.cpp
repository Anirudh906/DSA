class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        for(auto &x: nums){
            if(i < 1 || x > nums[i-1]){
                nums[i++] = x;
            }
        }
        return i;
    }
};