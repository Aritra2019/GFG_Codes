//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int NthRoot(int n, int m)
	{
	    // Code here.
	     int low = 1;
        int high = m;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            long long val = 1;
            bool overflow = false;
            for (int i = 0; i < n; i++) {
                val *= mid;
                if (val > m) {
                    overflow = true;
                    break;
                }
            }
            if (val == m) {
                return mid;
            } else if (val < m && !overflow) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		Solution ob;
		int ans = ob.NthRoot(n, m);
		cout << ans << "\n";
	}  
	return 0;
}
// } Driver Code Ends