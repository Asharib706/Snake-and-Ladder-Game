// Course Name : Data Structure and Algorithms(CT-159)
// Project name: Snake and Ladder Game
// Group Members: Muhammad Asharib Siddiqui(CT-85).
//                Abdul Wasay(CT-72).
//                Muhammad Ahmed Siddiqui(CT-78). 

#include<iostream>
#include<iomanip>
#include<random>
#include<string>
using namespace std;
const int board[10][10]={
{100,99,98,97,96,95,94,93,92,91},
{81,82,83,84,85,86,87,88,89,90},
{80,79,78,77,76,75,74,73,72,71},
{61,62,63,64,65,66,67,68,69,70},
{60,59,58,57,56,55,54,53,52,51},
{41,42,43,44,45,46,47,48,49,50},
{40,39,38,37,36,35,34,33,32,31},
{21,22,23,24,25,26,27,28,29,30},
{20,19,18,17,16,15,14,13,12,11},
{1,2,3,4,5,6,7,8,9,10}
};
int diceroll(){
    int dice=1+rand()%6;
    return dice; 
}

//function declerations
void snakebite(int* );
void ladderclimb(int* );
void snakeAndTails(int);
void ladderAndHead(int);
void displaytable(const int arr[][10],int ,int);
int playerturn(char []);
void showInstructions();
int checkL_S(int *);
void playgame();
// main function
int main(){
    char choice;
    bool a=true;
    char i;
    cout<<endl<<"Please Switch to Full screen"<<endl;
    cout<<"Press ENTER key to Run the game :";
    //cin>> i;
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    //cin.ignore();
    system("cls");
    while (a) {
       srand(time(0));
       system("cls");
       cout << "Welcome to Snake and Ladder!" << endl;
       cout << "1. Start new game" << endl;
       cout << "2. Instructions" << endl;
       cout << "3. Exit" << endl;
       cout << "Enter your choice: ";
       cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(),'\n');

       switch (choice) {
           case '1':
               // Start the Game
               cout<<endl;
               playgame();
               break;
           case '2':
               // Show instructions
               cout<<endl;
               showInstructions();
               cout<<endl<<endl;
               //int b;
               cout<<"Press ENTER key to return to the Main menu"<<endl;
               cin.ignore(numeric_limits<streamsize>::max(),'\n');
               break;
           case '3':
               char c;
               cout<<"Do you want to Quit the Game ? (y/n)";
               cin>>c;
               if (c=='y'){
                   a=false;    
               }
               break;
           default:
               std::cout << "Invalid choice! Please enter a valid option." << std::endl;
       }
   }
}
// snake and its tail
void snakeAndTails(int x){
    switch (x)
    {
    case 29:
        cout<<setw(6)<<"\"S\"(";
        cout<<setw(2)<<"10";
        cout<<setw(1)<<char(25);
        cout<<setw(1)<<")";
        break;
    case 10:
        cout<<setw(9)<<"\"10\"";
        cout<<setw(1)<<char(1);
        break;
    case 88:
        cout<<setw(6)<<"\"S\"(";
        cout<<setw(2)<<"54";
        cout<<setw(1)<<char(25);
        cout<<setw(1)<<")";

        break;
    case 99:
        cout<<setw(6)<<"\"S\"(";
        cout<<setw(2)<<"25";
        cout<<setw(1)<<char(25);
        cout<<setw(1)<<")";
        break;
    case 54:
        cout<<setw(9)<<"\"54\"";
        cout<<setw(1)<<char(1);

        break;
    case 25:
        cout<<setw(9)<<"\"25\"";
        cout<<setw(1)<<char(1);
        break;
    }
}
// ladder and its top
void ladderAndHead(int x){
    switch (x)
    {
    case 7:
        cout<<setw(6)<<"\"L\"(";
        cout<<setw(2)<<"28";
        cout<<setw(1)<<char(24);
        cout<<setw(1)<<")";
        break;
    case 42:
        cout<<setw(6)<<"\"L\"(";
        cout<<setw(2)<<"78";
        cout<<setw(1)<<char(24);
        cout<<setw(1)<<")";
        break;

    case 73:
        cout<<setw(6)<<"\"L\"(";
        cout<<setw(2)<<"92";
        cout<<setw(1)<<char(24);
        cout<<setw(1)<<")";
        break;

    case 55:
        cout<<setw(6)<<"\"L\"(";
        cout<<setw(2)<<"97";
        cout<<setw(1)<<char(24);
        cout<<setw(1)<<")";

        break;

    case 28:
        cout<<setw(9)<<"\"28\"";
        cout<<setw(1)<<char(2);
        break;
    case 78:
        cout<<setw(9)<<"\"78\"";
        cout<<setw(1)<<char(2);
        break;
    case 92:
        cout<<setw(9)<<"\"92\"";
        cout<<setw(1)<<char(2);
        break;
    case 97:
        cout<<setw(9)<<"\"97\"";
        cout<<setw(1)<<char(2);
        break;
    }
}
// Displaying Board
void displaytable(const int arr[][10],int p1,int p2){
    cout<<"\t\t\t  ";
    for (int a=0;a<11;a++){
        cout<<"===========";
}
    cout<<endl;
    for (int i=0;i<10;i++){
        cout<<"\t\t\t"<<"||";
        for(int j=0;j<10;j++){
            if (arr[i][j]==p1 && arr[i][j]==p2){
                cout<<"|";
                cout<<setw(9)<<"\"P1,P2\"";
                cout<<setw(1)<<char(29);
                cout<<"|";
            }
            else if (arr[i][j]==p1){
                cout<<"|";
                cout<<setw(9)<<"PLAYER1";
                cout<<setw(1)<<char(29);
                cout<<"|";
            }
            else if (arr[i][j]==p2){
                cout<<"|";
                cout<<setw(9)<<"PLAYER2";
                cout<<setw(1)<<char(29);
                cout<<"|";
            }
            else if(arr[i][j]==1){
                cout<<"|";
                cout<<setw(10)<<"Start(1)";
                cout<<"|";
            }
            else if (arr[i][j]==29||arr[i][j]==10||arr[i][j]==88||
                arr[i][j]==99||arr[i][j]==54||arr[i][j]==25 )
            {
                cout<<"|";
                snakeAndTails(arr[i][j]);
                //cout<<" ";
                cout<<"|";
            }
            else if(arr[i][j]==7 || arr[i][j]==28 || arr[i][j]== 97 ||
                    arr[i][j]==42 || arr[i][j]==92 || arr[i][j] ==55 || 
                    arr[i][j]==73 ||arr[i][j]==78 )
            {
                cout<<"|";
                ladderAndHead(arr[i][j]);
                //cout<<" ";
                cout<<"|";
            }
            else{
                cout<<"|";
                cout<<setw(10)<<arr[i][j];
                //cout<<" ";
                cout<<"|";
            }
        
        }
        cout<<"||"<<endl;//<<endl;
        cout<<"\t\t\t  ";
    for (int a=0;a<11;a++){
        cout<<"===========";
        }
        cout<<endl;
    }

    cout<<endl;
}
// snake bite
void snakebite(int* s){
    switch (*s)
    {
    case 99:
        cout<<"\t\t"<<"Opps! It's \"The Snake\""<<endl;
        *s=25;
        break;
    case 88:
        cout<<"\t\t"<<"Opps! It's \"The Snake\""<<endl;
        *s=54;
        break;
    case 29:
        cout<<"\t\t"<<"Opps! It's \"The Snake\""<<endl;
        *s=10;
        break;
    }
}
// ladder climb 
void ladderclimb(int* s){
    switch (*s)
    {
    case 7:
        cout<<"\t\t"<<"Yeah! Here's the \"Ladder\""<<endl;
        *s=28;
        break;
    case 42:
        cout<<"\t\t"<<"Yeah! Here's the \"Ladder\""<<endl;
        *s=78;
        break;
    case 55:
        cout<<"\t\t"<<"Yeah! Here's the \"Ladder\""<<endl;
        *s=97;
        break;
    case 73:
        cout<<"\t\t"<<"Yeah! Here's the \"Ladder\""<<endl;
        *s=92;
        break;
    }
}
// player turn
int playerturn(char s[]){
    cout<<"\t\t"<<s<<"'s turn"<<endl;
    char option;
    cout<<"\t\t"<<"Roll the dice (Enter any key + Enter):";
    cin>>option;
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    return diceroll();
}
//climb or fall?
int checkL_S(int* s){
    snakebite(s);
    ladderclimb(s);
    return *s;
}
// game 
void playgame(){
    int p1=1,p2=1;
    char player1[30],player2[30];
    cout<<"Enter Player 1 Name: ";
    cin>>player1;
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    cout<<"Enter Player 2 Name: ";
    cin>>player2;
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    do {
        system("cls");
        cout<<endl;
        cout<<setw(102)<<"-------------Board-------------"<<endl<<endl;
        displaytable(board,p1,p2);
        cout<<"\t\t\t"<<player1<<" (Player1) is at "<<p1<<endl;
        cout<<"\t\t\t"<<player2<<" (Player2) is at "<<p2<<endl;
        cout<<endl;
        //player 1 turn;
        int p=playerturn(player1);
        cout<<"\t\t"<<"Dice Gives: "<<p<<endl;
        if ((p1+p)<=100){
            p1+=p;
            cout<<"\t\t**"<<player1<<" move to "<<p1<<endl;
        }
        p1=checkL_S(&p1);
        
        //char n;
        cout<<endl<<"Press Enter key to next turn"<<endl;
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        

        //cout<<endl<<"Press (Any key + Enter) to next turn"<<endl;
        //cin>>n;
        system("cls");
        cout<<endl;
        cout<<setw(102)<<"-------------Board-------------"<<endl<<endl;
        displaytable(board,p1,p2);
        cout<<"\t\t\t"<<player1<<" (Player1) is at "<<p1<<endl;
        cout<<"\t\t\t"<<player2<<" (Player2) is at "<<p2<<endl;
        cout<<endl;
        //player 2 turn
        p=playerturn(player2);
        cout<<"\t\t"<<"Dice Gives: "<<p<<endl;
        if ((p2+p)<=100){
            p2+=p;
            cout<<"\t\t**"<<player2<<" move to "<<p2<<endl;
        }
        p2=checkL_S(&p2);
        cout<<endl<<"Press ENTER key to next turn"<<endl;
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        //cout<<endl<<"Press (Any key + Enter) to next turn"<<endl;
        //cin>>n;
    }
    while(p1<100 && p2<100);
    system("cls");
    cout<<endl;
    cout<<setw(102)<<"-------------Board-------------"<<endl<<endl;
    displaytable(board,p1,p2);
    cout<<"\t\t\t"<<player1<<" is at "<<p1<<endl;
    cout<<"\t\t\t"<<player2<<" is at "<<p2<<endl;
    cout<<endl;
    if (p1>=100){
        cout<<player1<<" Won."<<endl;
    }
    else if (p2>=100){
        cout<<player2<<" Won."<<endl;
    }
    else{
        cout<<"Game Tied!"<<endl;
    }
    int a;
    
    cout<<endl<<"Press ENTER to return to Main menu"<<endl;
    cin.ignore(numeric_limits<streamsize>::max(),'\n');

}
void showInstructions() {
    // Show instructions
    cout << "Instructions for Snake and Ladder:" << endl;
    cout << "1. The game is played on a board with a grid of squares." << endl;
    cout << "2. The goal of the game is to reach the last square of the board, also known as the 'home' or 'winning' square, before the other players." << endl;
    cout << "3. Players take turns rolling a die to determine how many squares they can move on the board." << endl;
    cout << "4. The player's piece moves according to the number rolled on the die, and the player takes the corresponding number of steps on the board." << endl;
    cout << "5. If a player lands on a square with a ladder, they can climb up the ladder to a higher square. If a player lands on a square with a snake, they must slide down to a lower square." << endl;
    cout << "6. The first player to reach the home square wins the game." << endl;
    cout << "7. If a player rolls a number greater than the number of squares remaining to the home square, that roll is forfeit and the player does not move." << endl;
    cout << "8. The game can only be played with 2 players" << endl;
}