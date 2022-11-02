#include<iostream>
#include<fstream>
#include<vector>
#include<string>
using namespace std;

class Contact{
    int id;
    string contactName;
    string contactNumber;
    int no_of_time_contacted;
    public:
    Contact(){
        this->no_of_time_contacted = 0;
    }
    void setContactName(string name){
        this->contactName = name;
    }
    void setContactNumber(string phoneNumber){
        this->contactNumber = phoneNumber;
    }
    void setNo_Of_Time_Contacted(int number){
        this->no_of_time_contacted += number; 
    }
    void setId(int contactid){
        this->id = contactid;
    }
    string getContactName(){
        return (this->contactName);
    }
    string getContactNumber(){
        return (this->contactNumber);
    }
    int getNo_Of_Time_Contacted(){
        return (this->no_of_time_contacted);
    }
    int getId(){
        return (this->id);
    }
    friend std::ostream & operator << (std::ostream &out, const Contact & contact);
    friend std::istream & operator >> (std::istream &in,  Contact &contact);
};

std::ostream & operator << (std::ostream &out, const Contact & contact){
    out << contact.id << "\n" << contact.contactName << "\n" << contact.contactNumber << "\n" << contact.no_of_time_contacted << endl;
    return out;
}

std::istream & operator >> (std::istream &in,  Contact &contact){
    in >> contact.id;
    in >> contact.contactName;
    in >> contact.contactNumber;
    in >> contact.no_of_time_contacted;
    return in;
}

class ContactManagement{
    public:

    void addContact(Contact &contact){
        if(fopen("Contact.txt","r")){
            fstream contactFile("Contact.txt",ios::app);
            fstream contactCount("ContactCount.txt",ios::in);
            int count;
            contactCount >> count;
            contactCount.close();
            count = count + 1;
            contactCount.open("ContactCount.txt",ios::out);
            contact.setId(count);
            contactCount << count;    
            contactFile << contact;
            contactCount.close();
            contactFile.close();
        }
        else{
            fstream contactFile("Contact.txt",ios::app);
            fstream contactCount("ContactCount.txt",ios::out);
            contactCount << 1;
            contact.setId(1);
            contactFile << contact;
            contactFile.close();
            contactFile.close();
        }
    }

    bool searchById(int id){
        fstream contactFile("Contact.txt",ios::in);
        Contact tempcontact;
        while(contactFile >> tempcontact){
            if(tempcontact.getId() == id){
                return true;       
            }
        }
        return false;        
    }

    Contact getSpecificContact(int id){
        fstream contactFile("Contact.txt",ios::in);
        Contact tempcontact;
        while(contactFile >> tempcontact){
            if(tempcontact.getId() == id){
                return tempcontact;       
            }
        }
        return tempcontact; 
    }

    int searchContactByName(string searchName){
        fstream contactFile("Contact.txt",ios::in);
        Contact tempcontact;
        while(contactFile >> tempcontact){
            if(tempcontact.getContactName() == searchName){
                return tempcontact.getId();        
            }
        }
        return -1;
    }

    int searchContactByNumber(string searchNumber){
        fstream contactFile("Contact.txt",ios::in);
        Contact tempcontact;
        while(contactFile >> tempcontact){
            if(tempcontact.getContactNumber() == searchNumber){
                return tempcontact.getId();       
            }
        }
        return -1;
    }

    void deleteContact(int contactId){
        fstream contactFile("Contact.txt",ios::in);
        vector<Contact> contactList;
        Contact contact;
        while (contactFile >> contact)
        {
            contactList.push_back(contact);
        }
        contactFile.close();
        for(int i = 0;i<contactList.size();i++){
            if(contactList[i].getId() == contactId){
                contactList.erase(contactList.begin()+(contactId - 1));                
            }
        }
        contactFile.open("Contact.txt",ios::out);
        fstream contactcount ("ContactCount.txt",ios::out);
        contactcount << contactList.size();
        contactcount.close();
        for(int i = 0;i<contactList.size();i++){
            contactList[i].setId(i+1);
            contactFile << contactList[i];
        }
        contactFile.close();
    }

    void updateContactName(int contactId,string Name){ //update contact name by using contact id
        fstream contactFile("Contact.txt",ios::in);
        vector<Contact> contactList;
        Contact contact;
        while (contactFile >> contact)
        {
            contactList.push_back(contact);
        }
        contactFile.close();
        contactList.at(contactId - 1).setContactName(Name);
        contactFile.open("Contact.txt",ios::out);
        for(int i = 0;i<contactList.size();i++){
            contactFile << contactList[i];
        }
        contactFile.close();
    }

