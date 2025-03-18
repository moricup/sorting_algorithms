#include <bits/stdc++.h>
using namespace std;

int left(int i){
    return 2 * i;
}

int right(int i){
    return 2 * i + 1;
}

void maxHeapify(int A[], int i, int N){
    int l = left(i);
    int r = right(i);
    int largest;
    if(l <= N && A[l] > A[i]){
        largest = l;
    }else{
        largest = i;
    }
    if(r <= N && A[r] > A[largest]){
        largest = r;
    }

    if(largest != i){
        swap(A[i], A[largest]);
        maxHeapify(A, largest, N);
    }
}

void buildMaxHeap(int A[], int N){
    for(int i = N / 2; i >= 1; i--){
        maxHeapify(A, i, N);
    }
}

int main(){
    int N;
    cin >> N;
    int A[N + 1];
    for(int i = 1; i <= N; i++){
        cin >> A[i];
    }
    buildMaxHeap(A, N);
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