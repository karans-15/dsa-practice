/*
    Single Number
    Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.
    (EASY)
*/

#include <bits/stdc++.h>
using namespace std;

int singleNumber(vector<int>& nums) {
    unordered_map<int,int> m;
    unordered_map<int,int> :: iterator it;
     
    for(int i = 0; i<nums.size(); i++){
        it = m.find(nums[i]);
        if(it != m.end())
            m.erase(nums[i]); 
        else
            m.insert({nums[i],1});
    }
    return m.begin()->first;
}

int main(){

    cout << "Enter number of elements in array: ";
    int n;
    cin >> n;
    vector<int> v(n,0);
    cout << "Enter Array: " << endl;
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    
    cout << singleNumber(v);

    return 0;
}

