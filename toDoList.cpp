#include<iostream>
#include<vector>
#include<string>
using namespace std;
vector<string> tasks;
void addTasks(string& task)
{
    tasks.push_back(task);
    cout<<"Task : "<<task<<"added."<<endl;
}
void viewTasks()
{
    if(!tasks.empty())
    {
        cout<<"Current Tasks : "<<endl;
        for(int i=0;i<tasks.size();i++)
        {
            cout<<i+1<<" : "<<tasks[i]<<endl;
        }
    }
    else
    {
        cout<<"No tasks found."<<endl;
    }
}
void deleteTask(int index)
{
    if(index>=0&&index<tasks.size())
    {
        cout<<"Tasks : "<<tasks[index]<<"deleted."<<endl;
        tasks.erase(tasks.begin()+index);
    }
    else
    {
        cout<<"Invalid Task Number."<<endl;
    }
}
void markComplete(int index)
{
    if(index>=0&&index<tasks.size())
    {
        cout<<"Tasks : "<<tasks[index]<<"completed."<<endl;
        tasks[index]=tasks[index]+"(COMPLETED)";
    }
    else
    {
        cout<<"No task Found."<<endl;
    }
}
int main()
{
    while(true)
    {
        cout<<"\nOptions:"<<endl;
        cout<<"1. Add Task"<<endl;
        cout<<"2. View Tasks"<<endl;
        cout<<"3. Delete Task"<<endl;
        cout<<"4. Mark Completed"<<endl;
        cout<<"5. Quit" <<endl;
        int choice;
        cout<<"Enter your choice (1-5): ";
        cin>>choice;
        switch(choice)
        {
        case 1:
        {
            string task;
            cout<<"Enter the task: ";
            cin.ignore();  // Clear the newline character from the buffer
            getline(cin, task);
            addTasks(task);
            break;
        }
        case 2:
        {
            viewTasks();
            break;
        }
        case 3:
        {
            viewTasks();
            int indexToDelete;
            cout<<"Enter the task index to delete: ";
            cin>>indexToDelete;
            deleteTask(indexToDelete - 1);
            break;
        }
        case 4:
        {
            viewTasks();
            int indexmarkComplete;
            cout<<"Enter the task index to delete: ";
            cin>>indexmarkComplete;
            markComplete(indexmarkComplete - 1);
            viewTasks();
            break;
        }
        case 5:
        {
            cout<<"Quitting the to-do list manager. Goodbye!"<<endl;
            return 0;
        }
        default:
        {
            cout<<"Invalid choice. Please enter a number between 1 and 4."<<endl;
            break;
        }
        }
    }
    return 0;
}