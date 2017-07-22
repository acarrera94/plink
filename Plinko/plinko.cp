/*
 
 Test cases
 
 MENU
 Select an Option
 1 - Drop a single chip into one slot
 2 - Drop multiple chips into one slot
 3 - Drop multiple chips into all slots
 4 - Quit the program
 2
 MULTIPLE
 How many chips to drop? (>0)
 k
 INVALID
 
 
 MENU
 Select an Option
 1 - Drop a single chip into one slot
 2 - Drop multiple chips into one slot
 3 - Drop multiple chips into all slots
 4 - Quit the program
 2
 MULTIPLE
 How many chips to drop? (>0)
 j
 INVALID
 
 
 MENU
 Select an Option
 1 - Drop a single chip into one slot
 2 - Drop multiple chips into one slot
 3 - Drop multiple chips into all slots
 4 - Quit the program
 2
 MULTIPLE
 How many chips to drop? (>0)
 2
 Which slot do you want to drop the chips in (0-8)?
 j
 INVALID
 
 
 MENU
 Select an Option
 1 - Drop a single chip into one slot
 2 - Drop multiple chips into one slot
 3 - Drop multiple chips into all slots
 4 - Quit the program
 3
 ALL SLOTS
 How many chips to drop in each slot? (>0)
 Potato
 INVALID
 
 
 MENU
 Select an Option
 1 - Drop a single chip into one slot
 2 - Drop multiple chips into one slot
 3 - Drop multiple chips into all slots
 4 - Quit the program
 1
 SINGLE
 Select a spot to drop your chip (0-8)
 4
 Path: [4.0 3.5 3.0 3.5 4.0 3.5 3.0 3.5 3.0 2.5 2.0 2.5 3.0]
 WINNINGS: $0.00
 
 
 MENU
 Select an Option
 1 - Drop a single chip into one slot
 2 - Drop multiple chips into one slot
 3 - Drop multiple chips into all slots
 4 - Quit the program
 2
 MULTIPLE
 How many chips to drop? (>0)
 4
 Which slot do you want to drop the chips in (0-8)?
 5
 TOTAL WINNINGS: $12000.00
 AVERAGE WINNINGS: $3000.00
 
 
 MENU
 Select an Option
 1 - Drop a single chip into one slot
 2 - Drop multiple chips into one slot
 3 - Drop multiple chips into all slots
 4 - Quit the program
 3
 ALL SLOTS
 How many chips to drop in each slot? (>0)
 55
 For slot 1:
 TOTAL WINNINGS: $45600.00
 AVERAGE WINNINGS: $829.09
 
 
 For slot 2:
 TOTAL WINNINGS: $68600.00
 AVERAGE WINNINGS: $1247.27
 
 
 For slot 3:
 TOTAL WINNINGS: $75500.00
 AVERAGE WINNINGS: $1372.73
 
 
 For slot 4:
 TOTAL WINNINGS: $170000.00
 AVERAGE WINNINGS: $3090.91
 
 
 For slot 5:
 TOTAL WINNINGS: $197500.00
 AVERAGE WINNINGS: $3590.91
 
 
 For slot 6:
 TOTAL WINNINGS: $162400.00
 AVERAGE WINNINGS: $2952.73
 
 
 For slot 7:
 TOTAL WINNINGS: $108400.00
 AVERAGE WINNINGS: $1970.91
 
 
 For slot 8:
 TOTAL WINNINGS: $44300.00
 AVERAGE WINNINGS: $805.45
 
 
 MENU
 Select an Option
 1 - Drop a single chip into one slot
 2 - Drop multiple chips into one slot
 3 - Drop multiple chips into all slots
 4 - Quit the program
 4
 GOODBYE
 */
#include <iostream>
#include <ctime>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <limits>

using namespace std;




   

void print_menu();
void doOption1(    int& spotmax,
               int& spotmin,
               int& pegRows,
               int& possiblities,
               int& right,
               int& left,
               double& peg,
               double& spot,
               int& chips,
               double& winnings,
               int& chipsMin,
               int& chipstart);
void doOption2 (
                int& spotmax,
                int& spotmin,
                int& pegRows,
                int& possiblities,
                int& right,
                int& left,
                double& peg,
                double& spot,
                int& chips,
                double& winnings,
                double& previousWinnings,
                double&averageWinnings,
                double& totalWinnings,
                int& chipsMin,
                int& chipstart);
void doOption3 (
                int& spotmax,
                int& spotmin,
                int& pegRows,
                int& possiblities,
                int& right,
                int& left,
                double& peg,
                double& spot,
                int& chips,
                double& winnings,
                double& previousWinnings,
                double&averageWinnings,
                double& totalWinnings,
                int& chipsMin,
                int& chipstart
                );
