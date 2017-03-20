#include<iostream>
using namespace std;

long long int max(int a, int b)
{
    if(a < b)
        return b;
    else 
        return a;
}
long long int calculate_candies(int a[], long long int n)
{
    long long int total = 0;
    int left[100000];
    int right[100000];
    
    for(int i=0; i<n; i++)
    {
        left[i] = 1;
        right[i] = 1;
    }
    
    for(int i=1; i<n; i++)
    {
        if(a[i-1] < a[i])
        {
            left[i] = left[i-1] + 1;
        }
    }
    
    for(int i=n-2; i>=0; i--)
    {
        if(a[i+1] < a[i])
        {
            right[i] = right[i+1] + 1;
        }
    }
    
    for(int i=0; i<n; i++)
    {
        total = total + max(left[i], right[i]);
    }
    
    return total;
}
int main()
{
    long long int n, total = 0;
    int a[100000];
    
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    
    total = calculate_candies(a, n);
    cout<<total;
    
    return 0;
}
