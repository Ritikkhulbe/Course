#include <iostream>
#include <vector>
using namespace std;

template <typename T>
struct Stack {
    int top;
    int size;
    T *S;

    Stack(int stackSize) : top(-1), size(stackSize), S(new T[stackSize]) {}

    ~Stack() {
        delete[] S;
    }

    void push(T value) {
        if (top < size - 1) {
            S[++top] = value;
        } else {
            cout<<"Overflow"<<endl;
        }
    }

    T pop() {
        if (top >= 0) {
            return S[top--];
        } else {
            cout<<"No elements to pop"<<endl;
            return T(); 
        }
    }
    T topElement(){
        return S[top];
    }

    bool empty() const {
        return top == -1;
    }

    bool isFull() const {
        return top == size - 1;
    }
};
vector<int> nextGreaterInLeft(int a[], int n)
{
    vector<int> left_index(n, 0);
    Stack<int> s(100);
    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && a[i] > a[s.topElement() - 1]) {
            int r = s.topElement();
            s.pop();
            left_index[r - 1] = i + 1;
        }
 
        s.push(i + 1);
    }
    return left_index;
}

vector<int> nextGreaterInRight(int a[], int n)
{
    vector<int> right_index(n, 0);
    Stack<int> s(100);
    for (int i = 0; i < n; ++i) {
 
        while (!s.empty() && a[i] > a[s.topElement() - 1]) {
            int r = s.topElement();
            s.pop();
            right_index[r - 1] = i + 1;
        }
 
        s.push(i + 1);
    }
    return right_index;
}
 
int LRProduct(int arr[], int n){
    vector<int> left = nextGreaterInLeft(arr, n);
    vector<int> right = nextGreaterInRight(arr, n);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, left[i] * right[i]);
    }
 
    return ans;
}
 
int main(){
    int n;
    cout<<"Enter number of elements : ";
    cin>>n;

    int *arr = new int[n];
    
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    cout << LRProduct(arr, n);
 
    return 0;
}