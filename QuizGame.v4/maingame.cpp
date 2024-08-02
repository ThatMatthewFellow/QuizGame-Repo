#include "QuizGame.h"

// The main program for the quiz
int main(){
    // Declare the game
    My_Game g;
    g.name = "Quiz Game";
    g.rules = "         Answer the questions to level up\n              Spelling is important\n You can answer the full answer or just the letter";
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
        set_question(q1, "What is the capital of Ohio?", "Columbus", "Cincinnati", "Cleveland", "Dayton");
        set_answer(q1, "Columbus", "A");
        ask_question(q1, g);
        // Check their answer
        answer_checker(p1, q1, g);
        // Question 2
        Question q2;
        set_question(q2, "What is the furthest planet from the sun?", "Venus", "Jupiter", "Earth", "Pluto");
        set_answer(q2, "Pluto", "D");
        ask_question(q2, g);
        answer_checker(p1,q2, g);
        // Question 3
        Question q3;
        set_question(q3, "When was the Eiffel Tower fully built?", "1889", "1788", "1902", "1890");
        set_answer(q3, "1889", "A");
        ask_question(q3, g);
        answer_checker(p1,q3, g);
        // Question 4
        Question q4;
        set_question(q4, "What latest season of The Boys?", "Season 3", "Season 4", "Season 2", "Season 5");
        set_answer(q4, "Season 4", "B");
        ask_question(q4,g);
        answer_checker(p1,q4,g);
        // End of quiz stuff
        // Output overall score
        score(p1, g);
        // Try again?
        retryQuiz(g,p1);
    }
    // Let the screen sit until a key is pressed
    system("pause");
    return 0;
}