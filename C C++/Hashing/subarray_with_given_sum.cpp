#include <bits/stdc++.h>
using namespace std;

int ZeroSumSubarray(int arr[], int n,int sum)
{
    unordered_set<int> us;
    int prefix_sum = 0;
    us.insert(0);
    for(int i = 0; i < n; i++)
    {
        prefix_sum += arr[i];
        if(us.find(prefix_sum-sum) != us.end())
          return 1;
        us.insert(prefix_sum);
    }
    return 0;
    
}

int main()
{
    int arr[] = {5,8,6,13,3,-1};
    int n = sizeof(arr)/sizeof(arr[0]);
    int sum = 22;
    cout << ZeroSumSubarray(arr, n,sum);
}