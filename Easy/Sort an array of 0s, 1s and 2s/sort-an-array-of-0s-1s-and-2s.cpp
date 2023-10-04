//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    void sort012(int a[], int n)
    {
        // code here 
        int arr[n];
        int i2=0;
        for(int i=0;i<n;i++)
        {
            if(a[i]==0)
            {
                arr[i2]=0;
                i2++;
            }
        }
            for(int i=0;i<n;i++)
            {
            if(a[i]==1)
            {
                arr[i2]=1;
                i2++;
            }
        }
            for(int i=0;i<n;i++)
            {
               if(a[i]==2)
               {
                 arr[i2]=2;
                 i2++;
               }
            }
        for(int i=0;i<n;i++)
        {
           a[i]=arr[i];
        }
    }   
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for(int i=0;i<n;i++){
            cout << a[i]  << " ";
        }

        cout << endl;
        
        
    }
    return 0;
}


// } Driver Code Ends