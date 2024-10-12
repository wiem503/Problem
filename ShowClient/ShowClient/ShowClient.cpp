// ShowClient.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include<string>
#include<vector>
#include<iomanip>
#include<fstream>
using namespace std;
const string FileNameClient = "Client.txt";
struct Sclients {
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;

};
vector<string>splitString(string S1, string Delim) {    vector<string>vString;
    short pos = 0;
    string Sword ;
    while ((pos = S1.find(Delim) )!= std::string::npos) {
        Sword = S1.substr(0, pos);
        if (Sword != "") {
            vString.push_back(Sword);
        }
            S1.erase(0,pos + Delim.length());
        }
        if (S1 != "") {
            vString.push_back(S1);
        }
        return vString;

    }
Sclients ConvertlineToData(string Line, string Seperator = "#//#") {
    Sclients Client;
    vector<string>VClientData ;
    VClientData = splitString(Line, Seperator);
    Client.AccountNumber = VClientData[0];
    Client.PinCode = VClientData[1];
    Client.Name = VClientData[2];
    Client.Phone = VClientData[3];
    Client.AccountBalance =stod(VClientData[4]);
    return  Client;
}
vector<Sclients>LoadClientToFile(string FileName) {
    vector<Sclients>VClient;
    fstream MyFile;
    MyFile.open(FileName,ios::in);
    if (MyFile.is_open()) {
        string Line;
        Sclients Client;
        while (getline(MyFile, Line)) {
            Client = ConvertlineToData(Line);
            VClient.push_back(Client);

        }
        MyFile.close();

    }
    return VClient;
}
 void PrintClientRecord(Sclients Client) {
     cout << "| " << setw(15) << left << Client.AccountNumber;    
     cout << "| " << setw(10) << left << Client.PinCode;   
     cout << "| " << setw(40) << left << Client.Name;   
     cout << "| " << setw(12) << left << Client.Phone;    
     cout << "| " << setw(12) << left << Client.AccountBalance;
 } void PrintAllClientsData(vector <Sclients> vClient) {
     cout << "\n\t\t\t\t\tClient List (" << vClient.size() << ") Client(s).";
     cout << "\n_______________________________________________________";
     cout << "_________________________________________\n" << endl;
     cout << "| " << left << setw(15) << "Accout Number";
     cout << "| " << left << setw(10) << "Pin Code";
     cout << "| " << left << setw(40) << "Client Name";
     cout << "| " << left << setw(12) << "Phone";
     cout << "| " << left << setw(12) << "Balance";
     cout << "\n_______________________________________________________";
     cout << "_________________________________________\n" << endl;
     for (Sclients Client : vClient) {
         PrintClientRecord(Client);
         cout << endl;
     }
     cout << "\n_______________________________________________________";

     cout << "_________________________________________\n" << endl;
 }



int main()
{
    vector <Sclients> vClients = LoadClientToFile(FileNameClient);
    PrintAllClientsData(vClients);
    system("pause>0");
    return 0;
}

// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
