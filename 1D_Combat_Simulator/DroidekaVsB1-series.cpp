#include <iostream>
#include <random>
#include <ctime>
 
using namespace std;
 
int main()
{
    
    //Droideka vs B1-series battle droids
    
    //Seed random engine with time
    default_random_engine randomEngine(time(NULL));
    uniform_real_distribution<float> attack(0.0f, 1.0f);
 
    // Droideka properties
    float DroidekaAttack = 0.6f;
    float DroidekaHealth = 250.0f;
    float DroidekaDamage = 200.0f;
    float currentDroidekaHealth = DroidekaHealth;
 
    //B1-series battle properties
    float B1Attack = 0.4f;
    float B1Health = 180.0f;
    float B1Damage = 70.0f;
    float currentB1Health = B1Health;
 
    float attackResult;
 
    int startB1;
    int startDroideka;
 
    int numB1;
    int numDroideka;
 
    char turn = 'D';
    
    cout << "### Simulator: B1-series battle droids Vs Droideka! ###\n\n";
 
    //Get the number of Droideka
    cout << "Enter the number of Droidekas: ";
    cin >> numDroideka;
 
    startDroideka = numDroideka;
 
    //Get the number of B1-series battle
    cout << "Enter the number of B1-series battle: ";
    cin >> numB1;
 
    startB1 = numB1;
 
    cout << "\nBeginning combat!\n\n";
 
    while ((numDroideka > 0) && (numB1 > 0)) {
        //Get our attack result
        attackResult = attack(randomEngine);
 
        // Droideka turn
        if (turn == 'D') {
         
            //Check if attack was successful
            if (attackResult <= DroidekaAttack) {
                currentB1Health -= DroidekaDamage;
 
                if (currentB1Health < 0) {
                    numB1--;
                    currentB1Health = B1Health;
                }
            }
            //now its B1-series battle turn!
            turn = 'B';
 
        } else {  // if its not Droideka turn, then B1 turn
 
            if (attackResult <= B1Attack) {
                currentDroidekaHealth -= B1Damage;
 
                if (currentDroidekaHealth < 0) {
                    numDroideka--;
                    currentDroidekaHealth = DroidekaHealth;
                }
            }
            //now its Droideka turn!
            turn = 'D';
 
        }
 
    }
 
    cout << "\nBattle is over!\n\n";
 
    //print out the results!
    if (numDroideka > 0) {
        cout << "Droideka won!\n";
        cout << "There are " << numDroideka << " Droideka left!\n";
    } else {
        cout << "B1-series battle won!\n";
        cout << "There are " << numB1 << " B1-series battle left!\n";
    }
 
    //KILL COUNTER!
    cout << startDroideka - numDroideka << " Droideka and " << startB1 - numB1 << " B1-series battle lost their lives.\n\n";
 
    return 0;
}
