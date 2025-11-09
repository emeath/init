#include <stdio.h>

struct Node {
	int value;
	//struct Node *next = NULL; // nao pode!
	struct Node *next;
};

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


	for(int i = 0; i < 3; ++i) {

	printf("Node %d:\n", n);
	printf("value: %d\n", currentNode->value);
	printf("& do node atual = %p\n", currentNode);
	printf("& next node = %p\n", currentNode->next);

	// sempre apontando pro head "node" nao muda
	//currentNode = node.next;
	//
	currentNode = currentNode->next;
		
	n++;
	}

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
	printf("h :  %p\n", &head);
	printf("n1: %p\n", &n1);
	printf("n2: %p\n", &n2);
	printf("1-1-\n");

	printInfo(head);
	
	return 0;

}
