#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int N = 0,M = 0,sum = 0,
        d1 = 0,d2 = 0,
        t1 = 0,t2 = 0;
    int arr[100000];
    cin >> N;
    for(int i = 0; i < N ; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }
    cin >> M;
    for(int j = 0; j < M; j++)
    {
        d1 = 0; d2 = 0;
        cin >> t1 >> t2;
        t1--; t2--;
        if(t1 > t2) swap(t1,t2);
        for(int i = t1; i < t2; i++ ) d1 += arr[i];
        d2 = sum - d1;
        d1 = d1 > d2 ? d2 : d1;
        cout << d1 << endl;
    }
    return 0;
}