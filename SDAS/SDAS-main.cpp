#include <iomanip>
#include <iostream>
#include <sstream>
#include <vector>
#include<complex>
#include<thread>
#include <SFML/Graphics.hpp>
#include <sqlite3.h>


using namespace std;

string id = "";

string name = "";

string sur = "";

string age = "";

string addr = "";

string sal = "";


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
auto dataform() {

   id = "";

   name = "";

   sur = "";

   age = "";

   addr = "";

   sal = "";
    sf::RenderWindow form(sf::VideoMode(960, 480), "SDAS form");
    sf::Font font;
    font.loadFromFile("images/Impact Regular.ttf");
    sf::Text text("", font, 60);
    text.setFillColor(sf::Color::White);
    text.setStyle(sf::Text::Bold | sf::Text::Underlined);
    
    text.setPosition(100, 100);
    form.draw(text);

    sf::Event event;
    sf::String userInput;
    sf::Text userText("", font, 60);

    userText.setPosition(360, 300);

    while (form.isOpen())
    {
        while (id == "") {
            text.setString("Enter id (integer)");
            while (form.pollEvent(event))
            {
                if (event.type == sf::Event::TextEntered && !sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
                {
                    if (event.text.unicode == '\b') {
                        userInput.erase(userInput.getSize() - 1, 1);
                        userText.setString(userInput);
                    }
                    else if (event.text.unicode < 128)
                    {
                        userInput += event.text.unicode;
                        userText.setString(userInput);
                    }
                }

            }
            form.clear();
            form.draw(userText);
            form.draw(text);
            form.display();

            if (userInput!="" && sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) { id = userInput; userInput = ""; userText.setString(userInput); form.clear(); form.draw(userText);
            form.draw(text);
            form.display();
            }
        }
        while (name == "") {
            text.setString("Enter name");
            while (form.pollEvent(event))
            {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Backspace)) {
                    userInput.erase(userInput.getSize() - 1, 1);
                    userText.setString(userInput);
                }
                else if (event.type == sf::Event::TextEntered && !sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
                {
                    if (event.text.unicode < 128)
                    {
                        userInput += event.text.unicode;
                        userText.setString(userInput);
                    }
                }

            }
            form.clear();
            form.draw(userText);
            form.draw(text);
            form.display();

            if (userInput != "" && sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) { name = userInput; userInput = ""; userText.setString(userInput); form.clear(); form.draw(userText);
            form.draw(text);
            form.display();
            }
        }
        while (sur == "") {
            text.setString("Enter surname");
            while (form.pollEvent(event))
            {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Backspace)) {
                    userInput.erase(userInput.getSize() - 1, 1);
                    userText.setString(userInput);
                }
                else if (event.type == sf::Event::TextEntered && !sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
                {
                    if (event.text.unicode < 128)
                    {
                        userInput += event.text.unicode;
                        userText.setString(userInput);
                    }
                }

            }
            form.clear();
            form.draw(userText);
            form.draw(text);
            form.display();

            if (userInput != "" && sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) { sur = userInput; userInput = ""; userText.setString(userInput); form.clear(); form.draw(userText);
            form.draw(text);
            form.display();
            }
        }
        while (age == "") {
            text.setString("Enter age (integer)");
            while (form.pollEvent(event))
            {
                if (event.text.unicode == '\b') {
                    userInput.erase(userInput.getSize() - 1, 1);
                    userText.setString(userInput);
                }
                else if (event.type == sf::Event::TextEntered && !sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
                {
                    if (event.text.unicode < 128)
                    {
                        userInput += event.text.unicode;
                        userText.setString(userInput);
                    }
                }

            }
            form.clear();
            form.draw(userText);
            form.draw(text);
            form.display();

            if (userInput != "" && sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) { age = userInput; userInput = ""; userText.setString(userInput); form.clear(); form.draw(userText);
            form.draw(text);
            form.display();
            }
        }
        while (addr == "") {
            text.setString("Enter address");
            while (form.pollEvent(event))
            {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Backspace)) {
                    userInput.erase(userInput.getSize() - 1, 1);
                    userText.setString(userInput);
                }
                else if (event.type == sf::Event::TextEntered && !sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
                {
                    if (event.text.unicode < 128)
                    {
                        userInput += event.text.unicode;
                        userText.setString(userInput);
                    }
                }

            }
            form.clear();
            form.draw(userText);
            form.draw(text);
            form.display();

            if (userInput != "" && sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) { addr = userInput; userInput = ""; userText.setString(userInput); form.clear(); form.draw(userText);
            form.draw(text);
            form.display();
            }
        }
        while (sal == "") {
            text.setString("Enter salary");
            while (form.pollEvent(event))
            {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Backspace)) {
                    userInput.erase(userInput.getSize() - 1, 1);
                    userText.setString(userInput);
                }
                else if (event.type == sf::Event::TextEntered && !sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
                {
                    if (event.text.unicode < 128)
                    {
                        userInput += event.text.unicode;
                        userText.setString(userInput);
                    }
                }

            }
            form.clear();
            form.draw(userText);
            form.draw(text);
            form.display();

            if (userInput != "" && sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) { sal = userInput; userText.setString(userInput); form.close(); form.clear(); form.draw(userText);
            form.draw(text);
            form.display();
            }
        }
    }

    return (id,name,sur,age,addr,sal);

}

