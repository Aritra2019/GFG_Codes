//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find floor of x
    // n: size of vector
    // x: element whose floor is to find
    int bsearch(vector<long long> &v, int low, int high, long long x) {
        int ans = -1;  // Initialize with -1 to indicate no floor found
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (v[mid] == x) {
                return mid;  // Exact match found
            } else if (v[mid] < x) {
                ans = mid;  // Possible floor found, continue searching right
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }

    int findFloor(vector<long long> &v, long long n, long long x) {
        return bsearch(v, 0, n - 1, x);
    }
};


//{ Driver Code Starts.

int main() {

    long long t;
    cin >> t;

    while (t--) {
        long long n;
        cin >> n;
        long long x;
        cin >> x;

        vector<long long> v;

        for (long long i = 0; i < n; i++) {
            long long temp;
            cin >> temp;
            v.push_back(temp);
        }
        Solution obj;
        cout << obj.findFloor(v, n, x) << endl;
    }

    return 0;
}
// } Driver Code Ends