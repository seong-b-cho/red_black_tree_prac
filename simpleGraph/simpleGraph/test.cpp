#include "simpleGraph.h"


int main() {
	SimpleGraph testGraph;
	testGraph.initGraph();
	bool testResult = true;
	for (int i = 0; i < 5; i++) {
		cout << "�׷����� ��� " << i << "���� �õ�" << endl;
		if (testResult &= testGraph.insertNode(i)) {
			cout << "����" << endl;
		}
		else {
			cout << "����" << endl;
		}
	}
	cout << testGraph;

		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				cout << "��� " << i << "��" << j << "�� ����õ�" << endl;
				if (testGraph.insertEdge(i,j)) {
					cout << "����" << endl;
				}
				else {
					cout << "����" << endl;
				}
			}			
		}
		cout << testGraph;
		/*
		for (int i = 0; i < 2; i++) {
			for (int j = 1; j < 4; j++) {
				cout << "��� " << i << "��" << j << "�� ���� ���� �õ�" << endl;
				if (testGraph.deleteEdge(i, j)) {
					cout << "����" << endl;
				}
				else {
					cout << "����" << endl;
				}
				cout << testGraph;
			}			
		}*/

	for (int i = 0; i < 2; i++) {
		cout << "��� " << i << "���� �õ�" << endl;
		testGraph.deleteNode(i);
		cout << testGraph;
	}
}