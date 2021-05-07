//05_data_structures_pointers

#include <iostream>

using namespace std;
/*
int main() {
    int v1 = 0;
    int *p1;
    p1 = &v1;
    *p1 = 42;
    cout << v1 << " and the ptr is " << p1 << endl;
}*/

struct Node {
    int data;
    Node *link;
};

typedef Node* nodePtr;

int main(){
    nodePtr head;
    head = new Node;
    head->data = 20;
    head->link = NULL;
}

/*
       _________
head   |  20   |
       |-------|
link   | NULL  |
*/