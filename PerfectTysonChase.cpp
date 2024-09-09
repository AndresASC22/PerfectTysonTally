#include<iostream>
#include<fstream>

void IncreaseTotals(int& Total, int& Today);
void AttemptsIncrement(int& P1TodayCount, int& P1TotalCount, int& P2TodayCount, int& P2TotalCount);

int main () {
    std::ifstream PerfectPhase1Count, PerfcetPhase2Count; 
    std::ofstream PerfectTysonILSheet;
    int PerfectP1;
    int PerfectP2;
    int P1Today = 0;
    int P2Today = 0;
    bool attempts = true;

    PerfectTysonILSheet.open("PerfectTyson.txt");
    PerfectPhase1Count.open("Phase1.txt");
    PerfcetPhase2Count.open("Phase2.txt");
    //both int variables will derive their values from the "count" files
    PerfectPhase1Count >> PerfectP1;
    PerfcetPhase2Count >> PerfectP2; 

    AttemptsIncrement(P1Today, PerfectP1, P2Today, PerfectP2);

    PerfectTysonILSheet << "Since (entermonth) (today)" << std::endl;
    PerfectTysonILSheet << "Perfect P1: " << PerfectP1 << "(" << P1Today << ")" << std::endl;
    PerfectTysonILSheet << "Perfect P2: " << PerfectP2 << "(" << P2Today << ")" << std::endl;

    std::ofstream ChangePhase1Count, ChangePhase2Count;
    ChangePhase1Count.open("Phase1.txt");
    ChangePhase2Count.open("Phase2.txt");

    //Adds todays attempt to total count, automatically updating them :3
    ChangePhase1Count << PerfectP1;
    ChangePhase2Count << PerfectP2;
}

void IncreaseTotals(int& Total, int& Today) { //simple addidditive function
    Total++;
    Today++;
}

void AttemptsIncrement(int& P1TodayCount, int& P1TotalCount, int& P2TodayCount, int& P2TotalCount) {
    bool Attempts = true;
    bool P1 = true;
    bool P2 = true;
    //Attempts means total attempts, p1 means while phase 1 is going on
    //and p2 means while phase 2 is going on
    while (Attempts == true) {
        while (P1 == true) {
            //This loop will do all the p1 processes and then move onto p2 if I tally it
            int P1choice;
            std::cout << "Press 1 to tally a perfect phase 1, 2 to end attempts count: ";
            std::cin >> P1choice; 

                if (P1choice == 2) {
                    P1 = false;
                    Attempts = false;
                }

                else if (P1choice == 1) {
                    //All this code will run if we tallied a perfect p1
                    IncreaseTotals(P1TodayCount, P1TotalCount); 
                    P2 = true;
                    while (P2 == true)
                    {
                        int P2Choice;
                        std::cout << "Press 1 to tally a perfect phase 2, 2 to go back to tallying phase 1: ";
                        std::cin >> P2Choice;

                        if (P2Choice == 1) {
                            IncreaseTotals(P2TodayCount, P2TotalCount);
                            P2 = false;
                        }

                        else if (P2Choice == 2) {
                            P2 = false;
                        }
                        
                        else {
                            std::cout << "Error, enter 1 or 2: ";
                        }
                    }
                    
                }

                else {
                    std::cout << "Error, enter 1 or 2. " << std::endl;
                }
        }
    }
}