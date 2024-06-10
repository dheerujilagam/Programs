#include <bits/stdc++.h>
using namespace std;

int largestSubarrayWithSumX(int arr[], int n, int sum)
{
    int prefix_sum = 0, res = 0;
    unordered_map<int,int> mp;
    for(int i = 0; i < n; i++)
    {
        prefix_sum += arr[i];
        if(prefix_sum == sum) res=i+1;
        if(mp.find(prefix_sum-sum)!=mp.end())
            res=max(res,i-mp[prefix_sum-sum]);
        if(mp.find(prefix_sum)==mp.end())
            mp[prefix_sum-sum]=i;
    }
    return res;
}

int main()
{
    int arr[] = {8, 3, -7, -4, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    int sum = -8;
    
    cout << largestSubarrayWithSumX(arr, n, sum);
    
}