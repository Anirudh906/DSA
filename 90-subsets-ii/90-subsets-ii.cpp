class Solution {
public:
  void helper(vector<int> &nums, int i, vector<int>&temp, vector<vector<int>> &res){
       
       res.push_back(temp);
       
      for(int j = i; j != nums.size(); j++){
          if(j == i || nums[j] != nums[j - 1]){
              temp.push_back(nums[j]);
              helper(nums, j + 1, temp, res);
              temp.pop_back();
          }
         // helper(nums, i + 1, temp, res);
      }
     }
    
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> temp;
        vector<vector<int>> res;
      sort(nums.begin(), nums.end());
        helper(nums, 0, temp, res);
        return res;
    }
};