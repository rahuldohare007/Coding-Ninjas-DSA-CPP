/*
It's Gary's birthday today and he has ordered his favourite square cake consisting of '0's and '1's . But Gary wants the biggest piece of '1's and no '0's . A piece of
cake is defined as a part which consist of only '1's, and all '1's share an edge with each other on the cake. Given the size of cake N and the cake, can you find the
count of '1's in the biggest piece of '1's for Gary ?

Input Format :
The first line of input contains an integer, that denotes the value of N. 
Each of the following N lines contain N space separated integers.

Output Format :
Print the count of '1's in the biggest piece of '1's, according to the description in the task.

Constraints :
1 <= N <= 1000
Time Limit: 1 sec

Sample Input 1:
2
1 1
0 1
Sample Output 1:
3
*/ 

#include <bits/stdc++.h>

// 1.
int offset[4][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};

int bfs(vector<vector<int>> &arr, vector<vector<bool>> &visited, int n, int i, int j)
{
    queue<pair<int, int>> q;
    q.push({i, j});

    int count = 1;
    visited[i][j] = true;

    while (!q.empty())
    {
        auto curr = q.front();
        q.pop();
        for (int k = 0; k < 4; k++)
        {
            int row = curr.first + offset[k][0];
            int col = curr.second + offset[k][1];
            if (row < n and col < n and row >= 0 and col >= 0 and !visited[row][col] and arr[row][col] == 1)
            {
                count++;
                q.push({row, col});
                visited[row][col] = true;
            }
        }
    }
    return count;
}

int getBiggestPieceSize(vector<vector<int>> &cake, int n) {
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    int ans = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (cake[i][j] == 1 and !visited[i][j])
            {
                ans = max(ans, bfs(cake, visited, n, i, j));
            }
        }
    }
    return ans;
}

// 2.
int dfs(vector<vector<int>> &cake, vector<vector<bool>> &visited, int x, int y, int n){
    if(visited[x][y]){
        return 0;
    }
    
    visited[x][y] = true;
    int count = 1;
    
    int dx[] = {0, 0, -1, 1};
    int dy[] = {1, -1, 0, 0};
    
    for(int i = 0; i < 4; i++){
        int X = x + dx[i];
        int Y = y + dy[i];
        if(X >= 0 && X < n && Y >= 0 && Y < n && cake[X][Y] == 1){
           count += dfs(cake, visited, X, Y, n); 
        }
    }
    return count;
}

int getBiggestPieceSize(vector<vector<int>> &cake, int n) {
    int biggestPieceSize = 0;
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(cake[i][j] == 1 && !visited[i][j]){
                biggestPieceSize = max(biggestPieceSize, dfs(cake, visited, i, j, n));
            }
        }
    }
    
    return biggestPieceSize;
}
