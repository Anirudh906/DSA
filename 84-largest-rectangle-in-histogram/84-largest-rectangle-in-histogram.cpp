class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> ps, ns; // index of previous and next smaller
        stack<int> s;
        
        ps.push_back(-1);
        s.push(0);
        
        for(int i = 1; i < n; i++){
            while(!s.empty() and heights[s.top()] >= heights[i]) s.pop();
            int idx = s.empty() ? -1 : s.top();
            ps.push_back(idx);
            s.push(i);
            
        }
        
        while(!s.empty())s.pop();
        ns.push_back(n);
        s.push(n - 1);
        for(int i = n - 1; i >= 0; i--){
            while(!s.empty() and heights[s.top()] >= heights[i])s.pop();
            
            int idx = s.empty() ? n : s.top();
            ns.push_back(idx);
            s.push(i);
            
        }
        reverse(ns.begin(), ns.end());
        int res = 0;        
        for(int i = 0; i < n; i++){
            int cur = 0;
            cur += (i - ps[i] - 1) * heights[i];
            cur += (ns[i] - i) * heights[i];
            res = max(res, cur);
        }
        return res;
    }
    
};