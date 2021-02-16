/*
    Koko Eating Bananas

    Koko loves to eat bananas. There are N piles of bananas, the i-th pile has piles[i] bananas. 
    The guards have gone and will come back in H hours. Koko can decide her bananas-per-hour eating speed of K.
    Each hour, she chooses some pile of bananas, and eats K bananas from that pile. If the pile has less than K bananas, 
    she eats all of them instead, and won't eat any more bananas during this hour. Koko likes to eat slowly, 
    but still wants to finish eating all the bananas before the guards come back.

    Return the minimum integer K such that she can eat all the bananas within H hours.
*/

#include <bits/stdc++.h>
using namespace std;

int hoursReq(vector<int>& piles, int k){
    int counter=0;
    for(int i=0; i<piles.size();i++){
        if(piles[i]>k)
            counter += ceil((float)piles[i]/(float)k);
        else
            counter++;
    }
    return counter;
}
    
int minEatingSpeed(vector<int>& piles, int H) {
    long long max = piles[0];
    for(int i = 1; i<piles.size(); i++){
        if(piles[i]>max)
            max = piles[i];
    }
    if(H==piles.size())
        return max;
    int low = 1, high = max;
    while(low<high){
        int mid = low + (high-low)/2;
        if(hoursReq(piles,mid)>H)
            low = mid+1;
        else
            high = mid;
    }
    return low;
}

int main(){

    int n;
    cin >> n;
    vector<int> piles;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        piles.push_back(x);
    }
    int h;
    cin >> h;

    cout << minEatingSpeed(piles,h);
    return 0;
}



