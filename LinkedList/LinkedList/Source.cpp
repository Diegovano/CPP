#include <iostream>

struct Node {
	int id, content;
	Node* ptrToNext;
};

class LList {
public:
	Node* ptrNode1;
	Node* nodePtr;
	Node* oldNodePtr;
	int numNodes = 0;
	void M_Append(int toApp) {
		nodePtr = new Node();
		if (numNodes == 0) {
			ptrNode1 = nodePtr;
		}
		nodePtr->id = numNodes + 1;
		nodePtr->content = toApp;
		if (numNodes > 0) {
			oldNodePtr->ptrToNext = nodePtr;
		}
		oldNodePtr = nodePtr;
		numNodes++;
	}
	Node* M_Search(int searchdId) {
		Node* curNode = ptrNode1;
		for (int iter = 0; iter < numNodes; iter++) {
			if (curNode->id == searchdId) {
				return curNode;
			}
			else curNode = curNode->ptrToNext;
		}
	}
	void M_Del(int delAt) { //ids are offset by 1
		M_Search(delAt+1)->ptrToNext = M_Search(delAt + 2);
		for (int iter = 0; iter < (numNodes - delAt + 1); iter++) {
			Node* tempPtr = M_Search(delAt)->ptrToNext;
			tempPtr->id++;
		}
		numNodes--;
	}
	void M_Ins(int insAt, int toIns) {
		Node* newPtr = new Node();
		newPtr->ptrToNext = M_Search(insAt)->ptrToNext;
		M_Search(insAt)->ptrToNext = newPtr;
		newPtr->id = insAt + 1;
		newPtr->content = toIns;
		Node* tempPtr = newPtr->ptrToNext;
		for (int iter = 0; iter < (numNodes - insAt); iter++) {
			tempPtr->id += 1;
			tempPtr = tempPtr->ptrToNext;
		}
		delete tempPtr, newPtr;
		numNodes++;
	}
	void M_Replace(int repId, int repWith) {
		M_Search(repId)->content = repWith;
	}
	void M_PrintNode(int printAt) {
		Node* curNode = ptrNode1;
		for (int iter = 0; iter < numNodes; iter++) {
			if (curNode->id == printAt) {
				std::cout << curNode->content << std::endl;
				break;
			}
			else curNode = curNode->ptrToNext;
		}
	}
};

int main() {
	LList list1;
	for (int i = 0; i < 10; i++) {
		list1.M_Append(i);
	}
	list1.M_Ins(4, 0);
	list1.M_Del(3);
	for (int i = 0; i < 11; i++) {
		list1.M_PrintNode(i + 1);
	}
	system("pause");
}