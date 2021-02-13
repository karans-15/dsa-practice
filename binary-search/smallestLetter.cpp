/*
Problem Link: https://leetcode.com/problems/find-smallest-letter-greater-than-target/

Problem: Find Smallest Letter Greater Than Target
	Given a list of sorted characters letters containing only lowercase letters, and given a target letter target, 
	find the smallest element in the list that is larger than the given target.
	Letters also wrap around. For example, if the target is target = 'z' and letters = ['a', 'b'], the answer is 'a'.

*/
#include <bits/stdc++.h>
using namespace std;


char nextGreatestLetter(vector<char>& letters, char target) {
	//Check if last element smaller than target
	if((int)target>=(int)letters[letters.size()-1]) return letters[0];
    int mid,high = letters.size()-1, low=0;
    while(low<high){
        mid = low + (high-low)/2;
        //Normal Binary Search Conditions
        if((int)letters[mid]<=(int)target) low = mid+1;
        else high = mid;
    }
    return letters[low];
}

int main(){

	int n;
	cin >> n;
	vector<char> v;
	for(int i=0; i<n; i++){
		char x;
		cin >> x;
		v.push_back(x);
	}
	char target;
	cin >> target;

	cout << nextGreatestLetter(v,target);

	return 0;
}