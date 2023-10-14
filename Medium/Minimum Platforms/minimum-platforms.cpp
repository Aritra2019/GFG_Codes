//{ Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
    	int max_time = 0;
    for (int i = 0; i < n; i++) {
        max_time = max(max_time, max(arr[i], dep[i]));
    }

    int p[max_time + 1] = {0};
    	for(int i=0;i<n;i++){
    	    p[arr[i]]++;
    	    p[dep[i]+1]--;
    	}
    	for(int i=1;i<max_time;i++){
    	   p[i]+=p[i-1];
    	}
    	int mx=p[0];
    	for(int i=1;i<max_time;i++) mx=max(mx,p[i]);
    	  
    	return mx;
    }
};


//{ Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}
// } Driver Code Ends