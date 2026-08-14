#include<iostream>
#include<string>
using namespace std;
class Library{
    public:
        virtual void display()=0;

};
class Book: public Library{
    private:
        int id;
        string name;
        string author;

    public :
        void getdata(){
            cout<<"Enter id of book:"<<endl;
            cin>>id;
            cin.ignore();
            cout<<"Enter book name:"<<endl;
            getline(cin,name);
            cout<<"enter author name:"<<endl;
           getline(cin,author);


        }
        void display(int){
            cout<<"Book id:"<<id<<endl;
            cout<<"Book name:"<<name<<endl;
            cout<<"Book author:"<<author<<endl;
        }
        void display(){
            cout<<"Book id:"<<id<<endl;
            cout<<"Book name:"<<name<<endl;
            
        }
        bool operator==(Book &b){
    return id == b.id &&
           name == b.name &&
           author == b.author;
}

};
int main(){
    Book b[2];
    cout<<"Enter book datails:"<<endl;
    for(int i=0;i<2;i++){
        cout<<"Enter details of "<<i+1<<" book"<<endl;
        b[i].getdata();
    }
    cout<<"all books details:"<<endl;
    for(int i=0;i<2;i++){
        cout<<i+1 <<" book details:"<<endl;
            b[i].display(1);
    }
    cout<<"comparison of books:"<<endl;
    if(b[0]==b[1]){
        cout<<"Both books are equal"<<endl;
    }
    else{
        cout<<"Both books are not equal"<<endl;
    }
    return 0;
}




//Output:
// Enter book datails:
// Enter details of 1 book
// Enter id of book:
// 1
// Enter book name:
// Object Oriented Programming in C++
// enter author name:
// Ganesh Jadhav
// Enter details of 2 book
// Enter id of book:
// 2
// Enter book name:
// DSA In Java
// enter author name:
// Prajakta Jadhav
// all books details:
// 1 book details:
// Book id:1
// Book name:Object Oriented Programming in C++
// Book author:Ganesh Jadhav
// 2 book details:
// Book id:2
// Book name:DSA In Java
// Book author:Prajakta Jadhav
// comparison of books:
// Both books are not equal