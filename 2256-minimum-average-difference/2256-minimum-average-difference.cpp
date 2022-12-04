class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int idx = -1, ans = INT_MAX;
        int n = nums.size();
        vector<long long> pref(n);
        pref[0] = 1ll*nums[0];
        for(int i = 1; i < n; i++){
            pref[i] = pref[i-1]+1ll*nums[i];
        }
    long long sum=accumulate(nums.begin(), nums.end(), 0ll);
        
        
        for(int i = 0; i < n; i++){
            int t1 = (pref[i]) / (i+1); int t2 =0;
    if(i < n-1) t2 = (sum - pref[i])/(n-i-1);
            int dif = abs(t1 - t2);
            if(dif < ans){
                ans = dif;
                idx = i;
            }
         }
         for(int i = 0; i < n; i++){
            int t1 = (pref[i]) / (i+1), t2 = 0;
     if(i < n-1)  t2 = (sum - pref[i])/(n-i-1);
            int dif = abs(t1 - t2);
            if(dif==ans){
                
                idx = i; break;
            }
         }
        return idx;
    } 
};