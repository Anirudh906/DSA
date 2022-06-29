class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size() == 0) return 0;
        int res = 0;
        int n = height.size();
        
        vector<int> lmax(n), rmax(n);
        lmax[0] = height[0];
        rmax[n - 1] = height[n - 1];
        
        for(int i = 1; i < n; i++){
            lmax[i] = max(lmax[i - 1], height[i]);
        }
        for(int i = n - 2; i >= 0; i--){
              rmax[i] = max(rmax[i + 1], height[i]);    
        }
        for(int i = 0; i < n; i++){
            int t = min(lmax[i], rmax[i]) - height[i];
            res+= t;         
            
        }
        return res;
    }
};