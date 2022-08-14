/*
You have been given two integer arrays/list(ARR1 and ARR2) of size N and M, respectively. You need to print their intersection; An intersection for
this problem can be defined when both the arrays/lists contain a particular value or to put it in other words, when there is a common value that exists in
both the arrays/lists.
Note :
Input arrays/lists can contain duplicate elements.

The intersection elements printed would be in ascending order.

Sample Input 1 :
2
6
2 6 8 5 4 3
4
2 3 4 7 
2
10 10
1
10
Sample Output 1 :
2 3 4
10
Sample Input 2 :
1
4
2 6 1 2
5
1 2 3 4 2
Sample Output 2 :
1 2 2
Explanation for Sample Output 2 :
Since, both input arrays have two '2's, the intersection of the arrays also have two '2's. The first '2' of first array matches with the first '2' of the second array.
Similarly, the second '2' of the first array matches with the second '2' if the second array.
*/

#include <bits/stdc++.h>

void intersection(int *arr1, int *arr2, int n, int m) 
{
    sort(arr1, arr1 + n);
    sort(arr2, arr2 + m);
    
    int i = 0, j = 0;
    while (i < n && j < m) {
        if (arr1[i] > arr2[j]) {
            j++;
        }
        else if (arr2[j] > arr1[i]) {
            i++;
        }
        else {
            // when both are equal
            cout << arr1[i] << " ";
            i++;
            j++;
        }
    }
}
