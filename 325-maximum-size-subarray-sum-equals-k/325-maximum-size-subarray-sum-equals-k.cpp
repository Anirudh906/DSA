class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
     int n = nums.size();
        long long cur_sum = 0;
        int mx_l = 0;
        unordered_map<long long, int> mp;
        for(int i = 0; i < nums.size(); i++){
            cur_sum += nums[i];
            if(cur_sum == k) mx_l = max(mx_l, i + 1);
            
            else if(mp.find(cur_sum - k) != mp.end()){
                mx_l = max(mx_l, max(0, i + 1 - mp[cur_sum - k]));
            }
            if(mp.find(cur_sum) == mp.end()){
                mp[cur_sum] = i + 1;
            }
         }
        
        return mx_l;
    }
};