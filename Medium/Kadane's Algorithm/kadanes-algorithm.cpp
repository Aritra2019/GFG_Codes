//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(int arr[], int n){
        
        // Your code here
        long long maxsum=arr[0],cursum=0,max1=INT_MIN;
        int k=1;
        for(int i=0;i<n;i++){
            if(arr[i]>=0){
                k=0;
            }
        }
        if(k==1){
            for(int i=0;i<n;i++)
            {
                if(arr[i]>max1){
                    max1=arr[i];
                }
            }
            return max1;
        }
        for(int i=0;i<n;i++)
        {
            cursum+=arr[i];
            if(cursum<0)
            {
                cursum=0;
            }
            else{
            maxsum=max(cursum,maxsum);}
            
        }
        return maxsum;
        
    }
};

//{ Driver Code Starts.

int main()
{
    int t,n;
    
    cin>>t; //input testcases
    while(t--) //while testcases exist
    {
        
        cin>>n; //input size of array
        
        int a[n];
        
        for(int i=0;i<n;i++)
            cin>>a[i]; //inputting elements of array
            
        Solution ob;
        
        cout << ob.maxSubarraySum(a, n) << endl;
    }
}

// } Driver Code Ends