#include "include.h"

typedef struct node_t {
	int intValue;

	struct node_t* nodeLeft;
	struct node_t* nodeRight;
} node;

void treeCreate(node* nodeHandle) {
	// set the values of the node
    node.intValue = nodeHandle;
}

void treeDestroy(node* nodeHandle) {
	// destroy all nodes by using a postfix recursion
}

void treeAdd(node* nodeHandle, int intValue) {
	// allocate a new node and then descend iteratively through the tree in order to find the correct position
}

void treeTraverse(node* nodeHandle) {
	// traverse through all nodes and print their value by using an infix recursion
}

int treeHeight(node* nodeHandle, int intHeight) {
	// determine the height of the tree by using recursion
}

int treeLeaves(node* nodeHandle) {
	// determine the number of leaves of the tree by using recursion
}

int main() {
	numbers numbersHandle = { 0 };

	{
		readNumbers("./Data1.txt", &numbersHandle);
	}

	{
		node nodeRoot = { 0 };

		{
			treeCreate(&nodeRoot);
		}

		{
			nodeRoot.intValue = numbersHandle.intData[0];

			for (int intFor1 = 1; intFor1 < numbersHandle.intSize; intFor1 += 1) {
				treeAdd(&nodeRoot, numbersHandle.intData[intFor1]);
			}
		}

		{
			treeTraverse(&nodeRoot);

			printf("\n");
		}

		{
			printf("treeHeight: %d\n", treeHeight(&nodeRoot, 0));

			printf("treeLeaves: %d\n", treeLeaves(&nodeRoot));
		}

		{
			treeDestroy(nodeRoot.nodeLeft);

			treeDestroy(nodeRoot.nodeRight);
		}
	}

	freeNumbers(&numbersHandle);
}
