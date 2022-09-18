class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int n = s.length();
        int i = 0, j = 0;
        int res = 0;
        int k = 2;
        unordered_map<int, int> mp;
        for(; j < s.size(); j++){
           if(!mp[s[j] - 'a']++) k--;
            while(k < 0){
                if(!--mp[s[i] - 'a'])k++;
                i++;
                 
            }
            res = max(res, j - i + 1);
         
        }
        return res;
    }
};
 