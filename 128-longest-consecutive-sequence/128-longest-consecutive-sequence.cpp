class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
      if(nums.empty()) return 0;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int res = 0, temp = 1;
        for(int i = 1; i < n; i++){
            if(nums[i] == nums[i - 1]) continue;
            if(nums[i] == nums[i - 1] + 1)temp++;
            else{
                res = max(res, temp);
                temp = 1;
                
            }
            
        }
        return max(res, temp);
    }
};