/*
Given an integer h, find the possible number of balanced binary trees of height h. You just need to return the count of possible binary trees which are balanced.
This number can be huge, so, return output modulus 10^9 + 7.
Time complexity should be O(h).

Input Format :
The first and only line of input contains an integer, that denotes the value of h. Here, h is the height of the tree.

Output Format :
The first and only line of output contains the count of balanced binary trees modulus 10^9 + 7.

Constraints :
1 <= h <= 10^6
Time Limit: 1 sec

Sample Input 1:
3
Sample Output 1:
15

Sample Input 2:
4
Sample Output 2:
315
*/ 

#include <bits/stdc++.h>

// Dynamic Programming
#define mod 1000000007
int balancedBTs(int n) {
    int *ans = new int[n + 1];
    ans[0] = 1;
    ans[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        int val1 = (int)(((long)ans[i - 1] * ans[i - 1]) % mod);
        int val2 = (int)((2 * (long)ans[i - 1] * ans[i - 2]) % mod);
        ans[i] = (val1 + val2) % mod;
    }
    return ans[n];
}

//Memorization
int balancedBTs(int n, int *arr) {
    
    if(n<=1) return 1;
    
    int x = balancedBTs(n-1, arr);
    int y = balancedBTs(n-2, arr);
    int mod = (int)(pow(10,9) + 7);
    
    int temp1 = (int) (((long)(x)*x)%mod);
    int temp2 = (int) ((2*(long)(x)*y)%mod);
    
    if(arr[n] != -1){
        return arr[n];
    }

    for(int i=2; i<=n; i++)
    {
        arr[n] = (temp1 + temp2) % mod;
        
    }
    return arr[n];
}
int balancedBTs(int n){
    int *arr = new int[n + 1];
    for(int i=0; i<=n; i++){
        arr[i] = -1;
    }
    return balancedBTs(n, arr);
}
