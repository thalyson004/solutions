#include <bits/stdc++.h>
using namespace std;
//#define int long long
#define oo ( (1<<30) + 5)
#define mp make_pair
#define pb push_back
#define ss second
#define ff first

struct node{

    int v;
    int p;
    int count;

    int ans;
    int suf;
    int pre;
    int soma;

    node *l, *r;
    node(){}
    node(int v_ = 0, int p_ = 0){
        v = v_;
        p = p_;

        l = r = NULL;

        ans = v;
        suf = v;
        pre = v;
        soma = v;
    }

};

int Pre(node *a){
    if(a == NULL) return 0;
    return a->pre;
}

int Suf(node *a){
    if(a == NULL) return 0;
    return a->suf;
}

int Ans(node *a){
    if(a == NULL) return -oo;
    return a->ans;
}

int Soma(node *a){
    if(a == NULL) return 0;
    return a->soma;
}

int Count(node *a){
    if(a == NULL) return 0;
    return a->count;
}

node *treap;

void Update(node *atual){

    if(atual == NULL) return;

    int v = atual->v;

    atual->ans = max(0, Pre(atual->r)) + v + max(0, Suf(atual->l));
    atual->ans = max(atual->ans, Ans(atual->r));
    atual->ans = max(atual->ans, Ans(atual->l));

    atual->soma = Soma(atual->l) + Soma(atual->r) + v;
    atual->count = 1 + Count(atual->r) + Count(atual->l);

    if(atual->l != NULL)
        atual->pre = max(Pre(atual->l), Soma(atual->l) + v),
        atual->pre = max(atual->pre, Soma(atual->l) + v + Pre(atual->r));

    else atual->pre = max(v, Pre(atual->r) + v);


    if(atual->r != NULL)
        atual->suf = max(Suf(atual->r), Soma(atual->r) + v),
        atual->suf = max(atual->suf, Soma(atual->r) + v + Suf(atual->l));

    else atual->suf = max(v, v + Suf(atual->l));

}

void Split(node *atual, node *&l, node *&r, int key){

    if(atual == NULL){
        l = r = NULL;
        return;
    }

    if(Count(atual->l) + 1 <= key){
        Split(atual->r, atual->r, r, key - Count(atual->l) - 1);
        l = atual;
    }

    else{
        Split(atual->l, l, atual->l, key);
        r = atual;
    }

    Update(atual);
}

void Merge(node *&atual, node *l, node *r){

    if(l == NULL || r == NULL) atual = (l == NULL)?r:l;

    else if( l->p < r->p ){
        Merge(r->l, l, r->l);
        atual = r;
    }

    else{
        Merge(l->r, l->r, r);
        atual = l;
    }

    Update(atual);
}

void Insert(int pos, int y){

    node *novo = new node(y, rand());

    node *l = NULL, *r = NULL;

    Split(treap, l, r, pos-1);

    treap = NULL;
    node *aux = NULL;

    Merge(aux, l, novo);
    Merge(treap, aux, r);

    aux = NULL;
}

void Delete(int pos){

    node *l = NULL, *r = NULL;
    Split(treap, l, r, pos);

    node *l2 = NULL, *r2 = NULL;
    Split(l, l2, r2, pos-1);

    treap = NULL;
    Merge(treap, l2, r);

    l2 = r2 = l = r = NULL;
}

int Query(int x, int y){

    node *l = NULL, *r = NULL;
    node *util = NULL, *r2 = NULL;

    Split(treap, l, r, x-1);
    Split(r, util, r2, y - x + 1);

    treap = r = NULL;

    int resposta = util->ans;

    Merge(r, util, r2);
    Merge(treap, l, r);

    return resposta;
}

main(){

    treap = NULL;
    srand(time(NULL));

    int n;
    scanf("%d", &n);

    for(int i = 1;i <= n;i++){

        int x;
        scanf("%d", &x);

        Insert(i, x);
    }

    int q;
    scanf("%d", &q);
    for(int i = 1;i <= q;i++){

        int x;
        int y;
        char op;

        scanf(" %c %d", &op, &x);

        if(op == 'I'){
            scanf("%d", &y);
            Insert(x, y);
        }

        else if(op == 'D') Delete(x);

        else if(op == 'R'){
            Delete(x);
            scanf("%d", &y);
            Insert(x, y);
        }

        else{
            scanf("%d", &y);
            printf("%d\n", Query(x, y));
        }

    }

    return 0;
}
