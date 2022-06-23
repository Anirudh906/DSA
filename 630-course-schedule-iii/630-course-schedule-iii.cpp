class Solution {
public:
   static bool mycomp (vector<int> &a, vector<int> &b){
        return a[1] < b[1];
    }    

    int scheduleCourse(vector<vector<int>>& courses) {
        priority_queue<int> pq;
        sort(courses.begin(), courses.end(), mycomp);
        
        int d = 0;
        for(int i = 0; i < courses.size(); i++){
            d += courses[i][0];
            pq.push(courses[i][0]);
            if(d > courses[i][1]){
                d -= pq.top();
                pq.pop();
            }
            
            
            
        }
         return pq.size();
        
    }
};