/*
Given an integer sorted array (sorted in increasing order) and an element x, find the x in given array using binary search. Return the index of x.
Return -1 if x is not present in the given array.
Note : If given array size is even, take first mid.
Input format :

Line 1 : Array size

Line 2 : Array elements (separated by space)

Line 3 : x (element to be searched)

Sample Input :
6
2 3 4 5 6 8 
5 
Sample Output:
3 
*/

int B(int a[],int s,int e, int i)
{
    if(s>e)
        return -1;
    int mid = (s+e)/2;
    if(a[mid]==i) return mid;
    if(a[mid]>i) return B(a,s,mid-1,i);
    if(a[mid]<i) return B(a,mid+1,e,i);
}
int binarySearch(int input[], int size, int element) {
    int start = 0;
    int end = size-1;
    int ans = B(input ,start,end,element);
    return ans;
}
