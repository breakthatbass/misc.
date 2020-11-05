#include <iostream>
using namespace std;

class Node {
    public:
        int m_data;
        Node *m_next;
};

class LinkedList {
    public:
        int len;
        Node *head;

        // methods
        void push(int data) {
            Node *node = new Node();
            node->m_data = data;
            node->m_next = this->head;
            this->head = node;
            this->len++;
        }


		void append(int data) {
			Node *node = new Node();
			node->m_data = data;

			if (this->head == NULL) {
				node->m_next = head;
				head = node;
			} else {
				Node *tmp = head;
				while (tmp->m_next != NULL) {
					tmp = tmp->m_next;
				}
				tmp->m_next = node;
			}
		}


        void print() {
            Node *head = this->head;
            int i = 1;
            while (head) {
                std::cout << i << ": " << head->m_data << std::endl;
                head = head->m_next;
                i++;
            }
        }

};


int main()
{
    LinkedList *list = new LinkedList();
    
	list->push(3);
	list->push(2);
	list->push(1);

	list->append(7);
    
    list->print();

	return 0;
}