    void updateContactNumber(int contactId,string PhoneNumber){
        fstream contactFile("Contact.txt",ios::in);
        vector<Contact> contactList;
        Contact contact;
        while (contactFile >> contact)
        {
            contactList.push_back(contact);
        }
        contactFile.close();
        contactList.at(contactId - 1).setContactName(PhoneNumber);
        contactFile.open("Contact.txt",ios::out);
        for(int i = 0;i<contactList.size();i++){
            contactFile << contactList[i];
        }
        contactFile.close();
    }

    void Call(int contactId){
        fstream contactFile("Contact.txt",ios::in);
        vector<Contact> contactList;
        Contact contact;
        while (contactFile >> contact)
        {
            contactList.push_back(contact);
        }
        contactFile.close();
        contactList.at(contactId - 1).setNo_Of_Time_Contacted(1);
        contactFile.open("Contact.txt",ios::out);
        fstream callHistory("Callhistory.txt",ios::app);
        callHistory << contactList.at(contactId - 1);
        for(int i = 0;i < contactList.size();i++){
            contactFile << contactList[i];
        }
        contactFile.close();
        callHistory.close();
    }

    void displayContact(){
        fstream contactFile("Contact.txt",ios::in);
        // vector<Contact> contactList;
        Contact contact;
        while (contactFile >> contact)
        {   
            cout << contact.getId() << " ";
            cout << contact.getContactName() << "    ";
            cout << contact.getContactNumber() << "\n";            
        }
        contactFile.close();
    }

    bool validatePhoneNumber(string phonenumber){
        if(phonenumber.length() != 10){
            return false;
        }
        for(int i = 0;i<phonenumber.length();i++){
            if(!isdigit(phonenumber[i])){
                return false;
            }
        }
        return true;
    }

    bool checkAlreadyExistContact(string name,string phonenumber){
        int nameid = this->searchContactByName(name);
        int numberid = this->searchContactByNumber(phonenumber);
        if((nameid > 0) & (numberid > 0)){
        if(nameid == numberid){
           return true; 
            }
            else{
                return false;
            }
        }
        else{
            return false;
        }
    }

