#include <stdio.h>

/*
 * Main operations
 * a) insert at beggining
 * b) insert at end
 * c) remove node
 * d) search elment
 */

struct Node {
	int value;
	//struct Node *next = NULL; // nao pode!
	struct Node *next;
};

struct LinkedList {
	int numberOfNodes;
	struct Node *head;
};

// pensar:
// struct LinkedList {
// 	int qtyNodes;
// 	struct Node *ptrHeadNode;
// 	struct Node *ptrCurrentNode;
// 	struct Node *ptrTailNode;
// 	};
//
// 	acho q pode acontecer inconsistencia talvez head apontar 
// 	p uma trilha de enderecos
//
// 	ptrTail pra outra e ptrCurrent pra outra...
//
// 	em teoria se organizar pra nao acontecer isso fica ok
// 	mas se o usuario realmente quiser bagaunçar ai eh com ele...

int addNodeOnBeggining(int value, struct Node workingLinkedList) {

	struct Node newNode;
	newNode.value = value;
	newNode.next = NULL;

	printf("Novo node criado.\n");
	printf("%d\n", newNode.value);
	printf("---\n");
	printf("%p<--\n", newNode.next);

	workingLinkedList.next = &newNode;
}
void printInfo(struct Node node) {

	int n = 0;

	struct Node *currentNode;
	currentNode = &node;

	if (node.next == NULL) {
		fprintf(stderr, "do not pass the tail node as argument.\n");
		return;
	}
	do {
	printf("[Node %d]:\n", n);
	printf("=============\n");
	printf("value: %d\n", currentNode->value);
	printf("& do node atual = %p\n", currentNode);
	printf("& next node = %p\n", currentNode->next);

	// sempre apontando pro head "node" nao muda
	//currentNode = node.next;
	//
	currentNode = currentNode->next;
		
	n++;
	} while (currentNode != NULL);

	printf("----------------\n\n");

}

int main(int argc, char *argv[]) {

	/*
	struct Node myLinkedList;
	
	printInfo(myLinkedList);

	addNodeOnBeggining(21, myLinkedList);
	
	
	printInfo(myLinkedList);
	*/

	struct Node head, n1, n2;
	head.value = 10;
	head.next = &n1;

	n1.value = 23;
	n1.next = &n2;

	n2.value = 39;
	n2.next = NULL;

	printf("-0-0-\n");
	printf("h : %p\n", &head);
	printf("n1: %p\n", &n1);
	printf("n2: %p\n", &n2);
	printf("1-1-\n");

	printInfo(head);

	printInfo(n1);
	
	printInfo(n2);


	struct LinkedList linkedList;
	linkedList.numberOfNodes = 0;
	// insert
	linkedList.numberOfNodes++;
	linkedList.head = &head;

	// ++
	linkedList.numberOfNodes++;
	linkedList.head->next = &n1;

	printf("%d\n", linkedList.numberOfNodes);

	printf("%p\n", linkedList.head);
	printf("%d\n", linkedList.head->value);

	printf("%p\n", linkedList.head->next);
	printf("%d\n", linkedList.head->next->value);


	return 0;

}
