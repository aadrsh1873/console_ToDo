#include<bits/stdc++.h>
using namespace std;

struct task
{
   int task_id;
   string task;
   bool task_status;
};

void addinto();
void deletefrom();
void display();

int main()
{
    int choice;
    while (true)
    {
        cout<<"....Console TO-DO App...."<<endl;
        

        //operations that can be performed in the todo app.

        cout<<"1. Add into the list."<<endl;
        cout<<"2. Delete from the list."<<endl;
        cout<<"3. Display the list."<<endl;
        cout<<"Press 0 to exit."<<endl;

        cout<<"Enter your choice!";
        cin>>choice;

        switch(choice)
        {
            case 1: addinto(); break;
            case 2: deletefrom(); break;
            case 3: display(); break;
            case 0: cout<<"!!!___Exited the app successfully___!!!"<<endl; break;
            default: cout<<"Invalid Choice! Try agian..."<<endl;
        }
    }

}