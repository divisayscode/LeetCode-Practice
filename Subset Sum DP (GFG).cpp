class Solution {
public:
    bool answer(vector<int> &arr, int sum, int n) {
        bool t[n+1][sum+1];

        for(int i=0; i<=n; i++) {
            for(int j=0; j<=sum; j++) {
                if(i == 0) t[i][j] = false; 
                if(j == 0) t[i][j] = true;  
            }
        }

        for(int i=1; i<=n; i++) {
            for(int j=1; j<=sum; j++) {
                if(arr[i-1] <= j) {
                    t[i][j] = t[i-1][j-arr[i-1]] || t[i-1][j];
                } else {
                    t[i][j] = t[i-1][j];
                }
            }
        }

        return t[n][sum];
    }

    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        return answer(arr, sum, n);
    }
};
