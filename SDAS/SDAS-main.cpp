#include <iomanip>
#include <iostream>
#include <sstream>
#include <vector>
#include<complex>
#include<thread>
#include <SFML/Graphics.hpp>
#include <sqlite3.h>


using namespace std;


class BankAccount
{
public:
	static const int MAX_SIZE = 30;

	BankAccount(int = 0, string = "",
		string = "", double = 0.0);
	~BankAccount();

	void setAccountNumber(int);
	void setLastName(string);
	void setFirstName(string);
	void setBalance(double);

	int getAccountNumber() const;
	string getFirstName() const;
	string getLastName() const;
	double getBalance() const;

private:
	int accountNumber;
	char firstName[MAX_SIZE];
	char lastName[MAX_SIZE];
	double balance;
};

static int callback(void* data, int argc, char** argv, char** azColName)
{
    int i;
    fprintf(stderr, "%s: ", (const char*)data);

    for (i = 0; i < argc; i++) {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }

    printf("\n");
    return 0;
}

auto Tablecreation(string name) {
    sqlite3* DB;
    const char* c = name.c_str();
    std::string sql = "CREATE TABLE PERSON("
        "ID INT PRIMARY KEY     NOT NULL, "
        "NAME           TEXT    NOT NULL, "
        "SURNAME          TEXT     NOT NULL, "
        "AGE            INT     NOT NULL, "
        "ADDRESS        CHAR(30), "
        "SALARY         REAL );";
    int exit = 0;
    exit = sqlite3_open(c, &DB);
    char* messaggeError;
    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError);

    if (exit != SQLITE_OK) {
        std::cerr << "Error Create Table" << std::endl;
        sqlite3_free(messaggeError);
    }
    else
        std::cout << "Table created Successfully" << std::endl;
    sqlite3_close(DB);
}

auto Tableinsert(const char* c) {
    sqlite3* DB;
    char* messaggeError;
    int exit = sqlite3_open(c, &DB);
    string query = "SELECT * FROM PERSON;";

    cout << "Enter persons ID" << endl;
    string id;
    cin >> id;
    
    cout << "Enter persons Name" << endl;
    string name;
    cin >> name;

    cout << "Enter persons Surname" << endl;
    string sur;
    cin >> sur;
   
    cout << "Enter persons Age" << endl;
    string age;
    cin >> age;

    cout << "Enter persons Adress" << endl;
    string addr;
    cin >> addr;
  
    cout << "Enter persons Salary" << endl;
    string sal;
    cin >> sal;
    

    string sql = "INSERT INTO PERSON VALUES(" + id + ", '" + name + "', '" + sur + "', " + age + ", '" + addr + "', " + sal + ");";

    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError);
    if (exit != SQLITE_OK) {
        std::cerr << "Error Insert" << std::endl;
        sqlite3_free(messaggeError);
    }
    else
        std::cout << "Records created Successfully!" << std::endl;

}

auto Tabledeletion(const char* c) {

    sqlite3* DB;
    char* messaggeError;
    int exit = sqlite3_open(c, &DB);
    string query = "SELECT * FROM PERSON;";
    string sql;

    cout << "Enter ID to delete" << endl;
    cin >> sql;
    sql = "DELETE FROM PERSON WHERE ID = "+sql+"; ";
    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError);
    if (exit != SQLITE_OK) {
        std::cerr << "Error DELETE" << std::endl;
        sqlite3_free(messaggeError);
    }
    else
        std::cout << "Record deleted Successfully!" << std::endl;
}

auto Tablemodification(string name) {
    const char* c = name.c_str();

    sqlite3* DB;
    char* messaggeError;
    int exit = sqlite3_open(c, &DB);
    string query = "SELECT * FROM PERSON;";

    cout << "STATE OF TABLE BEFORE INSERT" << endl;

    sqlite3_exec(DB, query.c_str(), callback, NULL, NULL);

    char ib = 'y';

    while (ib == 'y') {
        cout << "Want to insert a person into database? y/n" << endl;
        cin >> ib;
        if (ib == 'y') { Tableinsert(c); }

    }

    ib = 'y';

    while (ib == 'y') {
        cout << "Want to delete a person from database? y/n" << endl;
        cin >> ib;
        if (ib == 'y') { Tabledeletion(c); }

    }

    cout << "STATE OF TABLE AFTER MODIFICATION" << endl;

    sqlite3_exec(DB, query.c_str(), callback, NULL, NULL);
}


int main(int argc, char** argv)
{   
    char b;
    while (1 > 0) {
        cout << "Create a new database?   y/n" << endl;
        
        cin >> b;
        if (b == 'y') {
            cout << "Enter a new name, including .db" << endl;
            string name;
            cin >> name;
            Tablecreation(name);
        };
        cout << "Work with existing database? y/n" << endl;
        cin >> b;
        if (b == 'y') {
            cout << "Enter a name, including .db" << endl;
            string name;
            cin >> name;
            Tablemodification(name);
        }
        cout << "Exit the program? y/n" << endl;
        cin >> b;
        if (b == 'y') {
            break;
        }
    }
    return (0);
}