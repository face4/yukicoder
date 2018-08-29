#include<iostream>
#include<algorithm>
using namespace std;

int hit = 0, blow = 0;

int getNext(int arr[4], int pos){
    int next = (arr[pos] + 1)%10;
    while(1){
        bool judge = true;
        for(int i = 0; i < 4; i++)  if(arr[i] == next)  judge = false;
        if(judge)   break;
        else        next = (next+1)%10;
    }
    return next;
}

void ask(int arr[4]){
    cout << arr[0] << " " << arr[1] << " " << arr[2] << " " << arr[3] << endl << flush;
    cin >> hit >> blow;
    if(hit == 4)    exit(0);
}

int main(){
    int arr[4];
    arr[0] = 0, arr[1] = 1, arr[2] = 2, arr[3] = 3;

    ask(arr);
    int before = hit + blow;

    int now = 0;

    while(before < 4){
        int tmp = arr[now];
        arr[now] = getNext(arr, now);
        ask(arr);
        if(hit + blow > before){
            now++;
        }
        before = hit + blow;
    }

    sort(arr, arr+4);

    do{
        ask(arr);
    }while(next_permutation(arr, arr+4));

    return 0;
}