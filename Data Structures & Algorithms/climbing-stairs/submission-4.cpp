#include<cstring>

class Solution {
public:

    // Bottom up approach:
    int climbStairs(int n) { 
        if(n == 1 || n == 2 || n == 3) {
            return n;
        }

        vector<int> t(n+1);
        t[0] = 0;
        t[1] = 1;
        t[2] = 2;

        for(int i = 3; i <= n; i++) {
            t[i] = t[i-1] + t[i-2];
        }
        return t[n];

    }

    /* Memoization, TC = O(n), SC = O(n)
    int t[46];
    int solve(int n) {
        if(n < 0) return 0;
        if(n == 0) return 1;

        if(t[n] != -1) return t[n];

        return t[n] = solve(n-1) + solve(n-2);
    }
    int climbStairs(int n) {
        memset(t, -1, sizeof(t));
        return solve(n);
    } */
    /* Brute force approach: TC = O(2^n)
    int climbStairs(int n) {
        if(n < 0) {
            return 0;
        }
        if(n == 0) {
            return 1;
        }
        return climbStairs(n-1) + climbStairs(n-2);
    } */
};
