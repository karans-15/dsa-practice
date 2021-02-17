/*
    Given a string, check if it can form a palindrome or not (given all lowercase)
    Constraints: 0<=length(str)<=10^9
*/

#include <bits/stdc++.h>
using namespace std;


int main(){

    string str;
    bool canBePalindrome = true;
    cout << "Enter lowercase string: " << endl;
    cin >> str;

    int n;
    n = str.length();
    int numOddLetters = 0;

    /*
    //Implementation 1 (Using Array)
    vector<int> freq(256,0); //Can also do feq of 26 (26 alphabets) 
                            //However we will need to sub ascii of 'a'

    for(int i=0; i<n; i++){
        freq[str[i]]++; //checks ascii char and fills it in as per char
    }

    for(int i=0; i<256; i++){ 
        if(freq[i]%2==1){
            numOddLetters++;
        }
        if(numOddLetters>1){
            canBePalindrome = false;
            break;
        }
    }

    if(canBePalindrome)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    */
    
    
    //Implementation 2 (Using HashMap)
    unordered_map <char,int> m;
    unordered_map <char,int> :: iterator it;

    for(int i=0; i<n; i++){
        m[str[i]]++; //Can also initialize like an array
    }

    for(it = m.begin(); it!= m.end(); it++){
        if(it->second%2==1) //To access second, need to use '->' as it is not a reference, it is a pointer
            numOddLetters++;
        if(numOddLetters>1){
            canBePalindrome = false;
            break;
        }
    }   

    if(canBePalindrome)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}