void chanceLorR(
                int &pegRows,
                int &right,
                int &left,
                double &peg,
                double &spot,
                int &spotmin,
                int &spotmax,
                int &leftOrRight
                );
double winnings_in_round (double spot, double winnings);
void invalid_input ();

int main()
{
    int spotmax= 8;
    int spotmin= 0;
    int pegRows= 12;
    int possiblities = 2;
    int right=1;
    int left=0;
    double peg= .5;
    double spot = 0;
    int chips = 0;
    double winnings = 0;
    double totalWinnings= 0;
    double previousWinnings = 0;
    double averageWinnings = 0;
    int chipsMin = 0;
    int chipstart = 0;

    
    const int option1 = 1;
    const int option2 = 2;
    const int option3 = 3;
    const int option4 = 4;
    srand( (unsigned int) time(0) );
    
    
    while (true)
    {

    int option = 0;
        
    
        print_menu(); //show menu
        cin >> option;
    
    
    if (option == option1)
    {
        cout << "SINGLE" << endl;
        cout << "Select a spot to drop your chip (0-8)" << endl;
        
        cin >> spot;
         doOption1(spotmax,
                       spotmin,
                       pegRows,
                       possiblities,
                       right,
                       left,
                       peg,
                       spot,
                       chips,
                       winnings,
                       chipsMin,
                   chipstart);
    }
     
     
    else if (option == option2)
    {
        cout << "MULTIPLE" << endl;
        cout << "How many chips to drop? (>0)" << endl;
        
        cin >> chips;
        if (chips <= chipsMin || cin.fail())
        {
             invalid_input ();
            
        }
        else if (chips > chipsMin)
                {
                    cout << "Which slot do you want to drop the chips in (0-8)?" << endl;
                    
                    
                    cin >> spot;
                    chipstart = spot;
                    
                    if (spot < spotmin || spot > spotmax || cin.fail()) {
                        invalid_input ();
                        
                    }
                    else if (spot >= spotmin && spot <=spotmax)
                    {
                    doOption2 (
                        spotmax,
                        spotmin,
                        pegRows,
                        possiblities,
                        right,
                        left,
                        peg,
                        spot,
                        chips,
                        winnings,
                        previousWinnings,
                        averageWinnings,
                        totalWinnings,
                        chipsMin,
                    chipstart);
                    }
                    else
                    {
                         invalid_input ();
                    }
                }
        else
        {
            invalid_input ();
        }
        
        
                }
    else if (option == option3)
    {

        doOption3 (
                   spotmax,
                   spotmin,
                   pegRows,
                   possiblities,
                   right,
                    left,
                    peg,
                    spot,
                    chips,
                    winnings,
                    previousWinnings,
                   averageWinnings,
                    totalWinnings,
                    chipsMin,
                    chipstart
                   );

     
    }
    else if (option == option4)
    {
        cout << "GOODBYE" << endl;
        break;
    }
    else
    {

         invalid_input ();
       
        
    }
    }
    system ("pause");
    return 0;
}






//functions
void doOption1(    int& spotmax,
               int& spotmin,
               int& pegRows,
               int& possiblities,
               int& right,
               int& left,
               double& peg,
               double& spot,
               int& chips,
               double& winnings,
               int& chipsMin,
               int& chipstart)
{
   
    
    if (spot > spotmax || spot < spotmin || cin.fail())
    {
        invalid_input ();
        
    }
    
    
    else if (spot >= spotmin && spot <= spotmax)
    {
        cout << "Path: [";
        cout << fixed << setprecision(1) << spot ;
        
        
        
        for (int counter = 0; counter < pegRows; counter ++) //path on board
        {
            
            
            int leftOrRight = rand() % possiblities;
            chanceLorR(
                       pegRows,
                       right,
                       left,
                       peg,
                       spot,
                       spotmin,
                       spotmax,
                       leftOrRight
                       );
            cout << " " << fixed << setprecision(1) <<  spot ;
        }
        
        cout << "]"<< endl;
        
        winnings = winnings_in_round ( spot, winnings);
        
        cout << "WINNINGS: $"<< fixed  << setprecision(2) << winnings << endl;
        cout << endl << endl;
    }
    else
    {
         invalid_input ();
    }

    
    
}

