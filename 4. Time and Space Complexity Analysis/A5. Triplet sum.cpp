/*
You have been given a random integer array/list(ARR) and a number X. Find and return the triplet(s) in the array/list which sum to X.
Note :
Given array/list can contain duplicate elements.

Sample Input 1:
1
7
1 2 3 4 5 6 7 
12
Sample Output 1:
5
Sample Input 2:
2
7
1 2 3 4 5 6 7 
19
9
2 -5 8 -6 0 5 10 11 -3
10
Sample Output 2:
0
5

Explanation for Input 2:
Since there doesn't exist any triplet with sum equal to 19 for the first query, we print 0.

For the second query, we have 5 triplets in total that sum up to 10. They are, (2, 8, 0), (2, 11, -3), (-5, 5, 10), (8, 5, -3) and (-6, 5, 11)
*/

#include <bits/stdc++.h> 

int tripletSum(int *arr, int n, int num)
{ 
    sort(arr,arr+n);
    int i,l,r;
    int count=0;
    for(i=0;i<n-2;i++){
        l=i+1;
        r=n-1;
        int newNum = num-arr[i];
        while(l<r){
            if((arr[l]+arr[r])==newNum){
                if(arr[l] == arr[r]){
                    int tot = r-l+1;
                    count += (tot*(tot-1))/2;
                    break;
                }
                else{
                    int templ = l+1;
                    int tempr = r-1;
                    while(arr[templ]==arr[l])
                        templ++;
                    while(arr[tempr]==arr[r])
                        tempr--;
                    count += (templ-l)*(r-tempr);
                    l = templ;
                    r = tempr;
                }
            }
            else if((arr[l]+arr[r])>newNum){
                r--;
            }
            else{
                l++;
            }
        }
    }
    return count;
}
