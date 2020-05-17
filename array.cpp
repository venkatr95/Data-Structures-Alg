#include<iostream>
#include<array>
using namespace std;

int main()
{
    int i;
    array <int,7> a;
    array <int,7> b={5,2,3,9,6,1,4};

    cout << "\nSize of array b is : " << b.size();

    cout << "\nb elements are : ";
    for(i=0;i < b.size();i++)
        cout << b[i] << " ";

    cout << "\nFront element b : " << b.front();
    cout << "\nLast element b : " << b.back();

    a.fill(0);
    cout << "\nFill a with 5 in each block : ";
    for(i=0;i < a.size();i++)
        cout << a[i] << " ";

    a.swap(b);
    cout << "\nSwapping both arrays of same size and data type";
    cout << "\n a : ";
    for(i=0;i < a.size();i++)
        cout << a[i] << " ";
    cout<<"\n b : ";
    for(i=0;i < b.size();i++)
        cout << b[i] << " ";
}
