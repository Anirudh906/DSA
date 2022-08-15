class Solution {
public:
    int lastStoneWeight(vector<int>& S) {
     priority_queue<int> pq;
        for(auto &x: S)pq.push(x);
      while(!pq.empty()){
          auto t = pq.top();
          pq.pop();
          if(pq.empty()) return t;
          int t2;
          if(!pq.empty()){
              t2 = pq.top();
              pq.pop();
          }
      
          int res = abs(t-t2);
          if(res != 0) pq.push(res);
      }  
        return 0;
    }
};