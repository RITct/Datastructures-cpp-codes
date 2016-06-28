/*
 * This is a free program to show working and implementation of a simple linked list in CPP
 * You are free to use it however as you want.
 *
 * Author doesnt hold responsibility to this code
 *
 * Author : Sidhin S Thomas
 * email: sidhin.thomas@gmail.com
 */


#include<iostream>
#include <stdexcept>
using namespace std;


class node{
public:
    int d ;
    node *next ;
    node(int k){
        d = k ;
        next = NULL;
    }

};
class list {
private:
    node *head;
public:
    list(){
        head= NULL;
    }
    ~list(){
        node *temp = head;
        while(head!=NULL){
            temp = head;
            head = head->next;
            cout << "destroying "<< temp->d << "\n";
            delete temp ;
        }
    }
    bool insert(int);
    bool remove(int);
    int pop();
    int getItem(int);
    void printList();
    void insertAt(int,int);
    int search(int);
    void reverseList();
    void printReverse();
};

bool list::insert(int n) {
    if(head==NULL){
        head = new node(n);
        return true;
    }
    node *t = head ;
    while(t->next!=NULL)
        t = t->next;
    t->next = new node(n);
    return true;
}

bool list::remove(int n) {
    if(head==NULL){
        return false;
    }
    node *cur, *pre ;
    cur = head ;
    pre = NULL ;
    while(cur!=NULL){
        if(cur->d == n){
            if(pre!=NULL)
                pre->next = cur->next;
            else
                head = cur->next ;
            delete cur ;
            return true;
        }
        pre = cur ;
        cur = cur->next;
    }
    return false ;
}

int list::pop(){
    if(head==NULL){
        throw std::invalid_argument("Null list");
    }
    node *t = head ;
    int item ;
    if(t->next != NULL) {
        while (t->next->next != NULL)
            t = t->next;
        item = t->next->d;
        delete t->next ;
        t->next = NULL ;
    }
    else {
        item = t->d;
        delete t ;
        head = NULL ;
    }
    return item;
}
int list::getItem(int n) {
    int count = 0 ;
    node *t = head ;
    while(t!=NULL){
        if(count==n)
            return t->d ;
        count++;
        t=t->next;
    }
    throw n ;
}
void list::printList() {
    cout << "The list is : \n";
    node* t = head ;
    while(t!=NULL){
        cout << t->d << " ";
        t = t->next ;
    }
    cout << endl;
}
void list::insertAt(int n, int loc) {
    int count = 0 ;
    node *t = head ;
    while(t!=NULL){
        if(count == loc){
            t->d = n;
            return;
        }
        count ++ ;
        t = t->next;
    }
    throw std::invalid_argument("Out of bound index");
}
int list::search(int n) {
    node *t = head ;
    int count = 0 ;
    while(t!=NULL){
        if(t->d == n){
            return count ;
        }
        count ++ ;
        t = t->next ;
    }
    return -1 ;
}
void list::reverseList() {
    node *t = head ;
    node *newHead ;
    if(head!=NULL)
        newHead = new node(head->d);
    else return;
    t = t->next;
    while(t!= NULL){
        node *ptr = new node(t->d);
        ptr->next = newHead ;
        newHead = ptr ;
        t = t->next ;
    }
    while(head->next!=NULL){
        node *ptr = head ;
        head = head ->next ;
        delete ptr ;
    }
    if(head!=NULL) delete head ;
    head = newHead ;
}

void list::printReverse() {
    reverseList();
    printList();
    reverseList();
}

int main(){
    list l;
    int option ;
    cout << "Option: \n0 - insert element\n"
        <<"1 - remove\n"
        <<"2 - print list\n"
        <<"3 - get item at position\n"
        <<"4 - print reverse of list\n"
        <<"5 - reverse the list\n"
        <<"6 - search list\n"
        <<"7 - pop item from list\n"
        <<"8 - insert element at position\n";
    while(true){
        int k = 0 ;
        cout << "\n\nEnter choice :";
        cin >> option ;
        if(option == 0){
            cout << "Element to insert:";
            cin >> k ;
            l.insert(k);
        }
        if(option == 1){
            cout << "Element to remove:";
            cin >> k ;
            l.remove(k);
        }
        if(option == 2){
            l.printList();
        }
        if(option == 3){
            cin >> k ;
            k = l.getItem(k);
            cout << "Item is "<< k << endl ;
        }
        if(option == 4){
            l.printReverse();
        }
        if(option == 5){
            l.reverseList();
            cout << "List is reversed\n";
        }
        if(option == 6){
            cout << "Element to search:";
            cin >> k ;
            k = l.search(k);
            if(k!=-1)
                cout << "Found at " << k << endl ;
            else
                cout << "Not found\n";
        }
        if(option == 7){
            try {
                k = l.pop();
                cout << "Element popped :" << k << endl;
            }
            catch(const std::invalid_argument& e){
                cout << "Empty list\n";
            }
        }
        if(option == 8) {
            cout << "Enter element to insert:";
            cin >> k;
            int loc;
            cout << "Enter location:";
            cin >> loc;
            try {
                l.insertAt(k, loc);
            }
            catch (const std::invalid_argument &e) {
                cout << "Out of bound!\n";
            }
        }
        if(option == 100)
            break;
    }
}