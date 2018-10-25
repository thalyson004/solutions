#include <bits/stdc++.h>

using namespace std;
#define MAXD 1100005

typedef long long int64;
typedef unsigned long long uint64;


struct node{
    int c, y, val, swap;
    int sum[28];
    node *l, *r;
    node(){}
    node( int v ){
        val=v;
        memset(sum, 0, sizeof(sum));
        sum[v] = 1;
        y=rand();
        c=1;
        swap=0;
    }
};

node null, data[MAXD];
node *tree;
int d_cnt = 0;
string str = "";

node* new_node( int val ){
    node *ret = &(data[d_cnt++] = node(val));
    ret->r=ret->l=&null;
    return ret;
}

void relax( node* t ){
    if( t != &null ){
        t->c = t->l->c + t->r->c + 1;

        for(int i = 0; i < 27; i++){
            t->sum[i] = 0;
            if( t->l != &null ) t->sum[i] = t->l->sum[i];
            if( t->r != &null ) t->sum[i] += t->r->sum[i];
        }
        t->sum[t->val]++;
    }
}

void lazy( node* &t ){
    if( t!=&null ){
        if( t->swap==1 ){
            node* aux=t->l;
            t->l=t->r;
            t->r=aux;
            t->l->swap^=1;
            t->r->swap^=1;
            t->swap=0;
        }
    }
}

void split( node* &t, int x, node* &lt, node* &rt){
    lazy(t);
    if( t==&null ){
        lt=rt=&null;
    }
    else{
        node *a, *b;
        if( x <= t->l->c ){
            split(t->l,x,a,b);
            t->l=b;
            lt=a;
            rt=t;
            relax(t);
        }
        else{
            split(t->r,x-t->l->c-1,a,b);
            t->r=a;
            lt=t;
            rt=b;
            relax(t);
        }
    }
}

void merge( node* &t1, node* &t2, node* &t ){
    lazy(t1);
    lazy(t2);
    if( t1==&null ){
        t = t2;
    }
    else if( t2==&null ){
        t = t1;
    }
    else{
        node* a;
        if( t1->y < t2->y ){
            merge(t1->r,t2,a);
            t1->r = a;
            relax(t1);
            t = t1;
        }
        else{
            merge(t1,t2->l,a);
            t2->l = a;
            relax(t2);
            t = t2;
        }
    }
}

void insert( node* &t, int pos, int val ){
    node *lt, *rt, *a, *b;
    split(t,pos-1,lt,rt);
    a = new_node(val);
    merge(lt,a,b);
    merge(b,rt,t);
}

void put_print( node* t ){
    lazy(t);
    if( t!=&null ){
        put_print(t->l);
        str += char(t->val+'a');
        put_print(t->r);
    }
}

int querySum( node* &t, int a, int b, int c){
    int ret=0;
    if( t!=&null ){
        lazy(t);
        if( a<=1 && t->c<=b ){
            return t->sum[c];
        }
        if( t->l->c >= a ){
            ret+=querySum(t->l,a,b, c);
        }
        if( t->l->c+1 >= a && t->l->c+1 <= b ){
            ret+=t->val == c;
        }
        if( b > t->l->c+1 ){
            ret+=querySum(t->r,a-t->l->c-1,b-t->l->c-1, c);
        }
    }
    return ret;
}

void reverse( node* &t, int a, int b ){
    node *t1, *t2, *t3, *aux;
    split(t,a-1,t1,aux);
    split(aux,b-a+1,t2,t3);
    t2->swap^=1;
    merge(t1,t2,aux);
    merge(aux,t3,t);
}

