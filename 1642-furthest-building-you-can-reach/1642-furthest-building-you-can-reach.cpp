class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
       int n = heights.size(); int i =0;
        priority_queue <int, vector<int>, greater<int>> p;
        
        while(i < n - 1 and p.size()<ladders and ladders!=0){
            int t = heights[i+1]-heights[i];
            if(t>0){
                p.push(t);
            }
            i++;
        } 
        while(i < n - 1){
            int t = heights[i+1]- heights[i];
            if(t>0){
                if(ladders!=0 and t > p.top() and !p.empty()){
                    bricks -= p.top();
                    p.pop();
                    p.push(t);
                }
            
                else bricks-=t;
                
            }
                if(bricks < 0) return i;
                i++;
        }    
            return i;
         
    }
};