#include <iostream>
#include<vector>
using namespace std;

int main()
{
    vector<int> my_vec; //declaring a vector = vector<data_type> vector_name

    my_vec.push_back(10); //pushing element in vector = vector_name.push_back(value)
    my_vec.push_back(20);
    cout<<"Vector size = "<<my_vec.size()<<endl; //printing size of vector. Here vector size is 2.

    my_vec.push_back(30);
    my_vec.push_back(40);
    cout<<"Vector size = "<<my_vec.size()<<endl; // printing size if vector. Here vector size is 4. Because vector is generally a dynamic array.

    for(int i=0; i<my_vec.size(); i++)  // printing all elements in vector.
    {
        cout<<"Vector "<<i<<" is "<<my_vec[i]<<endl;
    }

    my_vec.erase(my_vec.begin()); // earing 1st element in the vector.

     cout<<"Vector after earing 1st value of vector:"<<endl;
        for(int i=0; i<my_vec.size(); i++)  // printing all elements in vector.
    {
        cout<<"Vector "<<i<<" is "<<my_vec[i]<<endl;
    }

        my_vec.erase(my_vec.begin() + 2); // earing specific vector element by mentioning the number. Here +2 means earing 3rd element of that vector.

        cout<<"Vector after earing 3rd value of vector:"<<endl;
        for(int i=0; i<my_vec.size(); i++)
        {
        cout<<"Vector "<<i<<" is "<<my_vec[i]<<endl; // vector after earing 3rd element
        }

        my_vec.clear(); // clearing a full vector

        cout<<"After clearing vector the vector is:"<<endl;
        for(int i=0; i<my_vec.size(); i++)
        {
        cout<<"Vector "<<i<<" is "<<my_vec[i]<<endl; // after clearing the full vector
        }

        cout<<"Is vector empty: "<<my_vec.empty(); // Empty = 1(Yes), Not empty = 0(No)

    return 0;
}
