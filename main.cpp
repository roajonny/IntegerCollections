/* This is a program that collects a list of integers and allows the user to select options from a menu
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
#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::vector;

char selection{};
vector<int> int_storage{};
bool is_empty{ false };

void checkEmpty()
{
    if(int_storage.size() == 0) {
        is_empty = true;
    } else
        is_empty = false;
}
void minNum()
{
    checkEmpty();
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

void maxNum()
{
    checkEmpty();
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

void meanNum()
{
    int sum{};
    double mean{};
    checkEmpty();
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

void addNum()
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
void printNum()
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
int main()
{
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
            printNum();
            break;
        }
        case 'a':
        case 'A': {
            addNum();
            break;
        }
        case 'm':
        case 'M': {
            meanNum();
            break;
        }
        case 's':
        case 'S': {
            minNum();
            break;
        }
        case 'l':
        case 'L': {
            maxNum();
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

    return 0;
}
