class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
              int n = arr.size();
        stack<int> st;
        for(int i = 0; i < n; i++){
            int temp = arr[i];
            while(st.size() > 0 and arr[i] < st.top()){
                int t = st.top();
                temp = max(temp, t);
                st.pop();
            }
            st.push(temp);
        }
        return (int)st.size();
    }
};