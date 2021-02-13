#include <bits/stdc++.h>
using namespace std;

//For arrays we dont need to pass by referenece as arrays are pointers

void merge(int arr[], int start, int mid, int end){

	//1. Left array size = mid-start + 1
	//   Right array size = end - mid + 1
	//2. Create left and right subarrays	
	//3. Fill them up with values from original array
	//4. Compare left and right array elements and increment accordingly
	//5. Dont loose the iterators, using same iterators fill in the rest of the array
	
	int l1 = mid-start+1; 		
	int l2 = end-mid;

	int left[l1],right[l2];		
	for(int i=0; i<l1; i++){
		left[i] = arr[start+i];
	}
	for(int i=0; i<l2; i++){
		right[i] = arr[mid+1+i]; 
	}

	int i=0, j=0, k=start;

	while(i<l1 && j<l2){
		if(left[i]<=right[j]){
			arr[k++] = left[i++]; 	//CHECK
		}
		else{
			arr[k++] = right[j++];
		}
	}

	while(i<l1){
		arr[k++] = left[i++];	 //CHECK 
	}
	while(j<l2){
		arr[k++] = right[j++]; 	//CHECK
	}
}

void mergeSort(int arr[], int start, int end){
	if(start<end){
		int mid = (start+end)/2;
		
		mergeSort(arr, start, mid);  
		mergeSort(arr, mid+1, end);

		merge(arr, start, mid, end);
	}
}


int main(){

	int n;
	cin >> n;

	int arr[n];

	for(int i=0; i<n; i++){
		cin >> arr[i];
	}

	mergeSort(arr, 0, n);

	for(int i=0; i<n; i++){
		cout << arr[i] << " ";
	}
	return 0;
}