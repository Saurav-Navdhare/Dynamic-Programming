#include<iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,mod=1e9+7;
    cin>>n;

    int totalSum = n*(n+1)/2;
    int half = totalSum>>1;
    if(half<<1 != totalSum){
        cout << 0 << endl;
        return 0;
    }

    vector<vector<int>> dp(n+1,vector<int>(half+1,0));

    dp[0][0] = 1;

    for(int sum=0;sum<=half;sum++)
        for(int i=1;i<n;i++){
            dp[i][sum] = dp[i-1][sum];
            if(sum - i >= 0){
                dp[i][sum] = dp[i-1][sum] + dp[i-1][sum-i];
                dp[i][sum] %= mod;
            }
        }
        
    cout << dp[n-1][half] <<endl;
    
    return 0;
}