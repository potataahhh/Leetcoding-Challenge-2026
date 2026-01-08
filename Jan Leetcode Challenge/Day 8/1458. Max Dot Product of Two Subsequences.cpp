class Solution {
public:

    int n,m;
    int dp[501][501];
    int temp(vector<int>& nums1, vector<int>& nums2,int i,int j){
        if(i==n || j==m){
            return -1e9;
        }

        if(dp[i][j]!=-1e9){
            return dp[i][j];
        }

        int opt1 = nums1[i]*nums2[j];
        int opt2 = (nums1[i]*nums2[j])+temp(nums1,nums2,i+1,j+1);
        int opt3 = temp(nums1,nums2,i+1,j);
        int opt4 = temp(nums1,nums2,i,j+1);

        return dp[i][j] = max({opt1,opt2,opt3,opt4});
    }

    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        n = nums1.size();
        m = nums2.size();

        for(int i=0;i<501;i++){
            for(int j=0;j<501;j++){
                dp[i][j]=-1e9;
            }
        }

        return temp(nums1,nums2,0,0);        
    }
};
