class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
            int score = 0;
        sort(tokens.begin(),tokens.end());
        int l = 0, r = tokens.size()-1;
        
         while(l<=r){
                 if(power>=tokens[l]){
                 power -= tokens[l++];
                 score++;
             }
             else{
                 if(score>0 && r!=l){
                     power += tokens[r--];
                     score--;
                 }
                 else
                 break;
             }
         }
        return score;
    }
};