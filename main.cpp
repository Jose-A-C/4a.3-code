#include <cstdlib>
#include <string>
#include <iostream>
#include <limits>
#include <iomanip>
#include <ostream>
#include <algorithm>
#include <cctype>
#include <fstream>

using namespace std;
// function calls for all of the screens
string checkIfNumGreaterThanZero(string thing);
bool checkIfNum(string num);
void num_error_scrn();
void title_scrn();
void exit_scrn();
void var_error_scrn();
void menu_scrn();
void input_scrn();
void edit_scrn();
string inputMethod(string ISBN,string Title, string Author, string EnrollmenT, string Costs, string Required, string NewOrUsed);
string output_scrn(string ISBN, string title, string author, string cost, string enrollment, string ReqOrNot, string newOrUsed);


int main()
{
    //--------  Start of variable and object creation ------
    string dummy = "xxxx";
    string ISBN = "XXXX"; //ISBN of book
    string title= "XXXX"; //title of book
    string author= "XXXX"; // author of book
    string enrollment = "XXXX"; // enrollment amount
    string cost = "XXXX"; // cost of book
    string ReqOrNot= "XXXX"; // If the book is required or not
    string newOrUsed= "XXXX"; // if the book is new or not
    string printString= "XXXXX";// used get input from the user on whether they want to print their data 


    int timelock =0;
    //--------  End of variable declarations -----------------------

            title_scrn();//calls upon the title screen function

    //--------  End of the Splash Screen  --------------------------
    
	//Transition to next screen
	cout << "                          Press <ENTER> to Continue";
	cin.get();
	//End of transition

    //--------  Start of main menu screen ------
            menu_scrn();//calls upon the menu screen function
    //--------  end of main menu screen ------
char choice; 
do {
cin >> choice;


    switch(choice){
        case 'i':
        case 'I':
        {
            //--------  Start of Input Screen  -----------------------------
                input_scrn();// calls upon the input screen function

              // getting the input of the user for the required information 
              
              cout << "     ISBN:  ";std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');getline(cin, ISBN);

              cout << "     TITLE:  "; getline(cin, title);

              cout << "     AUTHOR:  "; getline(cin, author); 

              cout << "     COST:  "; getline(cin, cost); 
                            cost = checkIfNumGreaterThanZero(cost);// calls upon the function/method that to check if the number is greater than 0

              cout << "     ENROLLMENT AMOUNT: ";getline(cin, enrollment);
                            enrollment = checkIfNumGreaterThanZero(enrollment);// calls upon the function/method that to check if the number is greater than 0

              cout << "     REQUIRED(Yes or No):  "; getline(cin, ReqOrNot);
              
              cout << "     NEW/USED(New or Used):  "; getline(cin, newOrUsed);

//--------  End of the Input Screen  --------------------------

	          //Transition to next screen
	          cout << "                          Press <ENTER> to Continue";
	          cin.get();
              menu_scrn();
              continue;
	         //End of transition
        }


        
    //--------  Case for Output Screen  -----------------------------
    case 'O':
    case 'o':
    {  
     cout << "\x1b[2J"; // clears terminal for vs code
     //system("cls");   //if your not using VS code replace cout << "\x1b[2J"; with this code instead
    cout << output_scrn( ISBN, title, author, cost, enrollment, ReqOrNot, newOrUsed) << endl;
    cout << "to print onto a .prn file please type <print> otherwise you will be returned to the main menu" << endl;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    getline(cin, printString);  
    //initiates, clears previous inputs, then set the toprint variable to the userinput  

    if (printString == "Print" || printString == "print" || printString == "P" || printString == "p") {
    ofstream outfile("output.prn", ios::trunc);// to create file

    outfile << output_scrn( ISBN, title, author, cost, enrollment, ReqOrNot, newOrUsed);//to print things onto the file

    outfile.close();// closes the file

    cout << "\x1b[2J";
    cout << "...file updated..." << endl;
    }
    // the if statement will check if the user typed yes
    // if true, then the code will clear the prn file for any previous inputs, then prints out the output to the output.prn file


//--------  End of the Output Screen  --------------------------

	          //Transition to next screen
	          cout << "                          Press <ENTER> to return";
	          cin.get();
              menu_scrn();
              continue;
	         //End of transition
    }

//-------- Case for Edit Screen  -----------------------------
case 'e':
case 'E':
{
//-------- Start of Edit Screen  -----------------------------
    edit_scrn();//calls upon the edit screen function 

    char editChoice;
    cin >> editChoice;

    switch(editChoice){ // switch case choices which take the input from the user to replace the chosen data
            case '1':
            {
                cout << "new ISBN:" << endl;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                getline(cin, ISBN);
                break;
            }
            case '2':
            {
                cout << " new TITLE:" << endl;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                getline(cin, title);
                break;
                
            }
            case '3':
            {
                cout << "new AUTHOR:" << endl;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                getline(cin, author);    
                break;       
            }
            case '4':
            {
                cout << "new COST:" << endl;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                getline(cin, cost);  
                break;   
                
                
            }
            case '5':
            {
                cout << "new ENROLLMENT:" << endl;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                getline(cin, enrollment);
                break;
                
            }
            case '6':
            {
                cout << "change if NEW or USED:" << endl;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                getline(cin, newOrUsed);
                break;
                
            }
            case '7':
            {
                cout << "change if REQUIRED:" << endl;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                getline(cin, ReqOrNot);
                break;
            }
            case 'q':
            {
                break;
            }
            default:
            {
               //
            }
    }
            //    transition/
    	      cout << "                          Press <ENTER> to return";
	          cin.get();
              menu_scrn();
              continue;
}





//-------- Case for Exit Screen  -----------------------------

        case 'Q':
        case 'q':
              exit_scrn();//calls upon the exit screen function
              timelock++;
	          break;

        default:
            var_error_scrn();
        
    }   
    } 
    while (timelock <=0 );
    return 0;



}


