// DeleteClientByAccountNumber.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include<string>
#include<vector>
#include<fstream>
#include<iomanip>
using namespace std;
const string ClientFileName = "Client.txt";
struct Sclients {
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;
    bool MarkForDelete = false;
};
vector<string>SplitClient(string S1, string Delim) {
    vector<string>vString;
    short pos = 0;
    string Sword;
    while ((pos = S1.find(Delim)) != std::string::npos) {
        Sword = S1.substr(0, pos);
        if (Sword != "") {
            vString.push_back(Sword);
        }
        S1.erase(0, pos + Delim.length());
    }
    if (S1 != "") {
        vString.push_back(S1);

    }
    return vString;
}
Sclients ConvertLineToRecord(string Line, string Seperator = "#//#") {
    Sclients Client;
    vector<string>VClientData;
    VClientData = SplitClient(Line, Seperator);
    Client.AccountNumber = VClientData[0];
    Client.PinCode = VClientData[1];
    Client.Name = VClientData[2];
    Client.Phone = VClientData[3];
    Client.AccountBalance = stod(VClientData[4]);//cast string to double
    return Client;
}
string ConvertLineToRecord(Sclients Client, string Seperator = "#//#") {
    string stClientRecord = "";
    stClientRecord += Client.AccountNumber + Seperator;
    stClientRecord += Client.PinCode + Seperator;
    stClientRecord += Client.Name + Seperator;
    stClientRecord += Client.Phone + Seperator;
    stClientRecord += to_string(Client.AccountBalance);
    return stClientRecord;

}

vector <Sclients> LoadCleintsDataFromFile(string  FileName) {
    vector <Sclients> vClients;
    fstream MyFile;
    MyFile.open(FileName, ios::in);//read Mode
    if (MyFile.is_open()) {
        string Line;
        Sclients Client;
        while (getline(MyFile, Line)) {
            Client = ConvertLineToRecord(Line);
            vClients.push_back(Client);
        }
        MyFile.close();
    }
    return vClients;
}

void PrintClientCard(Sclients Client) {
    cout << "\n the following are the client details";
    cout << "\n AcountNumber" << Client.AccountNumber;
    cout << "\n pincode" << Client.PinCode;
    cout << "\n Name" << Client.Name;
    cout << "\n Phone :" << Client.Phone;
    cout << "\n AccountBalance :" << Client.AccountBalance;


}
bool FindClientByAccountNumber(string AccountNumber, vector<Sclients>& VClients,Sclients &Client) {
    vector<Sclients>VClientData = LoadCleintsDataFromFile(ClientFileName);
    for (Sclients C : VClientData) {
        if (C.AccountNumber == AccountNumber) {
            Client = C;
            return true;
        }
    }
    return false;
}
bool MarkClientForDeleteByAccountNumber(string AccountNumber,vector<Sclients>& VClients){
    for(Sclients &C:VClients)
        if (C.AccountNumber == AccountNumber) {
            C.MarkForDelete= true;
            return true;
        }
    return false;
}
vector<Sclients>SaveClientDataToFile(string FileName, vector<Sclients>& VClients) {
    fstream MyFile;
    MyFile.open(FileName, ios::in);
    string DataLine;
        if(MyFile.is_open()){
            for(Sclients C:VClients){
                if (C.MarkForDelete == false) {
                    DataLine = ConvertLineToRecord(C);
                    MyFile << DataLine << endl;
                }
        }
            MyFile.close();
    }
        return VClients;


}
bool DeleteAccountByAccountNumber(string AccountNumber, vector<Sclients>& VClients) {
    Sclients Client;
    char Answer='n';
    if (FindClientByAccountNumber(AccountNumber,VClients,Client)) {
        PrintClientCard(Client);
        cout << "\n\nAre you sure you want delete this client? y/n ? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y') {
            MarkClientForDeleteByAccountNumber(AccountNumber, VClients);
                SaveClientDataToFile(ClientFileName, VClients);
            VClients = LoadCleintsDataFromFile(ClientFileName);
            cout << "\n\nClient Deleted Successfully.";
            return true;
        }
    }
    else
    {
        cout << "\nClient with Account Number (" << AccountNumber
            << ") is Not Found!";
        return false;
    }
}
string PrintAccountNumber() {
    string AccountNumber="";
    cout << "please entrer your AccountNumber : ";
    cin >> AccountNumber;
    return AccountNumber;
}
        
int main()
{
    vector<Sclients>VClients = LoadCleintsDataFromFile(ClientFileName);
    string AccountNumber = PrintAccountNumber();
    DeleteAccountByAccountNumber(AccountNumber, VClients);
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
