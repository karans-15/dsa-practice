#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<long long> vll; 

void insersionSort(vll v){

	for(int i=1;i<v.size();i++){
		for(int j=i; j>0; j--){
			if(v[j]<v[j-1]){
				swap(v[j],v[j-1]);
			}
		}
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
 
	//selectionSort(v);
 
	for (int i = 0; i < n; i++){
		cout << v[i] << " ";
	}

	return 0;
}