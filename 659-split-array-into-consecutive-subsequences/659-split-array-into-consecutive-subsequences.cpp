class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> now, end;
        for(int i = 0; i < nums.size(); i++){
            now[nums[i]]++;
        }
        
        for(int i = 0; i < nums.size(); i++){
            if(!now[nums[i]]) continue;
            now[nums[i]]--;
            
            if(end[nums[i] -1] > 0){
                end[nums[i] - 1]--;
                end[nums[i]]++;
            }
            
            else if(now[nums[i]+1] and now[nums[i]+2]){
                now[nums[i]+1]--;
                now[nums[i]+2]--;
                end[nums[i]+2]++;
            }
            else return false;
            
        }
        return true;
    }
};