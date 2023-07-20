// Header Files
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function Prototype
void First_Game();
void Second_Game();

// Main Function
int main()
{
	// Introduction of Group Members
	cout<<"\t#####  Group members  ##### "<<endl<<endl;
	cout<<"\tHasnain Bakht  (Fa22-BCS-076)"<<endl;
	cout<<"\t ()"<<endl;
	cout<<"\t ()"<<endl;
	cout<<"\t ()"<<endl;
	
	// Name of Project
	cout<<endl<<endl;
	cout<<"\t*****   Project name   *****"<<endl<<endl;
	cout<<"\t     Casino Gaming System "<<endl;
	
	// Starting of Programme
    char value;
	while(true){cout<<endl;
	cout<<"->Press a to Play \"Slot Machine Game\"."<<endl;
	cout<<"->Press b to Play \"Casino Number Guessing Game\"."<<endl;
	cout<<"->Press q to End the Program."<<endl<<endl;
	cin>>value;
	cin.ignore();
	switch(value){
		case 'a':
			First_Game();
			break;
		case 'b':
			Second_Game();
			break;
		case 'q':
			exit(0);
			break;
		default:
			cout<<"!!!===Invalid Input===!!!"<<endl;
	}
	}
}

// First Game


void First_Game(){ cout << endl;
	
	cout << "======Slot Machine Game Rules!======\n";
    cout << "To win, match any two or three numbers.\n";
    cout << "If you match two numbers, you win 2 times your bet.\n";
    cout << "If you match three numbers, you win 3 times your bet.\n";
    cout << endl;
    
    
    // Seed the random number generator
    srand(time(0));

    // Initialize variables
    int balance = 1000;
    int bet;

    // Start the game loop
    while (balance > 0)
    {
        // Get the bet amount from the user
        cout << "Your balance is " << balance << ". Place your bet: ";
        cin >> bet;

        // Check if the bet is valid
        if (bet <= 0 || bet > balance)
        {
            cout << "Invalid bet amount. Try again.\n";
            continue;
        }

        // Spin the reels and display the outcome
        int reel1 = rand() % 10 + 1;
        int reel2 = rand() % 10 + 1;
        int reel3 = rand() % 10 + 1;
        cout << "Reels: " << reel1 << " " << reel2 << " " << reel3 << endl;

        // Check for a win
        if (reel1 == reel2 && reel1 == reel3)
        {
            balance +=  bet*3;
            cout << "Congratulations! You won 3 times your bet.\n";
        }
        else if (reel1 == reel2 || reel1 == reel3 || reel2 == reel3)
        {
            balance += bet*2;
            cout << "Congratulations! You won 2 times your bet.\n";
        }
        else
        {
            balance -= bet;
            cout << "Sorry, you lost your bet.\n";
        }

        // Display the updated balance
        cout << "Your balance is now " << balance << endl;

        // Ask the player if they want to play again
        char playAgain;
        cout << "Do you want to play again? (Y/N): ";
        cin >> playAgain;

        if (playAgain != 'Y' && playAgain != 'y')
        {
            break;
        }
             
    }

    // End of game
    cout << "Thanks for playing. Your final balance is " << balance <<endl;
    cout <<endl<< "\nAnyone wants to play ?\n"<<endl<<endl<<endl<<endl<<endl;
    cout << "---------------Thanks for visiting---------------\n"<<endl;
}

// Second Game


void Second_Game() {
    string playerName;    //Player name
    int balance;
    int battingAmount;
    int guess;
    int dice;             //stores the random number
    char choice;
    srand(time(0));       //seed the random generator

    cout << "======CASINO NUMBER GUESSING RULES!======\n";
    cout << "Choose a number between 1 to 10\n";
    cout << "Winner gets 10 times of the money bet\n";
    cout << "Wrong bet, and you lose the amount you bet\n\n";

    cout << "WELCOME TO THE CASINO WORLD" << endl;
    cout << "What's your Name ?" << endl;
    getline(cin, playerName);
    cout << "Enter the starting balance to play the game" << endl;
    cin >> balance;
    cin.ignore();

    while (true) {
        cout << "Your current balance is $" << balance << endl; //players batting balance

        while (true) {
            cout << "Hi " << playerName << ", enter the amount for betting $" << endl;
            cin >> battingAmount;

            if (battingAmount > balance) 
			{
                cout << "Batting amount could not be more than the balance" << endl;
                cout << "Re-enter the amount" << endl;
            }
			else
			{
                break;
            }
        }

        while (true) 
		{
            cout << "Guess any number between 1 & 10" << endl;
            cin >> guess;

            if (guess <= 0 || guess >= 10) 
			{
                cout << "Number should be between 1 and 10" << endl;
                cout << "Re-enter the number" << endl;
            } 
			else 
			{
                break;
            }
        }

        dice = rand() % 10;
        if (guess == dice) 
		{
            cout << "You are lucky! Yohoo! You won the game RS " << balance * 10 << endl;
            balance = balance + battingAmount * 10;
        } 
		else 
		{
            cout << "Oops! Better luck next time. You lose the game $" << battingAmount << endl;
            balance = balance - battingAmount;
        }

        cout << "The Winning number was: " << dice << endl;
        cout << "\n" << playerName << ", you have a balance of $" << balance << endl;

        if (balance == 0) 
		{
            cout << "You have no money to play.";
            break;
        }

        cout << "Do you want to play again (Y/N)?" << endl;
        cin >> choice;

        if (choice != 'y' && choice != 'Y') 
		{
            break;
        }
    }

    cout << "Thanks for playing the game. Your balance is $" << balance <<endl<<endl<<endl;
    cout <<"\nAnyone wants to play?\n"<<endl<<endl<<endl;
    cout <<"---------------Thanks for Visiting---------------"<<endl<<endl<<endl;
}


// End of the Project

