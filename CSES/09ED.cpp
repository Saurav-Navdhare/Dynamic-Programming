#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s1, s2;
    cin >> s1 >> s2;
    int l1=s1.length(), l2 = s2.length();

    // vector<vector<int>> dp(l1+1, vector<int>(l2+1, 0));
    
    // for(int i=0; i<=l1; i++)
    //     dp[i][0] = i;
        
    // for(int i=0; i<=l2; i++)
    //     dp[0][i] = i;
        
    // for(int i=1; i<=l1; i++)
    //     for(int j=1; j<=l2; j++)
    //         if(s1[i-1] == s2[j-1])
    //             dp[i][j] = dp[i-1][j-1];
    //         else
    //         /*
    //             dp[i][j] = min(
    //                 dp[i-1][j-1]+1, //replace
    //                 dp[i-1][j]+1, // delete from string 1
    //                 dp[i][j-1] // delete from string 2
    //             );
    //         */
    //        dp[i][j] =min(dp[i-1][j-1], min(dp[i][j-1], dp[i-1][j]))+1;
            
    // cout << dp[l1][l2] << endl;

    vector<int> dp(l2+1, 0);
    for(int i=0; i<=l2; i++)
        dp[i]=i;
    
    for(int i=1; i<=l1; i++){
        vector<int> curr(l2+1, 0);
        curr[0] = i;
        for(int j=1; j<=l2; j++){
            if(s1[i-1]==s2[j-1])
                curr[j] = dp[j-1];
            else
                curr[j] = min(dp[j-1], min(dp[j], curr[j-1]))+1;
        }
        dp = curr;
    }
    cout << dp[l2] << endl;

    return 0;
}