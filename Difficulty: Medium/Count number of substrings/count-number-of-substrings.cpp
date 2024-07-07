//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
     long long int substrCount(string s, int k) {
        return atMostK(s, k) - atMostK(s, k - 1);
    }

private:
    long long int atMostK(string s, int k) {
        int n = s.size();
        if (k == 0) return 0;
        
        vector<int> cnt(26, 0);
        int start = 0, end = 0, uniqueCount = 0;
        long long int res = 0;
        
        while (end < n) {
            if (cnt[s[end] - 'a'] == 0) uniqueCount++;
            cnt[s[end] - 'a']++;
            end++;
            
            while (uniqueCount > k) {
                cnt[s[start] - 'a']--;
                if (cnt[s[start] - 'a'] == 0) uniqueCount--;
                start++;
            }
            
            res += (end - start);
        }
        
        return res;
    }
};

//{ Driver Code Starts.


int main()
{
    int t; cin >> t;
    while (t--)
	{
		string s; cin >> s;
		int k; cin >> k;
		Solution ob;
		cout <<ob.substrCount (s, k) << endl;
	}
}
// } Driver Code Ends