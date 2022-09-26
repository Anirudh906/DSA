class Solution {
public:
       int parent[26];
    
    int find(int val){
        if(val != parent[val]){
            parent[val] = find(parent[val]);
        }
        return parent[val];
    }
    
    bool equationsPossible(vector<string>& equations) {
        for(int i=0;i<26;i++){
            parent[i] = i;
        }
        for(string s: equations){
            if(s[1] == '='){
                int first = s[0]-'a';
                int last = s[3]-'a';
                parent[find(last)] = find(first); 
            }
        }
        for(string s: equations){
            if(s[1] == '!'){
                int first = s[0]-'a';
                int last = s[3]-'a';
                if(find(first) == find(last)){
                    return false;
                }
            }
        }
        return true;
    }   
   
};