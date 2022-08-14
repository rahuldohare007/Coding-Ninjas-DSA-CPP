/*
You have been given a random integer array/list(ARR) of size N. Write a function that rotates the given array/list by D elements(towards the left).
Note:
Change in the input array/list itself. You don't need to return or print the elements.

Sample Input 1:
1
7
1 2 3 4 5 6 7
2
Sample Output 1:
3 4 5 6 7 1 2
Sample Input 2:
2
7
1 2 3 4 5 6 7
0
4
1 2 3 4
2
Sample Output 2:
1 2 3 4 5 6 7
3 4 1 2
*/

void rotate(int *input, int d, int n)
{
    int temp[n];
    int k = 0;
    for (int i = d; i < n; i++) {
        temp[k] = input[i];
        k++;
    }
    for (int i = 0; i < d; i++) {
        temp[k] = input[i];
        k++;
    }
    for (int i = 0; i < n; i++) {
        input[i] = temp[i];
    }
}
