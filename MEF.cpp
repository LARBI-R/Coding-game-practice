/* CODING GAME 03/04/2021 */



/* GAME 7  MEF ---------------------------- */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main()
{
    vector<string> transitionList;

    vector<string> wordList;
    string starteStateCp;

    string input;
    getline(cin, input);

    cerr<<"alphabet"<<endl;
    cerr<<input<<endl;

    string states;
    getline(cin, states);
    int numberOfTransitions;
    cin >> numberOfTransitions; cin.ignore();
    for (int i = 0; i < numberOfTransitions; i++) {
        string transition;
        getline(cin, transition);

        cerr<<"transition"<<endl;
        cerr<<transition<<endl;
        transitionList.push_back(transition);
 
    }

    string resultat = "true";

    string startState;
    getline(cin, startState);

    starteStateCp = startState;



    string endStates;
    getline(cin, endStates);


    int numberOfWords;
    cin >> numberOfWords; cin.ignore();
    for (int i = 0; i < numberOfWords; i++) {
        string word;
        getline(cin, word);

        for (int j = 0; j < word.length() ; ++j)
        {
            if ( input.find(word[j]) != std::string::npos )
            {
                // rien
            }
            else 
            {
                resultat = "false";
            }
        }

        int f = 0; 

        cerr<<"word complet "<<word<<endl;

        while (f < word.length() )
        { 
            for (int k = 0; k < transitionList.size(); k++)
            {
                if ( (transitionList[k])[0] == startState[0] )
                {
                    if ( (transitionList[k])[2] == word[f] )
                    {
                        cerr<<"word------------------ "<<word[f]<<endl;
                        cerr<<"state av "<<endl;
                        cerr<<startState<<endl;
                        startState.clear();
                        startState.push_back((transitionList[k])[4]);
                        cerr<<"state ap "<<endl;
                        cerr<<startState<<endl;
                        break;
                    }
                }
            }
            f++;
        }


        if ( i == (numberOfWords - 3) ) 
        {
            cerr<<"OOOOOOO**********"<<word<<endl;
        }
        
        if ( endStates.find(startState[0]) != std::string::npos )
        {
            // rien
        }
        else 
        {
            resultat = "false";
        }

        
        
        cerr<<resultat<<endl;
                
        cout<<resultat<<endl;

        resultat = "true";
        
        startState = starteStateCp;        
        
    }

    



    // Write an answer using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

   // cout << "true or false" << endl;
}