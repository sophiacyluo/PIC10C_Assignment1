#include <iostream>

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
            more = false;
            error_message();
        }
    }
    
    return 0;
}

void game_start()
{
    cout << "The game has started." << endl;
}

void print_log()
{
    cout << "Print log" << endl;
}

void error_message()
{
    bool more = true;
    
    while(more)
    {
        cout << "There has been an error. Please make a valid choice" << endl;
        
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
            more = false;
    }
}
