//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution {
  public:
    int maxLen(vector<int>& arr, int n) {
        // Your code here
        unordered_map<int,int> mpp;
        int psum=0;
        int len=0;
        int maxlen=0;
        for(int i=0;i<n;i++){
            psum+=arr[i];
            if(psum==0){
                maxlen=i+1;
            }
            if(mpp.find(psum)!=mpp.end()){
                len=i-mpp[psum];
                maxlen=max(maxlen,len);
            }
            else{
                mpp[psum]=i;
            }
        }
        return maxlen;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int m;
        cin >> m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i) {
            cin >> array1[i];
        }
        Solution ob;
        cout << ob.maxLen(array1, m) << endl;
    }
    return 0;
}

// } Driver Code Ends