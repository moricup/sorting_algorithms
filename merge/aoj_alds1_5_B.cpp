#include <bits/stdc++.h>
using namespace std;

int num_compared = 0;

void merge(int A[], int left, int mid, int right){
    int n1 = mid - left;
    int n2 = right - mid;
    int L[n1 + 1], R[n2 + 1];
    int i,j;
    for(i = 0; i < n1; i++){
        L[i] = A[left + i];
    }
    for(j = 0; j < n2; j++){
        R[j] = A[mid + j];
    }
    L[n1] = INT_MAX;
    R[n2] = INT_MAX;
    i = 0;
    j = 0;
    for(int k = left; k < right; k++){
        num_compared++;
        if(L[i] <= R[j]){
            A[k] = L[i];
            i++;
        }else{
            A[k] = R[j];
            j++;
        }
    }
}

void mergeSort(int A[], int left, int right){
    if(left+1 < right){
        int mid = (left + right) / 2;
        mergeSort(A, left, mid);
        mergeSort(A, mid, right);
        merge(A, left, mid, right);
    }
}

int main(){
    int N;
    cin >> N;
    int A[N];
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }
    mergeSort(A, 0, N);
    for(int i = 0; i < N; i++){
        cout << A[i];
        if(i < N-1){
            cout << " ";
        }else{
            cout << endl;
        }
    }
    cout << num_compared << endl;
    return 0;
}