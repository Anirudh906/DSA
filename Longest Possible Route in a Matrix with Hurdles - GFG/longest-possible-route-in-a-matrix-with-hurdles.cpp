// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
public:
    vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
    int solve(vector<vector<int>> &matrix, int x, int y, int xd, int yd){
        if(x == xd and y == yd) return 0;
        int val = matrix[x][y];
        matrix[x][y] = 0;
        int temp = INT_MIN;
        for(int k = 0; k < 4; k++){
            int a = x + dir[k][0];
            int b = y + dir[k][1];
            if(a < 0 || b < 0 || a >= matrix.size() || b >= matrix[0].size() 
            || !matrix[a][b]) continue;
            int ans = solve(matrix, a, b, xd, yd);
            if(ans != INT_MIN) temp = max(temp, 1 + ans);
        }
        matrix[x][y] = val;
        return temp;
    }
    
    int longestPath(vector<vector<int>> matrix, int xs, int ys, int xd, int yd)
    {
        // code here
        if(!matrix[xs][ys]) return -1;
        int ans = solve(matrix, xs, ys, xd, yd);
        if(ans == INT_MIN) return -1;
        return ans;
        
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int xs, ys, xd, yd;
        cin >> xs >> ys >> xd >> yd;
        vector<vector<int>> mat(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> mat[i][j];
            }
        }
        Solution ob;
        int ans = ob.longestPath(mat, xs, ys, xd, yd);
        cout << ans;
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends