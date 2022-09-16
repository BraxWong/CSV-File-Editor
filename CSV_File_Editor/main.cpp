#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <limits>
#include <bits/stdc++.h>
using namespace std;
//File class, it contains two public method: dataEntry() and readFile()
class File {
    public:
        void dataEntry();
        void readFile(string fileName);
        void editFile(string fileName);
        void totalSpent(string fileName);
};

void File::totalSpent(string fileName) {
    ifstream object;
    int count = 0, total = 0;
    object.open(fileName);
    while(object.good()){
        string line;
        if(count >= 5){
            getline(object,line,',');
            total = stoi(line);
            count = 0;
            while(true){
                if(count == 2){
                    count = 0;
                    getline(object,line,',');
                    total += stoi(line);
                }
                getline(object,line,',');
                count++;
                if(!object.good()){
                    break;
                }
            }
            
        }
        getline(object,line,',');
        ++count;
    }
    cout <<"$" << total << endl;
    readFile(fileName);
}
void File::editFile(string fileName) {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    //Save the file as string
    string save,line,newString;
    int count = 0;
    ifstream object;
    object.open(fileName);
    while(object.good()){
        getline(object,save,'\n');
        line+=save;
    }
    //Close the file
    object.close();

    //Create a new file
    ofstream something;
    something.open(fileName);
    stringstream newLine(line);
    while(getline(newLine,newString,',')){
        if(count == 3){
            something << endl;
            count = 0;
        }
        something << newString << ",";
        count++;
    }
    something << endl;
    while(true){
        cout << "Please enter the date of purchase\n";
        getline(cin,line);
        something << line << ',';
        cout << "Please enter the item that you bought\n";
        getline(cin,line);
        something << line << ',';
        cout << "Please enter the price that you bought it for\n";
        getline(cin,line);
        something << line << ',';
        cout << "Q to quit, C to continue\n";
        getline(cin,line);
        if(line == "Q"){
            break;
        }
        else {
            something << endl;
        }
    }
    something.close();
}
//readFile() reads the file and prints out everything that is in it
void File::readFile(string fileName) {
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
    cout << endl;
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
    string fileName;
    cout << "Welcome to CSV File Editor (Version 1.0.0) Brax's Prduction.\nPlease enter the name of the file that you would like to access.\n";
    getline(cin,fileName);
    while(true){
        cout << "Menu:\nPress 1: Create a new file\nPress 2: Read a file\nPress 3: Edit a file\nPress 4: Total Spent\nPress 5: Exit\n";
        cin >> num;
        File file;
        if(num == 1){
            file.dataEntry();
        }
        else if(num == 2){
            file.readFile(fileName);
        }
        else if(num ==3) {
            file.editFile(fileName);
        }
        else if(num == 4){
            file.totalSpent(fileName);
        }
        else if(num == 5){
            break;
        }
        else {
            cout << "Its either 1 or 2.\n";
            break;
        }
    }
    system("Pause");
    return 0;
}
