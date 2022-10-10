#include "header.cpp"

int encounterId;
vector<string> encounter_vector;
string encounterText;

string Generate_Encounter()
{
    ifstream myEncounterFile("encounters.txt");
    
    if (myEncounterFile.is_open()) 
    {
        while (getline(myEncounterFile, encounterText)) { // while loop using our file f - >> "id" >> "idname" means our vector will read the first column's data as name and second as score
            encounter_vector.push_back(encounterText); // this fills score_vector with
        }

        myEncounterFile.close(); // closes the file 
    }

    int encounterId = rand() % encounter_vector.size();
    encounterText = encounter_vector.at(encounterId);

    sleep(2);
    return encounterText;
}

void Print_Encounter()
{
    cout << encounterText << endl;
}

/*
int main()
{
    system("clear");
    srand(time(NULL));
    
    Generate_Encounter();
    Print_Encounter();
    return 0;
}
*/
