/* CODING GAME 03/04/2021 */


// -------------- GAME 3 IPv6-shortner --------------------//


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
    string ip;
    getline(cin, ip);

    vector<char> resultvec;

    string cssip = ip;
    int etat = 0;
    vector<int> numzero;
    vector<int> rescnt;
    int j = 0, zero = 0;
    vector<int> state;

    vector<int> pointpointpos;

    for (int i = 0; i < ip.length(); ++i)
    {
        if ( ip[i] == ':')
        {
            pointpointpos.push_back(i);
        }
    }

    for (int i = 0; (ip[i] != ':' ); ++i)
    {
        if ( ip[i] == '0')
        {
            zero++;
        }
        else 
        {
            state.push_back(i);
            break;
        }
    } 
    
    numzero.push_back(zero);
    zero = 0;
    
    for ( int k : pointpointpos)
    {
        for (int i = k+1; (ip[i] != ':' ) || (i == (ip.length() -  1) ); ++i)
        {
            if ( ip[i] == '0')
            {
                zero++;
            }
            else 
            {
                state.push_back(i);
                break;
            }
        } 
        numzero.push_back(zero);
        zero = 0;
    }

    int cnt = 0;
    int k = 0;
    while ( k < numzero.size())
    {
        if ( numzero[k] == 0)
        {
            // rien
            resultvec.push_back('/');
            k++;
        }
        else 
        {
            if ( (numzero[k+1] != 4) && (numzero[k] == 4) )
            {
                // cas nb(0) = 4
                //cpip.replace(5*k, 4, "0");
                resultvec.push_back('z');
                k++;
            }
            else if ( numzero[k] != 4  )  
            {
                // cas nb(0) < 4
                resultvec.push_back(numzero[k]+48);
               // ip.erase(5*k, numzero[k]);
                k++;
            }
            else if (  (numzero[k] == 4) && (numzero[k+1] == 4) )
            {
                etat = k;
                // cas ::
                while ( numzero[++k] == 4)
                {
                    cnt++;
                }
                resultvec.push_back('p');
                rescnt.push_back(cnt);
               // cssip.replace(5*etat,(cnt+1)*4 + (cnt+1), ":");
            }
        }
        
    }


    string result ;
    int cnttemp = 0;

    for (int l = 0; l < resultvec.size(); ++l)
    {
        if ( resultvec[l] == '/')
        {
            for (int n = 0 ; n < 5; n++)
            {
                result += ip[(l+cnttemp)*5 + n];
            }
        }
        else if ( resultvec[l] == 'z')
        {
            result += "0:";
        }
        else if ( resultvec[l] == 'p')
        {
            result += ":";
            if ( l == 0)
            {
                result+=":";
            }
            cnttemp = rescnt.back();
            rescnt.pop_back();
        }
        else 
        {
            for (int n = (resultvec[l]-48) ; n < 5; n++)
            {
                result += ip[(l+cnttemp)*5 + n];
            }
        }
        
    }

    // Write an answer using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;
    cerr<<result<<endl;

    cout<<result<<endl;

}
