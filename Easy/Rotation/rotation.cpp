//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int findKRotation(int arr[], int n) {
	    // code here
	    int low = 0;
        int high = n - 1;
        int ans=INT_MAX;
        int idx=0;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            if (arr[mid] >= arr[low]) {
               if(arr[low]<ans){
                   idx=low;
                   ans=arr[low];
               }
               low=mid+1;
            } else {
                // Minimum is in the left part (including mid)
                if(arr[mid]<ans){
                    idx=mid;
                    ans=arr[mid];
                }
                high=mid-1;
            }
        }
        
        return idx;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findKRotation(a, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends