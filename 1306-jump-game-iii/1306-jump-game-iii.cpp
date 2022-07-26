class Solution {
public:
    bool check(vector<int> &arr, vector<bool> &visited, int pos){
        if(pos < 0 || pos >= arr.size() || visited[pos]) return false;
        
        if(arr[pos] == 0) return true;
        
        visited[pos] = true;
        
         return check(arr, visited, pos - arr[pos]) || check(arr, visited, pos + arr[pos]);
   
    }
    
    
    bool canReach(vector<int>& arr, int start) {
        vector<bool> visited(arr.size(), false);
        int n = arr.size();
    return check(arr, visited, start - arr[start]) || check(arr, visited, start + arr[start]);
    }
};