class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
       vector<int> res;
        int l = nums.size();
        int sum=0;
        map<int, int> s;
        for(int i=0; i<l; i++){
            s[nums[i]]++;
        }
        for(auto x : s)sum+=x.first;
        int sum1=l*(l+1)/2;
        int diff=sum1-sum;
        int duplicate=-1;
        for(auto x:s)if(x.second==2){duplicate=x.first;break;} 
        res.push_back(duplicate); res.push_back(diff);
        return res;
    }
};