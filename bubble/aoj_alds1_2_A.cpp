#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    int A[N];
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }
    int changed = 0;
    for(int i = 0; i < N; i++){
        for(int j = 1; j < N - i; j++){
            if(A[j-1] > A[j]){
                swap(A[j-1], A[j]);
                changed++;
            }
        }
    }
    for(int i = 0; i < N-1; i++){
        cout << A[i] << " ";
    }
    cout << A[N-1] << endl;
    cout << changed << endl;
    return 0;
}