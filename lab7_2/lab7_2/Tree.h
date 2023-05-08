#pragma once

#include <iostream>

template <class T>

class Tree {

public:

	Tree(const T& v);
	void add_node(Tree<T>* node);
	Tree* get_node(Tree<T>* parent);
	void delete_node();
	Tree* find(bool (*comp)(const T&, const T&), const T& v);
	void insert(Tree<T>* node, int index);
	void sort(bool (*comp)(const T&, const T&) = nullptr);
	int count();
	void dfs() const;
	void bfs() const;


	T value;
	Tree<T>* first_child;
	Tree<T>* next_sibling;

};

template<class T>
inline Tree<T>::Tree(const T& v) : value(v), first_child(nullptr), next_sibling(nullptr)
{
}

template<class T>
inline void Tree<T>::add_node(Tree<T>* node)
{
	if (!first_child) {
		first_child = node;
	}
	else {
		Tree* current = first_child;
		while (current->next_sibling) {
			current = current->next_sibling;
		}
		current->next_sibling = node;
	}

}

template<class T>
inline Tree<T>* Tree<T>::get_node(Tree<T>* parent)
{
	if (!parent) {
		return this;
	}
	Tree* current = parent->first_child;
	while (current) {
		if (current == this) {
			return current;
		}
		current = current->next_sibling;
	}
	return nullptr;
}

template<class T>
inline void Tree<T>::delete_node()
{
	Tree<T>* current = first_child;
	while (current) {
		Tree<T>* next = current->next_sibling;
		current->delete_node();
		current = next;
	}
	delete this;
}

template<class T>
inline Tree<T>* Tree<T>::find(bool(*comp)(const T&, const T&), const T& v)
{
	if (comp(value, v)) {
		return this;
	}
	Tree<T>* current = first_child;
	while (current) {
		Tree<T>* found = current->find(comp, v);
		if (found) {
			return found;
		}
		current = current->next_sibling;
	}
	return nullptr;
}

template<class T>
inline void Tree<T>::insert(Tree<T>* node, int index)
{
	if (index == 0) {
		node->next_sibling = first_child;
		first_child = node;
	}
	else {
		Tree<T>* current = first_child;
		for (int i = 0; i < index - 1 && current; i++) {
			current = current->next_sibling;
		}
		if (current) {
			node->next_sibling = current->next_sibling;
			current->next_sibling = node;
		}
	}
}

template<class T>
inline void Tree<T>::sort(bool (*comp)(const T&, const T&)) {

	if (!first_child) {
		return;
	}
	Tree<T>* current = first_child;
	while (current) {
		current->sort(comp);
		current = current->next_sibling;
	}
	if (comp) {
		for (int i = 0; i < count() - 1; i++) {
			current = first_child;
			for (int j = 0; j < count() - i - 1; j++) {
				if (comp(current->value, current->next_sibling->value)) {
					T aux = current->value;
					current->value = current->next_sibling->value;
					current->next_sibling->value = aux;
				}
				current = current->next_sibling;
			}
		}
	}
	else {
		for (int i = 0; i < count() - 1; i++) {
			current = first_child;
			for (int j = 0; j < count() - i - 1; j++) {
				if (current->value > current->next_sibling->value) {
					T aux = current->value;
					current->value = current->next_sibling->value;
					current->next_sibling->value = aux;
				}
				current = current->next_sibling;
			}
		}
	}
}


template<class T>
inline int Tree<T>::count()
{
	int count = 0;
	Tree<T>* current = first_child;
	while (current) {
		count++;
		count += current->count();
		current = current->next_sibling;
	}
	return count;
}


template<class T>
void Tree<T>::dfs() const
{
	const Tree<T>* stack[1000]{};
	int top = 0;
	stack[top++] = this;
	while (top > 0) {
		const Tree<T>* current = stack[--top];
		std::cout << current->value << " ";
		const Tree<T>* child = current->first_child;
		while (child != nullptr) {
			stack[top++] = child;
			child = child->next_sibling;
		}
	}
}

template<class T>
void Tree<T>::bfs() const
{
	const Tree<T>* queue[1000]{};
	int front = 0;
	int back = 0;
	queue[back++] = this;
	while (front < back) {
		const Tree<T>* current = queue[front++];
		std::cout << current->value << " ";
		const Tree<T>* child = current->first_child;
		while ( child!= nullptr) {
			queue[back++] = child;
			child = child->next_sibling;
		}
	}
}