#include<bits/stdc++.h>
using namespace std;
#define MAXSIZE 100
#define LIST_INIT_SIZE 100	//??????? 
#define LISTINCREMENT 10	//?????? 
#define OK true
#define ERROR -1

typedef struct {
	int *elem;	//??????? 
	int length;	//???????
	int listsize;	//???????????? 
}SqList;	//???????��?? 


int InitList_Sq(SqList &L){
	L.elem = new int[LIST_INIT_SIZE];
	if(!L.elem)return OVERFLOW;//????????
	L.length = 0;
	L.listsize = LIST_INIT_SIZE;//????????? 
	int *p=L.elem;
	for(int i=1;i<=10;++i){
		*p=rand()%10;
		p+=1;
		L.length+=1;
	}
	return OK; 
}

int ListInsert_Sq(SqList &L,int i,int e){
	//?????? ????????????��??????��???e
	if(i<1||i>=L.listsize)return ERROR;
	if(L.length>=L.listsize)//?��????????????
	{
		int *newbase = (int *)realloc(L.elem,(L.listsize+LISTINCREMENT)*sizeof(int));
		if(!newbase)return OVERFLOW;
		L.elem=newbase;
		L.listsize+=LISTINCREMENT;
	} 
	int *q=&(L.elem[i-1]);
	for(int *p=&(L.elem[L.length-1]);p>=q;--p)
		*(p+1)=*p;
	*q=e;	
	++L.length;
	return OK;
}

int ListDelete_Sq(SqList &L,int i,int &e){
	//??????????????????????e??????
	if(i<1||i>L.length)return ERROR;
	int *p=&(L.elem[i-1]);	//p????????????
	e=*p;
	int *q=L.elem+L.length-1;
	for(++p;p<=q;++p)
		*(p-1)=*p;
	L.length--;
	return OK; 
	
}

int MergeList_Sq(SqList La,SqList Lb,SqList &Lc){
	int *pa,*pb,*pc;
	pa=La.elem;pb=Lb.elem;
	Lc.listsize=Lc.length=La.length+Lb.length;
	pc = Lc.elem = (int*)malloc(Lc.listsize*sizeof(int));
	if(!Lc.elem)return OVERFLOW;
	int *pa_last=La.elem+La.length-1;
	int *pb_last=Lb.elem+Lb.length-1;
	while(pa<=pa_last&&pb<=pb_last){
		//?��
		if(*pa<=*pb)
			*pc++=*pa++;
		else
			*pc++=*pb++;	 
	}
	while(pa<=pa_last)*pc++=*pa++;
	while(pb<=pb_last)*pc++=*pb++;
	
}

int main(){
	SqList list;
	cout<<InitList_Sq(list)<<endl;
	cout<<"?????????? "<<list.length<<"\n"<<"?????��????: "<<list.listsize<<endl;
	cout<<"????????? "<<ListInsert_Sq(list,4,5)<<endl;
	int *p=list.elem;
	cout<<"??????? ";
	for(int i=0;i<list.length;++i){
		cout<<*p<<" ";
		p+=1;
	}
	p=list.elem;
	int e=0;
	cout<<"\n"<<"???????????<<ListDelete_Sq(list,5,e)<<endl;
	cout<<"??????? ";
	for(int i=0;i<list.length;++i){
		cout<<*p<<" ";
		p+=1;
	}
	
	cout<<"\n"<<"????????????"<<endl;
	SqList lista,listb;
	InitList_Sq(lista);
	InitList_Sq(listb);
	SqList listc;
	MergeList_Sq(lista,listb,listc);
	cout<<"??????? ";
	p=listc.elem;
	for(int i=0;i<listc.length;++i){
		cout<<*p<<" ";
		p+=1;
	}
	
	
	return 0;
}
