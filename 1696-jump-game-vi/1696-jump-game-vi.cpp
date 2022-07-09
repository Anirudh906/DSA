class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        vector<int> dp(nums.size());
        dp[0] = nums[0];
        deque<int> dq = {0};     		
       for(int i = 1; i < nums.size(); i++){
           if(dq.front() < i - k) dq.pop_front();
           dp[i] = nums[i] + dp[dq.front()];
           
           while(!dq.empty() and dp[i] >= dp[dq.back()]){
               dq.pop_back();
           }
           dq.push_back(i);
       }
        return dp[nums.size() - 1];            

    }
};

