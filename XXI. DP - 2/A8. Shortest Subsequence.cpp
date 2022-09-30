/*
Gary has two string S and V. Now, Gary wants to know the length shortest subsequence in S, which is not a subsequence in V.

Note: The input data will be such that there will always be a solution.

Input Format :
The first line of input contains a string, that denotes the value of S. The following line contains a string, that denotes the value of V.

Output Format :
Length of shortest subsequence in S such that it is not a subsequence in V

Constraints:
1 <= |S| <= 1000 (|x| implies the length of the string x)
1 <= |V| <= 1000 
Time Limit: 1 second

Sample Input 1:
babab
babba
Sample Output 1:
3
Explanation:
"aab" is the shortest subsequence which is present in S and absent in V.
*/ 

int getans(char *s1, char *s2, int len1, int len2, int **dp)
{
    if (len1 <= 0)
    {
        return 1001;
    }
    if (len2 <= 0)
    {
        return 1;
    }
    if (dp[len1][len2] > -1)
    {
        return dp[len1][len2];
    }
 
    int ans = 0;
    int option1 = getans(s1 + 1, s2, len1 - 1, len2, dp);
    int i = 0;
    
    for (; i < len2; i++)
    {
        if (s1[0] == s2[i])
        {
            break;
        }
    }
    if (i == len2)
    {
        return 1;
    }
    
    int option2 = 1 + getans(s1 + 1, s2 + i + 1, len1 - 1, len2 - 1 - i, dp);
    ans = min(option1, option2);
    dp[len1][len2] = ans;
    return ans;
}
int solve(string s, string v) {
    char *s1 = new char[s.length()];
    char *s2 = new char[v.length()];
    for (int i = 0; i < s.length(); i++)
    {
        s1[i] = s[i];
    }
    for (int i = 0; i < v.length(); i++)
    {
        s2[i] = v[i];
    }
    int **dp = new int *[s.length() + 1];
    for (int i = 0; i <= s.length(); i++)
    {
        dp[i] = new int[v.length() + 1];
        for (int j = 0; j <= v.length(); j++)
        {
            dp[i][j] = -1;
        }
    }
    return getans(s1, s2, s.length(), v.length(), dp);
}
