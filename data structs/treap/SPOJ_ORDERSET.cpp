#include <bits/stdc++.h>
using namespace std;
//#define int long long
#define oo 1000000000000000000LL
#define mp make_pair
#define pb push_back
#define ss second
#define ff first

struct node{
    int v, p;
    int quant;
    node *l, *r;
    node(){}
    node(int _v, int _p){ v = _v; p = _p; l = r = NULL; quant = 1; }
};

node *treap;

void Update(node *atual){
    if(atual==NULL) return ;
    atual->quant = 1;
    if(atual->l!=NULL) atual->quant += atual->l->quant;
    if(atual->r!=NULL) atual->quant += atual->r->quant;
}

void Split(node *atual, int key, node *&l, node *&r){
    if( atual == NULL ){
        l = r = NULL;
        return ;
    }else if( atual->v < key ){
        Split(atual->r, key, atual->r, r);
        l = atual;
    }else{
        Split(atual->l, key, l, atual->l);
        r = atual;
    }

    Update(atual);
}
void Merge(node *&atual, node *l ,node *r){
    if(l==NULL or r == NULL){
        atual = (l==NULL ? r : l);
    }else if(l->p < r->p) {
        Merge(r->l, l, r->l);
        atual = r;
    }else{
        Merge(l->r, l->r, r);
        atual = l;
    }
    Update(atual);
}

void Insert(node *&atual, node *it){
    if(atual == NULL) atual = it;
    else if(atual->v == it->v){
        return ;
    }else if(it->p < atual->p) {
        if(it->v < atual->v)
            Insert(atual->l, it );
        else
            Insert(atual->r, it );
    }else{
        Split(atual, it->v, it->l, it->r);
        atual = it;
    }
    //printf("%d >> %d %d\n", atual->v, atual->p, it->p);
    Update(atual);
}

void Erase(node *&atual, int key){
    if(atual==NULL) return ;
    else if(atual->v == key){
        Merge(atual, atual->l, atual->r);
    }else{
        Erase(key < atual->v ? atual->l : atual->r, key );
    }
    Update(atual);
}

int K_ele(node *&atual, int k){
    int el = atual->l != NULL ? atual->l->quant : 0;

    if(k-el == 1)
        return atual->v;
    else if(k <= el) return K_ele(atual->l, k);
    else return K_ele(atual->r, k - el - 1);
}

int CountMin(node *&atual, int k){
    if(atual == NULL) return 0;
    int el = atual->l != NULL ? atual->l->quant : 0;

    if(atual->v < k) return el + CountMin(atual->r, k) + 1;
    else  return CountMin(atual->l, k);
}

int Is(node *atual, int k){
    if(atual == NULL) return 0;
    if(atual->v == k) return 1;
    if(atual->v < k) return Is(atual->r, k);
    else return Is(atual->l, k);
}


main() {
    srand( time(NULL) );

    int n;
    int v, k;
    char op[10];
    treap = NULL;

    cin >> n;
    while(n--){
        scanf("%s %d", &op, &v);
        if(op[0]=='I'){
            if(Is(treap, v) == 1)continue;
            node *temp = new node(v, rand());
            Insert(treap, temp);
            temp = NULL;
        }else if(op[0]=='D'){
            if(Is(treap, v) == 0)continue;
            Erase(treap, v);
        }else if(op[0]=='K'){
            if(treap!=NULL and treap->quant >= v){
                printf("%d\n", K_ele(treap, v));
            }else printf("invalid\n");
        }else{
            printf("%d\n", CountMin(treap, v));
        }
    }
}
