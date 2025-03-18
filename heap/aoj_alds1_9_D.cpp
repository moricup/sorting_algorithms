#include <bits/stdc++.h>
using namespace std;

int up(int i){
    return i / 2;
}

void buildMaxHeapAsInverseOfHeapSort(int A[], int N){
    sort(A+1, A+N+1, less<int>());
    for(int i = 2; i < N; i++){
        swap(A[1], A[i]);
        int j = i;
        while(j > 1){
            swap(A[j], A[up(j)]);
            j = up(j);
        }
    }
    swap(A[1], A[N]);
}

int main(){
    int N;
    cin >> N;
    int A[N + 1];
    for(int i = 1; i <= N; i++){
        cin >> A[i];
    }
    buildMaxHeapAsInverseOfHeapSort(A, N);
    for(int i = 1; i <= N; i++){
        cout << A[i];
        if(i <= N - 1){
            cout << " ";
        }else{
            cout << endl;
        }
    }
    return 0;
}