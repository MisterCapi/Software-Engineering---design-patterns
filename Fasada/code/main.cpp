#include <iostream>
#include <vector>

using namespace std;


class CompanyInformation {
public:
    CompanyInformation(string companyName, string companyInformation){
        this->companyName = move(companyName);
        this->companyInformation = move(companyInformation);
    }

    string getCompanyName(){
        return this->companyName;
    }

    string getCompanyInformation(){
        return this->companyInformation;
    }

private:
    string companyName;
    string companyInformation;
};


class DataBase {
public:
    bool isInformationOnCompany(string companyName){
        for(int i=0; i<companyInformations.size(); i++){
            if(companyInformations[i].getCompanyName() == companyName)
                return true;
        }
        return false;
    }

    string getInformationOnCompany(string companyName){
        for(int i=0; i<companyInformations.size(); i++){
            if(companyInformations[i].getCompanyName() == companyName) {
                cout << "DataBase found and returned info on " << companyName << endl;
                return companyInformations[i].getCompanyInformation();
            }
        }
        return "No info";
    }

    void addInformationOnCompany(string companyName, string companyInfo){
        cout << "DataBase added info on " << companyName << endl;
        companyInformations.emplace_back(companyName, companyInfo);
    }

private:
    vector<CompanyInformation> companyInformations;
};


class WebScrapper {
public:
    string gatherInformationOnCompany(string companyName){
        cout << "WebScprapper gathered info on " << companyName << endl;
        return "Informations about " + companyName;
    }
};


class CompanyInfoAPI {
public:
    CompanyInfoAPI(DataBase* db, WebScrapper* ws){
        this->database = *db;
        this->webScrapper = *ws;
    }

    string getInformationOnCompany(string companyName){
        if(database.isInformationOnCompany(companyName)){
            return database.getInformationOnCompany(companyName);
        }
        else{
            cout << "No info on " << companyName << " in database, launching webscrapper" << endl;
            string informations = webScrapper.gatherInformationOnCompany(companyName);
            database.addInformationOnCompany(companyName, informations);
            return informations;
        }
    }

private:
    DataBase database;
    WebScrapper webScrapper;
};


class User {
public:
    User(CompanyInfoAPI* api){
        this->API = api;
    }

    void useAPI(){
        cout << API->getInformationOnCompany("Microsoft") << endl << endl;
        cout << API->getInformationOnCompany("Amazon") << endl << endl;
        cout << API->getInformationOnCompany("Apple") << endl << endl;
        cout << API->getInformationOnCompany("Microsoft") << endl << endl;
        cout << API->getInformationOnCompany("Amazon") << endl << endl;
    }

private:
    CompanyInfoAPI* API;
};


int main() {
    //Backend
    DataBase* db = new DataBase();
    WebScrapper* ws = new WebScrapper();
    CompanyInfoAPI* api = new CompanyInfoAPI(db, ws);

    //User
    User myUser = User(api);
    myUser.useAPI();

    return 0;
}
