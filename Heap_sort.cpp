#include <iostream>
#include <vector>
using namespace std;

class Node { //Node Ŭ���� ����
	int value;
	Node *Parents;
	Node *LChild;
	Node *RChild;
	Node *Next;
	Node *Before;

public:
	void set_value(int num) {
		this->value = num;
	}
	
	void set_Parents(Node *node) {
		this->Parents = node;
	}

	void set_LChild(Node *node) {
		this->LChild = node;
	}

	void set_RChild(Node *node) {
		this->RChild = node;
	}

	void set_Next(Node *node) {
		this->Next = node;
	}

	void set_Before(Node *node) {
		this->Before = node;
	}

	int get_value() {
		return this->value;
	}

	Node * get_Parents() {
		return this->Parents;
	}

	Node * get_LChild() {
		return this->LChild;
	}

	Node * get_RChild() {
		return this->RChild;
	}

	Node * get_Next() {
		return this->Next;
	}

	Node * get_Before() {
		return this->Before;
	}
};

class Heap_tree { //Ʈ�� Ŭ���� ����
	Node *root;
	Node *Pnode;
	Node *LastNode;
	int NodeNum;

public:
	Heap_tree(vector<int> arr) { //�����ڷ� �Էµ� ���ͷ� Ʈ�� ����
		this->NodeNum = 0;
		for (auto i : arr) {
			if (this->NodeNum == 0) { //ù��° ��� ������
				Node *inode = new Node;
				inode->set_value(i);
				inode->set_LChild(NULL);
				inode->set_RChild(NULL);
				this->root = inode;
				this->Pnode = inode;
				this->LastNode = inode;
			}
			else insert_heap(i); //�ι�° ��� ���� ������Ʈ
			this->NodeNum++;
			if (this->NodeNum != 1 && this->NodeNum % 2) { // ���ο� ����� �θ��� ����
				this->Pnode = this->Pnode->get_Next();
			}
		//this->print(); // ���� Ʈ�� ���� Ȯ��
		}
	}

	void insert_heap(int num) { //������ Ʈ�� ������Ʈ
		Node *temp;
		Node *inode = new Node; //���ο� ������ ��� ���� �� ����
		inode->set_value(num);
		inode->set_LChild(NULL);
		inode->set_RChild(NULL);
		inode->set_Before(this->LastNode);
		this->LastNode->set_Next(inode);
		inode->set_Parents(this->Pnode);
		if (this->NodeNum % 2) this->Pnode->set_LChild(inode);
		else this->Pnode->set_RChild(inode);
		this->LastNode = inode;
		temp = inode;
		while (temp != this->root) { //��������忡�� ��ȯ�� ���������� ��ȯ
			if (temp->get_value() < temp->get_Parents()->get_value()) {
				int tempInt = temp->get_value();
				temp->set_value(temp->get_Parents()->get_value());
				temp->get_Parents()->set_value(tempInt);
			}
			else break;
			temp = temp->get_Parents();
		}
	}

	void update() { //���Ϳ� ��ȯ�ϸ� Ʈ�� ������Ʈ
		this->root->set_value(this->LastNode->get_value());
		Node *temp = this->LastNode;
		if (this->LastNode == this->root) { //��尡 �ϳ� ������ ���
			//delete temp;
			this->NodeNum--;
			return;
		}
		this->LastNode = this->LastNode->get_Before();
		if (temp->get_Parents()->get_LChild() == temp) temp->get_Parents()->set_LChild(NULL);
		if (temp->get_Parents()->get_RChild() == temp) temp->get_Parents()->set_RChild(NULL);
		//delete temp;
		this->NodeNum--;
		temp = this->root;
		while (temp->get_LChild() != NULL) { // ������ ��带 ��Ʈ�� ���� �� Ʈ�� ������Ʈ
			if (temp->get_RChild() != NULL && temp->get_LChild()->get_value() > temp->get_RChild()->get_value() && temp->get_value() > temp->get_RChild()->get_value()) {
				int tempInt = temp->get_value();
				temp->set_value(temp->get_RChild()->get_value());
				temp->get_RChild()->set_value(tempInt);
				temp = temp->get_RChild();
			}
			else if (temp->get_value() > temp->get_LChild()->get_value()) {
				int tempInt = temp->get_value();
				temp->set_value(temp->get_LChild()->get_value());
				temp->get_LChild()->set_value(tempInt);
				temp = temp->get_LChild();
			}
			else break;
		}
	}

	vector<int> sort() {
		vector<int> sorted_vector;
		while (this->NodeNum) {
			sorted_vector.push_back(this->root->get_value());
			update();
		}
		return sorted_vector;
	}

	void print() { //Ʈ�� ���� Ȯ�� �Լ�
		Node *node;
		node = root;
		while (node != this->LastNode) {
			cout << node->get_value() << " ";
			node = node->get_Next();
		}
		cout << node->get_value() << endl;
	}
};

void Heap_sort(vector<int> &arr) {
	Heap_tree *ht = new Heap_tree(arr);
	arr = ht->sort();
	//delete ht;
}