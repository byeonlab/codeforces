#include<stdio.h>
#include<stdlib.h>

typedef struct LIST{
	int size;
	struct node *current;
	struct node *head;
	struct node *tail;
}LINKED_LIST;
typedef struct node{
	int val;
	int count;
	struct node *prev;
	struct node *next;
}NODE;

int create(LINKED_LIST *list, int val){
	NODE *newNode = (NODE * )malloc(sizeof(NODE));
	newNode->val = val;
	newNode->count = 1;
	newNode->next = NULL;
	newNode->prev = NULL; 
	if(list->head == NULL && list->tail == NULL){
		list->head = list->tail = newNode;
	}
	else{
		list->tail->next = newNode;
		list->tail = newNode;
	}
	list->size += 1;
	return 0;
}

//////////////////////////////////////////////////////////////////////

int static compare (const void* first, const void* second){
	return (*(int*)first > *(int*)second) - (*(int*)first < *(int*)second);
}
int l_cnt(int *n){
	*n = *n + 1;
	return *n;
}
int r_cnt(int *n){
	*n = *n - 1;
	return *n;
}
int count_edge(int (*f)(int*), int *arr, int pos){
	int ret = 1;
	while(arr[pos] == arr[f(&pos)]){
		ret += 1;
	}
	return ret;
}
int count_distinct(int *arr, int l_idx, int r_idx){
	int cnt = 1;
	for(int i = l_idx; i < r_idx ; i++) cnt += (arr[i] != arr[i + 1]);
	return cnt;
}
int log2N(int N){
	//if(N == 1) return 0;
	int ret = 0;
	while(N){
		ret ++;
		N >>= 1;
	}
	return ret - 1;
}

int main(){
	int n, I, *arr, l_idx, r_idx;
	int test[400000];
	printf("%d\n", test[399999]);

	//scanf("%d %d", &n, &I);
	//LINKED_LIST *list = (LINKED_LIST *)malloc(sizeof(LINKED_LIST));
	//list->size = 0;
	//list->current = NULL;
	//list->head = NULL;
	//list->tail = NULL;
	//list->current = list->head;
	//NODE *cur = list->current;

	//arr = malloc(sizeof(int) * n);


	l_idx = 0;
	r_idx = n - 1;

#if 0
	for(int i = 0; i < n; i++){
		int val;
		scanf("%d", &val);
		while(1){
			if(cur->val < val) {
				cur = cur->next;
				continue;
			}
			if(cur->val == val){
				cur->count += 1;
				break;
			}
			create

		}
	}
	for(int i = 0; i < n; i++){
		int val;
	}
#endif

//	qsort(arr, n, sizeof(int), compare);
//	while(log2N(count_distinct(arr, l_idx, r_idx) + 1) * n > I * 8){
//
//		int l_gap = count_edge(l_cnt, arr, l_idx), r_gap = count_edge(r_cnt, arr, r_idx);
//		if(l_gap > r_gap) r_idx -= r_gap;
//		else l_idx += l_gap;
//	}
//	printf("%d", n - r_idx - 1 + l_idx);
	
	return 0;
}
