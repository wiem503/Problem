

#include <iostream>
#include<string>
#include<vector>
#include<fstream>
#include<iomanip>
using namespace std;
const string ClientsFileName = "Client.txt";
struct Sclients {
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    string AccountBalance;

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
    VClientData= SplitClient(Line, Seperator);
    Client.AccountNumber = VClientData[0];  
    Client.PinCode = VClientData[1];  
    Client.Name = VClientData[2];   
    Client.Phone = VClientData[3];  
    Client.AccountBalance = stod(VClientData[4]);//cast string to double
    return Client; 
}
vector <Sclients> LoadCleintsDataFromFile(string  FileName) { 
    vector <Sclients> vClients; 
    fstream MyFile;  
    MyFile.open(FileName, ios::in);//read Mode
    if (MyFile.is_open())     { 
        string Line; 
        Sclients Client;
        while (getline(MyFile, Line))         {  
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
bool FindClientByAccountNumber(string AccountNumber, Sclients& Client) {
    vector<Sclients>VClientData=LoadCleintsDataFromFile(ClientsFileName);
    for (Sclients C : VClientData) {
        if (C.AccountNumber == AccountNumber) {
            Client = C;
            return true;
        }
    }
    return false;
}
string ReadAccountNumber() {
    string AccountNumber = "";
    cout << "\n please AccountNumber";
    cin >> AccountNumber;
    return AccountNumber;
}

int main()
{
    Sclients Client;
    string AccountNumber = ReadAccountNumber();
    if(FindClientByAccountNumber(AccountNumber, Client)) {
        PrintClientCard(Client);
    }
 else { 
        cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!";
    }     
    system("pause>0"); 
    return 0;
    
}
