/*
Sort an array A using Quick Sort.
Change in the input array itself. So no need to return or print anything.


Input format :
Line 1 : Integer n i.e. Array size
Line 2 : Array elements (separated by space)
Output format :
Array elements in increasing order (separated by space)

Sample Input 1 :
6 
2 6 8 5 4 3
Sample Output 1 :
2 3 4 5 6 8
Sample Input 2 :
5
1 5 2 7 3
Sample Output 2 :
1 2 3 5 7 
*/

void swap(int input[],int i,int j){
    int temp = input[i];
    input[i] = input[j];
    input[j] = temp;
}
int partition(int input[], int start,int end){
    int pivot=input[end];
    int i=start-1;
    for(int j=start; j<end; j++){
        if(pivot>=input[j]){
            i++;
            swap(input,i,j);
        }
    }
    swap(input,i+1,end);
    return i+1;
}
void quickSort(int input[], int start, int end){
    if(start >= end){
        return;
    }
    int PI = partition(input,start,end);
    quickSort(input,start,PI-1);
    quickSort(input,PI+1,end);
}
void quickSort(int input[], int size) {
 if(size<=0){
     return;
 }
    quickSort(input, 0, size-1);
}
