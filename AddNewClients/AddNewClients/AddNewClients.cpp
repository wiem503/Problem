// AddNewClients.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include<string>
#include<vector>
#include<fstream>
using namespace std;
const string ClientFileName="Client.txt";
struct Sclients {
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;
};
Sclients ReadClients() {
    Sclients Client;

    cout << "entrer les informations des clients " << endl;
    cout << "entrer la AccountNumber de Client";
    getline(cin >> ws, Client.AccountNumber);
    cout << "entrer le PinCode de Client :";
    getline(cin , Client.PinCode);
    cout << "entrer le nom de Client :";
    getline(cin >> ws, Client.Name);
    cout << "entrer la AccountBalance de Client :";
    cin >> Client.AccountBalance;
    return Client;
}
string ConvertDatatoLine(Sclients Client, string Seperator = "#//#") {
    string stClient = "";
        stClient += Client.AccountNumber + Seperator;
        stClient += Client.PinCode + Seperator;
        stClient += Client.Name + Seperator;
        stClient += Client.Phone+ Seperator;
        stClient += to_string(Client.AccountBalance);
        return stClient;
}
void AddDataLineToFile(string FileName, string stDataLine) {
    fstream MyFile;
    MyFile.open(FileName, ios::out | ios::app);
    if(MyFile.is_open()){
        MyFile << stDataLine << endl;
        MyFile.close();


    }
}
void AddNewClient() {
    Sclients Client;
    Client = ReadClients();
    AddDataLineToFile(ClientFileName, ConvertDatatoLine(Client));
}
void AddClients() {
    char AddMore = 'Y';
    do {
        system("cls");
        AddNewClient();
        cout << "do you Add a New Client : ";
        cin >> AddMore;
    } while (toupper(AddMore)=='Y');
}

int main()
{
    AddClients();
    system("pause>0");
        return 0;
    // Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
    // Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

    // Astuces pour bien démarrer : 
    //   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
    //   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
    //   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
    //   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
    //   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
    //   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
}