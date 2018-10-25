#include <bits/stdc++.h>
using namespace std;

#define oo 100000000

void Unico();

int n;
int v[100005];
int Random[100005], ir;

struct node{
    node *l, *r;
    int p, k, q;
    int menor;
    int lazy;
    node(){
        l = r = NULL;
    }
    node(int _k){
        l = r = NULL;
        p = Random[ir++];
        k = _k;
        menor = k;
        q = 1;
        lazy = 0;
    }
};

int Menor(node *t){
    if(t == NULL) return oo;
    return t -> menor;
}

int Q(node *t){
    if(t == NULL) return 0;
    return t->q;
}

void Update(node *t){
    if(t == NULL) return;

    t->menor = min(min(t->k, Menor(t->l)), Menor(t->r));
    t->q = 1 + Q(t->l) + Q(t->r);
}

void Push(node *t){
    if(t == NULL) return;
    t->lazy = t->lazy%2;
    if(t->lazy){
        swap(t->l, t->r);
        if(t->l != NULL )t->l->lazy++;
        if(t->r != NULL )t->r->lazy++;
        t->lazy = 0;
    }
}

void Print(node *t){
    Push(t);
    if(!t) {
        printf("quitou\n");
        return ;
    }
    if(t->l) Print(t->l);
    printf("%d ", t->k);
    if(t->r) Print(t->r);
}

void split(node *t, node *&l, node *&r, int pos){
    Push(t);
    if(t==NULL){
        l = r = NULL;
        return;
    }
    if(Q(t->l) + 1 < pos){
        split(t->r, t->r, r, pos - Q(t->l) - 1);
        l = t;
    }else{
        split(t->l, l, t->l, pos);
        r = t;
    }
    Update(t);
}

void Merge(node *&t, node *l, node *r){
    Push(l); Push(r);
    if(l == NULL || r == NULL){
        t = l==NULL ? r : l;
    }else{
        if(l->p < r->p){
            Merge(r->l, l, r->l);
            t = r;
        }else{
            Merge(l->r, l->r, r);
            t = l;
        }
    }
    Update(t);
}

void Insert(node *&t, int x, int pos){
    Push(t);
    node *l = NULL, *r = NULL;
    split(t, l, r, pos);
    t = NULL;
    node *novo = new node(x);
    node *temp = NULL;
    Merge(temp, l, novo);
    Merge(t, temp, r);
    Update(t);
}

void Erase(node *t, int pos){
    Push(t);
    node *l = NULL, *r = NULL;
    split(t, l, r, pos);
    node *temp = NULL;
    split(r, temp, r, 2);
    delete temp;
    Merge(t, l, r);
}

int PosMenor(node *t){
    Push(t);
    if(t == NULL) return 0;
    if(Menor(t->l) == Menor(t)) return PosMenor(t->l);
    if(Menor(t->r) == Menor(t)) return PosMenor(t->r) + Q(t->l) + 1;
    return Q(t->l) + 1;
}

int Rodada(int j, node *&t){
    Push(t);
    int pm = PosMenor(t);

    node *l = NULL, *r = NULL, *rr = NULL, *temp = NULL;
    split(t, l, r, pm);
    split(r, temp, rr, 2);
    t = NULL, r = NULL;
    delete temp;
    if(l!=NULL)l->lazy++;
    Merge(t, l, rr);

    return pm;
}


int main() {
    for(int i = 0; i < 100005; i++) Random[i] = i;

    while(scanf("%d", &n) && n){
        node *treap = NULL;
        random_shuffle(Random, Random+n);
        ir = 0;

        for(int i = 0; i < n; i++) scanf("%d", &v[i]);
        Unico();

        for(int i = 0; i < n; i++)
            Insert(treap, v[i], i+1);

        for(int i = 1; i <= n; i++)
            printf("%d%c", Rodada(i, treap) + i - 1, i==n?'\n':' ');
    }
}

void Unico(){
    map<int,int> compress;
    int temp[100005];
    for(int i = 0; i < n; i++) temp[i] = v[i];
    sort(temp, temp+n);
    int id = 1;
    compress[temp[0]] = id;
    for(int i = 1; i <n; i++) if(temp[i] != temp[i-1]) compress[ temp[i] ] = ++id;
    for(int i = 0; i < n; i++) v[i] = compress[ v[i] ];
    int q[100005];
    int c[100005];
    memset(q, 0, sizeof q);
    memset(c, 0, sizeof c);
    for(int i = 0; i < n; i++) q[ v[i] ]++;
    for(int i = 1; i < n; i++) q[i] += q[i-1];
    for(int i = 0; i < n; i++){
        c[v[i]]++;
        v[i] = q[ v[i]-1 ] + c[v[i]];
    }
}
