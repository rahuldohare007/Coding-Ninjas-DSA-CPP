/*
Sort an array A using Merge Sort.
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
2 1 5 2 3
Sample Output 2 :
1 2 2 3 5 
*/

void merging(int input [],int low, int mid, int high) {

    int b[high-low+1];
    int l1=low,l2=mid+1,i=0;
    while(l1 <= mid && l2 <= high) {
        if(input[l1] <= input[l2])
            b[i++] = input[l1++];
        else
            b[i++] = input[l2++];
    } 
        while(l1 <= mid)  
        {
            b[i++] = input[l1++];
        }

        while(l2 <= high)  
        {
            b[i++] = input[l2++];
        }

        int j=0;
        for(i = low; i <= high; i++)
            input[i] = b[j++];
       
}
void mergeSort1(int input[],int first,int last)
{


    if(first<last) {
        int mid = (first+last) / 2;
        mergeSort1(input,first, mid);
        mergeSort1(input,mid+1,last);
        merging(input,first, mid,last);
    } else { 
        return;
    }   
}
void mergeSort(int input[],int length)
{
    if(length<=0)
    {
        return;
    }
    mergeSort1(input,0,length-1);
}

  
