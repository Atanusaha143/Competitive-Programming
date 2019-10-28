#include <iostream>
#include<vector>
#include<algorithm>
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

     cout<<"Vector after erasing 1st value of vector:"<<endl;
        for(int i=0; i<my_vec.size(); i++)  // printing all elements in vector.
    {
        cout<<"Vector "<<i<<" is "<<my_vec[i]<<endl;
    }

        my_vec.erase(my_vec.begin() + 2); // earing specific vector element by mentioning the number. Here +2 means earing 3rd element of that vector.

        cout<<"Vector after erasing 3rd value of vector:"<<endl;
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


        //////////////////////// Pushing into a vector as many as you want ///////////////////////////
        cout<<endl;
        cout<<endl;

        int a,b;
        cout<<"Enter how many numbers to push in the vector: ";
        cin>>a;
        vector<int> myVector;
        cout<<"Enter vector elements: ";
        for(int i=0; i<a; i++) // pushing vector elements
        {
            cin>>b;
            myVector.push_back(b);
        }
        cout<<"Vector contains: "; // printing vectors elements
        for(int i=0; i<a; i++)
        {
            cout<<myVector[i]<<" ";
        }
        cout<<endl;

        for(int i=0; i<a-1; i++)  // Accessing vector elements
        {
            if(myVector[i]==myVector[i+1]) cout<<i<<" and "<<i+1<<" positions vector elements are same"<<endl;
            else cout<<i<<" and "<<i+1<<" positions vector elements are not same"<<endl;
        }

        sort(myVector.begin(),myVector.end()); // Sorting vector elements in ascending order
        cout<<"Vector elements after sorting in ascending order: ";
        for(int i=0; i<a; i++)
        {
            cout<<myVector[i]<<" ";
        }
        cout<<endl;

        sort(myVector.begin(),myVector.end(),greater<int>()); // Sorting vector elements in descending order
        cout<<"Vector elements after sorting in descending order: ";
        for(int i=0; i<a; i++)
        {
            cout<<myVector[i]<<" ";
        }


        //////////////////////// Transfering array elements into a vector ///////////////////////////
        cout<<endl;
        cout<<endl;

        int c;
        cout<<"Enter size of the array: ";
        cin>>c;
        int arr[c];
        cout<<"Enter array elements: ";
        for(int i=0; i<c; i++)
        {
            cin>>arr[i];
        }

        vector<int> myVector1 (arr,arr+c); // Declaring a vector with array elements
        cout<<"Elements of Vector form Array: "; // Which is a copy if Array
        for(int i=0; i<c; i++)
        {
            cout<<myVector1[i]<<" ";
        }


}
