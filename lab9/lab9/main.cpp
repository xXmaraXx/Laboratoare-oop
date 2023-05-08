#include <stdio.h>
#include <iostream>
template <class K, class V>

class Map {
	struct Node {
		K key;
		V value;
		Node* next;
	};
	Node* head;
	int size;
public:
	

	Map() :head(nullptr), size(0) {}
	~Map() {
		Clear();
	}
	void Set(const K& key, const V& value) {
		Node* nod = head;
		while (nod != nullptr) {
			if (nod->key == key) {
				nod->value = value;
				return;
			}
			nod = nod->next;
		}
		Node* newNode = new Node;
		newNode->key = key;
		newNode->value = value;
		newNode->next = head;
		head = newNode;
		size++;
	}

	bool Get(const K& key, V& value) const {
		Node* nod = head;
		while (nod != nullptr) {
			if (nod->key == key) {
				value = nod->value;
				return true;
			}
			nod = nod->next;
		}
		return false;
	}

	int Count() const {
		return size;
	}

	void Clear() {
		while (head != nullptr) {
			Node* nod = head;
			head = head->next;
			delete nod;
		}
		size = 0;
	}

	bool Delete(const K& key) {
		if (head == nullptr) {
			return false;
		}
		if (head->key == key) {
			Node* nod = head;
			head = head->next;
			delete nod;
			size--;
			return true;
		}
		Node* prev = head;
		Node* curr = head->next;
		while (curr != nullptr) {
			if (curr->key == key) {
				prev->next = curr->next;
				delete curr;
				size--;
				return true;
			}
			prev = curr;
			curr = curr->next;
		}
		return false;
	}

	bool Includes(const Map<K, V>& map) const {
		Node* nod = map.head;
		while (nod != nullptr) {
			V value;
			if (!Get(nod->key, value) || value != nod->value) {
				return false;
			}
			nod = nod->next;
		}
		return true;
	}

	class Iterator {
	private:
		Node* current;
		int index;
	public:
		Iterator(Node* node, int i) :current(node), index(i) {}

		bool operator!=(const Iterator& other)const {
			return current != other.current;
		}

		void operator++() {
			current = current->next;
			index++;
		}
		auto operator *() const {
			return std::make_tuple(current->key, current->value, index);
		}
	};
	Iterator begin() const {
		return Iterator(head, 0);
	}
	Iterator end() const {
		return Iterator(nullptr, size);
	}
	V& operator[](const K& key) {

		Node* nod = head;
		while (nod != nullptr) {
			if (nod->key == key) {
				return nod->value;
			}
			nod = nod->next;
		}
		Node* newNode = new Node;
		Node* last = head;
		newNode->key = key;
		newNode->value = V();
		newNode->next = nullptr;
		if (head == nullptr) {
			head = newNode;
			return head->value;
		}
		while (last->next != nullptr) {
			last = last->next;
		}
		last->next = newNode;
		return newNode->value;
	}

};


int main()

{

    Map<int, const char*> m;

    m[10] = "C++";

    m[20] = "test";

    m[30] = "Poo";

    for (auto [key, value, index] : m) {

        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }

    m[20] = "result";

    for (auto [key, value, index] : m) {

        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }

    return 0;

}