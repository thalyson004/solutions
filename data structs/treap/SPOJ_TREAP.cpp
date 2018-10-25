#include <bits/stdc++.h>
using namespace std;
#define int long long
#define oo 1000000000000000000LL
#define mp make_pair
#define pb push_back
#define ss second
#define ff first

struct node{
    int v, p;
    int qmin, qmax, qdiff;
    int quant;
    node *l, *r;
    node(){}
    node(int _v, int _p){
    	v = _v; p = _p;
    	l = r = NULL;
    	quant = 1;
    	qmin = qmax = _v;
    	qdiff = oo;
    }
};

node *treap;

void Update(node *atual){
    if(atual==NULL) return ;

    atual->quant = 1;
    if(atual->l!=NULL) atual->quant += atual->l->quant;
    if(atual->r!=NULL) atual->quant += atual->r->quant;

    atual->qmax = atual->qmin = atual->v;
    if(atual->r!=NULL){
    	atual->qmax = max(atual->qmax, atual->r->qmax);
    	atual->qmin = min(atual->qmin, atual->r->qmin);
    }
    if(atual->l!=NULL){
    	atual->qmax = max(atual->qmax, atual->l->qmax);
    	atual->qmin = min(atual->qmin, atual->l->qmin);
    }

    atual->qdiff = oo;
    if(atual->r!=NULL) atual->qdiff = min(atual->qdiff,
    	min(atual->r->qdiff, atual->r->qmin - atual->v) );

	if(atual->l!=NULL) atual->qdiff = min(atual->qdiff,
		min(atual->l->qdiff, atual->v - atual->l->qmax) );

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

int K_ele(node *atual, int k){
    int el = atual->l != NULL ? atual->l->quant : 0;

    if(k-el == 1)
        return atual->v;
    else if(k <= el) return K_ele(atual->l, k);
    else return K_ele(atual->r, k - el - 1);
}


int Nquery(node *&atual, int i, int j){
    int e1 = K_ele(atual, i+1);
    int e2 = K_ele(atual, j+1);

    node *l, *r;
    Split(atual, e1, l, r);
    Split(r, e2+1, atual, r);
 	int ans = atual->qdiff;
    Merge(atual, l, atual);
    Merge(atual, atual, r);
    return ans;
}

int CountMin(node *atual, int k){
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
    int v, i, j;
    char op[10];
    treap = NULL;

    cin >> n;
    while(n--){
        scanf(" %s", op);
        if(op[0]=='I'){
        	scanf("%lld", &i);
            if(Is(treap, i) == 1)continue;
            node *temp = new node(i, rand());
            Insert(treap, temp);
            temp = NULL;
        }else if(op[0]=='D'){
        	scanf("%lld", &i);
            if(Is(treap, i) == 0)continue;
            Erase(treap, i);
        }else if(op[0]=='X'){
        	scanf("%lld %lld", &i, &j);
        	if(j < i)swap(i,j);
            if(treap!=NULL and (j-i)!=0){
                printf("%lld\n", K_ele(treap, j+1) - K_ele(treap, i+1));
            }else printf("-1\n");
        }else if(op[0] == 'N'){
        	scanf("%lld %lld", &i, &j);
        	if(j < i)swap(i,j);
            if(treap!=NULL and (j-i)!=0){
	            printf("%lld\n", Nquery(treap, i, j));
            }else printf("-1\n");
        }
    }
}
