#include <iostream>
#include <fstream>
#include <string.h>

//using namespace std; *Disabled for following good practices*

//Menu Functions
void login();
void registration();
void forgot();

//Command-line menu interface
int main()
{

    int i;
    cout<<"\t\t\t__________________________________________________________\n\n\n";
    cout<<"\t\t\t                        Welcome!!                           \n\n\n";
    cout<<"\t\t\t_______________________    MENU         ________________________\n\n";
    cout<<"                                                                     \n\n";
    cout<<"\t| Press 1 to LOGIN                    |"<<endl;
    cout<<"\t| Press 2 to REGISTER                 |"<<endl;
    cout<<"\t| Press 3 if you forgot your PASSWORD |"<<endl;
    cout<<"\t| Press 4 to EXIT                     |"<<endl;
    cout<<"\n\t\t\t Please enter your choice : ";
    cin>>i;
    cout<<endl;
    
    //The switch statement allows to execute a block of code among many alternatives
    switch(i)
    {
        case 1:
            login();
            break;

        case 2:
            registration();
            break;

        case 3:
            forgot();
            break;

        case 4:
            cout<<"\t\t\t Thanky you \n\n";
            break;
        default:
            system("CLS"); //function to clear the window
            cout<<"\t\t\t Please select from the options give above\n"<<endl;
            main();
    }
}

void login()
{
    int count;
    string userId, password, id, pass;
    system("CLS");
    cout<<"\t\t\t Please enter the username and password : "<<endl;
    cout<<"\t\t\t USERNAME ";
    cin>>userId;
    cout<<"\t\t\t PASSWORD ";
    cin>>password;

    //Function to read data from a file
    ifstream input("records.txt"); // Declare an ifstream object named "input"

    while(input>>id>>pass){

            if(id==userId && pass==password){

                    count=1;
                    system("CLS");
            }
    }

    input.close(); 

    if(count==1){
        cout<<userId<<"\n Your LOGIN is successfull\n Thanks ! \n";
        main();
    }
    else{
        cout<<"\n LOGIN ERROR \n Please check your username and password\n";
        main();
    }

}

void registration(){

    string ruserId, rpassword, rid, rpass;
    system("CLS");
    cout<<"\t\t\t Enter the username : ";
    cin>>ruserId;
    cout<<"\t\t\t Enter the password : ";
    cin>>rpassword;
    
    //Function to create the file and write the data
    ofstream f1("records.txt", ios::app); // Declare an ofstream object named "f1"
    f1<<ruserId<<rpassword<<endl;
    system("CLS");
    cout<<"\n\t\t\t Registration is successfull! \n";
    main();

}

void forgot(){
    int option;
    system("CLS");
    cout<<"\t\t\t You forgot the password? \n";
    cout<<"Press 1 to search your id by username"<<endl;
    cout<<"Press 2 to go back to the main menu"<<endl;
    cout<<"\t\t\t Enter your choice :";
    cin>>option;

     switch(option){

        case 1:{

            int count=0;
            string suserId, sId, spass;
            cout<<"\n\t\t\t Enter the username which you remember :";
            cin>>suserId;

            ifstream f2("records.txt");

            while(f2>>sId>>spass){

                if(sId==suserId){

                    count=1;
                }
            }
            f2.close();
            if(count==1){
                cout<<"\n\n Your account is found! \n";
                cout<<"\n\n Your password is :"<<spass <<endl;
                main();
            }
            else{
                cout<<"\n\t Sorry! Your account is not found! \n";
                main();
            }
            break;


        }

            case 2 : {

                main();

            }
            default:
                cout<<"\t\t\t Wrong choice ! Please try again "<<endl;
                forgot();
    }
}
