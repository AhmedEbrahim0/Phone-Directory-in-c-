#include <iostream>
#include<windows.h>
#include<string>
#include<fstream>
using namespace std;

fstream contacts_file;
fstream auth_file;

    // global variable for numbers and names 
    struct contacts{
        int id;
        string name;
        string phone;
    };
    struct auth1{
        int id;
        string username;
        string password;
    };

    contacts con[100];
    auth1   acc[100];

    int error =0;



    // end of global variable for numbers and names 

    // function
    void begin();
    void auth();
    void select (int);
    int menu();
    void login();
    void regisration();
    // end of function


// main function
int main(){
        begin();
        auth();

    }
// end of main function


    // functions

        void begin(){
        system("cls"); 
        system("Color 0B");
        char x=219;
        cout<<"\n\n\n\n";
        cout<<"\t\t\t\t\t\t-----------------------------------------------------\n";
        cout<<"\t\t\t\t\t\t-----------------------------------------------------\n";
        cout<<"\t\t\t\t\t\t--------------Phone Directory project ---------------\n";
        cout<<"\t\t\t\t\t\t-----------------------------------------------------\n";
        cout<<"\t\t\t\t\t\t-----------------------------------------------------\n";
        cout<<"\t\t\t\t\t\tLoading ";
        for(int i=0;i<35;i++){
                cout<<x;
            if(i>=0 && i<10)
                Sleep(200);
            else if(i>=10 && i<20)
                Sleep(100);
            else if(i>=20 && i<30)
                Sleep(70);
            else if(i>=30 && i<40)
                Sleep(30);
        }
        system("cls");
        }

        void auth(){
        system("cls");
        int num;
        cout<<"\n\n\n\n\n";
        cout<<"\t\t\t\t\t------------------------------------------------------\n";
        cout<<"\t\t\t\t\t -------------------- PHONE DIRECTORY ----------------\n";
        cout<<"\t\t\t\t\t------------------------------------------------------\n";
        cout<<"\t\t\t\t\t | [1] have an account                               |\n";
        cout<<"\t\t\t\t\t | [2] Add a new account                             |\n";
        cout<<"\t\t\t\t\t------------------------------------------------------\n";
        cout<<"\t\t\t\t\t------------------------------------------------------\n";
        cout<<"\t\t\t\t\t  enter number  from 1 : 2  ";
        cin>>num;
        if(num==1){
            login();
        }else if(num==2){
            regisration();
        }
        auth();
    }




        int menu(){
                        error=0;
        system("Color 0B");
    cout<<"\n\n\n\n\n\n\n";
    cout<<"\t\t\t\t\t\t\t-----------------------------------------\n";
    cout<<"\t\t\t\t\t\t\t---------PHONE DIRECTORY PROCESS  -------\n";
    cout<<"\t\t\t\t\t\t\t-----------------------------------------\n";
    cout<<"\t\t\t\t\t\t\t- |  [1] Add contacts                  |-\n";
    cout<<"\t\t\t\t\t\t\t- |  [2] Show All contacts             |-\n";
    cout<<"\t\t\t\t\t\t\t- |  [3] search  by name               |-\n";
    cout<<"\t\t\t\t\t\t\t- |  [4] search by number              |-\n";
    cout<<"\t\t\t\t\t\t\t- |  [5] update by name                |-\n";
    cout<<"\t\t\t\t\t\t\t- |  [6] update by number              |-\n";
    cout<<"\t\t\t\t\t\t\t- |  [7] delete                        |-\n";
    cout<<"\t\t\t\t\t\t\t- |  [8] Delete  All contacts          |-\n";
    cout<<"\t\t\t\t\t\t\t-----------------------------------------\n";
    cout<<"\t\t\t\t\t\t\t   |  [9] Exit                          |\n";
    cout<<"\t\t\t\t\t\t\t-----------------------------------------\n";
    
    cout<<"enter number from 1 to 9 :  ";
    int number;
    cin>>number;
    select (number);

}



        void select (int num){
    
        if(num==1){
        string name;
        string number;
        // this variable to sum the count of contacts 
        int i=0;

        contacts_file.open("contact.txt",ios::in);
        while(contacts_file>>con[i].id && contacts_file>>con[i].name && contacts_file>>con[i].phone){
            i++;
        }
        contacts_file.close();

        // here you bring the last id of contacts and plus one for new contact
        con[i].id=con[i-1].id + 1 ;
        cout<<"\t\t\t\t\t name : ";
        cin>>con[i].name;
        cout<<"\t\t\t\t\t phone : ";
        cin>>con[i].phone;

        contacts_file.open("contact.txt",ios::app);
        contacts_file<<con[i].id<<endl;
        contacts_file<<con[i].name<<endl;
        contacts_file<<con[i].phone<<endl;
        contacts_file.close();            
        system("Color 74");
        cout<<"\t\t\t\t\t ********************************************\n";
        cout<<"\t\t\t\t\t ****|    store has been successfully   |****\n";
        cout<<"\t\t\t\t\t ********************************************\n";
        Sleep(2000);
        system("cls");

        menu();
    }

        else if(num==2){
            // system("cls");
            int i=0;
            error=0;
                cout<<"\n\n\n\n\n\n-------------------- your contacts ----------------\n";
                cout<<"----------------------------------------------------\n\n";

            contacts_file.open("contact.txt",ios::in);
            while (contacts_file>>con[i].id &&contacts_file>>con[i].name && contacts_file>>con[i].phone ){
            i++;
            }
            contacts_file.close();

            if(i==0){
                system("cls");
                system("Color 74");
                cout<<"\t\t\t\t\t\t\t****************************************\n";
                cout<<"\t\t\t\t\t\t\t******************  no data  ***********\n";
                cout<<"\t\t\t\t\t\t\t****************************************\n";
                Sleep(3000);
                error=0;
                menu();
            }else{
                cout<<"\t\t\t\t\t-------------------------------------------------\n";
                cout<<"\t\t\t\t\t-      ID     -         name        -     phone  \n";
                cout<<"\t\t\t\t\t-------------------------------------------------\n";
                for(int i=0;i<100;i++){
                    if(con[i].id != 0){
                        cout<<"\t\t\t\t\t#      "<<con[i].id<<"         -";
                        cout<<con[i].name;
                        cout<<"             "<<con[i].phone<<"         ";
                        error=1;
                        cout<<endl;
                    }
                }
                cout<<"\t\t\t\t\t-------------------------------------------------\n";

            }
        
        menu();
    }
    
        else if(num==3){
        system("cls");
        string search_name;
        int i=0;
        cout<<"enter name for search : ";
        cin>>search_name;

        contacts_file.open("contact.txt",ios::in);
        while(contacts_file>>con[i].id && contacts_file>>con[i].name && contacts_file>>con[i].phone){
            i++;
        }
        contacts_file.close();
        error=0;
        for(int k=0;k<100;k++){
            if(con[k].id !=0 && con[k].name==search_name){
                cout<<"\t\t\t\t\t   -------------------------------------   \n";
                cout<<"\t\t\t\t\t   -----------------  result -----------   \n";
                cout<<"\t\t\t\t\t   -------------------------------------   \n";
                cout<<"\t\t\t\t\t   #ID => "<<con[k].id<<endl;
                cout<<"\t\t\t\t\t   #Name => "<<con[k].name<<endl;
                cout<<"\t\t\t\t\t   #Phone => "<<con[k].phone<<endl;
                cout<<"\t\t\t\t\t   -------------------------------------   \n";
                error=1;
            }
        }

            if(error==0){
                system("cls");
                system("Color 74");
                cout<<"\n\n\n\n\n\n\n\n\n";
                cout<<"\t\t\t\t\t\t**************************************************************************\n";
                cout<<"\t\t\t\t\t\t**************************************************************************\n";
                cout<<"\t\t\t\t\t\t************************** the name not exist ****************************\n";
                cout<<"\t\t\t\t\t\t**************************************************************************\n";
                cout<<"\t\t\t\t\t\t**************************************************************************\n";
                Sleep(3000);
                error=0;
                system("cls");
                menu();
            }
        menu();
    }

        else if(num==4){
        system("cls");
        error=0;
        string search_number;
        cout<<"enter number for search : ";
        cin>>search_number;

        contacts_file.open("contact.txt",ios::in);
        int i=0;
        while (contacts_file>>con[i].id && contacts_file>>con[i].name && contacts_file>>con[i].phone){
            i++;
        }
        contacts_file.close();
        for(int k=0;k<100;k++){
            if(con[k].id !=0 && con[k].phone==search_number){
                cout<<"\t\t\t\t\t   -------------------------------------   \n";
                cout<<"\t\t\t\t\t   -----------------  result -----------   \n";
                cout<<"\t\t\t\t\t   -------------------------------------   \n";
                cout<<"\t\t\t\t\t   #ID => "<<con[k].id<<endl;
                cout<<"\t\t\t\t\t   #Name => "<<con[k].name<<endl;
                cout<<"\t\t\t\t\t   #Phone => "<<con[k].phone<<endl;
                cout<<"\t\t\t\t\t   -------------------------------------   \n";
                error=1;
            }
        }

                    if(error==0){
                system("cls");
                system("Color 74");
                cout<<"\n\n\n\n\n\n";
                cout<<"******************************************\n";
                cout<<"********* the number not exist ***********\n";
                cout<<"******************************************\n";
                Sleep(3000);
                error=0;
                system("cls");
                menu();
            }

        menu();
    }

        else if(num==5){
            string name;
            error=0;
            int i=0;

            cout<<"enter name :";
            cin>>name;
            contacts_file.open("contact.txt" , ios::in);
            while (contacts_file>>con[i].id && contacts_file>>con[i].name && contacts_file>>con[i].phone)
            {
                i++;
            }
            contacts_file.close();
            for(int k=0;k<100;k++){
                if(con[k].id !=0 && con[k].name == name ){
                    string new_name;
                    string new_phone;
                    cout<<"\t\t\t\t\t new name : ";
                    cin>>new_name;
                    cout<<"\t\t\t\t\t new number : ";
                    cin>>new_phone;
                    con[k].name=new_name;
                    con[k].phone=new_phone;
                    contacts_file.open("contact.txt",ios::out);
                    if(contacts_file.is_open()){
                        for(int j=0;j<100;j++){
                            if(con[j].id !=0){
                                contacts_file<<con[j].id<<endl;
                                contacts_file<<con[j].name<<endl;
                                contacts_file<<con[j].phone<<endl;
                            }
                        }
                    }

                    error=1;
                }
            }
            


            if(error==0){
                system("cls");
                system("Color 74");
                cout<<"\n\n\n\n\n\n";
                cout<<"******************************************\n";
                cout<<"********* the name not exist *************\n";
                cout<<"******************************************\n";
                Sleep(3000);
                system("cls");
                menu();
            }else{
            system("Color 4F");
            cout<<"update has been successfully ";
            Sleep(2000);
            menu();
            }
        }
        
        else if(num==6){
            string update_number;
            int i=0;
            cout<<"\t\t\t\t\t enter number for search : ";
            cin>>update_number;
            
            contacts_file.open("contact.txt",ios::in);
            while(contacts_file>>con[i].id && contacts_file>>con[i].name && contacts_file>>con[i].phone  ){
                i++;
            }
            contacts_file.close();

            for(int k=0;k<100;k++){
                if(con[k].id != 0 && con[k].phone == update_number){
                    string new_name;
                    string new_phone;
                    system("Color 74");
                    cout<<"\t\t\t\t\t ********************************************\n";
                    cout<<"\t\t\t\t\t ***************  is founded ****************\n";
                    cout<<"\t\t\t\t\t ********************************************\n";
                    Sleep(2000);
                    system("cls");
                    system("Color 0B");
                    cout<<"\t\t\t\t\t new name : ";
                    cin>>new_name;
                    cout<<"\t\t\t\t\t new number : ";
                    cin>>new_phone;
                    con[k].name=new_name;
                    con[k].phone=new_phone;
                    contacts_file.open("contact.txt",ios::out);
                    for(int j=0;j<100;j++){
                        if(con[j].id !=0 ){
                            contacts_file<<con[j].id<<endl;
                            contacts_file<<con[j].name<<endl;
                            contacts_file<<con[j].phone<<endl;
                        }
                    }
                    contacts_file.close();
                    Sleep(2000);
                    cout<<"\t\t\t\t\t ********************************************\n";
                    cout<<"\t\t\t\t\t ****|   update has been successfully   |****\n";
                    cout<<"\t\t\t\t\t ********************************************\n";
                    error=1;
                }
            }

            if(error==0){
                    system("Color 74");
                    cout<<"\t\t\t\t\t ********************************************\n";
                    cout<<"\t\t\t\t\t *************** not founded ****************\n";
                    cout<<"\t\t\t\t\t ********************************************\n";
                    Sleep(2000);
                    menu();
            }
            menu();
        }
        
        else if(num==7){
            string name_delete;
            contacts afterDelete[100];

            int i=0;
            int position=-1;
            error=0;
            cout<<"enter name for delete : ";
            cin>>name_delete;

            contacts_file.open("contact.txt",ios::in);
                while(contacts_file>>con[i].id&& contacts_file>>con[i].name && contacts_file>>con[i].phone){
                    i++;
                }
            contacts_file.close();
            for(int k=0;k<100;k++){
                if(con[k].id !=0 && con[k].name == name_delete){
                    position=k;
                    error=1;
                }
            }
            if(position !=-1){
                for(int j=0;j<100;j++){
                    if(j== position){
                        con[j].id=0;
                        con[j].name="\0";
                        con[j].phone="\0";
                        continue;
                    }
                    afterDelete[j].id=con[j].id;
                    afterDelete[j].name=con[j].name;
                    afterDelete[j].phone=con[j].phone;
                }
                                        system("Color 74");
                    cout<<"\t\t\t\t\t ********************************************\n";
                    cout<<"\t\t\t\t\t ***************  is founded ****************\n";
                    cout<<"\t\t\t\t\t ********************************************\n";
                    Sleep(2000);

                    contacts_file.open("contact.txt",ios::out);
                    for(int m=0;m<100;m++){
                        if(afterDelete[m].id !=0 && afterDelete[m].name != "\0" && afterDelete[m].phone != "\0"){
                        contacts_file<<afterDelete[m].id<<endl;
                        contacts_file<<afterDelete[m].name<<endl;
                        contacts_file<<afterDelete[m].phone<<endl;
                        }
                    }
                    contacts_file.close();
                    system("cls");
                    system("Color 0B");
                    cout<<"\t\t\t\t\t ********************************************\n";
                    cout<<"\t\t\t\t\t ****|   delete has been successfully   |****\n";
                    cout<<"\t\t\t\t\t ********************************************\n";
                    error=1;
                    menu();

                
                
            }

            if(error==0){
                    system("Color 74");
                    cout<<"\t\t\t\t\t ********************************************\n";
                    cout<<"\t\t\t\t\t *************** not founded ****************\n";
                    cout<<"\t\t\t\t\t ********************************************\n";
                    Sleep(2000);
                    menu();
            }
        }
        
        else if(num==8){
            contacts_file.open("contact.txt",ios::out);
            contacts_file<<"";
            contacts_file.close();
                cout<<"\t\t\t\t\t ********************************************\n";
                cout<<"\t\t\t\t\t ****|   delete has been successfully   |****\n";
                cout<<"\t\t\t\t\t ********************************************\n";
                Sleep(2000);
                menu();
        }
        
        else if(num==9){
            auth();
        }else{
            menu();
        }




}




    void login(){
        string username,password;
        cout<<"username :  ";
        cin>>username;
        cout<<"password : ";
        cin>>password;

        auth_file.open("auth.txt",ios::in);
        int k=0;
        while(auth_file>>acc[k].id && auth_file>>acc[k].username && auth_file>>acc[k].password){
            k++;
        }
        auth_file.close();
        for(int i=0;i<100;i++){
            if(acc[i].id !=0 && acc[i].username==username && acc[i].password ==password){
                menu();
            }
        }
        auth();
    }

    void regisration(){

        int i=0;
        auth_file.open("auth.txt",ios::app | ios::in | ios::out);
        while(auth_file>>acc[i].id  &&  auth_file>>acc[i].username && auth_file>>acc[i].password  ) {
            i++;
        }
        auth_file.close();

            auth_file.open("auth.txt",ios::app);
            string username,password;
            acc[i].id=i+1;
            cout<<"\t\t\t\t\t username ";
            cin>>acc[i].username;
            cout<<"\t\t\t\t\t password ";
            cin>>acc[i].password;
            auth_file<<acc[i].id<<endl;
            auth_file<<acc[i].username<<endl;
            auth_file<<acc[i].password<<endl;
            Sleep(2000);
            system("Color 74");
            cout<<"\t\t\t\t\t ********************************************\n";
            cout<<"\t\t\t\t\t ****|  register has been successfully  |****\n";
            cout<<"\t\t\t\t\t ********************************************\n";
            Sleep(500);
        auth_file.close();



        system("Color 3D");
        cout<<"\t\t\t\t\t --------------------------------------\n";
        cout<<"\t\t\t\t\t after create an account sign in again :\n ";
        cout<<"\t\t\t\t\t---------------------------------------\n";
        Sleep(2000);
        auth();
    }