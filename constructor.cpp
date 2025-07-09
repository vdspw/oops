#include<iostream>
using namespace std;

class car {
public :
string name;
string model;
int year;
car(string x,string y,int z) //constructor
{
name =x;
model=y;
year =z;
}

};

int main()
{
car obj1 ("BMW","x5",2000);  //calling the constructor 
car obj2 ("Rolls Royce", "Ghost",2012); // --||--

//print values
cout << obj1.name << " " << obj1.model << " " << obj1.year << "\n ";
cout << obj2.name << " " << obj2.model << " " << obj2.year << "\n ";
return 0;
}
