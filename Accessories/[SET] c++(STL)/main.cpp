/// Author : ATANU SAHA

#include<iostream>
#include<set>
#include<iterator>
using namespace std;
int main()
{
    set <int> st; // Decleration (Ascending)
    set <int> :: iterator it;

    st.insert(1); // Insert
    st.insert(3);
    st.insert(2);
    cout<<"1st set in ascending formet: ";
    for(it=st.begin(); it!=st.end(); it++) // Have to access with pointer iterrator for related work
    {
        cout<<*it<<" ";
    }

    cout<<endl;

    set <int, greater<int>> sst; // Decleration (Dscending)
    set <int, greater<int>> :: iterator iit;
    sst.insert(1); // Insert
    sst.insert(3);
    sst.insert(2);
    cout<<"2nd set in descending formet: ";
    for(iit=sst.begin(); iit!=sst.end(); iit++)
    {
        cout<<*iit<<" ";
    }

    cout<<endl;

    it = st.begin(); // it(iterator) contain the first element of the set
    st.erase(it); // erasing the first element
    cout<<"1st set after erasing the first element:  ";
    for(it=st.begin(); it!=st.end(); it++)
    {
        cout<<*it<<" ";
    }

    cout<<endl;

    iit = sst.begin(); //// it(iterator) contain the last element of the set
    sst.erase(iit); // erasing the last element
    cout<<"2nd set after erasing the first element:  ";
    for(iit=sst.begin(); iit!=sst.end(); iit++)
    {
        cout<<*iit<<" ";
    }

    cout<<endl;

    cout<<"after erasing 2 from 1st set we have: ";
    st.erase(2); // erasing a specific value
    for(it=st.begin(); it!=st.end(); it++) cout<<*it<<" ";

    cout<<endl;

    cout<<"after erasing 2 from 2nd set we have: ";
    sst.erase(2); // erasing a specific value
    for(iit=sst.begin(); iit!=sst.end(); iit++) cout<<*iit<<" ";

    cout<<endl;

    set <int> st1;
    set <int> :: iterator it1;
    for(int i=1; i<=10; i++) st1.insert(i);
    cout<<"NEW SET: ";
    for(it1 = st1.begin(); it1!=st1.end(); it1++) cout<<*it1<<" ";
    cout<<endl;
    cout<<"after erasing up to 5 in NEW SET: ";
    st1.erase(st1.begin(),st1.find(5)); // erasing from begining up to 5
    for(it1 = st1.begin(); it1!=st1.end(); it1++) cout<<*it1<<" ";

    cout<<endl;

    cout<<"after erasing from 6 to 9 with upper_bound && lower_bound: ";
    set<int>::iterator upr_bnd,lwr_bnd;
    lwr_bnd = st1.lower_bound(6); // sets 6 as a lower bound
    upr_bnd = st1.upper_bound(9); // sets 9 as an upper bound
    st1.erase(lwr_bnd,upr_bnd); // erasing from 6 to 9
    for(it1 = st1.begin(); it1!=st1.end(); it1++) cout<<*it1<<" ";

    cout<<endl;

    cout<<"After cleaning the NEW SET it is: ";
    st1.clear(); // clears all values in a set
    for(it1 = st1.begin(); it1!=st1.end(); it1++) cout<<*it1<<" ";

    cout<<endl;

    cout<<"Is the NEW SET empty: ";
    cout<<st1.empty(); // returns 1 if the set is empty or 0 if it is non_empty

    cout<<endl;

    cout<<"Again a NEW SET is: ";
    set <int> st2;
    set <int> :: iterator it2;
    for(int i=1; i<=5; i++) st2.insert(i);
    for(it2 = st2.begin(); it2!=st2.end(); it2++) cout<<*it2<<" ";
    cout<<endl;
    set <int> copy_st2(st2.begin(),st2.end()); // copying  set 'st2' to set 'copy_st2'
    cout<<"After copying NEW SET, the set is: ";
    for(it2 = copy_st2.begin(); it2!=copy_st2.end(); it2++) cout<<*it2<<" ";

    cout<<endl;

    set <string> str;
    set <string> :: iterator itr;
    str.insert("Atanu");
    str.insert("Saha");
    for(itr=str.begin(); itr!=str.end(); itr++) cout<<*itr<<" ";
}
