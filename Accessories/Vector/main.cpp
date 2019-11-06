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
        cout<<"### Pushing into a Vector as many as you want ###"<<endl;
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
            if(myVector[i]==myVector[i+1]) cout<<i<<" and "<<i+1<<" Positions of vector elements are same"<<endl;
            else cout<<i<<" and "<<i+1<<" Positions of vector elements are not same"<<endl;
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


        //////////////////////// Transferring array elements into a vector ///////////////////////////
        cout<<endl;
        cout<<endl;
        cout<<"### Transferring array elements into a Vector ###"<<endl;
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

        ///////////////////////////////// Resize ////////////////////////////////////////
        cout<<endl;
        cout<<endl;
        cout<<"### Resize ###"<<endl;
        vector<int> vec;
        cout<<"Enter a Vector size: ";
        int a1,b1;
        cin>>a1;
        cout<<"Enter Vector elements: ";
        for(int i=0; i<a1; i++)
        {
            cin>>b1;
            vec.push_back(b1);
        }
        cout<<"Enter a Resize of Vector: ";
        int x;
        cin>>x;
        if(vec.size()>x)
        {
            cout<<"Resized Vector is less than Current Vector"<<endl;;
            vec.resize(x); // Resized with lower size
            cout<<"New Resized Vector contains: ";
            for(int i=0; i<vec.size(); i++) cout<<vec[i]<<" ";
        }
        else
        {
            cout<<"Resized Vector is greater than Current Vector"<<endl;
            cout<<"New Resized Vector contains: ";
            vec.resize(x); // Resized with greater size
            for(int i=0; i<vec.size(); i++) cout<<vec[i]<<" ";
        }
        cout<<endl;

        cout<<"Current Vector Size: "<<vec.size()<<endl;
        cout<<"Enter a new Size of Vector which is greater than Current Vector size: ";
        int x1,x2;
        cin>>x1;
        cout<<"Enter an Element with which you want to Resize your Vector: ";
        cin>>x2;
        cout<<"New Resized vector with element "<<x2<<" : ";
        vec.resize(x1,x2); // Resized with element (Vector size must be greater than previous) --> vector_name(vector_size, resized_element)
        for(int i=0; i<vec.size(); i++) cout<<vec[i]<<" ";

        /////////////////////////////// Front and Back ////////////////////////////////
        cout<<endl;
        cout<<endl;
        cout<<"### Front and Back ### "<<endl;
        int a2,b2;
        vector<int> veci;
        cout<<"Enter Vector Size: ";
        cin>>a2;
        cout<<"Enter Vector elements: ";
        for(int i=0; i<a2; i++)
        {
            cin>>b2;
            veci.push_back(b2);
        }
        cout<<"Front element of this Vector is: "<<veci.front()<<endl;
        cout<<"Back element of this Vector is: "<<veci.back()<<endl;
        if(veci.front()>veci.back()) cout<<"Difference between Front and Back: "<<veci.front() - veci.back();
        else if(veci.back()>veci.front()) cout<<"Difference between Front and Back: "<<veci.back() - veci.front();
}
