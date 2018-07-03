#pragma once
#include <iostream>
#define MAX_NODE_NUM 5
#define MAX_ADJ 5
#define NOTFOUND -1

using namespace std;

class SimpleNode;
class SimpleGraph;

ostream & operator << (ostream &stream, SimpleNode &node);
ostream & operator << (ostream &stream, SimpleGraph &graph);

class SimpleNode {
public:
	void Print(ostream &stream) {
		stream << "노드" << nodeName << "의 인접노드 : ";
		for (int i = 0; i < numOfAdjs; i++) {
			stream << adjs[i] << " ";
		}
		stream << endl;
	}
private:
	SimpleNode() {
		nodeName = NOTFOUND;
		numOfAdjs = NOTFOUND;
		for (int i = 0; i < MAX_ADJ; i++) {
			adjs[i] = NOTFOUND;
		}
	}
	SimpleNode(int nodeName) {
		this->nodeName = nodeName;
		numOfAdjs = 0;
		for (int i = 0; i < MAX_ADJ; i++) {
			adjs[i] = NOTFOUND;
		}
	}
	bool AddAdj(int nodeToAdd) {
		bool isSuccess = false;
		if (searchAdjs(nodeToAdd) == NOTFOUND && numOfAdjs < MAX_ADJ) {
			adjs[numOfAdjs] = nodeToAdd;
			numOfAdjs++;
			isSuccess = true;
		}
		return isSuccess;
	}
	bool DelAdj(int nodeToDel) {
		bool isSuccess = false;
		int foundIndex = searchAdjs(nodeToDel);
		if (foundIndex != NOTFOUND) {
			adjs[foundIndex] = adjs[numOfAdjs - 1];
			isSuccess = true;
			numOfAdjs--;
		}
		return isSuccess;
	}
	int searchAdjs(int nodeToFind) {
		int index;
		for (index = 0; index < numOfAdjs; index++) {
			if (adjs[index] == nodeToFind) {
				break;
			}
		}
		if (adjs[index] != nodeToFind) {
			index = NOTFOUND;
		}
		return index;
	}
	SimpleNode& operator = (const SimpleNode& src) {
		nodeName = src.nodeName;
		numOfAdjs = src.numOfAdjs;
		for (int i = 0; i < numOfAdjs; i++) {
			adjs[i] = src.adjs[i];
		}
		return *this;
	}
	int nodeName;
	int numOfAdjs;
	int adjs[MAX_ADJ];
	friend class SimpleGraph;
};

class SimpleGraph {
public :
	SimpleGraph(){
		initGraph();
	}
	~SimpleGraph() {
		delete[MAX_NODE_NUM] nodes;
	}
	void initGraph() {
		int graphSize = 0;
		nodes = new SimpleNode[MAX_NODE_NUM];
	}
	bool isEmpty() {
		bool isSuccess = false;
		if (graphSize == 0) {
			isSuccess = true;
		}
		return isSuccess;
	}
	bool insertNode(int v) {
		bool isSuccess = false;
		if (graphSize < MAX_NODE_NUM) {
			nodes[graphSize] = SimpleNode(v);
			graphSize++;
			isSuccess = true;
		}
		return isSuccess;
	}
	bool insertEdge(int v, int u) {
		bool isSuccess = false;
		int vIndex = search(v);
		int uIndex = search(u);
		if (vIndex != NOTFOUND && uIndex != NOTFOUND && v != u) {
			isSuccess = true;
			isSuccess &= nodes[vIndex].AddAdj(u);
			isSuccess &= nodes[uIndex].AddAdj(v);
		}
		return isSuccess;
	}
	bool deleteNode(int v) {
		bool isSuccess = false;
		int vIndex = search(v);
		if (vIndex != NOTFOUND) {
			isSuccess = true;
			int* adjs = nodes[vIndex].adjs; 
			int numOfAdjs = nodes[vIndex].numOfAdjs;
			for (int i = 0; i < numOfAdjs; i++) {
				int uIndex = search(adjs[i]);
				if (uIndex != NOTFOUND) {
					isSuccess &= nodes[uIndex].DelAdj(v);
				}
			}
			if (isSuccess) {
				if (vIndex <= graphSize - 1) {
					nodes[vIndex] = nodes[graphSize - 1];
					graphSize--;
					isSuccess = true;
				}				
				else {
					isSuccess = false;
				}
			}
		}
		return isSuccess;
	}
	bool deleteEdge(int v, int u) {
		bool isSuccess = false;
		int vIndex = search(v);
		int uIndex = search(u);
		if (vIndex != NOTFOUND && uIndex != NOTFOUND) {
			isSuccess = nodes[vIndex].DelAdj(u);
			isSuccess &= nodes[uIndex].DelAdj(v);
		}
		return isSuccess;
	}
	int* adjacent(int v) {
		int vIndex = search(v);
		return nodes[vIndex].adjs;
	}
	void Print(ostream &stream) {
		for (int i = 0; i < graphSize; i++) {
			stream << nodes[i];
		}		
	}
private :
	int search(int nodeToFind) {
		int index;
		for (index = 0; index < graphSize; index++) {
			if (nodes[index].nodeName == nodeToFind) {
				break;
			}
		}
		if (nodes[index].nodeName != nodeToFind) {
			index = NOTFOUND;
		}
		return index;
	}
	SimpleNode* nodes;
	int graphSize;
};

ostream & operator << (ostream &stream, SimpleNode &node) {
	node.Print(stream);
	return stream;
}
ostream & operator << (ostream &stream, SimpleGraph &graph) {
	graph.Print(stream);
	return stream;
}