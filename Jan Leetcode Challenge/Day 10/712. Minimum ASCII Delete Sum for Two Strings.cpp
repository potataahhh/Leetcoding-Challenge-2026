class Solution {
public:

    int n,m;
    int dp[1001][1001];

    int func(int i, int j, string &s1, string &s2){
        if(i>=n && j>=m){
            return 0;
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        if(i>=n){
            return dp[i][j] = s2[j] + func(i,j+1,s1,s2);
        }
        else if(j>=m){
            return dp[i][j] = s1[i] + func(i+1,j,s1,s2);
        }

        if(s1[i]==s2[j]){
            return dp[i][j] = func(i+1,j+1,s1,s2);
        }

        int del_I = s1[i]+func(i+1,j,s1,s2);
        int del_J = s2[j]+func(i,j+1,s1,s2);

        return dp[i][j] = min(del_I,del_J);
    }

    int minimumDeleteSum(string s1, string s2) {
        n=s1.size();
        m=s2.size();
        memset(dp,-1,sizeof(dp));

        return func(0,0,s1,s2);
    }
};
