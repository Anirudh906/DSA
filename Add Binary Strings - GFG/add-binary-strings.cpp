//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	string addBinary(string a, string b)
	{
	   int n = a.size(), m = b.size();
        string sum;
        int carry = 0;
        
        int i = n - 1, j = m - 1;
        while (i >= 0 || j >= 0 || carry > 0){
            if (i >= 0) {
                carry += a[i] - '0';
                i -= 1;
            }
            if (j >= 0) {
                carry += b[j] - '0';
                j -= 1;
            }
            sum += (carry % 2) + '0';
            carry /= 2;
        }
        reverse(sum.begin(), sum.end());
        while(sum[0] == '0') sum=sum.substr(1);
        return sum;
	}
};

//{ Driver Code Starts.

int main()
{
	int t; cin >> t;
	while (t--)
	{
		string A, B; cin >> A >> B;
		Solution ob;
		cout << ob.addBinary (A, B);
		cout << "\n";
	}
}

// Contributed By: Pranay Bansal

// } Driver Code Ends