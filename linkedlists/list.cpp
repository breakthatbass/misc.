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
		// push: add element to front of list
        void push(int data) 
		{
            Node *node = new Node();
            
			node->m_data = data;
            node->m_next = this->head;
            this->head = node;
            this->len++;
        }

		// append: add element to end of list
		void append(int data) 
		{

			Node *node = new Node();
			node->m_data = data;

			if (this->head == NULL) {
				// if list is empty, made node head of list
				this->head = node;
			} else {
				Node *tmp = this->head;
				while (tmp->m_next != NULL) {
					tmp = tmp->m_next;
				}
				tmp->m_next = node;
			}
		}


		// reverse: rearrange pointers to reverse list
		void reverse() 
		{
			Node *prev = NULL;
			Node *current = this->head;
			Node *next = NULL;

			while (current != NULL) {
				// store next
				next = current->m_next;
				// reverse current node's pointer
				current->m_next = prev;
				// move pointers one position ahead
				prev = current;
				current = next;
			}
			this->head = prev;
		}


		// insert_after: insert new node after certain position in list
		void insert_after(int data, int insert_after)
		{

			Node *node = new Node();
			node->m_data = data;

			Node *tmp = this->head;

			while (tmp != NULL) {
				if (tmp->m_data == insert_after) {
					node->m_next = tmp->m_next;
					tmp->m_next = node;
				}
				tmp = tmp->m_next;
			}
		}


		// insert_before: insert new node before certain position in list
		void insert_before(int data, int insert_before)
		{
			Node *node = new Node();
			node->m_data = data;

			Node *prev = NULL;
			Node *tmp = this->head;

			// check to see if head node is one to insert before
			if (tmp->m_data == insert_before) {
				node->m_next = this->head;
				head = node;  // made this node the new head
				
			} else {
				while (tmp != NULL) {
					if (tmp->m_data == insert_before) {
						node->m_next = tmp;
						prev->m_next = node;
					}
					prev = tmp;
					tmp = tmp->m_next;
				}
			}
		}


		// exists: search for node in list
		bool exists(int data_to_find)
		{	
			Node *tmp = this->head;
			while (tmp != NULL) {
				if (tmp->m_data == data_to_find) {
					return true;
				}
				tmp = tmp->m_next;
			}
			return false;
		}


		// pop: remove and return element from end of list.
		int pop(void)
		{
			int last;
			Node *prev = NULL;
			Node *current = this->head;

			while (current != NULL) {
				if (current->m_next == NULL) {
					break;
				}
				prev = current;
				current = current->m_next;
			}
			
			last = current->m_data;
			prev->m_next = NULL;
			return last;
		}


		// delete_node: delete a node from the list if it exists.
		void delete_node(int data)
		{
			Node *prev = NULL;
			Node *current = this->head;
			Node *next = NULL;
			
			while(current) {
				// store next
				next = current->m_next;
				if (current->m_data == data) {
					prev->m_next = next;
					delete current;
				}
				prev = current;
				current = next;
			}
		}


		// print: print list with the position of each element
        void print() 
		{
            Node *head = this->head;
            int i = 1;
            while (head) {
                cout << i << ": " << head->m_data << endl;
                head = head->m_next;
                i++;
            }
        }
};


int main()
{
    LinkedList *list = new LinkedList();
   
	list->append(25);	
	list->push(3);
	list->push(2);
	list->push(1);
	list->append(7);
    
    list->print();

	cout << "reverse list" << endl;

	list->reverse();
	list->print(); 

	cout << "insert 10 after 2" << endl;
	list->insert_after(10, 2);
	list->print(); 

	cout << "insert 12 before 3" << endl;
	list->insert_before(12, 3);
	list->print();

	cout << "exists: searching for node 12 and 79" << endl;
	bool yes = list->exists(12);
	bool no = list->exists(79);
	cout << "12: " << yes << endl;
	cout << "79: " << no << endl;

	cout << "popping!" << endl;
	int last_el = list->pop();
	cout << "popped elemenet: " << last_el << endl;
	list->print();

	cout << "deleting 12" << endl;
	list->delete_node(12);
	list->print();

	delete list;

	return 0;
}

