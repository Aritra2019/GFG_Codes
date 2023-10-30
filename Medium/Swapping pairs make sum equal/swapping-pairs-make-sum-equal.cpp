//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

int getSum(int X[],int n){
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=X[i];
    }
    return sum;
}

class Solution{

	public:
	int findSwapValues(int A[], int n, int B[], int m)
	{
        // Your code goes here
       int sumA = getSum(A, n);
    int sumB = getSum(B, m);
    int diff = sumA - sumB;
    
    if (diff % 2 != 0) 
        return -1;

    diff /= 2;

    unordered_set<int> setB(B, B + m);

    for (int i = 0; i < n; i++) {
        int target = A[i] - diff;
        if (setB.count(target)) {
            return 1;
        }
    }

    return -1;
}
};

//{ Driver Code Starts.

int main() 
{
   	
   	int t;
    cin >> t;
    while (t--)
    {
    	int n,m;
        cin>>n>>m;
        int a[n];
        int b[m];
        for(int i=0;i<n;i++)
            cin>>a[i];
        for(int i=0;i<m;i++)
            cin>>b[i];
        

        Solution ob;
        cout <<  ob.findSwapValues(a, n, b, m);
	    cout << "\n";
	     
    }
    return 0;
}






// } Driver Code Ends