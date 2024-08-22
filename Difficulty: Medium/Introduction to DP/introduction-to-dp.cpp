//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long int f(int n,vector<long long int> &dp){
        if(n<=1){
            return n;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        return dp[n]=(f(n-1,dp)+f(n-2,dp))%1000000007;
        // return dp[n];
    }
    long long int topDown(int n) {
        // code here
        vector<long long int>dp(n+1,-1);
        return f(n,dp);
        }
    long long int bottomUp(int n) {
        // code here
         if (n <= 1) {
            return n;
        }
        //vector<long long int> dp(n + 1);
        int prev1 = 0;
        int prev2 = 1;
        int curri=0;
        for (int i = 2; i <= n; i++) {
            curri = (prev1 + prev2)%1000000007;
            prev1=prev2;
            prev2=curri;
        }
        
        return prev2%100000000007;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;
        long long int topDownans = obj.topDown(n);
        long long int bottomUpans = obj.bottomUp(n);
        if (topDownans != bottomUpans) cout << -1 << "\n";
        cout << topDownans << "\n";
    }
}
// } Driver Code Ends