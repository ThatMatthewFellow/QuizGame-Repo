#include <iostream>
#include <string>
#include <cctype>
using namespace std;

// Quiz Game -- ThatMatthewFellow

// A setup and a real quiz game in C++
// Within there are structs and functions to make a quiz game within the main program

// Setup for the game
// @ string name -> The name of the game
// @ string rules -> The rules of the game
// @ bool endGame -> The bool that ends the game, or keeps it going
struct My_Game{
    string name;
    string rules;
    bool endGame = false;
};

// Setup for the question
// @ int num -> The question number the player is currently on
// @ string answer -> The answer to the question
// @ string letter -> The letter that corresponds to the answer
// @ string q -> Question for the problem
// @ string a -> Answer a to the problem
// @ string b -> Answer b to the problem
// @ string c -> Answer c to the problem
// @ string d -> Answer d to the problem
struct Question{
    double num;
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
    double level = 1;
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
    cout << g.name << endl;
    cout << "Rules: " << endl << g.rules << endl;
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
/// @param num -> Number for the question
/// @param q -> Question for the problem
/// @param a -> Answer a to the problem
/// @param b -> Answer b to the problem
/// @param c -> Answer c to the problem
/// @param d -> Answer d to the problem
void set_question(Question& question, int num, string q, string a, string b, string c, string d){
    question.num = num;
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
void ask_question(Question& question){
    cout << "This is question " << question.num << ": " << question.q << endl;
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
void answer_checker(Player& p, Question& q){
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
        cout << "Incorrect!" << endl;
}

// Output the overall score of the player
/// @param question -> All question info (for question.num)
/// @param player -> All player info (for player.level)
void score(Player& player, Question& question){
    // Perfect score
    double score = (((player.level-1)/question.num)*100);
    if(score == 1){
        cout << "Very nice job! ";
    }
    cout << "Your score percentage is: " << score << "%" << endl;
    cout << "You answered " << player.level-1 << " out of " << question.num << " questions" << endl;
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
        cout << "Ending program" << endl << endl;
    }
    else{
        g.endGame = false;
        p.level = 1;
    }
}

int main(){
    // Declare the game
    My_Game g;
    g.name = "Quiz Game";
    g.rules = "Answer the questions to level up\nSpelling is important\nYou can answer the full answer or just the letter";
    output_game_info(g);
    // Declare the player
    Player p1;
    // Get the player's name
    cout << "What is your name?: ";
    cin >> p1.name;
    // Let them know their level
    cout << p1.name << ", you are currently level "  << p1.level << endl << endl;
    // Loop the quiz questions in case they want to try again
    while(!g.endGame){
        // Question 1
        Question q1;
        set_question(q1, 1, "What is the capital of Ohio?", "Columbus", "Cincinnati", "Cleveland", "Dayton");
        set_answer(q1, "Columbus", "A");
        ask_question(q1);
        // Enter their answer
        cin >> p1.answer;
        // Check their answer
        answer_checker(p1, q1);
        // Question 2
        Question q2;
        set_question(q2, 2, "What is the furthest planet from the sun?", "Venus", "Jupiter", "Earth", "Pluto");
        set_answer(q2, "Pluto", "D");
        ask_question(q2);
        cin >> p1.answer;
        answer_checker(p1,q2);
        // Question 3
        Question q3;
        set_question(q3, 3, "When was the Eiffel Tower fully built?", "1889", "1788", "1902", "1890");
        set_answer(q3, "1889", "A");
        ask_question(q3);
        cin >> p1.answer;
        answer_checker(p1,q3);
        // End of quiz stuff
        // Output overall score
        score(p1,q3);
        // Try again?
        retryQuiz(g,p1);
    }
    // Let the screen sit until a key is pressed
    system("pause");
    return 0;
}