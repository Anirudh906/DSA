class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        vector<int> goodDays;
        int n = security.size();
        vector<int> pref(n), suff(n);
        
        pref[0] = 0;
        for(int i = 1; i < n; i++){
            if(security[i] <= security[i - 1]) 
            { pref[i] = 1;
            pref[i] += pref[i - 1];
            }
        }
        suff[n - 1] = 0;
        for(int j = n - 2; j >= 0; j--){
            if(security[j + 1] >= security[j]){
                suff[j] = 1;
             suff[j] += suff[j + 1];
            }
        }
        
        for(int k = time; k + time < n; k++){
            if(pref[k] >= time and suff[k] >= time){
                goodDays.push_back(k);
            }
        }
        
        return goodDays;
    }
};