void title_scrn(){ //This the title screen method that is called upon at the start of the code.

       cout << "\x1b[2J"; // clears terminal for vs code
     //system("cls");   //if your not using VS code replace cout << "\x1b[2J"; with this code instead
    //--------  Beginning of the Splash Screen   -------------------

              cout << "  _______________________________________________________  " << endl;
              cout << "  |                                                     |  " << endl;
              cout << "  |                                                     |  " << endl;
              cout << "  |    M I R A M A R   C O L L E G E   B O O K          |  " << endl;
              cout << "  |                                                     |  " << endl;
              cout << "  |       O R D E R I N G   S Y S T E M                 |  " << endl;
              cout << "  |                                                     |  " << endl;
              cout << "  |                                                     |  " << endl;
              cout << "  |             by Jose Chavez                          |  " << endl;
              cout << "  |                                                     |  " << endl;
              cout << "  |                                                     |  " << endl;
              cout << "  |_____________________________________________________|  " << endl;
              cout << "                                                           " << endl;
}//End of title_scrn

void menu_scrn(){//this is the menu screen method that is called for the menu screen 
               cout << "\x1b[2J"; // clears terminal for vs code
    //system("cls");   //if your not using VS code replace cout << "\x1b[2J"; with this code instead

              cout << "  _________________________________________________________ " << endl;
              cout << "  |                                                       |  " << endl;
              cout << "  |                                                       |  " << endl;
              cout << "  |     M I R A M A R   C O L L E G E   B O O K           |  " << endl;
              cout << "  |                                                       |  " << endl;
              cout << "  |        O R D E R I N G   S Y S T E M                  |  " << endl;
              cout << "  |                                                       |  " << endl;
              cout << "  |                                                       |  " << endl;
              cout << "  |   To enter the Input screen please type <I> or <i>.   |  " << endl;
              cout << "  | To view the the output screen please type <O> or <o>. |  " << endl;
              cout << "  |   To enter the edit screen please type <E> or <e>.m   |  " << endl;
              cout << "  |     To exit the program please type <Q> or <q>.       |  " << endl;
              cout << "  |                                                       |  " << endl;
              cout << "  |                                                       |  " << endl;
              cout << "  |_______________________________________________________|  " << endl;
              cout << "                                                             " << endl;

}
void input_scrn(){
    cout << "\x1b[2J"; // clears terminal for vs code
    //system("cls");   //if your not using VS code replace cout << "\x1b[2J"; with this code instead

              cout << "  _______________________________________________________  " << endl;
              cout << "  |                                                     |  " << endl;
              cout << "  |                                                     |  " << endl;
              cout << "  |    M I R A M A R   C O L L E G E   B O O K          |  " << endl;
              cout << "  |                                                     |  " << endl;
              cout << "  |       O R D E R I N G   S Y S T E M                 |  " << endl;
              cout << "  |                                                     |  " << endl;
              cout << "  |                                                     |  " << endl;
              cout << "  |    Enter the required information that is asked.    |  " << endl;
              cout << "  |              press <ENTER> after each.              |  " << endl;
              cout << "  |                                                     |  " << endl;
              cout << "  |                                                     |  " << endl;
              cout << "  |_____________________________________________________|  " << endl;
              cout << "                                                           " << endl;
}

