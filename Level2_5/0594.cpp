// 三分探索を関数化してプログラムをすっきりさせたい
#include<iostream>
using namespace std;

int ask(int x, int y, int z){
    int d;
    cout << "? " << x << " " << y << " " << z << endl;
    cin >> d;
    return d;
}

void answer(int x, int y, int z){
    cout << "! " << x << " " << y << " " << z << endl;
}

int main(){
    int lx = -150, rx = 150, ly = -150, ry = 150, lz = -150, rz = 150;
    int x, y = 0, z = 0;

    while(lx+2 < rx){
        int mid1 = (rx-lx)/3+lx, mid2 = (rx-lx)*2/3+lx;
        int ask1 = ask(mid1,y,z);
        int ask2 = ask(mid2,y,z);
        if(ask1 <= ask2){
            rx = mid2;
        }else{
            lx = mid1;
        }
    }

    x = (lx+rx)/2;
    
    while(ly+2 < ry){
        int mid1 = (ry-ly)/3+ly, mid2 = (ry-ly)*2/3+ly;
        int ask1 = ask(x,mid1,z);
        int ask2 = ask(x,mid2,z);
        if(ask1 <= ask2){
            ry = mid2;
        }else{
            ly = mid1;
        }
    }

    y = (ly+ry)/2;

    while(lz+2 < rz){
        int mid1 = (rz-lz)/3+lz, mid2 = (rz-lz)*2/3+lz;
        int ask1 = ask(x,y,mid1);
        int ask2 = ask(x,y,mid2);
        if(ask1 <= ask2){
            rz = mid2;
        }else{
            lz = mid1;
        }
    }

    z = (lz+rz)/2;

    answer(x, y, z);

    return 0;
}