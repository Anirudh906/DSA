class Solution {
public:
    void helper(vector<int> &comb, int strt, vector<int>&c, int target, vector<vector<int>>&res){
        //if(target < 0)return;
        if(target == 0) {
            res.push_back(comb);
            return;
        }
        for(int i = strt; i < c.size() and target >= c[i]; i++){
            if(i == strt || c[i] != c[i - 1]){
                comb.push_back(c[i]);
                helper(comb, i + 1, c, target - c[i], res);
                comb.pop_back();
            }
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
     sort(candidates.begin(), candidates.end());
     vector<vector<int>> res;
     vector<int> comb;
     helper(comb, 0, candidates, target, res);
     return res;   
    }
};

