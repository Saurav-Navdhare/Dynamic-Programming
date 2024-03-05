#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, maxSum=0;
    cin >> n;
    
    vector<int> coins(n);
    
    for(int i=0; i<n; i++){
        cin >> coins[i];
        maxSum+=coins[i];
    }
/*
    // bruteforce: Time Complexity: O(n*2^n)  Space Complexity: O(2^n)
    set<int> inc, dinc;
    inc.insert(coins[0]);
    for(int i=1; i<n; i++){
        dinc = inc;

        for(auto x: dinc)
            inc.insert(x+coins[i]);
        
        inc.insert(coins[i]);
    }

    cout << inc.size() << endl;
    for(auto x: inc)
        cout << x << " ";
*/
    vector<int> dp(maxSum+1, 0);
    dp[0] = 1;
    for(int i=0; i<n; i++){
        vector<int> curr = dp;
        for(int j=0; j<= maxSum; j++){
            if(j-coins[i] >= 0)
                curr[j] = dp[j-coins[i]] || dp[j];
        }
        dp = curr;
    }

    cout << accumulate(dp.begin()+1, dp.end(), 0) << endl;

    for(int i=1; i<=maxSum; i++)
        if(dp[i])
            cout << i << ' ';
    cout << endl;
    
    return 0;
}