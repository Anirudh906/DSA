class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
            map<int, int> mp;
            for(auto &x: target) mp[x]++;
        for(int i = 0; i < arr.size(); i++){
        if(mp.find(arr[i]) == mp.end()) return false;
            mp[arr[i]]--;
            if(mp[arr[i]] == 0) mp.erase(arr[i]);
        }
        return mp.size() == 0;
    }
};