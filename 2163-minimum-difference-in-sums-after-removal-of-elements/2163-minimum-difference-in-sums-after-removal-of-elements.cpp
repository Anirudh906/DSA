class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int n = nums.size();
        priority_queue<int> pq1;
        priority_queue<int, vector<int>, greater<int>> pq2;
        vector<long long> temp(n);
        long long l = 0, r = 0;
        for(int i = n -1; i >= n/3; i--){
            pq2.push(nums[i]);
            r += 1ll*nums[i];
            if(pq2.size() > n/3){
                r -= 1ll*pq2.top();
                pq2.pop();
            }
            if(pq2.size() == n/3){
                temp[i] = r;
            }
        }
        long long ans = LLONG_MAX;
        for(int i = 0; i < 2*n/3; i++){
            pq1.push(nums[i]);
            l += 1ll*nums[i];
            if(pq1.size() > n/3){
                l -= 1ll*pq1.top();
                pq1.pop();
            }
            if(pq1.size() == n/3){
                ans = min(ans, l-temp[i+1]);
            }
            
        }
        return ans;
        
    }
};