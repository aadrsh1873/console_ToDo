// Header files
#include<iostream>   // for input/output (cin, cout)
#include<vector>     // for dynamic array (vector) to store tasks
#include<string>     // for string type and getline function

using namespace std; // to avoid writing std:: everywhere

// ---------------------------
// User-defined data type
// ---------------------------
// Structure to represent a single task
struct task
{
   string content; // stores the description/content of the task
   bool status;    // false = not done, true = done
};

// ---------------------------
// Helper function
// ---------------------------
// Converts a boolean value to 'y' (yes) or 'n' (no) for display purposes
char booltoYN(bool value)
{
    return value ? 'y' : 'n';
}

// ---------------------------
// Function prototypes
// ---------------------------
// Declaring all functions before main() so the compiler knows about them
void addinto(vector<task> &storage);      // Adds a new task
void deletefrom(vector<task> &storage);   // Deletes a task by id
void display(vector<task> &storage);      // Displays all tasks
void markdone(vector<task> &storage);     // Marks a task as done

// ---------------------------
// Main function
// ---------------------------
int main()
{
    vector<task> storage; // Vector to store all tasks dynamically

    int choice; // User's menu choice

    while (true) // Infinite loop until user chooses to exit
    {
        // ---------------------------
        // Display the menu
        // ---------------------------
        cout << "....Console TO-DO App...." << endl;
        cout << "1. Add into the list." << endl;
        cout << "2. Delete from the list." << endl;
        cout << "3. Display the list." << endl;
        cout << "4. Mark as done." << endl;
        cout << "Press 0 to exit." << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        // ---------------------------
        // Handle user's choice
        // ---------------------------
        switch(choice)
        {
            case 1: addinto(storage); break;     // Add a new task
            case 2: deletefrom(storage); break;  // Delete a task by id
            case 3: display(storage); break;     // Display all tasks
            case 4: markdone(storage); break;    // Mark a task as done
            case 0: cout << "!!!___Exited the app successfully___!!!" << endl;  
                    return 0;                    // Exit the program
            default: cout << "Invalid Choice! Try again..." << endl;
        }
    }
}

// ---------------------------
// Function: addinto
// ---------------------------
// Adds a new task to the vector
void addinto(vector<task> &storage)
{
    task t;             // Create a temporary task object

    cin.ignore();       // Ignore leftover newline character from previous input

    // ---------------------------
    // Get valid task content from user
    // ---------------------------
    do
    {
        cout << "Enter task: ";
        getline(cin, t.content);   // Read the full line including spaces
    } while (t.content.length() == 0 || t.content == " "); // Ensure non-empty task

    t.status = false; // Default status: not done

    storage.push_back(t); // Add task to the vector
}

// ---------------------------
// Function: deletefrom
// ---------------------------
// Deletes a task from the vector based on user-provided task id
void deletefrom(vector<task> &storage)
{
    int id;

    if(storage.empty()) // If there are no tasks
    {
        cout << "There is no task to delete." << endl;
        return;
    }

    cout << "Enter task id to delete the task: ";
    cin >> id;

    // ---------------------------
    // Validate the task id
    // ---------------------------
    if(id < 1 || id > storage.size())
    {
        cout << "Invalid task id." << endl;
        return;
    }

    // ---------------------------
    // Remove the task from vector
    // ---------------------------
    storage.erase(storage.begin() + (id - 1));
    cout << "Task deleted successfully!!" << endl;
}

// ---------------------------
// Function: display
// ---------------------------
// Displays all tasks with their id and status
void display(vector<task> &storage)
{
    if(storage.empty()) // If no tasks exist
    {
        cout << "No task exist till now." << endl;
        cout << "Are you ready to create some action?" << endl;
        return;
    }

    // ---------------------------
    // Display header
    // ---------------------------
    cout << "Id | Task | Status " << endl;

    int task_id = 1; // 1-based display ID
    for(auto &t : storage) 
    {
        cout << task_id << " ";              // Task ID
        cout << " " << t.content << " ";     // Task content
        cout << " " << booltoYN(t.status);   // Task status: 'y' or 'n'
        cout << endl;
        task_id++;
    }
}

// ---------------------------
// Function: markdone
// ---------------------------
// Marks a task as done based on user-provided task id
void markdone(vector<task> &storage)
{
    if(storage.empty()) // No tasks to mark
    {
        cout << "There is no task to mark." << endl;
        return;
    }

    int id;
    cout << "Enter task id to change the task status: ";
    cin >> id;

    // ---------------------------
    // Validate task id
    // ---------------------------
    if(id < 1 || id > storage.size())
    {
        cout << "Invalid task id." << endl;
        return;
    }

    // ---------------------------
    // Mark the task as done
    // ---------------------------
    storage[id - 1].status = true;
    cout << "Task marked as done." << endl;
}
