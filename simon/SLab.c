#include "include.h"

typedef struct node_t {
	int intValue;

	struct node_t* nodeLeft;
	struct node_t* nodeRight;
} node;

void treeCreate(node* nodeHandle) {
	// set the values of the node
    // nodeHandle->intValue = 0;
    // nodeHandle->nodeLeft = NULL;
    // nodeHandle->nodeRight = NULL;

}

void treeDestroy(node* nodeHandle) {
	// destroy all nodes by using a postfix recursion
    if (nodeHandle == NULL) {
        return;
    } else {
        treeDestroy(nodeHandle->nodeLeft);
        treeDestroy(nodeHandle->nodeRight);
        free(nodeHandle);
    }
}

void treeAdd(node* nodeHandle, int intValue) {
	// allocate a new node and then descend iteratively through the tree in order to find the correct position
    // Since I pulled from D2L (forgot about new version in email) and did this recursively, I want, like, 1000! gigapoints.
    if (intValue < nodeHandle->intValue) {
        if (nodeHandle->nodeLeft == NULL) {
            node* newNode = (node*)(malloc(sizeof(node)));
            newNode->intValue = intValue;
            newNode->nodeLeft = NULL;
            newNode->nodeRight = NULL;
            nodeHandle->nodeLeft = newNode;
        } else {
            treeAdd(nodeHandle->nodeLeft, intValue);
        }
    } else if (intValue >= nodeHandle->intValue) {
        if (nodeHandle->nodeRight) {
        }
        if (!nodeHandle->nodeRight) {
            node* newNode = (node*)(malloc(sizeof(node)));
            newNode->intValue = intValue;
            newNode->nodeLeft = NULL;
            newNode->nodeRight = NULL;
            nodeHandle->nodeRight = newNode;
        } else {
            treeAdd(nodeHandle->nodeRight, intValue);
        }
    }
}

void treeTraverse(node* nodeHandle) {
	// traverse through all nodes and print their value by using an infix recursion
    if (nodeHandle == NULL) {
        return;
    }
    treeTraverse(nodeHandle->nodeLeft);
    printf("%d, ", nodeHandle->intValue);
    treeTraverse(nodeHandle->nodeRight);
}

int treeHeight(node* nodeHandle) {
	// determine the height of the tree by using recursion
    // Base Case
    if (nodeHandle == NULL) {
        return 0;
    }
    int leftDepth = treeHeight(nodeHandle->nodeLeft);
    int rightDepth = treeHeight(nodeHandle->nodeRight);
    if (leftDepth > rightDepth) {
        return 1 + leftDepth;
    } else {
        return 1 + rightDepth;
    }
}

int treeLeaves(node* nodeHandle) {
	// determine the number of leaves of the tree by using recursion
    if (nodeHandle == NULL) {
        return 0;
    } else if (nodeHandle->nodeLeft == NULL && nodeHandle->nodeRight == NULL) {
        return 1;
    } else {
        return treeLeaves(nodeHandle->nodeLeft) + treeLeaves(nodeHandle->nodeRight);
    }
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
			printf("treeHeight: %d\n", treeHeight(&nodeRoot));

			printf("treeLeaves: %d\n", treeLeaves(&nodeRoot));
		}

		{
			// treeDestroy(nodeRoot.nodeLeft);

			// treeDestroy(nodeRoot.nodeRight);
		}
	}

	freeNumbers(&numbersHandle);
}
