#include <iostream>
#include <vector>

using namespace std;

const int n = 10;

struct deq {
	int data[n];
	int last;
	int first;
};

class Deque 
{
private:
	deq *ourDeque;
public:
	int size;

	Deque() {
		size = 0;
        ourDeque = new deq;
		for (int i = 0; i < n; i++) {
			ourDeque->data[i] = 0;
		}
		ourDeque->last = 0;
		ourDeque->first = 0;
	}
	~Deque() {
		delete ourDeque;
	}

	int front() {
		if (size == 0) {
			cout << "deque is empy." << endl;
			return 0;
		}
		return ourDeque->first;
	}

	int back() {
		if (size == 0) {
			cout << "deque is empy" << endl;
			return 0;
		}
		return ourDeque->last;
	}

	void push_front(int x) {
		if (size == n) {
			cout << "deque is full" << endl;
			return;
		}
		if (size == 0) {
			ourDeque->last = x;
			ourDeque->first = x;
			ourDeque->data[0] = x;
			size++;
			return;
		}
		for (int i = size; i > 0; i--) {
			ourDeque->data[i] = ourDeque->data[i - 1];
		}
		ourDeque->data[0] = x;
		ourDeque->first = x;
		size++;
	}

	void push_back(int x) {
		if (size == n) {
			cout << "deque is full" << endl;
			return;
		}
		ourDeque->data[size] = x;
		ourDeque->last = x;
		if (size == 0) {
			ourDeque->first = x;
		}
		size++;
	}

	void pop_front() {
		if (size == 0) {
			cout << "deque is empy" << endl;
			return;
		}
		for (int i = 0; i < size - 1; i++) {
			ourDeque->data[i] = ourDeque->data[i + 1];
		}
		ourDeque->data[size - 1] = 0;
		ourDeque->first = ourDeque->data[0];
		size--;
	}

	void pop_back() {
		if (size == 0) {
			cout << "deque is empy" << endl;
			return;
		}
		ourDeque->data[size - 1] = 0;
		ourDeque->last = ourDeque->data[size - 2];
		size--;
	}

	void clear() {
		for (int i = 0; i < size; i++) {
			ourDeque->data[i] = 0;
		}
		ourDeque->last = 0;
		ourDeque->first = 0;
		size = 0;
	}
};

class objectPool
{
private:
	struct poolRecord
	{
		Deque* instance;
		bool in_use;
	};

	vector<poolRecord> obj;
public:
	~objectPool() {
		for (int i = 0; i < obj.size(); i++) {
			delete obj[i].instance;
		}
	}

	Deque* takeNewObject(){
		for (int i = 0; i < obj.size(); i++) {
			if (!obj[i].in_use) {
				obj[i].in_use = true;
				return obj[i].instance;
			}
		}

		poolRecord newObj;
		newObj.instance = new Deque;
		newObj.in_use = true;
		obj.push_back(newObj);
		return newObj.instance;
	}

	void returneObject(Deque* object) {
		for (int i = 0; i < obj.size(); i++) {
			if (obj[i].instance == object) {
				obj[i].in_use = false;
				break;
			}
		}
	}
};

int main() 
{
    
	system("pause");
	return 0;
}