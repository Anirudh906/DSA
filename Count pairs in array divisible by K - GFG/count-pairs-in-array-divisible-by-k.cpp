// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    long long countKdivPairs(int A[], int n, int K)
    {
        //code here
        long long ans = 0;
        map<int, int> mp;
        for(int i = 0; i < n; i++){
            mp[A[i] % K]++;
        }
        
        ans += (mp[0] * (mp[0] - 1))/2;
        
        for(int i = 1; i <= K/2 and i != (K-i); i++){
            ans += 1ll*mp[i]*mp[K-i];
        }
        if (K % 2 == 0)
        ans += 1ll*(mp[K/2] * (mp[K/2]-1) / 2);
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
		int n;
		cin >> n;

		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];

		int k;
		cin >> k;

        Solution ob;
		cout << ob. countKdivPairs(a, n , k) << "\n";



	}


	return 0;
}
  // } Driver Code Ends