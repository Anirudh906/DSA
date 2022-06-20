// { Driver Code Starts
#include <iostream>
using namespace std;


 // } Driver Code Ends

#include<bits/stdc++.h>
class Solution{
public:


 long ncr(int n,int r)
    {
        long res=1;
        vector<int> tmp;
        for(int i=2;i<=n-r;i++)
        {
            tmp.push_back(i);
        }
        for(int i=n;i>r;i--)
        {   
            res*=i;
            for(int j=0;j<tmp.size();j++)
            {
                if(res%tmp[j]==0)
                {
                    res/=tmp[j];
                    tmp[j]=1;
                }
            }
        }
        return res;
    }
    long posIntSol(string s)
    {
        int n = 0, k = 0;
        for(auto &ch : s){
            if(ch == '+') n++;
        }
        int i = 0;
        for(; i < s.length(); i++){
            if(s[i] == '='){
                string temp = s.substr(i+1); 
                k = stoi(temp);
                break;
            }
        }     
        if(n > k-1) return 0;
        return ncr(k-1, n);
        
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.posIntSol(s)<<endl;
    }
    return 0;
}
  // } Driver Code Ends