void doOption2 (
                int& spotmax,
                int& spotmin,
                int& pegRows,
                int& possiblities,
                int& right,
                int& left,
                double& peg,
                double& spot,
                int& chips,
                double& winnings,
                double& previousWinnings,
                double& averageWinnings,
                double& totalWinnings,
                int& chipsMin,
                int& chipstart)
{


            
            for (int counter= 0; counter < chips; counter++)
            {                                                   // for how many chips
                
                      spot = chipstart;//reset chip spot
                for (int counter = 0; counter < pegRows; counter ++) // one board
                {
                    
                    
                    
                    int leftOrRight = rand() % possiblities;
                    
                    chanceLorR(
                               pegRows,
                               right,
                               left,
                               peg,
                               spot,
                               spotmin,
                               spotmax,
                               leftOrRight
                               );
                    
                } //end of each chip
                
                winnings = winnings_in_round ( spot, winnings); //winnings function
                
                
                
                totalWinnings = winnings + previousWinnings;
                
                
                previousWinnings = totalWinnings;

                
                
                
            }//end of total chips loop
            
            averageWinnings = totalWinnings/chips;
            
            cout << "TOTAL WINNINGS: $" << fixed << setprecision(2) << totalWinnings << endl;
            cout << "AVERAGE WINNINGS: $" << fixed << setprecision(2) << averageWinnings << endl << endl << endl;
            totalWinnings = 0;
            winnings = 0;
            previousWinnings = 0; //reseting winnings
            
            
            
    
        

    
}


void doOption3 (
                int& spotmax,
                int& spotmin,
                int& pegRows,
                int& possiblities,
                int& right,
                int& left,
                double& peg,
                double& spot,
                int& chips,
                double& winnings,
                double& previousWinnings,
                double&averageWinnings,
                double& totalWinnings,
                int& chipsMin,
                int& chipstart
                )
{
    cout << "ALL SLOTS" << endl;
    cout << "How many chips to drop in each slot? (>0)" << endl;
    
    cin >> chips;
    if (chips <= chipsMin || cin.fail() )
    {
        invalid_input ();
        
    }
    else if (chips > chipsMin)
    {


//for each spot
        //for how many chips
        spot = 0;
        chipstart =  0;
        for (int slot = 0; slot < spotmax; slot ++) {
            cout << "For slot " << fixed << setprecision(0) << spot +1 <<":" << endl;
            
            doOption2 (
                       spotmax,
                       
                       spotmin,
                       pegRows,
                       possiblities,
                       right,
                       left,
                       peg,
                       spot,
                       chips,
                       winnings,
                       previousWinnings,
                       averageWinnings,
                       totalWinnings,
                       chipsMin,
                       chipstart);
            chipstart++;
            spot = chipstart;
        }
        //Drop chips into slot 1, 2, etc.
        //do option1
        //Report winnings for each slot
        
        }
    else
    {
        invalid_input();
    }
    
    
}


double winnings_in_round (double spot, double winnings) //winings function
{

    if (spot == 0)
    {
         winnings = 100.00;
    }
    else if (spot == 1)
    {
        winnings = 500.00;
    }
    else if (spot == 2)
    {
        winnings = 1000.00;
    }
    else if (spot ==3)
    {
        winnings = 0.00;
    }
    else if (spot ==4)
    {
        winnings = 10000.00;
    }
    else if (spot ==5)
    {
        winnings = 0.00;
    }
    else if (spot == 6)
    {
        winnings = 1000.00;
    }
    else if (spot == 7)
    {
        winnings = 500.00;
    }
    else if (spot ==8)
    {
        winnings = 100.00;
    }
    
    return winnings;
}

void chanceLorR( //left or right function
                   int &pegRows,
                   int &right,
                   int &left,
                   double &peg,
                   double &spot,
                   int &spotmin,
                int &spotmax,
                    int &leftOrRight
                   )
{

    
    if (leftOrRight == right) //go right
    {
        if (spot < spotmax  && spot >= spotmin )
        {
            spot = spot + peg;
        }
        else if (spot == spotmax) //unless it's 8
        {
            spot = spot - peg;
        }
    }
    else if (leftOrRight == left ) //go left
    {
        if (spot <= spotmax  && spot > spotmin )
        {
            spot = spot - peg;
        }
        else if (spot == spotmin) //unless it's 0
        {
            spot = spot + peg;
        }
    }
}
void print_menu()
{
    cout << "MENU" << endl;
    cout << "Select an Option" << endl;
    cout << "1 - Drop a single chip into one slot" << endl;
    cout << "2 - Drop multiple chips into one slot" << endl;
    cout << "3 - Drop multiple chips into all slots" << endl;
    cout << "4 - Quit the program" << endl;
}

void invalid_input ()
{
    cout << "INVALID" << endl << endl << endl;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');

}