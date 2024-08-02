#include <iostream>
#include <string>
#include <cctype>
#include <iomanip>
#include <ctime>
#include <windows.h>
using namespace std;

// Quiz Game -- ThatMatthewFellow

// A setup and a real quiz game in C++
// Within there are structs and functions to make a quiz game within the main program

// Setup for the game
// @ string name -> The name of the game
// @ string rules -> The rules of the game
// @ double num -> The question number the player is currently on
// @ bool endGame -> The bool that ends the game, or keeps it going
// @ clock_t start -> The time it was when the quiz started
struct My_Game{
    string name;
    string rules;
    float num = 1;
    bool endGame = false;
    clock_t start = clock();
};

// Setup for the question
// @ string answer -> The answer to the question
// @ string letter -> The letter that corresponds to the answer
// @ string q -> Question for the problem
// @ string a -> Answer a to the problem
// @ string b -> Answer b to the problem
// @ string c -> Answer c to the problem
// @ string d -> Answer d to the problem
struct Question{
    string answer;
    string letter;
    string q;
    string a;
    string b;
    string c;
    string d;
};

// Setup for the player
// @ string name -> The name of the player
// @ int level -> The level of the player
// @ string answer -> The player's answer to the problem
struct Player{
    string name;
    float level = 1;
    string answer;
};

// Make a string have an uppercase letter in the front
/// @param s -> The string to uppercase
void UpperCase(string& s){
    // For all instances, make sure the first letter is capitalized
    s[0] = toupper(s[0]);
}

// Output game info
/// @param g -> The info for the game: name/rules
void output_game_info(My_Game& g){
    cout << endl;
    for(int i = 0; i < 50; i++){
        if(i % 2)
            cout << "#";
        else   
            cout << " ";
    }
    cout << endl;
    cout << setw(30) << g.name << endl;
    cout << setw(30) << "Rules: " << endl << g.rules << endl;
    for(int i = 0; i < 50; i++){
        if(i % 2)
            cout << "#";
        else   
            cout << " ";
    }
    cout << endl << endl;
}

// Set the question options
/// @param question -> The info the for the question: a,b,c,d
/// @param q -> Question for the problem
/// @param a -> Answer a to the problem
/// @param b -> Answer b to the problem
/// @param c -> Answer c to the problem
/// @param d -> Answer d to the problem
void set_question(Question& question, string q, string a, string b, string c, string d){
    question.q = q;
    question.a = a;
    question.b = b;
    question.c = c;
    question.d = d;
}

// Set the answer info for the question
/// @param question -> The info for the question to manipulate
/// @param answer -> The correct answer for the question
/// @param letter -> The correct letter correlating to the answer
void set_answer(Question& question, string answer, string letter){
    question.answer = answer;
    question.letter = letter;
}

// Output the question to the screen
/// @param question -> All question info for the question the player is currently on
/// @param game -> All game info (for game.num)
void ask_question(Question& question, My_Game& game){
    cout << "This is question " << game.num << ": " << question.q << endl;
    cout << "A: " << question.a << endl;
    cout << "B: " << question.b << endl;
    cout << "C: " << question.c << endl;
    cout << "D: " << question.d << endl;
    cout << endl;
    cout << "What is your answer: ";
}

// Checks if the answer to the problem is correct and levels up the player if so
/// @param p -> The player's struct info (for p.answer, p.level)
/// @param q -> The question struct info (for q.answer, q.letter)
/// @param g -> All game info (for g.num)
void answer_checker(Player& p, Question& q, My_Game& g){
    // Enter their answer
    cin >> p.answer;
    // Make sure the first letter is capitalized in the string
    UpperCase(p.answer);
    // Check to see if the answer is correct
    if(p.answer == q.answer || p.answer == q.letter){
        cout << "Correct!";
        // Level up player
        p.level++;
        // Output what level they are based on it they correctly or not
        cout << " You are now level " << p.level << endl << endl;
    }
    // The player is wrong, let them know
    else
        cout << "Incorrect!" << endl << endl;
    // Update the question number
    g.num += 1;
}

// Output the overall score of the player
/// @param player -> All player info (for player.level)
/// @param game -> All game info (for game.num)
void score(Player& player, My_Game& game){
    // Perfect score
    float score = (((player.level-1)/(game.num-1))*100);
    if(score == 1){
        cout << "Very nice job! ";
    }
    // The total time it took to do the quiz
    clock_t total = clock() - game.start;
    // Output the time it took the user to do the quiz
    cout << "The quiz took you " << (float)total/CLOCKS_PER_SEC << " seconds" << endl;
    // Output the percent score to the screen
    cout << "Your score percentage is: " << setprecision(4) << score << "%" << endl;
    // Output the fraction score to the screen
    cout << "You answered " << player.level-1 << " out of " << game.num-1 << " questions" << endl << endl;
}

// Retrying the quiz
/// @param g -> The game info (for the use of g.endGame)
/// @param p -> The player info (to reset the p.level)
void retryQuiz(My_Game& g, Player& p){
    // Try again?
    cout << "Try the quiz again? (y/n) " << endl;
    string choice = "";
    bool c2 = false;
    // Check for if the choice is valid
    while(c2 != true){
        // Input
        cout << "Enter your choice: ";
        cin >> choice;
        if(choice == "y" || choice == "n"){
            c2 = true;
            if(choice == "y")
                cout << endl;
        }
        else{
            cout << "Invalid input!" << endl;
        }
    }
    // Set answer to y just in case
    // End or keep going
    if(choice == "n"){
        g.endGame = true;
        cout << "Thanks for taking the quiz " << p.name << endl << endl;
    }
    else{
        g.endGame = false;
        p.level = 1;
        g.num = 1;
        g.start = clock();
    }
}