auto Tableinsert(const char* c) {
    sqlite3* DB;
    char* messaggeError;
    int exit = sqlite3_open(c, &DB);
    string query = "SELECT * FROM PERSON;";
        
    
    
    dataform();
    
    string sql = "INSERT INTO PERSON VALUES(" + id + ", '" + name + "', '" + sur + "', " + age + ", '" + addr + "', " + sal + ");";

    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError);
    if (exit != SQLITE_OK) {
        std::cerr << "Error Insert" << std::endl;
        sqlite3_free(messaggeError);
    }
    else
        std::cout << "Records created Successfully!" << std::endl;

}

bool insertconfirmation() {

    sf::RenderWindow form(sf::VideoMode(1100, 480), "SDAS form conf");
    sf::Font font;
    font.loadFromFile("images/Impact Regular.ttf");
    sf::Text text("", font, 60);
    text.setFillColor(sf::Color::White);
    text.setStyle(sf::Text::Bold | sf::Text::Underlined);
    text.setString("Want to add a record?");
    text.setPosition(100, 100);

    sf::Vector2i position;

    sf::Event event;
    

    sf::Texture button_4;
    button_4.loadFromFile("images/YES.png");
    sf::Sprite yes;
    yes.setTexture(button_4);
    yes.setPosition(50, 300);

    sf::Texture button_5;
    button_5.loadFromFile("images/NO.png");
    sf::Sprite no;
    no.setTexture(button_5);
    no.setPosition(550, 300);

    

    while (form.isOpen())
    {
        while (form.pollEvent(event))
        {
            position = sf::Mouse::getPosition(form);
            form.clear();
            form.draw(text);
            form.draw(yes);
            form.draw(no);
            form.display();

            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (position.x > 50 && position.x < 530 && position.y > 300 && position.y < 372) {

                    form.close(); return 1;
                }
                if (position.x > 550 && position.x < 1030 && position.y > 300 && position.y < 372) {

                    form.close(); return 0;
                }

            }



        }



    }
}

bool deleteconfirmation() {

    sf::RenderWindow form(sf::VideoMode(1100, 480), "SDAS form conf");
    sf::Font font;
    font.loadFromFile("images/Impact Regular.ttf");
    sf::Text text("", font, 60);
    text.setFillColor(sf::Color::White);
    text.setStyle(sf::Text::Bold | sf::Text::Underlined);
    text.setString("Want to delete a record?");
    text.setPosition(100, 100);

    sf::Vector2i position;

    sf::Event event;


    sf::Texture button_4;
    button_4.loadFromFile("images/YES.png");
    sf::Sprite yes;
    yes.setTexture(button_4);
    yes.setPosition(50, 300);

    sf::Texture button_5;
    button_5.loadFromFile("images/NO.png");
    sf::Sprite no;
    no.setTexture(button_5);
    no.setPosition(550, 300);



    while (form.isOpen())
    {
        while (form.pollEvent(event))
        {
            position = sf::Mouse::getPosition(form);
            form.clear();
            form.draw(text);
            form.draw(yes);
            form.draw(no);
            form.display();

            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (position.x > 50 && position.x < 530 && position.y > 300 && position.y < 372) {

                    form.close(); return 1;
                }
                if (position.x > 550 && position.x < 1030 && position.y > 300 && position.y < 372) {

                    form.close(); return 0;
                }

            }



        }



    }
}