void edit_scrn(){
         cout << "\x1b[2J"; // clears terminal for vs code
     //system("cls");   //if your not using VS code replace cout << "\x1b[2J"; with this code instead

              cout << "  _______________________________________________________  " << endl;
              cout << "  |                                                     |  " << endl;
              cout << "  |                                                     |  " << endl;
              cout << "  |    M I R A M A R   C O L L E G E   B O O K          |  " << endl;
              cout << "  |                                                     |  " << endl;
              cout << "  |       O R D E R I N G   S Y S T E M                 |  " << endl;
              cout << "  |                                                     |  " << endl;
              cout << "  |                                                     |  " << endl;
              cout << "  |      What would you like to change?                 |  " << endl;
              cout << "  |                                                     |  " << endl;
              cout << "  |                                                     |  " << endl;
              cout << "  |     To change the ISBN press <1>                    |  " << endl; 
              cout << "  |     To change the TITLE press <2>                   |  " << endl;
              cout << "  |     To change the AUTHOR press <3>                  |  " << endl;
              cout << "  |     To Change the COST press <4>                    |  " << endl;
              cout << "  |     To change the ENROLLMENT AMOUNT press <5>       |  " << endl;
              cout << "  |     To change if it is REQUIRED press <6>           |  " << endl;
              cout << "  |     To change whether it is NEW/USED press <7>      |  " << endl;
              cout << "  |                                                     |  " << endl;;
              cout << "  |_____________________________________________________|  " << endl;
              cout << "                                                           " << endl;
}

void exit_scrn(){
    
    cout << "\x1b[2J"; // clears terminal for vs code
    //system("cls");   //if your not using VS code replace cout << "\x1b[2J"; with this code instead

              cout << "  _______________________________________________________  " << endl;
              cout << "  |                                                     |  " << endl;
              cout << "  |                                                     |  " << endl;
              cout << "  |    M I R A M A R   C O L L E G E   B O O K          |  " << endl;
              cout << "  |                                                     |  " << endl;
              cout << "  |       O R D E R I N G   S Y S T E M                 |  " << endl;
              cout << "  |                                                     |  " << endl;
              cout << "  |                                                     |  " << endl;
              cout << "  |         Thank you for using this program.           |  " << endl;
              cout << "  |              press <ENTER> to exit.                 |  " << endl;
              cout << "  |                                                     |  " << endl;
              cout << "  |                                                     |  " << endl;
              cout << "  |_____________________________________________________|  " << endl;
              cout << "                                                           " << endl;
}//End of exit_scrn

void num_error_scrn(){ // this is the error screen that is called upon when inputting the wrong value

    cout << "\x1b[2J"; // clears terminal for vs code
    //system("cls");   //if your not using VS code replace cout << "\x1b[2J"; with this code instead

              cout << "  _______________________________________________________  " << endl;
              cout << "  |                                                     |  " << endl;
              cout << "  |                                                     |  " << endl;
              cout << "  |    M I R A M A R   C O L L E G E   B O O K          |  " << endl;
              cout << "  |                                                     |  " << endl;
              cout << "  |       O R D E R I N G   S Y S T E M                 |  " << endl;
              cout << "  |                                                     |  " << endl;
              cout << "  |                                                     |  " << endl;
              cout << "  |                       ERROR                         |  " << endl;
              cout << "  |        Invalid input. Please input a number         |  " << endl;
              cout << "  |                  Greater than 0.                    |  " << endl;
              cout << "  |                                                     |  " << endl;
              cout << "  |_____________________________________________________|  " << endl;
              cout << "                                                           " << endl;

}//End of num_error_scrn

void var_error_scrn(){ // this is the error screen that is called upon when inputting the wrong value

    cout << "\x1b[2J"; // clears terminal for vs code
    //system("cls");   //if your not using VS code replace cout << "\x1b[2J"; with this code instead

              cout << "  _______________________________________________________  " << endl;
              cout << "  |                                                     |  " << endl;
              cout << "  |                                                     |  " << endl;
              cout << "  |    M I R A M A R   C O L L E G E   B O O K          |  " << endl;
              cout << "  |                                                     |  " << endl;
              cout << "  |       O R D E R I N G   S Y S T E M                 |  " << endl;
              cout << "  |                                                     |  " << endl;
              cout << "  |                                                     |  " << endl;
              cout << "  |                       ERROR                         |  " << endl;
              cout << "  |       Invalid input. Please enter one of the        |  " << endl;
              cout << "  |     mentioned values from the previous screen.      |  " << endl;
              cout << "  |_____________________________________________________|  " << endl;
              cout << "                                                           " << endl;

}//End of num_error_scrn

