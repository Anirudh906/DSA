class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
      vector<int> res;
      
        if(p.size() > s.size()) return res;
        vector<int> mp(26, 0);
        for(int i= 0; i < p.size(); i++){
           mp[p[i] - 'a']++;
        }
    
        
        int l = p.size();
       for(int j = 0; j < s.size() - l + 1; j++){
           vector<int> mp2(26, 0);
       
           for(int k = j; k < j + l; k++){
                mp2[s[k] - 'a']++;
           
           }
         
           int f = 1;
           for(int i = 0; i < 26; i++){
               if(mp[i] > mp2[i]) {
          
                   f = 0;
                   break;
               }
           }
           if(f) res.push_back(j); 
           
       }
        return res;
    }
};