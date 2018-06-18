#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void game_start();
void print_log();
void error_message();

int main()
{
    bool more = true;
    
    while(more)
    {
        cout << "-----------Menu-----------" << endl;
        cout << "Start a new game (press 1)" << endl;
        cout << "View history (press 2)" << endl;
        cout << "Exit (press 3)" << endl;
        cout << "--------------------------" << endl;
        cout << "Please enter our answer here: ";
        
        int answer = 0;
        cin >> answer;
        
        if(answer == 1)
            game_start();
        else if(answer == 2)
            print_log();
        else if(answer == 3)
            more = false;
        else
        {
            error_message();
        }
    }
    
    return 0;
}

void game_start()
{
    cout << endl;
    cout << "The game has started." << endl;
    
    ofstream fout;
    fout.open("gamelog.txt");
    
    fout << "Blah blah blah";
    
    fout.close();
}

void print_log()
{
    cout << endl;
    cout << "----------History----------" << endl;
    
    ifstream fin;
    fin.open("gamelog.txt");
    
    while(fin.is_open())
    {
        cout << fin.rdbuf();
        fin.close();
    }
    
    cout << endl;
    cout << "--------------------------" << endl;
    cout << endl;
}

void error_message()
{
    bool more = true;
    
    while(more)
    {
        cout << "There has been an error. Please make a valid choice: ";
        
        int answer = 0;
        cin >> answer;
        
        if(answer == 1)
        {
            more = false;
            game_start();
        }
        else if(answer == 2)
        {
            more = false;
            print_log();
        }
        else if(answer == 3)
            exit(0);
    }
}
