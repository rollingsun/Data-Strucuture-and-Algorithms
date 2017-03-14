/**
 **
 ** Queue using array
 **
 **/

#include <iostream>

using namespace std;

class Queue {
  private:
    int* arr;
    int size;
    int front;
    int back;

  public:
    void add(int x) {
      arr[back] = x;
      back = (back+1)%size;
    }

    void remove() {
      front = (front+1)%size;
    }

    int top() {
      return arr[front];
    }

    int pop() {
      int result = top();
      remove();
      return result;
    }

    bool underflow() {
      return (front == back);
    }

    bool overflow() {
      return (front == (back+1)%size);
    }

    Queue(int x) {
      size = x+1;
      arr = new int[size];
      front = 0;
      back = 0;
    }
};

void create(Queue &q) {
	int x;
	cout << "Enter elements of the queue(-99 for termination): " << endl;
	while(true) {
		if(q.overflow()) {
			cout << "Queue is full" << endl << endl;
			break;
		}
		cout << ">> ";
		cin >> x;
		if(x == -99) break;
		q.add(x);
	}
	return;
}

void remove(Queue &q) {
	if(q.underflow()) {
		cout << "Queue is empty" << endl << endl;
		return;
	}
	cout << q.pop() << endl << endl;
	return;
}

void full(Queue &q) {
	cout << (q.overflow() ? "True" : "False") << endl << endl;
}

void empty(Queue &q) {
	cout << (q.underflow() ? "True" : "False") << endl << endl;
}

int main() {
  int size;
  cout << "Enter maximum size of queue: ";
  cin >> size;

  Queue q(size);

  int operation;
  while(true) {
		cout << "Enter operation on queue:\n1\tadd\n2\tremove\n3\toverflow\n4\tunderflow\n>> ";
		cin >> operation;

		switch(operation) {
			case 1: create(q);
				break;
			case 2: remove(q);
				break;
			case 3: full(q);
				break;
			case 4: empty(q);
				break;
			default: return 0;
		}
	}
}


/**
 **
 ** Queue using linked list
 **
 **/

 #include <iostream>

 using namespace std;

 struct ListNode
 {
 	int val;
 	ListNode* next;
 	ListNode(int x): val(x){}
 };

 class Queue {
   private:
     int size;
     ListNode* head;
     ListNode* tail;

   public:
     void add(int x) {
       ListNode* temp = new ListNode(x);
 			tail->next = temp;
 			tail = temp;
 			size++;
     }

     void remove() {
       ListNode* temp = head->next;
 			head->next = head->next->next;
 			delete temp;
 			size--;
 			if(!size) tail = head;
     }

     int top() {
 			return head->next->val;
     }

     int pop() {
       int result = top();
       remove();
       return result;
     }

     bool underflow() {
       return (head == tail);
     }

     bool overflow() {
       return false;
     }

     Queue() {
 			size = 0;
 			head = new ListNode(INT_MIN);
 			tail = head;
     }
 };

 void create(Queue &q) {
 	int x;
 	cout << "Enter elements of the queue(-99 for termination): " << endl;
 	while(true) {
 		if(q.overflow()) {
 			cout << "Queue is full" << endl << endl;
 			break;
 		}
 		cout << ">> ";
 		cin >> x;
 		if(x == -99) break;
 		q.add(x);
 	}
 	return;
 }

 void remove(Queue &q) {
 	if(q.underflow()) {
 		cout << "Queue is empty" << endl << endl;
 		return;
 	}
 	cout << q.pop() << endl << endl;
 	return;
 }

 void full(Queue &q) {
 	cout << (q.overflow() ? "True" : "False") << endl << endl;
 }

 void empty(Queue &q) {
 	cout << (q.underflow() ? "True" : "False") << endl << endl;
 }

 int main() {
   Queue q;

   int operation;
   while(true) {
 		cout << "Enter operation on queue:\n1\tadd\n2\tremove\n3\toverflow\n4\tunderflow\n>> ";
 		cin >> operation;

 		switch(operation) {
 			case 1: create(q);
 				break;
 			case 2: remove(q);
 				break;
 			case 3: full(q);
 				break;
 			case 4: empty(q);
 				break;
 			default: return 0;
 		}
 	}
 }
