/*
Suppose you have a string, S, made up of only 'a's and 'b's. Write a recursive function that checks if the string was generated using the following rules:
a. The string begins with an 'a'
b. Each 'a' is followed by nothing or an 'a' or "bb"
c. Each "bb" is followed by nothing or an 'a'
If all the rules are followed by the given string, return true otherwise return false.
Input format :
String S
Output format :
'true' or 'false'

Sample Input 1 :
abb
Sample Output 1 :
true
Sample Input 2 :
abababa
Sample Output 2 :
false
Explanation for Sample Input 2
In the above example, a is not followed by either "a" or "bb", instead it's followed by "b" which results in false to be returned.
*/

bool solve(char input[]) {
    if(input[0]=='\0')
        return true;
    bool so;
    if(input[0]=='a' && (input[1]=='\0' || input[1]=='a'))
        so=solve(input+1);
    else if(input[0]=='a' && (input[1]=='b' && input[2]=='b'))
        so=solve(input+1);
    else if(input[0]=='b' && input[1]=='b' && (input[2]=='\0' || input[2]=='a'))
        so= solve(input+2);
    else
        return false;
    return so;
}

bool checkAB(char input[]) {
    if(input[0] == '\0')
        return true; 
    else if (input[0] != 'a')
        return false;
    return solve(input);
}
