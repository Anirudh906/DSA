class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int  ans = INT_MAX, sum =0, curr =0;
        for(int i=0; i<n; i++){
            curr+= gas[i]-cost[i];
            
            if(curr>=0){
              ans = min(ans, i);
            }else{
                curr =0;
                ans =INT_MAX;
            }
            sum+=gas[i]-cost[i];
        }
        if(sum<0)return -1;
        else return ans;
        
    }
};