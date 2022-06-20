// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    int findSubString(string str)
    {
        // Your code goes here   
        int n = str.length();
        
        //int dis = set<char>(str.begin(), str.end()).size();
        int end = 0, strt = 0;
        unordered_map<int, int> mp2;
        
        int distCnt = set<char>(str.begin(), str.end()).size();
        
        int ans = INT_MAX;
        while(end < n){
            mp2[str[end]]++;
            while(strt <= end and distCnt == mp2.size()){
                ans = min(ans, end-strt+1);
                mp2[str[strt]]--;
                if(mp2[str[strt]] == 0) mp2.erase(str[strt]);
                strt++;
            }
             end++;
        }
        return ans;
    }
};

// { Driver Code Starts.
// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;
    }
    return 0;
}  // } Driver Code Ends