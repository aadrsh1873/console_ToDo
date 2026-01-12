#include<bits/stdc++.h>
using namespace std;

struct task
{
   string content;
   bool status;
};

void addinto(vector<task> &storage);
void deletefrom(vector<task> &storage);
void display(vector<task> &storage);
void markdone(vector<task> &storage);

int main()
{
    //vector to store tasks
    vector<task> storage;

    int choice;
    while (true)
    {
        cout<<"....Console TO-DO App...."<<endl;
        

        //operations that can be performed in the todo app.

        cout<<"1. Add into the list."<<endl;
        cout<<"2. Delete from the list."<<endl;
        cout<<"3. Display the list."<<endl;
        cout<<"4. Mark as done."<<endl;
        cout<<"Press 0 to exit."<<endl;

        cout<<"Enter your choice:"<<" ";
        cin>>choice;

        switch(choice)
        {
            case 1: addinto(storage); break;
            case 2: deletefrom(storage); break;
            case 3: display(storage); break;
            case 4: markdone(storage); break;
            case 0: cout<<"!!!___Exited the app successfully___!!!"<<endl;  return 0;
            default: cout<<"Invalid Choice! Try agian..."<<endl;
        }
    }

}

void addinto(vector<task> &storage)
{
    task t;

    cin.ignore();// to ignore the next line or spaces of previous cin

    do
    {

    cout<<"Enter task : ";
    getline(cin,t.content);

    } while (length(t.content) == 0 || t.content ==" ");

    
    t.status = false;

    storage.push_back(t);


}

void deletefrom(vector<task> &storage)
{
    cout<<"Under progress:"<<endl;
}

void display(vector<task> &storage)
{
    cout<<"Under progress:"<<endl;
}
void markdone(vector<task> &storage)
{
    cout<<"Under progress:"<<endl;
}