    void displayCallHistory(){
        fstream contactFile("Callhistory.txt",ios::in);
        vector<Contact> contactList;
        Contact contact;
        while (contactFile >> contact)
        {   
            contactList.push_back(contact);
        }
        contactFile.close();        
        for(int i = contactList.size()-1;i >= 0;i--){
            cout << contactList[i].getContactName() << "    " << contactList[i].getContactNumber() <<endl;
        }
    }
};
int main(){
    try{
    int option;
    ContactManagement manage;
    bool flag = true;
    while(flag){
    std::cout << "\t\t\t1.Call\n\t\t\t2.Search Contact\n\t\t\t3.Add new Contact\n\t\t\t4.delete Contact\n\t\t\t5.Update Contact\n\t\t\t6.History\n\t\t\t7.Exit\n";
    if(!(std::cin >> option)){
        throw "Invalid option!";
    }
    if(option == 1){
        cout << "\t\t\t1.Show Contact List\n\t\t\t2.Enter PhoneNumber\n";
        int suboption;
        if(!(cin >> suboption)){
            throw "Invalid option!";
        }
        if(suboption == 1){
            manage.displayContact();
            int calloption;
            if(!(cin >> calloption)){
                throw "Invalid option!";
            }
            if(manage.searchById(calloption)){
            manage.Call(calloption);
            cout << "Speaking to " << manage.getSpecificContact(calloption).getContactName() << endl;
            }
            else{
                cout << "Invalid option \n";
            }
        }
        else if(suboption == 2){
            string Phonenumber;
            cout << "Enter the PhoneNumber : ";
            cin >> Phonenumber;
            if(manage.validatePhoneNumber(Phonenumber)){
                int searchcontactid = manage.searchContactByNumber(Phonenumber);
                if(searchcontactid < 0){
                Contact newNumber;
                newNumber.setContactNumber(Phonenumber);
                newNumber.setContactName("Anonymous");
                newNumber.setId(0);
                newNumber.setNo_Of_Time_Contacted(1);
                fstream callhistory("CallHistory.txt",ios::app);
                callhistory << newNumber;
                callhistory.close();
                cout << "Speaking to "<<Phonenumber<<endl;
                }
            else{
                manage.Call(searchcontactid);
                cout << "Speaking to " << manage.getSpecificContact(searchcontactid).getContactName() << endl;
                }
            }
            else{
                cout << "Invalid phone number";
            }
        }
    } 
    else if(option == 2){
        cout << "\t\t\t1.Search By Name\n\t\t\t2.Search By Phone Number\n";
        int suboption2;
        if(!(cin >> suboption2)){
            throw "Invalid option!";
        }
        if(suboption2 == 1){
            string searchName;
            cout << "Enter Name : ";
            cin >> searchName;
            Contact searchedContact;
            int searchContactId = manage.searchContactByName(searchName);
            if(searchContactId > 0){
                searchedContact = manage.getSpecificContact(searchContactId);
                cout << "Name : " << searchedContact.getContactName() << endl;
                cout << "Phone Number : " << searchedContact.getContactNumber() << endl;
                cout << "Contacted " << searchedContact.getNo_Of_Time_Contacted() << " times\n";
            }
            else{
                cout << "Contact with Name " << searchName << " does not exist." <<endl;
            }
        }
        else if(suboption2 == 2){
            string searchNumber;
            cout << "Enter phone number : ";
            cin >> searchNumber;
            Contact searchedContact;
            int searchContactId = manage.searchContactByNumber(searchNumber);
            if(searchContactId > 0){
                searchedContact = manage.getSpecificContact(searchContactId);
                cout << "Name : " << searchedContact.getContactName() << endl;
                cout << "Phone Number : " << searchedContact.getContactNumber() << endl;
                cout << "Contacted " << searchedContact.getNo_Of_Time_Contacted() << " times";
            }
            else{
                cout << "Contact with Phone Number " << searchNumber << " does not exist." <<endl;
            }
        }        
    } 
    else if(option == 3){
        string name;
        string phonenumber;
        cout << "Enter Name : ";
        cin >> name;
        cin.ignore();
        cout << "Enter phone number : ";
        cin >> phonenumber;
        if(manage.validatePhoneNumber(phonenumber)){
        if((manage.searchContactByName(name) < 0) & (manage.searchContactByNumber(phonenumber) < 0)){
            Contact contact;
            contact.setContactName(name);
            contact.setContactNumber(phonenumber);
            manage.addContact(contact);
        }
        else{
            cout << "Contact Already exists.\n";
        }
    }
        else{
            cout << "Invalid Phone number\n";
        }
    }
    else if(option == 4){
        string deleting_contact_name;
        cout << "Enter Name of contact need to delete : ";
        cin >> deleting_contact_name;
        int deleting_contact_id = manage.searchContactByName(deleting_contact_name);
        if(deleting_contact_id > 0){
            manage.deleteContact(deleting_contact_id);
            cout << "Contact deleted\n";
        }
        else{
            cout << "Contact named "<<deleting_contact_name << " does not exist.\n";
        }
    }
    else if(option == 5){
        manage.displayContact();
        cout << "Enter contact need to update : ";
        int contactid;
        if(!(cin >> contactid)){
            throw "Invalid option!";
        }
        Contact updatecontact;
        updatecontact = manage.getSpecificContact(contactid);
        cout << "1.Name : " << updatecontact.getContactName() << "\n";
        cout << "2.PhoneNumber : " << updatecontact.getContactNumber() << "\n";
        cout << "Enter 1(name) or 2(phonenumber) or 3(update All) to update : ";
        int updateoption;
        if(!(cin >> updateoption)){
            throw "Invalid option!";
        }
        if(updateoption == 1){
            string updatedname;
            cout << "Enter updated name : ";
            cin >> updatedname;
            manage.updateContactName(contactid,updatedname);
            cout << "Contact Name updated\n";
        }
        else if(updateoption == 2){
            string updatedphonenumber;
            cout << "Enter updated phonenumber : ";
            cin >> updatedphonenumber;
            manage.updateContactNumber(contactid,updatedphonenumber);
            cout << "Contact Phone number updated\n";
        }
        else if(updateoption == 3){
            string updatedname;
            cout << "Enter updated name : ";
            cin >> updatedname;
            string updatedphonenumber;
            cout << "Enter updated phonenumber : ";
            cin >> updatedphonenumber;
            manage.updateContactNumber(contactid,updatedphonenumber);
            manage.updateContactName(contactid,updatedname);
            cout << "Contact Updated\n";
        }
    }
    else if(option == 6){
        manage.displayCallHistory();
    }
    else if(option == 7){
        flag = false;
       }
    else{
        flag = false;
        }
    }
}
    catch(const char *errorchar){
        cout << errorchar << endl;
    } 
}