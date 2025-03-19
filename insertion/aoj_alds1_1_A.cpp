#include <bits/stdc++.h>
using namespace std;

void answerForNowStep(int A[], int N){
    for(int k = 0; k < N; k++){
        cout << A[k];
        if(k< N-1){
            cout << " ";
        }
    }
    cout << endl;
}

void insertionSortAndAnswerForEachStep(int A[], int N){
    int i, j, v;
    for(i = 0; i< N; i++){
        v = A[i];
        for(j = i-1; j >= 0; j--){
            if(A[j] > v){
                A[j+1] = A[j];
            }else{
                break;
            }
        }
        A[j+1] = v;
        answerForNowStep(A, N);
    }
}

int main(){
    int N;
    cin >> N;
    int A[N];
    for(int k = 0; k < N; k++){
        cin >> A[k];
    }
    insertionSortAndAnswerForEachStep(A, N);
    return 0;
}