#include <iostream>
#include <vector>
using namespace std;

// Input vector
void input_vector(vector<int>& v)
{
    int num, val;

    cout << "Enter the number of elements in vector ";
    cin >> num;
    for (int i = 0; i < num; i++)
    {
        cin >> val;
        v.push_back(val);
    }
}

// Linear Search
int linear_search(vector<int> v, int val)
{
    int key = -1;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == val)
        {
            key = i;
            break;
        }
    }
    return key;
}

int main()
{
    int key, value;
    vector<int> v;
    input_vector(v);
    cout << "Enter the number to search: ";
    cin >> value;
    key = linear_search(v, value);
    if (key != -1)
        std::cout << "\nElement " << value << " is at position " << ++key;
    else
        std::cout << "\nElement " << value << " is not present";
}
