/*
A thief is robbing a store and can carry a maximal weight of W into his knapsack. There are N items and ith item weighs wi and is of value vi. Considering the 
constraints of maximum weight that knapsack can carry, you have to find and return the maximum value that thief can generate by stealing items.

Note:
Space complexity should be O(W).

Input Format :
The first line contains an integers, that denote the value of N. The following line contains N space separated integers, that denote the values of weight of items.
The following line contains N space separated integers, that denote the values associated with the items. The following line contains an integer that denote the value of
W. W denotes maximum weight that thief can carry.

Output Format :
The first and only line of output contains the maximum value that thief can generate, as described in the task. 

Constraints
1 <= N <= 10^4
1<= wi <= 100
1 <= vi <= 100
Time Limit: 1 second

Sample Input 1 :
4
1 2 4 5
5 4 8 6
5
Sample Output 1 :
13
*/ 

//	Memoization  
int knapsack(int* weights, int* values, int n, int maxWeight, int **output)
{	
    if (maxWeight == 0 || n == 0)
        return 0;

    if(output[n][maxWeight] != -1)
        return output[n][maxWeight];
    
    int ans;
    if (maxWeight < weights[0])
        ans =  knapsack(weights + 1, values + 1, n - 1, maxWeight, output);
    else
    {
        int a = knapsack(weights + 1, values + 1, n - 1, maxWeight - weights[0], output) + values[0];
        int b = knapsack(weights + 1, values + 1, n - 1, maxWeight, output);
        ans = max(a, b);
    }
    
    output[n][maxWeight] = ans;
    
    return output[n][maxWeight];
}

int knapsack(int *weights, int *values, int n, int maxWeight)
{
	  int **output = new int*[n + 1];
    for(int i=0; i<=n; i++){
        output[i] = new int[maxWeight + 1];
        for(int j=0; j<=maxWeight; j++){
            output[i][j] = -1;
        }
    }
    
    return knapsack(weights, values, n, maxWeight, output);
}

// dynamic programming
int knapsack(int *weights, int *values, int n, int maxWeight)
{
    
    int **output = new int *[n + 1];
    for (int i = 0; i <= n; i++)
        output[i] = new int[maxWeight + 1];

    for (int i = 0; i <= n; i++)
        output[i][0] = 0;

    for (int i = 0; i <= maxWeight; i++)
        output[0][i] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= maxWeight; j++)
        {
            if (j < weights[n - i])
                output[i][j] = output[i - 1][j];
            else
            {
                int a = output[i - 1][j - weights[n - i]] + values[n - i];
                int b = output[i - 1][j];
                output[i][j] = max(a, b);
            }
        }
    }
    return output[n][maxWeight];
}
