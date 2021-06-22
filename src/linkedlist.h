#include <iostream>

template<typename tNodeType>
struct Node {
	tNodeType value;
	Node* next;
};


template <typename tNodeType>
class List {
public:
	List() {
		m_head = nullptr;
		m_tail = nullptr;
	}

	void Add(const tNodeType& in_value) {
		Node<tNodeType>* node = new Node<tNodeType>;
		node->next = nullptr;
		node->value = in_value;

		if (!m_head) {
			m_head = node;
			m_tail = node;
			return;
		}

		m_tail->next = node;
		m_tail = node;
	}
	void Print() {
		Node<tNodeType>* current = m_head;
		while (current) {
			std::cout << current->value << std::endl;
			current = current->next;
		}
	}

private:
	Node<tNodeType>* m_head;
	Node<tNodeType>* m_tail;
};