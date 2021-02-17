/*
	Given an array of integer nums and a target, return indices of two numbers that add to the target.
	Assume every array has just one solution same index cannot be repeated.
	
	Constraints:
		0 <=length(nums)<= 10^3
		10^-9 <= elements <= 10^9
		10^-9 <= target <= 10^9

*/

#include <bits/stdc++.h>
using namespace std;

int main(){

	int n;
	cout << "Enter no of elements in array: " ;
	cin >> n;
	vector<int> nums(n,0); //Creates n length vector and initializes all elements to 0 
	vector<int> ans(2,-1);

	cout << "Enter Array: " << endl;
	for(int i=0; i<n; i++){
		cin >> nums[i]; //Need not do pushback as vector already made. If we do pushback, it will be added after n empty elements	
	}

	int target;
	cout << "Enter target: " ;
	cin >> target;

	unordered_map<int,int> m;
	unordered_map<int,int> :: iterator it;

	for(int i=0; i<n; i++){
		m.insert({nums[i],i}); //Key = number, value = index
	}
	//Calculates hash function by itself and .find() uses hash function to find index
	for(int i=0;i<n;i++){
		it = m.find(target-nums[i]); //If it doesnt find, iterator goes to .end() pos, points to one element after end

		if(it!=m.end()){
			if(it->second != i){ //To check that it is not returning the same index
				ans[0] = i;
				ans[1] = it->second;
				break;
			}
		}
	}
	if(ans[0]==-1 && ans[1]==-1)
		cout << "No such element found!" << endl;
	else
		cout << ans[0] << " " << ans[1] << endl;
	return 0;
}