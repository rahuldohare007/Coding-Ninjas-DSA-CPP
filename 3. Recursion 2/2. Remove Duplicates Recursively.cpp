/*
Given a string S, remove consecutive duplicates from it recursively.
  
Sample Input 1 :
aabccba
Sample Output 1 :
abcba
Sample Input 2 :
xxxyyyzwwzzz
Sample Output 2 :
xyzwz
*/

void removeConsecutiveDuplicates(char *input) {
    if(input[0]=='\0'){ 
        return;
    }
    if(input[0] == input[1]){        
        for(int i=0; input[i] != '\0'; i++){
            input[i]=input[i+1];
        }
        return removeConsecutiveDuplicates(input);
    }
    else{
        return removeConsecutiveDuplicates(input+1);
    }
}
