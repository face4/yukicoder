#include<iostream>
#include<queue>
using namespace std;

int main(){
    int x, y, move = 0;
    cin >> x >> y;
    pair<int, int> dst = {x, y};
    bool able = false;
    
    queue<pair<int, int> > points;
    points.push({0, 0});

    while(!points.empty() && move <= (8+64+512)){
        pair<int , int> now = points.front();
        points.pop();

        if(now == dst){
            able = true;
            break;
        }

        for(int dx = 1; dx <= 2; dx++){
            int dy = (dx == 1 ? 2 : 1);
            points.push(make_pair(now.first+dx, now.second+dy));
            points.push(make_pair(now.first+dx, now.second-dy));
            points.push(make_pair(now.first-dx, now.second+dy));
            points.push(make_pair(now.first-dx, now.second-dy));
        }

        move++;
    }

    if(able)    cout << "YES" << endl;
    else        cout << "NO" << endl;

    return 0;
}