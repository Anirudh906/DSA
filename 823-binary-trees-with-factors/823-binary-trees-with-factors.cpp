class Solution {
public:
    const int mod = 1e9 + 7;
    int numFactoredBinaryTrees(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        unordered_map<int, long long> mp;
        mp[arr[0]] = 1;
        for(int i = 1; i < n; i++){
            long long c = 1;
            for(auto &x: mp){
                if((arr[i] % x.first == 0) and mp.count(arr[i]/x.first)){
                    c += 1ll*mp[x.first] * mp[arr[i]/x.first];
                }
            }
              mp[arr[i]]= c;
        }
        long long ans = 0;
        for(auto &y: mp){
            ans = (ans + 1ll*y.second) % mod;
        }
        return ans;
    }
};