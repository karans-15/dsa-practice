#include <bits/stdc++.h>
using namespace std;

//Implementation of Bubble Sort. Time Complexity: O(n^2)

void bubbleSort(vector<long long>& v, int n){
	bool swapped;
	for(unsigned int i=0;i<n-1;i++){
		swapped = false;
		for(unsigned int j=0;j<n-1;j++){
			if(v[j]>v[j+1]){
				swap(v[j],v[j+1]);
				swapped = true;
			}
		}
		if (swapped == false) 
        break; //If no swaps occur, array is sorted
	}
}

int main(){

	int n;
	cin >> n;

	vector<long long> v(n);
	for(auto i=0; i<n;i++){
		cin >> v[i];
	}

	bubbleSort(v,v.size());

	cout << "Sorted Array: ";

	for(auto i=0; i<n; i++){
		cout << v[i] << " ";
	}

	return 0;
}