bool salchangeconfirmation() {

    sf::RenderWindow form(sf::VideoMode(1100, 480), "SDAS form conf");
    sf::Font font;
    font.loadFromFile("images/Impact Regular.ttf");
    sf::Text text("", font, 60);
    text.setFillColor(sf::Color::White);
    text.setStyle(sf::Text::Bold | sf::Text::Underlined);
    text.setString("Want to change salary?");
    text.setPosition(100, 100);

    sf::Vector2i position;

    sf::Event event;


    sf::Texture button_4;
    button_4.loadFromFile("images/YES.png");
    sf::Sprite yes;
    yes.setTexture(button_4);
    yes.setPosition(50, 300);

    sf::Texture button_5;
    button_5.loadFromFile("images/NO.png");
    sf::Sprite no;
    no.setTexture(button_5);
    no.setPosition(550, 300);



    while (form.isOpen())
    {
        while (form.pollEvent(event))
        {
            position = sf::Mouse::getPosition(form);
            form.clear();
            form.draw(text);
            form.draw(yes);
            form.draw(no);
            form.display();

            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (position.x > 50 && position.x < 530 && position.y > 300 && position.y < 372) {

                    form.close(); return 1;
                }
                if (position.x > 550 && position.x < 1030 && position.y > 300 && position.y < 372) {

                    form.close(); return 0;
                }

            }



        }



    }
}

auto Tabledeletion(const char* c) {

    sqlite3* DB;
    char* messaggeError;
    int exit = sqlite3_open(c, &DB);
    string query = "SELECT * FROM PERSON WHERE ID = ";
    string sql;

    
    sf::RenderWindow form(sf::VideoMode(960, 480), "SDAS form");
    sf::Font font;
    font.loadFromFile("images/Impact Regular.ttf");
    sf::Text text("", font, 60);
    text.setFillColor(sf::Color::White);
    text.setStyle(sf::Text::Bold | sf::Text::Underlined);

    text.setPosition(100, 100);
    form.draw(text);

    sf::Event event;
    sf::String userInput;
    sf::Text userText("", font, 60);

    userText.setPosition(360, 300);
    id = "";

    while (form.isOpen())
    {
        while (id == "") {
            text.setString("Enter id (integer)");
            while (form.pollEvent(event))
            {
                if (event.type == sf::Event::TextEntered && !sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
                {
                    if (event.text.unicode == '\b') {
                        userInput.erase(userInput.getSize() - 1, 1);
                        userText.setString(userInput);
                    }
                    else if (event.text.unicode < 128)
                    {
                        userInput += event.text.unicode;
                        userText.setString(userInput);
                    }
                }

            }
            form.clear();
            form.draw(userText);
            form.draw(text);
            form.display();

            if (userInput != "" && sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
                id = userInput; userInput = ""; form.close();
            }
        }
    }
    sql = id;

    sql = "DELETE FROM PERSON WHERE ID = "+sql+"; ";
    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError);
    if (exit != SQLITE_OK) {
        std::cerr << "Error DELETE" << std::endl;
        sqlite3_free(messaggeError);
    }
    else
        std::cout << "Record deleted Successfully!" << std::endl;
}

auto Tablesalchange(string name) {
    const char* c = name.c_str();

    sqlite3* DB;
    char* messaggeError;
    int exit = sqlite3_open(c, &DB);
    string query = "SELECT * FROM PERSON;";
    string sql;
    id = "";

    sal = "";
    sf::RenderWindow form(sf::VideoMode(960, 480), "SDAS form");
    sf::Font font;
    font.loadFromFile("images/Impact Regular.ttf");
    sf::Text text("", font, 60);
    text.setFillColor(sf::Color::White);
    text.setStyle(sf::Text::Bold | sf::Text::Underlined);

    text.setPosition(100, 100);
    form.draw(text);

    sf::Event event;
    sf::String userInput;
    sf::Text userText("", font, 60);

    userText.setPosition(360, 300);
    
    double ch = 0.0;

    
        while (ch == 0.0) {
            text.setString("Enter new salary");
            while (form.pollEvent(event))
            {
                if (event.text.unicode == '\b') {
                    userInput.erase(userInput.getSize() - 1, 1);
                    userText.setString(userInput);
                }
                else if (event.type == sf::Event::TextEntered && !sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
                {
                    if (event.text.unicode < 128)
                    {
                        userInput += event.text.unicode;
                        userText.setString(userInput);
                    }
                }

            }
            form.clear();
            form.draw(userText);
            form.draw(text);
            form.display();

            if (userInput != "" && sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
                string l = userInput;
                ch =stod(l); userInput = ""; userText.setString(userInput); form.clear(); form.draw(userText);
                form.draw(text);
                form.display();
            }
        }
        while (1>0) {
            text.setString("Enter id-s or type 'all'/'end'");
            while (form.pollEvent(event))
            {
                if (event.text.unicode == '\b') {
                    userInput.erase(userInput.getSize() - 1, 1);
                    userText.setString(userInput);
                }
                else if (event.type == sf::Event::TextEntered && !sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
                {
                    if (event.text.unicode < 128)
                    {
                        userInput += event.text.unicode;
                        userText.setString(userInput);
                    }
                }

            }
            form.clear();
            form.draw(userText);
            form.draw(text);
            form.display();

            if (userInput == "end" && sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
                form.close(); break;
            }

            if (userInput != "all" && sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
                

                sql = "UPDATE PERSON SET SALARY = " + to_string(ch) + " WHERE ID = " + userInput + "; ";

                exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError);
                if (exit != SQLITE_OK) {
                    std::cerr << "Error Insert" << std::endl;
                    sqlite3_free(messaggeError);
                }
                else
                    std::cout << "Records updated Successfully!" << std::endl;
                userInput = ""; userText.setString(userInput);
                form.clear();
                form.draw(userText);
                form.draw(text);
                form.display();
                }
            if (userInput == "all" && sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {


                sql = "UPDATE PERSON SET SALARY = " + to_string(ch)  + "; ";

                exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError);
                if (exit != SQLITE_OK) {
                    std::cerr << "Error Insert" << std::endl;
                    sqlite3_free(messaggeError);
                }
                else
                    std::cout << "Records updated Successfully!" << std::endl;
                form.close();
                break;
            }
                
            }

        
        return 0;
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
        bool t = insertconfirmation();
        if (t==1) { Tableinsert(c); }
        else { ib = 'n'; }

    }

    ib = 'y';

    while (ib == 'y') {
        bool t = deleteconfirmation();
        if (t == 1) { Tabledeletion(c); }
        else { ib = 'n'; }

    }

    ib = 'y';

    while (ib == 'y') {
        bool t = salchangeconfirmation();
        if (t == 1) { Tablesalchange(c); }
        else { ib = 'n'; }

    }

    cout << "STATE OF TABLE AFTER MODIFICATION" << endl;

    sqlite3_exec(DB, query.c_str(), callback, NULL, NULL);
}


