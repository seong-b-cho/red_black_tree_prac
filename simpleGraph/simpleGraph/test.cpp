#include "simpleGraph.h"


int main() {
	SimpleGraph testGraph;
	testGraph.initGraph();
	bool testResult = true;
	for (int i = 0; i < 5; i++) {
		cout << "그래프에 노드 " << i << "삽입 시도" << endl;
		if (testResult &= testGraph.insertNode(i)) {
			cout << "성공" << endl;
		}
		else {
			cout << "실패" << endl;
		}
	}
	cout << testGraph;

		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				cout << "노드 " << i << "와" << j << "를 연결시도" << endl;
				if (testGraph.insertEdge(i,j)) {
					cout << "성공" << endl;
				}
				else {
					cout << "실패" << endl;
				}
			}			
		}
		cout << testGraph;
		/*
		for (int i = 0; i < 2; i++) {
			for (int j = 1; j < 4; j++) {
				cout << "노드 " << i << "와" << j << "의 엣지 제거 시도" << endl;
				if (testGraph.deleteEdge(i, j)) {
					cout << "성공" << endl;
				}
				else {
					cout << "실패" << endl;
				}
				cout << testGraph;
			}			
		}*/

	for (int i = 0; i < 2; i++) {
		cout << "노드 " << i << "제거 시도" << endl;
		testGraph.deleteNode(i);
		cout << testGraph;
	}
}