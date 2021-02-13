#include <bits/stdc++.h>
using namespace std;
typedef long long ll; // long long as ll
typedef vector<long long> vll;  //Vector<long long> as vll

//Find i'th min add swap with ith position. Find min of unsorted array and append to sorted array.

void selectionSort(vll& v){ //Do not forget use pointers!!!! (&)
	int index;
	ll min;
	for(int i=0;i<v.size()-1;i++){
		min = v[i];
		for(int j=i;j<v.size();j++){
			if(v[j]<=min){
				min = v[j];
				index = j;
			}
		}
		swap(v[i],v[index]);
	}

}


int main(){

	int n;
	cin >> n;
	vll v;

	for (int i = 0; i < n; i++){
		ll x;
		cin >> x;
		v.push_back(x);
	}
 
	selectionSort(v);
 
	for (int i = 0; i < n; i++){
		cout << v[i] << " ";
	}

	return 0;
}