int queryRangeHi(node *& t, int c){
    if( t != &null ){
        lazy(t); //atualiza swaps e o acumulado das letras na subarvore t

        //se tem filho direito e a subarvore do filho direito contem a letra c
        if( t->r && t->r->sum[c] ){
            return queryRangeHi(t->r, c) + 1 + ((t->l) ? (t->l->c) : (0));
        }
        //note que estamos procurando a ultima letra c, se o no atual for a propria letra entao
        //essa e a ultima letra do intervalo visto que a subarvore a direita contem
        //as letras anteriores a atual
        else if( t->val != c && t->l && t->l->sum[c] ){
            return queryRangeHi(t->l, c);
        }
        //devemos contabilizar se o no atual eh a letra em questao + a quantidade de letras que aparecem antes
        //dessa forma descobrimos a posicao correta =)
        return (t->val == c) +  ((t->l) ? (t->l->c) : (0));
    }
    return 0;
}

int queryRangeLo(node *& t, int c){
    if( t != &null ){
        lazy(t);
        //se tem filho esquerdo e a subarvore do filho esquerdo contem a letra em questao
        if( t->l && t->l->sum[c] ){
            return queryRangeLo(t->l, c);
        }
        //note que estamos procurando a primeira ocorrencia da letra c, se o no atual
        //for a letra c entao as letras que estao na subarvore a direita estao
        //depois da letra na posicao atual da range ( OBS: visitamos toda a subarvore da esquerda primeiro,
        //dessa forma garantimos que visitamos todas as letras c anteriores a atual)
        else if( t->val == c ){
            return 1 + ((t->l) ? (t->l->c) : (0));
        }
        //OK o no atual nao eh a letra c, devemos olhar na subarvore da direita mas sempre contabilizando
        //a quantidade de letras na subarvore da esquerda, garantindo a posicao correta
        else if( t->r && t->r->sum[c] ){
            return queryRangeLo(t->r, c) + 1 + ((t->l) ? (t->l->c) : (0));
        }
    }
    return 0;
}

pair < int, int > queryRange(node *&t, int a, int b, int val) {
    pair < int, int > ans;
    node *t1, *t2, *t3, *aux;

    lazy(t);

    split(t,a-1,t1,aux); // range(2 5) --> 0 1 2 3 4 5 6 7 --> t1 = 0 1  e  aux = 2 3 4 5 6 7
    split(aux,b-a+1,t2,t3); // range (2 5) --> t2 = 2 3 4 5 e t3 = 6 7

    // final:
    // t1 = 0 1
    // t2 = 2 3 4 5
    // t3 = 6 7

    //com a range de interesse basta descobrir a primeira e a ultima posicao da letra val
    ans.first = queryRangeLo(t2, val)-1;
    ans.second = queryRangeHi(t2, val)-1;

    merge(t1,t2,aux);
    merge(aux,t3,t);
    return ans;
}


int main(){
    ios::sync_with_stdio(false);
    srand(time(NULL));

    int l, n, a, b, op, qtd;
    char c;
    pair < int, int > p;

    cin >> l >> n;

    d_cnt = null.c = null.val = 0;
    tree = &null;

    cin >> str;
    for(int i = 0; i < l; i++){
        insert(tree,i+1,str[i]-'a');
    }

    while( n-- ){
        cin >> op;
        switch(op){
            case 1:
                cin >> a >> b >> c;
                if( b < a ){
                    swap(a,b);
                }
                cout << querySum(tree, a, b, c-'a') << '\n';
            break;
            case 2:
                cin >> a >> b >> c;
                if( b < a ){
                    swap(a,b);
                }
                qtd = querySum(tree, a, b, c-'a');
                if( qtd <= 0 ){
                    cout << "-1\n";
                }
                else{
                    p = queryRange(tree, a, b, c-'a');
                    cout << p.first+a << " " << p.second+a << '\n';
                }
            break;
            case 3:
                cin >> a >> b;
                if( b < a ){
                    swap(a,b);
                }
                reverse(tree, a, b);
            break;
            case 4:
                cin >> a >> c;
                insert(tree, a, c-'a');
                l++;
            break;
        }
    }

    str = "";
    put_print(tree);
    cout << str << '\n';

    return 0;
}
