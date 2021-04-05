/* CODING GAME 03/04/2021 */


// ----------- GAME 5  101 GAME -----------------------------//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

 vector<string> split (string s, string delimiter) {
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    string token;
    vector<string> res;

    while ((pos_end = s.find (delimiter, pos_start)) != string::npos) {
        token = s.substr (pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back (token);
    }

    res.push_back (s.substr (pos_start));
    return res;
}

int main()
{
    int N;
    cin >> N; cin.ignore();
    
    vector<string> players;
    vector<string> shoots;
    vector<vector<string>> shoots2;
    map<string,vector<int>> playerrounds;
    map<string,vector<int>> score;
    for (int i = 0; i < N; i++) {
        string PLAYER;
        getline(cin, PLAYER);
        players.push_back(PLAYER);
    }
    for (int i = 0; i < N; i++) {
        string SHOOTS;
        getline(cin, SHOOTS);
        shoots.push_back(SHOOTS);
    }

    int j = 0;

    vector<string> temp;
    string delimiter = " ";
    size_t foundat;
    vector<int> multiptemp;
    string tempoav = "";
    string tempoar = "";
    int countx = 0;
    //vector<int> score;
    size_t xfound;
    for ( int i = 0; i < N; ++i)
    {   
        shoots2.push_back(split((shoots[i]), delimiter));
        
        for ( int j = 0; j < (shoots2[i]).size(); j++)
        {
            foundat = (shoots2[i])[j].find('*');
            xfound = (shoots2[i])[j].find('X');

            if ( foundat <  (shoots2[i])[j].length())
            {
                for (int h = 0 ; h < foundat; h++)
                {
                    // av *
                    tempoav += ((shoots2[i])[j])[h];
                }
                for (int h = foundat+1; h < (shoots2[i])[j].length(); ++h)
                {
                    // ap *
                    tempoar +=  ((shoots2[i])[j])[h] ;
                }
                cerr<<"mul "<<stoi(tempoav)*stoi(tempoar)<<endl;
                playerrounds[players[i]].push_back(stoi(tempoav)*stoi(tempoar));
                tempoav = "";
                tempoar = "";
            }
            else if ( xfound <  (shoots2[i])[j].length() )
            {
                if ( (shoots2[i])[j].length() == 1)
                {
                    playerrounds[players[i]].push_back(-20);
                }
                
                // pour linstant NaN
            }
            else 
            {
                playerrounds[players[i]].push_back(stoi((shoots2[i])[j]));
            }

        }
        int somtempo = 0;
        int compteur = 0;
        
        for (int t = 0 ; t < playerrounds[players[i]].size(); t++)
        {
            somtempo += playerrounds[players[i]][t];

            if ( ( (compteur % 2 ) == 0) && (compteur != 0))
            {  
                score[players[i]].push_back(somtempo);
                compteur  = 0 ;
            }
            else if ( somtempo == 101)
            {
                score[players[i]].push_back(somtempo);
                break;
            }
            else if ( somtempo > 101 )
            {
                somtempo -= playerrounds[players[i]][t];
                score[players[i]].push_back(somtempo);
            }
            else 
            {
                compteur++;
            }            
        }
    }

    cerr<<"scoooore "<<endl;
    for (int i : score[players[0]])
    {
        cerr<<i<<endl;
    }
    cerr<<"end score"<<endl;

    for (int y : playerrounds[players[0]])
    {
        cerr<<y<<endl;
    }

    int min = playerrounds[players[0]].size();
    int storei = 0;
    for ( int i = 0; i < N; i++)
    {
        if ( playerrounds[players[i]].size() < min)
        {
            min = playerrounds[players[i]].size();
            storei = i;
        }
    }
    
    cout<<players[storei]<<endl;


    // Write an answer using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

}