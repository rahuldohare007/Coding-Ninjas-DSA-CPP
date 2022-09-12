/*
Given an array A of random integers and an integer k, find and return the kth largest element in the array.

Note: Try to do this question in less than O(N * logN) time.

Input Format :
The first line of input contains an integer, that denotes the value of the size of the array. Let us denote it with the symbol N.
The following line contains N space separated integers, that denote the value of the elements of the array.
The following contains an integer, that denotes the value of k.

Output Format :
The first and only line of output contains the kth largest element

Constraints :
1 <= N, Ai, k <= 10^5
Time Limit: 1 sec

Sample Input 1 :
6
9 4 8 7 11 3
2
Sample Output 1 :
9

Sample Input 2 :
8
2 6 10 11 13 4 1 20
4
Sample Output 2 :
10
*/ 

#include <queue>
#include <vector>
int kthLargest(int* arr, int n, int k) {
 
  // 1.-----------------------------------------------
    priority_queue<int> pq; 
    
    // push first k eements in the priority queue
    for(int i=0; i<n; i++)
		    pq.push(arr[i]);
        
    // for remaining elements compare the element with max of pq ie top if smaller push in heap
    for(int j=0; j<k-1; j++){
        pq.pop();
    }
  
    return pq.top();
  
  // 2.------------------------------------------------
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i=0; i<k; i++){
        pq.push(arr[i]);
    }
    
    for(int i=k; i<n; i++){
        if(arr[i] > pq.top()){
            pq.pop();
            pq.push(arr[i]);
        }
    }
    
    return pq.top();
}
}
