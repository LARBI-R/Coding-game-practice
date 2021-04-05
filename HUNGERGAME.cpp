/* CODING GAME 03/04/2021 */



/** GAME 9 HUNGER GAME **************************************/ 

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

    vector<string> players;
    vector<string> infos ;


    int tributes;
    cin >> tributes; cin.ignore();
    for (int i = 0; i < tributes; i++) {
        string playerName;
        getline(cin, playerName);   
        players.push_back(playerName);
    }
    string result = "";
    int ok = 0 ;
    int turns;
    cin >> turns; cin.ignore();
    for (int i = 0; i < turns; i++) {
        string info;
        getline(cin, info);

        cerr<<info<<endl;

        for (int j = 0 ; j < players.size(); j++)
        {
            size_t foundPlayer = info.find(players[j]);
            size_t foundKilled = info.find("killed");
            

            size_t foundplinfo = info.find(players[j]);
            if (foundplinfo != string::npos)
            {
                if ( foundPlayer > foundKilled)
                {
                    if ( ok != 0 )
                    {
                        cout<<endl;
                    }
                    ok++;
                    cout<<"Name: "<<players[j]<<endl;
                    cout<<"Killed: None"<<endl;
                    //int cnt = 0;
                    cout<<"Killer: ";

                    for ( string pl : players)
                    {
                        if ( pl == players[j])
                        {

                        }
                        else 
                        {
                            size_t found = info.find(pl);
                            if (found != string::npos)
                            {
                                cout<<pl;
                            }
                        }
                        
                    }
                    cout<<endl;
                    /*
                    for ( string pl : players)
                    {   
                        if ( pl != players[j])
                        {
                            cnt++;
                            if ( cnt >  1)
                            {
                                cout<<",";
                            }
                            cout<<pl;
                        }
                    }
                    cnt = 0;
                    cout<<endl;
                    */

                }
                if ( ( foundPlayer < foundKilled) )
                {
                    if ( ok != 0 )
                    {
                        cout<<endl;
                    }
                    ok++;
                    cout<<"Name: "<<players[j]<<endl;
                    //int cnt2 = 0;
                    cout<<"Killed: ";

                    for ( string pl : players)
                    {
                        if ( pl == players[j])
                        {

                        }
                        else 
                        {
                            size_t found = info.find(pl);
                            if (found != string::npos)
                            {
                                cout<<pl;
                            }
                        }
                        
                    }
                    cout<<endl;

                    /*
                    for ( string pl : players)
                    {   
                        if ( pl != players[j])
                        {
                            cnt2++;
                            if ( cnt2 >  1)
                            {
                                cout<<",";
                            }
                            cout<<pl;
                        }
                    }
                    cnt2 = 0;
                    cout<<endl;

                    */

                    cout<<"Killer: Winner"<<endl;
                }
            }
            else 
            {
                //
            }
            
        }

        //cout<<result<<endl;
        
    }

    

    // Write an answer using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

}