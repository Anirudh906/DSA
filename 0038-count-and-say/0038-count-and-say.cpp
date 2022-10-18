class Solution {
public:
    string countAndSay(int n) {
       if(n == 0) return "";
        string res = "1";
        n--;
        while(n--){
            string cur = "";
        
            for(int i= 0; i < res.length(); i++){
                int curCount = 1;
                while((i+1) < res.length() and (res[i] == res[i+1])){
                    i++;
                    curCount++;
                }
                cur += to_string(curCount) + res[i]; 
            }
            
            res = cur;
        }
         
        return res; 
    }
};