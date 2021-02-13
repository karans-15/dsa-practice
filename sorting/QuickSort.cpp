#include <bits/stdc++.h>
using namespace std;

//If we have a different choice of pivot, keep swapping till you reach pivot = arr[high] and then only use this particular implementation

int partition(int arr[], int low, int high){
	int pivot = arr[high];
	int i = low-1;

	for(int j=low; j<high;j++){
		if(arr[j]<pivot){
			i++;
			swap(arr[i],arr[j]);

//If a swap does not occur, i is fixated at an element before the element greater than or equal to pivot, hence, if then the next time 
// if there will be a swap, j will definately be on the position that is less than pivot, hence the swap is useful.
//At the high of all swaps, i will be at the last position less than pivot, hence it is then swapped with the next position(i+1).
		}
	}
	swap(arr[i+1],arr[high]);
	return i+1;
}

void quickSort(int arr[], int low, int high){

	if(low<high){
		int part = partition(arr, low, high);
		quickSort(arr,low,part-1);
		quickSort(arr,part+1,high);
	}
}


int main(){

	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++){
		cin >> arr[i];
	}
 
	quickSort(arr, 0, n - 1);
 
	for (int i = 0; i < n; i++){
		cout << arr[i] << " ";
	}

	return 0;
}