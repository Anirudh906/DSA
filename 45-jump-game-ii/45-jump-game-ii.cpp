class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        
        int curEnd = 0,  jumps = 0, farthest = 0;
        for(int i = 0; i < n-1; i++){
            farthest = max(farthest, i + nums[i]);
            if(i == curEnd){
                jumps++;
                curEnd = farthest;
            }
        }
        return jumps;
    }
};