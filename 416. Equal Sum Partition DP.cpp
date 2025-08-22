class Solution {
public:
  
    bool answer(vector<int> &nums , int sum, int n)
    {
       vector<vector<bool>>t(n+1,vector<bool>(sum+1,false)); 
    /*    Earlier I had made t[n+1][sum+1] . That gave error because: Variable Length Array (VLA) is not standard C++
        In C++, array dimensions must be compile-time constants.
    n and sum are input values (runtime), so bool t[n+1][sum+1]; is technically illegal in standard C++ (though some compilers     like GCC/Clang allow it as an extension).*/
     for(int i=0;i<n;i++)
     {
        for(int j=0;j<sum;j++)
        {
            if(i==0) t[i][j]= false;
            else if(j==0)  t[i][j]=true;
        }
     }

     for(int i=1;i<n+1;i++)
     {
        for(int j=1;j<=sum;j++)
        {
            if(nums[i-1]<=j)
            {
                t[i][j]= t[i-1][j-nums[i-1]] || t[i-1][j];
            }
            else
            {
                t[i][j]=t[i-1][j];
            }
        }
     }
     return t[n][sum];
    }


    bool canPartition(vector<int>& nums) {
    int n = nums.size();
    int sum=0;
    for(int i=0;i<n;i++){
        sum= sum+nums[i];
    }
    if(sum%2!=0) return false;
    else return answer(nums,sum/2,n);
    

    }
};
