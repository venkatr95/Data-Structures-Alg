#include<iostream>
#include<vector>
using namespace std;
class bubbleSort
{
public:
 int temp;
 std::vector<int> bSort(std::vector<int> arr)
 {
  int arr_len = arr.size();
  for (int i=0;i<=(arr_len-1)-1;i++)
  {
  for (int j=0;j<=(arr_len-1)-1-i;j++)
  {
    if (arr[j]>arr[j+1])
    {
     temp=arr[j];
     arr[j]=arr[j+1];
     arr[j+1]=temp;
    }
  }
  }
  return arr;
   }
};
int main()
{
 vector<int> arr;
 vector<int> sorted_arr;
 int arr_count;
 cout << "Enter length of array: \n";
 cin >> arr_count;
 cout << "Enter your numbers: \n";
 int temp;
 int i_c = 0;
 while (i_c < arr_count){
    cin >> temp;
    arr.push_back(temp);
    i_c++;
 }

 bubbleSort b;
 sorted_arr=b.bSort(arr);
 cout << "Array before sort" << endl;
 for (int i = 0; i < arr.size(); i++) {
     std::cout << arr.at(i) << ' ';
 }
 cout << endl << "Array after sort" << endl;
 for (int i = 0; i < sorted_arr.size(); i++) {
     std::cout << sorted_arr.at(i) << ' ';
 }
 return 0;
}
