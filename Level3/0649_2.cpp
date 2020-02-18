#include<iostream>
#include<random>
#include<vector>
using namespace std;
typedef long long ll;

// 0-indexed
template<class T>
struct Treap{
    struct Node{
        T val;
        int pri;
        int cnt;
        Node* ch[2];
        Node(T v, int p) : val(v), pri(p){
            cnt = 1;
            ch[0] = ch[1] = NULL;
        }
    };

    Node* root;
    vector<T> v;    // 列を返すとき用
    T def;  // !!!

    Treap(T d) : def(d){
        root = NULL;
    }

    int count(Node* t)  { return t==NULL ? 0 : t->cnt;}

    Node* update(Node* t){
        t->cnt = count(t->ch[0]) + count(t->ch[1]) + 1;
        return t;
    }

    Node* rotate(Node* t, int b){
        Node* s = t->ch[b];
        t->ch[b] = s->ch[1-b];
        s->ch[1-b] = t;
        update(t);
        update(s);
        return s;
    }

    Node* insert(Node* t, int k, T val, int pri){
        if(t == NULL)   return new Node(val, pri);
        int leftCnt = count(t->ch[0]);
        int b = k > leftCnt;
        t->ch[b] = insert(t->ch[b], k-(b ? leftCnt+1 : 0), val, pri);
        update(t);
        if(t->ch[b]->pri > t->pri)  t = rotate(t, b);
        return t;
    }

    Node* erase(Node* t, int k, bool me=false){
        if(!me && count(t) <= k)   return t;    // out-of-range
        me |= count(t->ch[0])==k;
        if(me){
            if(t->ch[0]==NULL && t->ch[1]==NULL){
                delete t;
                return NULL;
            }
            int b = (t->ch[0]==NULL ? -1 : t->ch[0]->pri) < (t->ch[1]==NULL ? -1 : t->ch[1]->pri);
            t = rotate(t, b);
            t->ch[1-b] = erase(t->ch[1-b], k, me);
        }else{
            if(count(t->ch[0]) > k){
                t->ch[0] = erase(t->ch[0], k, me);
            }else{  // definitely count(t->ch[0]) < k
                t->ch[1] = erase(t->ch[1], k-count(t->ch[0])-1, me);
            }
        }
        return update(t);
    }

    T get(Node* t, int k){
        int leftCnt = count(t->ch[0]);
        if(leftCnt > k)     return get(t->ch[0], k);
        if(leftCnt == k)    return t->val;
        return get(t->ch[1], k-1-leftCnt);
    }

    Node* insert(int k, T val){
        return root = insert(root, k, val, rand());
    }

// !!! 雑拡張
    Node* insert_value(Node* t, T val, int pri){
        if(t == NULL)   return new Node(val, pri);
        int b = t->val < val;
        t->ch[b] = insert_value(t->ch[b], val, pri);
        update(t);
        if(t->pri < t->ch[b]->pri)  t = rotate(t, b);
        return t;
    }
    Node* insert_value(T val){
        return root = insert_value(root, val, rand());
    }
// !!!

    Node* erase(int k){
        return root = erase(root, k);
    }
    T get(int k){
        return k < count(root) ? get(root, k) : def;    // !!!
    }
    
    void flatten(Node* t){
        if(t==NULL) return;
        if(t->ch[0] != NULL)    flatten(t->ch[0]);
        v.push_back(t->val);
        if(t->ch[1] != NULL)    flatten(t->ch[1]);
    }

    vector<T> flatten(){
        v.clear();
        flatten(root);
        return v;
    }
};

int main(){
    Treap<ll> t(-1);
    int q, k;
    scanf("%d %d", &q, &k);
    k--;
    while(q--){
        int op;
        ll x;
        scanf("%d", &op);
        if(op == 1){
            scanf("%lld", &x);
            t.insert_value(x);
        }else if(op == 2){
            printf("%lld\n", t.get(k));
            if(t.get(k) != -1)  t.erase(k);
        }
    }
    return 0;
}