#include <bits/stdc++.h>
using namespace std;

int partition(int A[], int p, int r){
    int i = p - 1;
    for(int j = p; j < r; j++){
        if(A[j] <= A[r]){
            i++;
            swap(A[i], A[j]);
        }
    }
    int q = i + 1;
    swap(A[q], A[r]);
    return q;
}

int main(){
    int N;
    cin >> N;
    int A[N];
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }
    int q = partition(A, 0, N-1);
    for(int i = 0; i < q; i++){
        cout << A[i] << " ";
    }
    cout << "[" << A[q] << "]";
    if(q < N-1){
        cout << " ";
    }
    for(int i = q+1; i < N; i++){
        cout << A[i];
        if(i < N-1){
            cout << " ";
        }
    }
    cout << endl;    
    return 0;
}