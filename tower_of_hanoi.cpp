#include<iostream>
using namespace std;
int TOH(int n, char blockA, char blockB, char blockC)
{
    ///If only 1 plate,move from blockA to blockC.
    if (n==1)
    {
        cout << "\n" << blockA << " to " << blockC;
        return(0);
    }
    ///Move n-1 plates from blockA to blockB
    TOH(n-1,blockA, blockC, blockB);
    ///Move last plate from blockA to blockC
    cout << "\n" << blockA << " to " << blockC;
    ///Move n-1 plates from blockB to blockC
    TOH(n-1, blockB, blockA, blockC);
}
int main()
{
    char blockA = 'A', blockB = 'B', blockC = 'C';
    int n;
    cout<<"\n  X   \t   X   \t   X     ";
    cout<<"\n  X   \t   X   \t   X     ";
    cout<<"\n  X   \t   X   \t   X     ";
    cout<<"\n----- \t ----- \t -----   ";
    cout<<"\n  A   \t   B   \t   C     ";

    cout << "\n\nEnter number of plates - ";
    cin >> n;
    TOH(n, blockA, blockB, blockC);

}
