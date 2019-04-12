/* VERSION 2
 * This is a program that collects a list of integers and allows the user to select options from a menu
 * to perform operations on the list
 *
 *  P - Print numbers
 *  A - Add a number
 *  M - display mean of numbers
 *  S - display smallest number
 *  L - display largest number
 *  Q - quit
 *
 * Accepts upper and lowercase letters
 */

// A refactored version that eliminates global variables and instead
// creates the integer vector in main and passes it to all the functions

#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::vector;

bool checkEmpty(vector<int>& int_storage)
{
    bool is_empty{ false };
    (int_storage.size() == 0) ? (is_empty = true) : (is_empty = false);
    return is_empty;

    // Slimmed down the code below to the above code
    //    bool is_empty{ false };
    //    if(int_storage.size() == 0) {
    //        is_empty = true;
    //    } else
    //        is_empty = false;
}
void minNum(vector<int>& int_storage)
{
    bool is_empty = checkEmpty(int_storage);
    if(is_empty) {
        cout << "\nUnable to determine the smallest number - list is empty\n" << endl;
    } else {
        int min_temp = int_storage.at(0);
        for(unsigned int i{}; i < int_storage.size(); i++) {
            if(min_temp > int_storage.at(i)) {
                min_temp = int_storage.at(i);
            }
        }
        cout << "\nThe smallest number is: " << min_temp << "\n" << endl;
    }
}

void maxNum(vector<int>& int_storage)
{
    bool is_empty = checkEmpty(int_storage);
    if(is_empty) {
        cout << "\nUnable to determine the largest number - list is empty\n" << endl;
    } else {
        int max_temp = int_storage.at(0);
        for(unsigned int i{}; i < int_storage.size(); i++) {
            if(max_temp < int_storage.at(i)) {
                max_temp = int_storage.at(i);
            }
        }
        cout << "\nThe largest number is: " << max_temp << "\n" << endl;
    }
}

void meanNum(vector<int>& int_storage)
{
    int sum{};
    double mean{};
    bool is_empty = checkEmpty(int_storage);
    if(is_empty) {
        cout << "\nUnable to determine the mean of numbers - list is empty\n" << endl;
    } else {
        for(int elem : int_storage) {
            sum += elem;
        }
        mean = (static_cast<double>(sum) / int_storage.size());
        cout << "\nThe mean is " << mean << "\n" << endl;
    }
}

void addNum(vector<int>& int_storage)
{
    int num_to_add{};
    cout << "Enter number to be added: ";
    cin >> num_to_add;
    int_storage.push_back(num_to_add);
    cout << "\n"
         << num_to_add << " was added."
         << "\n"
         << endl;
}
void printNum(vector<int>& int_storage)
{
    if(int_storage.size() == 0) {
        cout << "[] - the list is empty"
             << " \n"
             << endl;
    } else {
        cout << "[";
        for(int elem : int_storage) {
            cout << elem << " ";
        }
        cout << "\b]"
             << " \n"
             << endl;
    }
}
void display_menu(vector<int>& int_storage)
{
    char selection{};
    bool terminate{ false };
    do {
        cout << "P - Print numbers" << endl;           // finished
        cout << "A - Add a number" << endl;            // finished
        cout << "M - Display mean of numbers" << endl; // finished
        cout << "S - Display smallest number" << endl; // finished
        cout << "L - Display largest number" << endl;  // finished
        cout << "Q - Quit" << endl; // had a problem with getting program to terminate, so had this correspond with a
                                    // boolean val instead
        cout << " \nMake a selection: ";
        cin >> selection;
        switch(selection) {
        case 'p':
        case 'P': {
            printNum(int_storage);
            break;
        }
        case 'a':
        case 'A': {
            addNum(int_storage);
            break;
        }
        case 'm':
        case 'M': {
            meanNum(int_storage);
            break;
        }
        case 's':
        case 'S': {
            minNum(int_storage);
            break;
        }
        case 'l':
        case 'L': {
            maxNum(int_storage);
            break;
        }
        case 'q':
        case 'Q': {
            cout << "\nProgram terminated.\n" << endl;
            terminate = true;
            break;
        }
        default:
            cout << "\nInvalid selection, please make another.\n" << endl;
        }
    } while(terminate == false);
}
int main()
{
    vector<int> int_storage{};
    display_menu(int_storage);
    return 0;
}