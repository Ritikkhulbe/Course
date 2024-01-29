#include <iostream>
#include <list>

using namespace std;

void displayList(const list<int>& myList) {
    cout << "Linked List: ";
    for (const auto& element : myList) {
        cout << element << " ";
    }
    cout << endl;
}

int main() {
    list<int> myList;

    for(int i = 0; i < 3 ; i++){
        int x;
        cin>>x;
        myList.push_back(x);
    }
    for(int i = 0; i < 3; i++){
        int x;
        cin>>x;
        myList.push_front(x);
    }

    displayList(myList);

    myList.pop_back();
    myList.pop_front();

    displayList(myList);
    
    return 0;
}
