/*
You have been given an integer array/list(ARR) of size N. It has been sorted(in increasing order) and then rotated by some number 'K' in the right hand direction.
Your task is to write a function that returns the value of 'K', that means, the index from which the array/list has been rotated.

Sample Input 1:
1
6
5 6 1 2 3 4
Sample Output 1:
2
Sample Input 2:
2
5
3 6 8 9 10
4
10 20 30 1
Sample Output 2:
0
3
*/

int arrayRotateCheck(int *input, int size)
{
    int min = input[0], min_index = 0;
    for (int i = 0; i < size; i++) {
        if (min > input[i]) {
            min = input[i];
            min_index = i;
        }
    }
    return min_index;
}
