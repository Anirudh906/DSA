class Solution {
public:
    long long numberOfWeeks(vector<int>& milestones) {
        long long sum = 0, mx = 0;
        for(int i= 0; i < milestones.size(); i++){
            sum += (long long)milestones[i];
            mx = max(mx, (long long)milestones[i]);
        }
        long long t = sum - mx;
        if(t >= mx){
            return sum;
        }
        else return 2LL*(t) + 1LL;
        
    }
};