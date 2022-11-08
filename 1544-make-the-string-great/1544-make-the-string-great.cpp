class Solution {
public:
    string makeGood(string s) {
        string str="";
        for(int i=0; i<s.size(); i++){
              if(str.empty()){
                   str+=s[i];
               }
              else if(abs(str.back()-s[i])==32){
                   str.pop_back();
                }
              else{
                    str+=s[i];
               }
          }
        return str;
    }
};