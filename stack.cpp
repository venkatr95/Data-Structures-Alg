#include<iostream>
using namespace std;

class stack{ // Last In First Out Mechanism
private:
    int s[5],top;

public:
    stack(){
        top=-1;
    }
    void pop(){ // Remove from the stack
    if (top==-1)
        cout << "\nStack is Empty";
    else
        top--;
    }
    void push(int n){ // Add to stack
    if (top==4){
        cout << "\nStack is Full";
    }
    else{
        top++;
        s[top]=n;
    }
    }
    void display(){ // Print stack
        cout << "\n";
        for(int i=0;i<=top;i++){
		cout << "" << s[i];
    }}
};

int main(){
    int x,n;
    stack s;
    cout << "\nPress 1 for POP";
    cout << "\nPress 2 for PUSH";
    cout << "\nPress 3 for DISPLAY";
    cout << "\nPress 4 for EXIT";
    while (x!=4){
    cout << "\nEnter your choice";
    cin >> x;


    switch (x)
    {
    case 1:
        s.pop();
        break;
    case 2:
        cout << "\nEnter integer value - ";
        cin >> n;
        s.push(n);
        break;
    case 3:
        s.display();
        break;
    case 4:
        break;
    default:
        cout << "\nInvalid input";
    }
    }
}
