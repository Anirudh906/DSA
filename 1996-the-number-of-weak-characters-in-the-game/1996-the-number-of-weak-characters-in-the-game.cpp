class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& p) {
        int n = p.size();
        
        sort(p.begin(), p.end(), [](vector<int>&a, vector<int>&b){
          
              if(a[0] == b[0]){
                  return a[1] > b[1];
              } 
            else return a[0] < b[0];
            
        });
        int mx = INT_MIN;
        int cnt = 0;
        for(int i = n - 1; i >= 0; i--){
            
           if(p[i][1] < mx) cnt++;
            mx = max(mx, p[i][1]);
        }
        
        return cnt;
    }
};