#include<stdio.h>
typedef int DATA;
typedef struct _node{
	int key;
	struct _node *left,*right,*p;
	DATA data;
}node;
typedef struct _T{
	node *root;
}BST;
BST T;

void bt_insert(BST *T,node *v){
	node *y=NULL;
	node *x=T->root;
	while(x!=NULL){
		y=x;
		if(v->key<x->key){
			x=x->left;
		}
		else{
			x=x->right;
		}
	}
	if(y==NULL){
		T->root=v;
		return ;
	}
	if(v->key < y->key){
		y->left=v;
	}
	else{
		y->right=v;
	}
	v->p=y;
}
void setp(node *p,int key){
	p->key=key;
	p->left=NULL;
	p->right=NULL;
}
void touch(node *x){
	if(x!=NULL){
		touch(x->left);
		printf("%d\n",x->key);
		touch(x->right);
	}
	return;
}
void walk(BST T){
	node *x=T.root;
	touch(x);
	return;
}



node *tree_search(node *x,int k){
	if(x==NULL || x->key==k){
		return x;
	}
	if(k<x->key){
		return tree_search(x->left,k);
	}else{
		return tree_search(x->right,k);
	}
} 
node *TREE_SEARCH(BST T,int k){
	return tree_search(T.root,k);
}

node *iterative_tree_search(node *x,int k){
	while(x!=NULL && x->key!=k){
		if(k<x->key){
			x=x->left;
		}
		else
		{
			x=x->right;
		}
	}
	return x;
}
node *ITERATIVE_TREE_SEARCH(BST T,int k){
	iterative_tree_search(T.root,k);
}
node *minimum(node *x){
	while(x->left!=NULL){
		x=x->left;
	}
	return x;
}
node *MINIMUM(BST T){
	return minimum(T.root);
}

node *miximum(node *x){
	while(x->right!=NULL){
		x=x->right;
	}
	return x;
}
node *MIXIMUM(BST T){
	return miximum(T.root);
}

node *TREE_SUCCESSOR(BST T,int k){
	node *x=TREE_SEARCH(T,k);
	//this x maybe NIL
	if(x==NULL){
		return x;
	}
	node *y;
	if(x->right!=NULL){
		return minimum(x->right);
	}
	y=x->p;
	while(y!=NULL && x==y->right){
		x=y;
		y=y->p;
	}
	return y;
}
node *TREE_PREDECESSOR(BST T,int k){
	node *x=TREE_SEARCH(T,k);
	if(x==NULL) return x;
	node *y;
	if(x->left!=NULL){
		return miximum(x->left);
	}
	y=x->p;
	while(y!=NULL && x==y->left){
		x=y;
		y=y->p;
	}
	return y;
}
void TRANSPLANT(BST *T,node *u,node *v){
	if(u->p==NULL){
		T->root=v;
	}
	else if(u->p->left==u){
		u->p->left=v;
	}
	else{
		u->p->right=v;
	}
	if(v!=NULL){
		v->p=u->p;
	}
}


void tree_delete(BST *T,node *z){
	if(z->left==NULL){
		TRANSPLANT(T,z,z->left);
	}
	else if(z->right==NULL){
		TRANSPLANT(T,z,z->right);
	}
	else{
		node *y=minimum(z->right);
		if(y!=z->right){
			TRANSPLANT(T,y,y->right);
			y->right=z->right;
			z->right->p=y;
		}
		TRANSPLANT(T,z,y);
		y->left=z->left;
		z->left->p=y;
	}
}
void TREE_DELETE(BST *T,int k){
	node *x=TREE_SEARCH(*T,k);
	if(x==NULL){
		return ;
	}
	return tree_delete(T,x);
}

int main(){
	node p1,p2,p3,p4,p5,p6,p7,p8;
	node *ret;
	T.root=NULL;
	setp(&p1,12);
	bt_insert(&T,&p1);

	setp(&p2,5);
	bt_insert(&T,&p2);
	setp(&p3,2);
	bt_insert(&T,&p3);
	setp(&p4,9);
	bt_insert(&T,&p4);
	
	setp(&p5,18);
	bt_insert(&T,&p5);
	
	setp(&p6,15);
	bt_insert(&T,&p6);
	
	setp(&p7,17);
	bt_insert(&T,&p7);
	
	setp(&p8,19);
	bt_insert(&T,&p8);
	//insert end
	printf("%d\n",T.root);
	walk(T);
	
	ret=TREE_SEARCH(T, 9);
	printf("%d\n",ret->key);
	
	ret=TREE_SEARCH(T, 20);
	printf("%d\n",ret);
	
	ret=ITERATIVE_TREE_SEARCH(T,9);
	printf("%d\n",ret->key);
	
	ret=MINIMUM(T);
	printf("%d\n",ret->key);
	
	ret=MIXIMUM(T);
	printf("%d\n",ret->key);
	
	ret=TREE_SUCCESSOR(T,18);
	printf("%d\n",ret->key);
	
	
	ret=TREE_PREDECESSOR(T,17);
	printf("%d\n",ret->key);
	
	TREE_DELETE(&T,20);
	TREE_DELETE(&T,2);
	
	printf("------------------------------\n");
	
	walk(T);
	
	
	return 0;
}
