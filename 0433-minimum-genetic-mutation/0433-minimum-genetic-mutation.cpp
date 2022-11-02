class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        queue<pair<string, int>> q;
        unordered_set<string> s(bank.begin(), bank.end());
        q.push({start, 0}); 
        
        while(!q.empty()){
            string word = q.front().first;
            int count = q.front().second;
            q.pop();
            
            if(word == end) return count;
            for(int i = 0; i < word.size(); i++){
                string original = word;
                for(char ch: "ACGT"){
                    word[i] = ch;
                    if(s.count(word)){
                        s.erase(word);
                        q.push({word, count+1});
                    }
                }
                word = original; 
            }
        }
        return -1;
    }
};