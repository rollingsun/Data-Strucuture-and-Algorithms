#include <iostream>

using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode* prev;
  ListNode(int x): val(x){}
};

class Dequeue {
  private:
    ListNode* head;
    ListNode* tail;

  public:
    void push(bool end, int x) {
      ListNode* temp = new ListNode(x);
      if(end) {
        tail->prev->next = temp;
        temp->prev = tail->prev;
        tail->prev = temp;
        temp->next = tail;
      }
      else {
        head->next->prev = temp;
        temp->next = head->next;
        head->next = temp;
        temp->prev = head;
      }
    }

    int pop(bool end) {
      int result;
      ListNode* temp;
      if(end) {
        result = tail->prev->val;
        temp = tail->prev;
        tail->prev = temp->prev;
        temp->prev->next = tail;
      }
      else {
        result = head->next->val;
        temp = head->next;
        head->next = temp->next;
        temp->next->prev = head;
      }
      delete temp;
      return result;
    }

    bool empty() {
      return (head->next == tail);
    }

    Dequeue() {
      head = new ListNode(-99);
      tail = new ListNode(-99);
      head->next = tail;
      tail->prev = head;
    };
};

void addDQ(Dequeue* dq, bool end) {
  int x;
	cout << "Enter elements of Dequeue(-99 for termination): " << endl;
	while(true) {
		cout << ">> ";
		cin >> x;
		if(x == -99) {
			break;
		}
		dq->push(end, x);
	}
}

void removeDQ(Dequeue* dq, bool end) {
  if(dq->empty()) {
    cout << "The dequeue is empty" << endl << endl;
    return;
  }
  cout << dq->pop(end) << endl << endl;
}

int main() {
  Dequeue* dq = new Dequeue;

  int operation;
  while(true) {
    cout << "Enter operation on Dequeue:\n1\taddFront\n2\taddBack\n3\tremoveFront\n4\tremoveBack\n>> ";
    cin >> operation;

    switch(operation) {
			case 1: addDQ(dq, 0);
				break;
			case 2: addDQ(dq, 1);
				break;
			case 3: removeDQ(dq, 0);
				break;
			case 4: removeDQ(dq, 1);
				break;
			default: return 0;
		}
  }

}
