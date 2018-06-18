#include <iostream>
#include <fstream>
#include <string>
#include "cards.h"

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
        cout << "Please enter your answer here: ";
        
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
   
    ofstream fout;
    fout.open("gamelog.txt");
    
    Player user(100);
    Player computer(900);
    
    
    Hand h_user(0);
    Hand h_computer(0);
    
    cout << "Starting fund: " << user.get_fund() << " pesos" << endl;
    
    int bet;
    
    while(true)
    {
        cout << "Please enter the amount you would like to bet: ";
        cin >> bet;
        cout << endl;
        
        if(bet > user.get_fund())
            cout << "That's more than you have! Nice try." << endl;
        else
            break;
    }
    
    do
    {
        cout << "Draw a card? (y/n): ";
        char answer;
        cin >> answer;
        string remainder;
        getline(cin, remainder);
        
        if(answer == 'y')
        {
            Card temp1 = Card();
            h_user.add_card(temp1);
            
            Card temp2 = Card();
            h_computer.add_card(temp2);
            
            cout << "You have drawn " << temp1.get_spanish_rank() << " de " << temp1.get_spanish_suit()
            << "     (" << temp1.get_english_rank() << " of " << temp1.get_english_suit() << ")" << endl;
            
            cout << "You currently have " << h_user.get_total() << " points" << endl;
            cout << endl;
        }
        else
        {
            if(h_user.get_total() > 7.5)
            {
                if(h_computer.get_total() > 7.5)
                {
                    user.set_fund(user.get_fund() - bet);
                    cout << "House advantage! You lose..." << endl;
                }
                else
                {
                    user.set_fund(user.get_fund() - bet);
                    cout << "You bursted! Your opponent has " << h_computer.get_total() << " points. You lose!" << endl;
                }
            }
            else
            {
                if(h_computer.get_total() > 7.5)
                {
                    user.set_fund(user.get_fund() + bet);
                    cout << "Your opponent bursted! You win this round. Congratulations!" << endl;
                }
                else
                {
                    if(7.5 - h_user.get_total() < 7.5 - h_computer.get_total())
                    {
                        user.set_fund(user.get_fund() + bet);
                        cout << "You are closer to siete y medio! You win this round. Congratulations!" << endl;
                    }
                    else
                    {
                        user.set_fund(user.get_fund() - bet);
                        cout << "Your opponent is closer to siete y medio! You looooose this round." << endl;
                    }
                }
            }
        }
    }
    while(user.get_fund() > 0 && computer.get_fund() > 0);
    
    fout.close();
}

void print_log()
{
    cout << endl;
    cout << "---------History----------" << endl;
    
    ifstream fin;
    fin.open("gamelog.txt");
    
    while(fin.is_open())
    {
        cout << fin.rdbuf();
        fin.close();
    }
    
    cout << endl;
    cout << "--------------------------" << endl;
    
    cout << "Return to menu (press 1)" << endl;
    cout << "Exit (press 2)" << endl;
    cout << "--------------------------" << endl;
    cout << "Please enter your answer here: ";
    
    int answer = 0;
    
    do
    {
        cin >> answer;
        
        if(answer == 1)
        {
            cout << endl;
            return;
        }
        if(answer == 2)
            exit(0);
        else
            cout << "Not a valid answer. Please try again: ";
    }
    while(answer != 1 && answer != 2);
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
