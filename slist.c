#include "slist.h"

Snode * SLnewNode(int ins);

Snode * SLnewNode(int ins){
	Snode * newNode = malloc(sizeof(Snode));
	newNode->data = ins;
	newNode->next = NULL;
	return newNode;
}

Slist * SLnew(){
	Slist * slist = malloc(sizeof(Slist));
	list->head = NULL;
	return slist;
}

void SLaddFirst(Slist * slist, int ins){
	if(slist->head == NULL){
		slist->head = SLnewNode(ins);
	}
	else{
		Snode * curhead = slist->head;
		slist->head = SLnewNode(ins);
		slist->head->next = curhead;
	};
}

void SLaddLast(Slist * slist, int ins){
	Snode * curNode = slist->head;
	if(curNode == NULL){
		slist->head = SLnewNode(ins);	
	}
	else{
		while(curNode->next != NULL){
			curNode = curNode->next;
		};
		curNode->next = SLnewNode(ins);
	};
}

void SLaddAfterIdx(Slist * slist, int ins, int idx){
	Snode * curNode = slist->head;
	//if idx < 0, add at beginning
	if(idx < 0){
		SLaddFirst(slist, ins);
	}
	else if(curNode == NULL){
		//if list is empty, just stick it at the head
		slist->head = SLnewNode(ins);
	}
	else{
		//if not, traverse until we hit the correct idx
		//if idx does not exist (too big), add at end
		int counter = 0;
		while(counter < idx && curNode->next != NULL){
			curNode = curNode->next;
			counter++;
		};
		Snode * curNext = curNode->next;
		curNode->next = SLnewNode(ins);
		curNode->next->next = curNext;
	};

}


void SLaddBeforeIdx(Slist * slist, int ins, int idx){
	Snode * curNode = slist->head;
	//if idx < 0, add at beginning
	if(idx < 0){
		SLaddFirst(slist, ins);
	}
	else if(curNode == NULL){
		//if list is empty, just stick it at the head
		slist->head = SLnewNode(ins);
	}
	else{
		//if not, traverse until we hit the correct idx
		//if idx does not exist (too big), add at end
		int counter = 0;
		Snode * prevNode = NULL;
		while(counter < idx && curNode->next != NULL){
			prevNode = curNode;
			curNode = curNode->next;
			counter++;
		};
		if(counter != idx){
			//reached the end without hitting idx
			//so add at the end
			SLaddLast(slist, ins);
		}
		else if(prevNode == NULL){
			//we're at the head, just add to the head
			SLaddFirst(slist, ins);
		}
		else{
			//else normal operating procedures
			prevNode->next = SLnewNode(ins);
			prevNode->next->next = curNode;
		};
	};

}

void SLdeleteIdx(Slist * list, int idx){
	Snode * curNode = list->head;
	if(curNode != NULL && idx >= 0){
		Node * prevNode = NULL;
		int counter = 0;
		while(counter < idx && curNode->next != NULL){
			prevNode = curNode;
			curNode = curNode->next;
			counter++;
		};
		if(counter==idx){
			//if we actually hit idx, else ignore
			if(prevNode != NULL){
				prevNode->next = curNode->next;
			};
			free(curNode);
		};
	};
}

void SLprintIdx(Slist * slist, int idx){
	Snode * curNode = slist->head;
	int counter = 0;
	if(curNode != NULL){
		int counter = 0;
		while(curNode->next != NULL && counter < idx){
			curNode = curNode->next;
			counter++;
		};
		if(counter==idx){
			printf("%f\n", curNode->data);
		};
	};
}

void SLdumpList(Slist * slist){
	Snode * curNode = slist->head;
	while(curNode != NULL){
		printf("%f ", curNode->data);
		curNode = curNode->next;
	};
	printf("\n");
}

void SLreverse(Slist * slist){
	Snode * curNode = slist->head;
	if(curNode != NULL){
		Snode * prevNode = NULL;
		while(curNode != NULL){
			Snode * nextNode = curNode->next;
			if(nextNode != NULL){
				curNode->next = prevNode;
			};
			prevNode = curNode;
			curNode = nextNode;	
		};
		slist->head = prevNode;
	};
}

void SLemptyList(Slist * slist){
	Snode * curNode = slist->head;
	while(curNode != NULL){
		Snode * nextNode = curNode->next;
		free(curNode);
		curNode = nextNode;
	};
	slist->head = NULL;
}

void SLdeleteList(Slist * slist)
	SLemptyList(slist);
	free(slist);
}