string nameform() {
    sf::RenderWindow form(sf::VideoMode(960, 480), "SDAS form");
    sf::Font font; 
    font.loadFromFile("images/Impact Regular.ttf");
    sf::Text text("", font, 60);
    text.setFillColor(sf::Color::White);
    text.setStyle(sf::Text::Bold | sf::Text::Underlined);
    text.setString("Enter Database name");
    text.setPosition(100, 100);
    form.draw(text);

    sf::Event event;
    sf::String userInput;
    sf::Text userText("", font, 60);
    
    userText.setPosition(360, 300);
   
    while (form.isOpen())
    {
        while (form.pollEvent(event))
        {
            if (event.text.unicode == '\b') {
                userInput.erase(userInput.getSize() - 1, 1);
                userText.setString(userInput);
            }
            else if (event.type == sf::Event::TextEntered)
            {
                if (event.text.unicode < 128)
                {
                    userInput += event.text.unicode;
                    userText.setString(userInput);
                }
            }
            
        }
        form.clear();
        form.draw(userText);
        form.draw(text);
        form.display();

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) { form.close(); }
    }

    return userInput;
    
}


int main(int argc, char** argv)
{   
    sf::RenderWindow window(sf::VideoMode(1080, 640), "SDAS");
    sf::Texture logo;
    logo.loadFromFile("images/SDAS_logo.png");
    sf::Sprite SDAS_logo;
    SDAS_logo.setTexture(logo);
    SDAS_logo.setPosition(0, 0);

    sf::Texture button_1;
    button_1.loadFromFile("images/button_1.png");
    sf::Sprite button1;
    button1.setTexture(button_1);
    button1.setPosition(300, 300);
    
    sf::Texture button_2;
    button_2.loadFromFile("images/button_2.png");
    sf::Sprite button2;
    button2.setTexture(button_2);
    button2.setPosition(300, 400);

    sf::Texture button_3;
    button_3.loadFromFile("images/button_3.png");
    sf::Sprite button3;
    button3.setTexture(button_3);
    button3.setPosition(300, 500);

    sf::Vector2i position;
    
    

    while (window.isOpen())
    {
        position = sf::Mouse::getPosition(window);

        sf::Event event;
        while (window.pollEvent(event))
        {

            window.clear();
            window.draw(SDAS_logo);
            window.draw(button1);
            window.draw(button2);
            window.draw(button3);
            window.display();



            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (position.x > 300 && position.x < 780 && position.y > 300 && position.y < 372) {

                    Tablecreation(nameform() + ".db");
                }
                if (position.x > 300 && position.x < 780 && position.y > 400 && position.y < 472) {

                    Tablemodification(nameform() + ".db");
                }
                if (position.x > 300 && position.x < 780 && position.y > 500 && position.y < 572 or event.type==sf::Event::Closed) {

                    window.close();
                }
            };
        }
    }
    return (0);
}
