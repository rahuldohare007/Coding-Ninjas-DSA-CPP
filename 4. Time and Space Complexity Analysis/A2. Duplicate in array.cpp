/*
You have been given an integer array/list(ARR) of size N which contains numbers from 0 to (N - 2). Each number is present at least once. 
That is, if N = 5, the array/list constitutes values ranging from 0 to 3, and among these, there is a single integer value that is present twice.
You need to find and return that duplicate number present in the array.
Note :
Duplicate number is always present in the given array/list.

Sample Input 1:
1
9
0 7 2 5 4 7 1 3 6
Sample Output 1:
7
Sample Input 2:
2
5
0 2 1 3 1
7
0 3 1 5 4 3 2
Sample Output 2:
1
3
*/

#include <bits/stdc++.h>

int findDuplicate(int *arr, int n)
{
    unordered_set<int> s;
   for (int i=0; i<n; i++)
   {
      if (s.find(arr[i]) != s.end())
         return arr[i];
      s.insert(arr[i]);
   }
    
   // If input is correct, we should
   // never reach here
   return -1;
}
