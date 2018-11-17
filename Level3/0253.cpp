#include<iostream>
using namespace std;

int ask(int Y){
	cout << "? " << Y << endl << flush;
	int res;
	cin >> res;
	return res;
}

void answer(int Y){
    cout << "! " << Y << endl << flush;
}

int main(){
    if(ask(99) <= 0){
        for(int i = 1;;i++){
            if(ask(0) == 0){
                answer(i);
                return 0;
            }
        }
    }

    // l inclusive, r inclusive
    int l = 10, r = 1000000000;
    int cnt = 1;

    while(r-l > 1){
        int mid = (l+r)/2;
        switch(ask(mid-cnt)){
            case -1:
                r = mid;
                break;
            case 1:
                l = mid+1;
                break;
            case 0:
                answer(mid);
                return 0;
        }
        cnt++;
    }

    answer(l);

    return 0;
}