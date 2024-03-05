#include <iostream>
#include <bits/stdc++.h>
using namespace std;


int main(){
    int MOD=1e9+7, n;
    cin >> n;
    vector<vector<int>> grid(n, vector<int>(n));
    for(int i=0; i<n; i++){
        string s;
        cin >> s;
        for(int j=0; j<n; j++)
            grid[i][j]=s[j]=='*'?-1:1;
    }


    if(grid[0][0] == -1 || grid[n-1][n-1] == -1){
        cout << 0 << endl;
        return 0;
    }
    // space complexity: O(n^2)
/*
    vector<vector<long long>> dp(n, vector<long long>(n, 0));
    dp[n-1][n-1]=1;
    for(int i=n-2; i>=0; i--){
        dp[i][n-1] = grid[i][n-1]==-1 ? 0 : dp[i+1][n-1];
        dp[n-1][i] = grid[n-1][i]==-1 ? 0 : dp[n-1][i+1];
    }

    for(int i=n-2; i>=0; i--)
        for(int j=n-2; j>=0; j--){
            int right = (grid[i][j+1]==-1) ? 0 : dp[i][j+1];
            int down = (grid[i+1][j]==-1) ? 0 : dp[i+1][j];
            dp[i][j] = (right + down)%MOD;
        }
    cout << dp[0][0] << endl;
    */
// space complexity: O(n) : optimized
    vector<long long> dp(n, 0);
    dp[n-1]=1;
    for(int i=n-1; i>=0; i--){
        for(int j=n-1; j>=0; j--){
            if(i==n-1 && j==n-1) continue;
            int left = (j==n-1) ? 0 : dp[j+1];
            int down = (i==n-1) ? 0 : dp[j];
            if(grid[i][j] == -1)
                dp[j]=0;
            else
                dp[j] = (left + down)%MOD;
        }
    }
    cout << dp[0] << endl;
 
    return 0;
}