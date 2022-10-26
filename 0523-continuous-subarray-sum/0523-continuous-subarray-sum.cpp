class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        set<int> st;
        int curSum = 0, lstSum = 0;
        for(int i = 0; i < n; i++){
            curSum += nums[i];
            if(st.count(curSum % k)) return true;
            st.insert(lstSum % k);
            lstSum = curSum;
        }
        return false;
    }
};