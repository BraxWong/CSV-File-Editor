#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <limits>
using namespace std;
//File class, it contains two public method: dataEntry() and readFile()
class File {
    public:
        void dataEntry();
        void readFile();
};
//readFile() reads the file and prints out everything that is in it
void File::readFile() {
    //Clears out previous user inputs
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    string fileName;
    //Ask for file name
    cout << "Please enter the name of the file you would like to read(Add .csv at the end)\n";
    getline(cin,fileName);
    //Creating an ifstream object to read the file
    ifstream object;
    object.open(fileName);
    //object.good() returns true when there is still data within the file specified
    while(object.good()){
        string line;
        //getting the line and parse it into line
        getline(object,line,',');
        cout << line << " ";
    }
    //closing the ifstream object
    object.close();
}

//dataEntry() creates a file and allows users to add data into it
void File::dataEntry() {
    //Clear out user inputs
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    string fileName;
    //Ask for file name
    cout << "Please enter the name of the file you would like to create(Add .csv at the end)\n";
    getline(cin,fileName);
    //Creating an ofstream object to store the filename
    ofstream object;
    object.open(fileName);
    string header, cell;
    //While loop for header items
    while(true){
        //Ask for header text
        cout << "(Q to quit) Please enter the header\n";
        getline(cin,header);
        //If the input is Q, exit the method
        if(header == "Q" || header == "q"){
            object << endl;
            break;
        }
        //Else inputting the data
        object << header << ",";
    }
    //while loop for cell items
    while(true){
        cout << "(Q to quit) Please enter the data to store in the cell\n";
        getline(cin,cell);
        if(cell == "Q" || cell == "q"){
            object.close();
            break;
        }
        object << cell;
        while(true){
            //Excel moves to the right if it is a ,
            cout << "Would you like to move to the next column or next row(C/R)\n";
            getline(cin,cell);
            if(cell == "C" || cell == "c"){
                object << ",";
                break;
            }
            //Excels moves down if it is an endl
            else if(cell == "R" || cell == "r"){
                object << endl;
                break;
            }
            else {
                cout << "It is either C or R, try again.\n";
            }
        }
    }
}
int main() {
    int num;
    cout << "Welcome to CSV File Editor (Version 1.0.0) Brax's Prduction.\n";
    while(true){
        cout << "Menu:\nPress 1: Create a new file\nPress 2: Read a file\nPress 3: Files Editting\n";
        cin >> num;
        File file;
        if(num == 1){
            file.dataEntry();
        }
        else if(num == 2){
            file.readFile();
        }
        else {
            cout << "Its either 1 or 2.\n";
            break;
        }
    }
    system("Pause");
    return 0;
}