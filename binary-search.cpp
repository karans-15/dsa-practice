#include <bits/stdc++.h>
using namespace std;


//Finds position of Target
int search1(vector<long long>& nums,long long target){
    //First T
    int high = nums.size()-1, low = 0, mid;
    while(low<high){
        mid = low + (high-low)/2;
        if(nums[mid]<target) low = mid+1;
        else high = mid;
    }
    if(target==nums[low]) return low;
    return -1;
}



//Finds first number less than target
int search2(vector<long long>& nums,long long target){
    //First T
    int high = nums.size()-1, low = 0, mid;
    while(low<high){
        mid = low + (high-low+1)/2;
        if(nums[mid]<target) low = mid;
        else high = mid-1;
    }
    return nums[low];
}


int main(){

    int n;
    cout << "Number of Elements in array: ";
    cin >> n;
    cout << "Input Sorted array(space seperated): ";

    vector<long long> nums;

    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        nums.push_back(x);
    }

    cout << "Enter Element to search for: ";
    long long target;
    cin >> target;

    cout << "Biggest Number Less than " << target << " is: " << search2(nums, target) << endl;
    //if(search(nums,target)==-1) cout << "NOTE:Position '-1' means target element not found" << endl;

    return 0;
}



