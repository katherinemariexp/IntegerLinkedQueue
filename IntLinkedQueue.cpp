#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include "IntLinkedQueue.h"

using namespace std;

string del = ","; 

void menu()
{
    cout << "\n--- AS9 LinkedQueue Test Menu ---\n"
    << " N - to bulk create New Queue\n"
    << " D - to Display\n"
    << " E - is Empty?\n"
    << " A - to Add ~ push front\n"
    << " a - to append ~ push back\n"
    << " R - to Remove ~ pop front\n"
    << " r - to Remove ~ pop back\n"
    << " G - to get by subscription\n"
    << " P - to put by subscription\n"
    << " L - Length of Queue?\n"
    << " C - to Clear\n"
    << " Q - to Q this program\n"
    << " H - this menu\n";
}

int main() {
    bool stay = true;
    

    cout << "\nInstanciate an object of Queue\n";
  
    IntLinkedQueue q;
    
    cout << "\nFirst, test with hard-wired data sets!\n"
         << "For example, \nyou may use one set of tokens for all test classes: \n";
    string choice; 
    string str;
    int s[] = {1, 3, 5, 7, 9};
    vector<int> input(s, end(s));
    int num;
    
    
    int input_size = input.size();
    for (auto item : input ) {
        cout << item << ((input_size <= 1) ? " " : ", ");
        input_size--;
    }
    cout << endl;
    
    
    for (auto i: input) q.append( i );
    cout << "\nUse menu to test a Queue class instance.\n";
    menu();

    while(stay) { 
        cout << "\n Enter your command: ";
        stay = true;
        cin >> choice;
        cin.ignore();
        int pos;
        string input;
        string token;
        int item;
        stringstream sst;
        stringstream ss;
        int Queue_size;
        
        if(choice.size() == 1) {
            char ch = choice[0];
            vector<string> dump;
            string value;
            switch(ch) { // main menu switch starts
            
                case 'n':
                case 'N':
                {
                    // if(!q.isEmpty()) q.clear();
                    cout << "\t\tEnter a line of comma (,) delmited data set: ";
                    getline (cin, input); // user input -> string
                    ss << input; // string -> stream
                    while ( getline(ss, token, ',') ) { // stream -> string token
                        stringstream sst(token);
                        sst >> item;
                        q.append(item);
                    }
                    break;
                }
                
                case 'd':
                case 'D': q.displayList();
                break;

                case 'e':
                case 'E': q.isEmpty();
                break;
                
                case 'A': 
                {
                    cout << "Enter a number: ";
                    cin >> num;
                    cout << "You have entered: " << num << endl;
                    q.add(num);
                    q.displayList();
                    break;
                }
                
                
                case 'q': // exit Queue sub-menu
                case 'Q':
                    stay = false;
                    break;
                
                case 'h': // help - display menu
                case 'H':
                case '?':
                    menu();
                    break;
                
                default:
                    cout << "\nInvalid Selection!\nTry again!\n\n";
            
            } // end of menu switch
        } // only process single character
    } // end of main menu while
    cout << "Program exit!\n";
} // end of main