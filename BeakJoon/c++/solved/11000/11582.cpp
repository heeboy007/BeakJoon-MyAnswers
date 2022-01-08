#include<iostream>
#include<vector>
#include<algorithm>

#define MAX 1024 * 1024

using namespace std;

int n, k;
int sorted[MAX];

void merge(int nums[], int left, int right){
    int i, j, k, l, mid = (left + right) / 2;
    i = left;
    j = mid+1;
    k = left;

    while(i<=mid && j<=right){
        if(nums[i]<=nums[j])
            sorted[k++] = nums[i++];
        else
            sorted[k++] = nums[j++];
    }

    if(i>mid){
        for(l=j; l<=right; l++)
            sorted[k++] = nums[l];
    }
    else{
        for(l=i; l<=mid; l++)
            sorted[k++] = nums[l];
    }

    for(l=left; l<=right; l++){
        nums[l] = sorted[l];   
    }
}

void merge_sort(int nums[]){
    for(int step = 2; step <= n; step *= 2){
        for(int i = 0; i < n; i += step){
            merge(nums, i, i + step - 1);
        }
        if(step == n / k){
            for(int i = 0; i < n; i++){
                cout << nums[i] << ' ';
            }
        }
    }

    // if(left<right){
    //     int mid = (left+right) / 2;
    //     merge_sort(nums, left, mid, k);
    //     merge_sort(nums, mid+1, right, k);
    //     merge(nums, left, mid, right);
    //     if(nums.size() / k == (right - left + 1) && right == (nums.size() - 1)){
    //         for(int node : nums){
    //             cout << node << ' ';
    //         }
    //     }
    // }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    int nums[n] = {0};
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    cin >> k;

    merge_sort(nums);

    // for(int node : nums){
    //     cout << node << ' ';
    // }

    return 0;
}