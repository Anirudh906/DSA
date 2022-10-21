class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        map<int, int> mp;
        for(int i = 0; i <= min(n-1, k); i++){
            mp[nums[i]]++;
        }
        if(k >= n-1){
            for(auto &x: mp){
                if(x.second > 1) return true;
            }       
        }
        else {
        for(int i = k+1; i < n; i++){
            mp[nums[i]]++;
            mp[nums[i-k-1]]--;
            if(mp[nums[i]] > 1) return true;
        }
        }
        return false;
    }
};