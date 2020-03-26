#include<iostream>
#include<bitset>

#define SIZE 8
using namespace std;

int main()
{
    bitset <8> bit; // Normally sets all bits to zero
    cout<<"Normally \'bit\' is initialized to --> "<<bit<<endl<<endl;


    bit.set(); // sets all bits to one
    cout<<"All bits of \'bit\' is set to --> "<<bit<<endl<<endl;


    bit.reset(); // sets all bits to zero
    cout<<"All bits of \'bit\' is reset to --> "<<bit<<endl<<endl;


    bitset <20> b (string ("1101")); // this can also be initialized
    cout<<"\'bit\' with string initialization --> "<<b<<endl<<endl;



    // this can't compile
    // because bitset have to be initialized at the time of compile
    /*int SIZE = 8
    bitset <SIZE> bits*/ // wrong initialization

    // But we can define a constant then use
    bitset <SIZE> bits;
    cout<<"\'bits\' with defined constant --> "<<bits<<endl<<endl;



    // bitsets indexing starts from right to left
    bitset <8> b1(7); //this will make binary 7 starting from 1st index
    cout<<"\'b1\' is initialized with binary 7 starting from 1st index --> "<<b1<<endl<<endl;



    cout<<"Printing the 0th index of \'b1\' --> "<<b1[0]<<endl<<endl; // this will print 0th index's value
    b1[2] = 0; // making 2nd index 0 of b1
    cout<<"After making 2nd index 0 of \'b1\' it is --> "<<b1<<endl<<endl;
    b1.set(2); // making 2nd index 1 of b1
    cout<<"After making 2nd index set of \'b1\' it is --> "<<b1<<endl<<endl;
    b1.reset(2); // making 2nd index 0 of b1
    cout<<"After making 2nd index reset of \'b1\' it is --> "<<b1<<endl<<endl;



    cout<<"Size of \'b1\' is --> "<<b1.size()<<endl<<endl; // Printing the size of b1


    cout<<"Counting how many 1 in \'b1\' --> "<<b1.count()<<endl<<endl; // Counts how many 1's in this bits;


    cout<<"Counting how many 0 in \'b1\' --> "<<b1.size()-b1.count()<<endl<<endl; // Counts how many 0's in this bits;


    cout<<"If there is at least one 1 then \'b1\' will return --> "<<b1.any()<<endl<<endl; // returns 1 if at least one bit is set means 1, else 1


    cout<<"If all bits are not 0 then \'b1\' will return --> "<<b1.none()<<endl<<endl; // returns 1 if all bits are reset means 0, else 0


    cout<<"Fliping all the bits of \'b1\' --> "<<b1.flip()<<endl<<endl; // fliping all the bits means 0 will be 1 and 1 will be 0


    //left shifting

    bitset <4> bset (string ("0011"));
    cout<<"\'bset\' --> "<<bset<<endl<<endl;
    //bset = bset << 1;
    //cout<<"\'bset\' shifted 1 indexed left -->"<<bset<<endl<<endl;
    bset <<= 2;
    cout<<"\'bset\' shifted 2 indexed left -->"<<bset<<endl<<endl;


    //right shifting
    bset >>= 1;
    cout<<"\'bset\' shifted 1 indexed right -->"<<bset<<endl<<endl;


    //equality checking

    bitset <4> c (string ("0011"));
    bitset <4> d (string ("0011"));
    cout<<"If '\c\' and \'d'\ are equal then it will return --> "<<(c==d)<<endl<<endl;

    c.set();
    cout<<"'\c\' & \'d'\  --> "<< (c&d) <<endl<<endl; // will do c and(&) d
    cout<<"'\c\' | \'d'\  --> "<< (c|d) <<endl<<endl; // will do c or(|) d
    cout<<"'\c\' ^ \'d'\  --> "<< (c^d) <<endl<<endl; // will do c xor(^) d
}
