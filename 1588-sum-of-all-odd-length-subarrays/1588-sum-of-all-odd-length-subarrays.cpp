class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int sum = 0;
        int n = arr.size();
        
        
        for(int i = 0; i < n; i++){
            int c = (i+1)*(n-i);
            c = (c+1)/2;
            sum += arr[i]*c;
        }
        
        return sum;
    }
};