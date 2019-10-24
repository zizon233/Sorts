#pragma once
#ifndef Sorts_H
#define Sorts_H
#include <vector>
using namespace std;

class Node { //Node 클래스 선언
	int value;
	Node *Parents;
	Node *LChild;
	Node *RChild;
	Node *Next;
	Node *Before;

public:
	void set_value(int num);

	void set_Parents(Node *node);

	void set_LChild(Node *node);

	void set_RChild(Node *node);

	void set_Next(Node *node);

	void set_Before(Node *node);

	int get_value();

	Node * get_Parents();

	Node * get_LChild();

	Node * get_RChild();

	Node * get_Next();

	Node * get_Before();
};

class Heap_tree { //트리 클래스 선언
	Node *root;
	Node *Pnode;
	Node *LastNode;
	int NodeNum;

public:
	Heap_tree(vector<int> arr);

	void insert_heap(int num);

	void update();

	vector<int> sort();

	void print();
};

void Heap_sort(vector<int> &arr);

void Quick_sort(vector<int> &arr, int sidx, int eidx);

void bubble_sort(vector<int> arr);

#endif