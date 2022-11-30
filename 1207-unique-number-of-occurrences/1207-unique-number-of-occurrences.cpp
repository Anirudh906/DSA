class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
     int n = arr.size();
        map<int, int> mp;
        for(int i = 0; i < n; i++){
            mp[arr[i]]++;
        }
        vector<int> s;
        for(auto x: mp){
            s.push_back(x.second);
        }
        mp.clear();
        for(int i = 0; i < s.size(); i++){
            mp[s[i]]++;
        }
        for(auto y: mp){
            if(y.second > 1) return false;
        }
        return true;
    }
};