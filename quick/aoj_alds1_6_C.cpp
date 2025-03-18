#include <bits/stdc++.h>
using namespace std;

class RankedCard{
    public:
        char suit;
        int num;
        int rank;
};

int partition(RankedCard A[], int p, int r){
    // partition
    int i = p - 1;
    for(int j = p; j < r; j++){
        if(A[j].num <= A[r].num){
            i++;
            swap(A[i], A[j]);
        }
    }
    int q = i + 1;
    swap(A[q], A[r]);
    return q;
}

void quick_sort(RankedCard A[], int p, int r){
    if(p < r){
        int q = partition(A, p, r);
        quick_sort(A, p, q-1);
        quick_sort(A, q+1, r);
    }
}

int main(){
    // input
    int N;
    cin >> N;
    RankedCard A[N];
    char A_suit;
    int A_num;
    map<int, int> num_count;
    for(int i = 0; i < N; i++){
        cin >> A_suit >> A_num;
        A[i].suit = A_suit;
        A[i].num = A_num;
        if(num_count.find(A_num) == num_count.end()){
            num_count[A_num] = 0;
        }
        A[i].rank = num_count[A_num];
        num_count[A_num]++;
    }
    // sort
    quick_sort(A, 0, N-1);
    // output
    bool is_stable = true;
    for(int i = 0; i < N-1; i++){
        if(A[i].num == A[i+1].num && A[i].rank > A[i+1].rank){
            is_stable = false;
            break;
        }
    }
    if(is_stable){
        cout << "Stable" << endl;
    }else{
        cout << "Not stable" << endl;
    }
    for(int i = 0; i < N; i++){
        cout << A[i].suit << " " << A[i].num << endl;
    }
    return 0;
}