string output_scrn(string ISBN, string title, string author, string cost, string enrollment, string ReqOrNot, string newOrUsed){
    double newCost = 0.0; // new cost variable for atof conversion
    int newEnrollment = 0; // new enrollment variable for atoi conversion
    double order_factor = 0.0; // order factor
    double totalValue = 0.0; // total cost of books needed
    int numBooks = 0.0; // number of books needed

        newEnrollment = atoi(enrollment.data()); // to convert enrollment from string to int      

        newCost = atof(cost.data()); // to conver cost from string to double

              if(newOrUsed == "N" || newOrUsed == "n") {

                if(ReqOrNot == "Y" || ReqOrNot == "y")

                order_factor = 1.0;   // Book is new and required

                else

                order_factor = 0.35;  // Book is new but not required
              }

            else {

                if(ReqOrNot == "Y" || ReqOrNot == "y")

                order_factor = 0.6;  // Book is not new but is required

                else

                order_factor = 0.1;  // Book is not new and is not required
            }
    // end of price calculation for new or used
               numBooks = newEnrollment*order_factor;
               totalValue = numBooks*newCost;
              stringstream outputScreen; 
              outputScreen << "  _______________________________________________________  " << endl;
              outputScreen << "  |                                                     |  " << endl;
              outputScreen << "  |                                                     |  " << endl;
              outputScreen << "  |    M I R A M A R   C O L L E G E   B O O K          |  " << endl;
              outputScreen << "  |                                                     |  " << endl;
              outputScreen << "  |       O R D E R I N G   S Y S T E M                 |  " << endl;
              outputScreen << "  |                                                     |  " << endl;
              outputScreen << "  |                                                     |  " << endl;
              outputScreen << "  |                                                     |  " << endl;
              outputScreen << "  |                                                     |  " << endl;
              outputScreen << "  |                                                     |  " << endl;
                                    // has all of the expected outputs printed on the screen
              outputScreen << "  |     ISBN: " << ISBN << endl; 
              outputScreen << "  |     TITLE: " << title  << endl;
              outputScreen << "  |     AUTHOR: " << author  << endl;
              outputScreen << "  |     COST: " << cost << endl; cout<< " $" << endl;
              outputScreen << "  |     ENROLLMENT AMOUNT: " <<enrollment << endl;
              outputScreen << "  |     REQUIRED: " <<ReqOrNot << endl;
              outputScreen << "  |     NEW/USED: " <<newOrUsed << endl;
              outputScreen << "  |     Number of Books to order: " << numBooks << endl;
              outputScreen << "  |     inventory value of the books: " << totalValue << endl; cout << " $ " << endl;
              outputScreen << "  |                                                     |  " << endl;
              outputScreen << "  |                                                     |  " << endl;
              outputScreen << "  |                                                     |  " << endl;
              outputScreen << "  |                                                     |  " << endl;
              outputScreen << "  |                                                     |  " << endl;
              outputScreen << "  |                                                     |  " << endl;
              outputScreen << "  |                                                     |  " << endl;
              outputScreen << "  |                                                     |  " << endl;
              outputScreen << "  |                                                     |  " << endl;
              outputScreen << "  |                                                     |  " << endl;
              outputScreen << "  |_____________________________________________________|  " << endl;
              outputScreen << "                                                           " << endl;

    return outputScreen.str();
}

string checkIfNumGreaterThanZero(string thing) { //used to check if the input is greater than zero with a while loop

    while((std::atoi(thing.c_str()) <= 0) || checkIfNum(thing)){//converts the string into an int and also checks to see if it is greater than 0 

        num_error_scrn(); std::getline(std::cin, thing);//calls the error screen forward and tries to get a response from the user

    }

    return thing;
}//End Of checkIfNumGreaterThanZero


bool checkIfNum (string num){ //used to check if input is a letter. used to check that the input for Price and enrollment is numbers not letters
if (!num.empty() && std::isalpha(num[0])) { //check that the value isn't empty and check if it is a letter
    return true;
}
else {
    return false;
}
}