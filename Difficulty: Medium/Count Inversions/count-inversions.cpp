//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long int inversionCount(long long arr[], int n) {
        // Your Code Here long long int inversionCount(long long arr[], int n) {
        vector<long long> temp(n);
        return mergeSort(arr, temp, 0, n - 1);
    }

  private:
    long long merge(long long arr[], vector<long long>& temp, int low, int mid, int high) {
        int left = low;      // starting index of left half of arr
        int right = mid + 1; // starting index of right half of arr
        int k = low;         // starting index to be sorted
        long long cnt = 0;

        // Merging the two halves in a sorted manner
        while (left <= mid && right <= high) {
            if (arr[left] <= arr[right]) {
                temp[k++] = arr[left++];
            } else {
                temp[k++] = arr[right++];
                cnt += (mid - left + 1); // Count inversions
            }
        }

        // Copy the remaining elements of left half, if any
        while (left <= mid) {
            temp[k++] = arr[left++];
        }

        // Copy the remaining elements of right half, if any
        while (right <= high) {
            temp[k++] = arr[right++];
        }

        // Copy the sorted subarray into Original array
        for (int i = low; i <= high; i++) {
            arr[i] = temp[i];
        }

        return cnt;
    }

    long long mergeSort(long long arr[], vector<long long>& temp, int low, int high) {
        long long cnt = 0;
        if (low < high) {
            int mid = (low + high) / 2;

            cnt += mergeSort(arr, temp, low, mid);   // Left half
            cnt += mergeSort(arr, temp, mid + 1, high); // Right half

            cnt += merge(arr, temp, low, mid, high); // Merging the two halves
        }
        return cnt;
    }
};

//{ Driver Code Starts.

int main() {

    long long T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        long long A[N];
        for (long long i = 0; i < N; i++) {
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A, N) << endl;
    }

    return 0;
}

// } Driver Code Ends