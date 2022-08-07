class Solution {
public:
    int countVowelPermutation(int n) {
        vector<vector<int>> r = {{1,2,4},{0,2},{1,3},{2},{2,3}};
        int mod = 1e9 + 7;
        
        vector<long long> vowel(5, 1), cvowel;
        
        while(--n){
            cvowel = vowel;
            for(int i = 0; i < 5; i++){
                vowel[i] = 0;  
                for(auto &q: r[i]){
                      vowel[i] += cvowel[q]; vowel[i] %= mod;
                  }
            }
        }
        long long res = 0;
        for(auto &c: vowel){
            res += c; res %= mod;
        }
        return res;
    }
};