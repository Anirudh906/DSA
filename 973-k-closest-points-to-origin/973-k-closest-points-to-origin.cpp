class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

  
        //for(auto x: points) cout << x[0] << " " << x[1] << endl;
      //  cout << endl;
        int l = 0, r = points.size() - 1;
        while(l <= r){
               int p = partition(points, l, r);
               if(p == k - 1){
                  break;   
               }
              else if(p < k - 1){
                  l = p + 1;
              }else{
                  r = p - 1;
              }
        }
       // for(auto x: points) cout << x[0] << " " << x[1] << endl;
      //  cout << endl;
        return vector<vector<int>> (points.begin(), points.begin() + k); 
    }
    bool closer(vector<int> &a, vector<int> &b){
        return (a[0] * a[0] + a[1] * a[1] < b[0] * b[0] + b[1] * b[1]) ;
    }
    bool far(vector<int> &a, vector<int> &b){
        return (a[0] * a[0] + a[1] * a[1] > b[0] * b[0] + b[1] * b[1]);
    }
    //lomuto
    int partition(vector<vector<int>> &points, int l, int r){
        int i = l - 1;
        swap(points[r], points[l + rand() % (r-l+1)]);
        vector<int> pivot = points[r];
        
        for(int j = l; j <= r - 1; j++){
            if(closer(points[j], pivot)){
                i++;
                swap(points[i], points[j]);
            }
        }
        swap(points[i + 1], points[r]);
        return i + 1;
        
    }
};


