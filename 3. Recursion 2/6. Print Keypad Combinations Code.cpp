/*
Given an integer n, using phone keypad find out and print all the possible strings that can be made using digits of input n.
Note : The order of strings are not important. Just print different strings in new lines.
Input Format :
Integer n
Output Format :
All possible strings in different lines

Sample Input:
23
Sample Output:
ad
ae
af
bd
be
bf
cd
ce
cf
*/

#include <iostream>
#include <string>
using namespace std;

void print(int num,string out){
    if(num==0)
    {
        cout<<out<<endl;
        return ;
    }
    string s[]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    string input=s[num%10];
    for(int i=0;i<input.size();i++){
        print(num/10,input[i]+out);
    }
}
void printKeypad(int num){
     print(num,"");
}

