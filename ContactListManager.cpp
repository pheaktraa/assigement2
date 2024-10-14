#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

//
void CreateBirthdayList()
{
    ofstream Myfile("birthdayList.csv");
    
    int n;
    cout << "Enter N People : "; cin >> n;
    cout << endl;
    cout << "Enter Guest detail "<< endl;

    string id;
    string name, nGuess, gStatus, phone_number, address;  

    //read input
    for ( int i = 0; i < n; i++)
    {
        cout << "========================================" << endl;
        cout << "Guest ID : "; cin >> id;
        cout << "Guest Name : ";
        cin.ignore(); 
        getline(cin,name);
        cout << "Guest Phone Number: "; getline(cin, phone_number);
        // cin.ignore(); // Optional, in case there are leftover newlines in the input buffer
        // getline(cin, phone_number); // Use getline to capture the entire string including leading zeros

        cout << "Number of Guest : "; cin >> nGuess;
        cout << "Guest Address : "; 
        cin.ignore();  // To handle leftover newline from previous input
        getline(cin, address);

        //insert data to file
        Myfile << id << "," << name << "," << phone_number << "," << nGuess << "," << address << endl;

    }
}

void SearchBirthdayList()
{
    ifstream Myfile;
    Myfile.open("birthdayList.csv");

    //get id contact to display
    int idNum, roll2, count = 0;
    cout << "Enter ID to display :"; cin >> idNum;

    //read data form file as string vector
    vector<string> row;
    string line, word;

    //first loop
    while (getline(Myfile, line))
    {
        row.clear();

        //use stringstream to split line by comma
        stringstream s(line);
        while (getline(s, word, ','))
        {
            row.push_back(word);
        }

        //check if the idnum match
        // roll2 = stoi(row[0]);
        stringstream ss(row[0]);
        ss >> roll2;

            if (roll2 == idNum)
            {
                count = 1;
                //print data
                cout << endl;
                cout << "ID : " << row[0] << endl;
                cout << "Name : " << row[1] << endl;
                cout << "Phone-Number : " << row[2] << endl;
                cout << "Number of Guest : " << row[3] << endl;
                cout << "Address : " << row[4] << endl;
                break;
            } 
    }
    if (count == 0)
    {
        cout << "Data not found" << endl;
    }
    Myfile.close();
}

void UpdateBirthdayList()
{
    ifstream ok("birthdayList.csv");

    //new file
    ofstream newfile ("reportcardnew.csv");

    int rollnum, roll1, count = 0, i;
    int index;
    string new_data;

    string line, word;
    vector<string> row;

    cout << "Enter Guess ID to update : ";
    cin >> rollnum;

    char choice;
    cout << "What You want to Update Name/Phone-Number/Number of Guest/Address (N/P/G/A) : "; 
    // cout << "Name/Phone-Number/Email/Address";
    cin >> choice;

    if (choice == 'n' || choice == 'N')
    {
        index = 1;
    }
    else if (choice == 'p' || choice == 'P')
    {
        index = 2;
    }
    else if (choice == 'e' || choice == 'E')
    {
        index = 3;
    }
    else if (choice == 'a' || choice == 'A')
    {
        index = 4;
    }
    else 
    {
        cout << "wrong input." << endl;
    }

    cout << "Enter New Data : "; 
    cin.ignore(); 
    getline(cin, new_data);

    //update loop 
    while (getline(ok, line))
    {
        row.clear();
        stringstream s(line);

        while (getline(s, word, ','))
        {
            row.push_back(word);
        }

        stringstream ss(row[0]);
        ss >> roll1;
        int row_size = row.size();

        if (roll1 == rollnum)
        {
            count = 1; 
            row[index] = new_data;  // Update the specific field with new data
        }

        //
        for (i = 0; i < row_size - 1; i++)
        {
            newfile << row[i] << ",";
        }

        newfile << row[row_size - 1] << "\n";
    }

    if (count == 0)
    {
        cout << "Record not found\n";
    }

    ok.close();
    newfile.close();

    //
    remove("birthdayList.csv");
    rename("reportcardnew.csv", "brithdayList.csv");
}

void DeleteBirthdayList()
{
        // 
    fstream fin;

    //open existing file
    fin.open("birthdayList.csv");

    //create new file to store non-delete data
    ofstream new_file("reportcardnew.csv");

    int rollnum, roll1, count = 0;
    string line, word;
    vector<string> row;

    //
    cout << "Enter Guest ID Number to delete : ";
    cin >> rollnum;

    //
    while (getline(fin, line))
    {
        row.clear();   
        stringstream s(line);

        // string word;
        while (getline(s, word, ','))
        {
            row.push_back(word);
        }

        stringstream ss(row[0]);
        ss >> roll1;
        int row_size = row.size();

        //
        if (roll1 != rollnum)
        {
            for (size_t i = 0; i < row.size() - 1; i++)
            {
                new_file << row[i] << ", ";
            }
            new_file << row.back() << "\n";
        }
        else 
        {
            count = 1;
        }
    }

    if (count == 1)
    {
        cout << "Record deleted successfully.\n";
    }
    else 
    {
        cout << "Record not found.\n";
    }

    //
    fin.close();
    new_file.close();

    //
    remove("birthdayList.csv");

    //
    rename("reportcardnew.csv", "brithdayList.csv");
}

//
void CreateContactList()
{
    ofstream Myfile("contactList.csv");
    
    int n;
    cout << "Enter N People : "; cin >> n;
    cout << endl;
    cout << "Enter the detail of "<< endl;

    string id;
    string name, email, phone_number, address;  

    //read input
    for ( int i = 0; i < n; i++)
    {
        // cin >> id >> name >> phone_number >> email;
        cout << "========================================" << endl;
        cout << "ID : "; cin >> id;
        cout << "Name : ";
        cin.ignore(); 
        getline(cin,name);
        cout << "Phone Number: "; getline(cin, phone_number);
        // cin.ignore(); // Optional, in case there are leftover newlines in the input buffer
        // getline(cin, phone_number); // Use getline to capture the entire string including leading zeros

        cout << "Email : "; cin >> email;
        cout << "Address : "; 
        cin.ignore();  // To handle leftover newline from previous input
        getline(cin, address);

        //insert data to file
        Myfile << id << "," << name << "," << phone_number << "," << email << "," << address << endl;

    }
}

void SearchContactList()
{
    ifstream Myfile;
    Myfile.open("contactList.csv");

    //get id contact to display
    int idNum, roll2, count = 0;
    cout << "Enter ID to display :"; cin >> idNum;

    //read data form file as string vector
    vector<string> row;
    string line, word;

    //first loop
    while (getline(Myfile, line))
    {
        row.clear();

        //use stringstream to split line by comma
        stringstream s(line);
        while (getline(s, word, ','))
        {
            row.push_back(word);
        }

        //check if the idnum match
        // roll2 = stoi(row[0]);
        stringstream ss(row[0]);
        ss >> roll2;

            if (roll2 == idNum)
            {
                count = 1;
                //print data
                cout << endl;
                cout << "ID : " << row[0] << endl;
                cout << "Name : " << row[1] << endl;
                cout << "Phone-Number : " << row[2] << endl;
                cout << "Email : " << row[3] << endl;
                cout << "Address : " << row[4] << endl;
                break;
            } 
    }
    if (count == 0)
    {
        cout << "Data not found" << endl;
    }
    Myfile.close();
}

void UpdateContactList()
{
    ifstream ok("contactList.csv");

    //new file
    ofstream newfile ("reportcardnew.csv");

    int rollnum, roll1, count = 0, i;
    int index;
    string new_data;

    string line, word;
    vector<string> row;

    cout << "Enter ID number to update : ";
    cin >> rollnum;

    char choice;
    cout << "What You want to Update Name/Phone-Number/Email/Address (N/P/E/A) : "; 
    // cout << "Name/Phone-Number/Email/Address";
    cin >> choice;

    if (choice == 'n' || choice == 'N')
    {
        index = 1;
    }
    else if (choice == 'p' || choice == 'P')
    {
        index = 2;
    }
    else if (choice == 'e' || choice == 'E')
    {
        index = 3;
    }
    else if (choice == 'a' || choice == 'A')
    {
        index = 4;
    }
    else 
    {
        cout << "wrong input." << endl;
    }

    cout << "Enter New Data : "; 
    cin.ignore(); 
    getline(cin, new_data);

    //update loop 
    while (getline(ok, line))
    {
        row.clear();
        stringstream s(line);

        while (getline(s, word, ','))
        {
            row.push_back(word);
        }

        stringstream ss(row[0]);
        ss >> roll1;
        int row_size = row.size();

        if (roll1 == rollnum)
        {
            count = 1; 
            row[index] = new_data;  // Update the specific field with new data
        }

        //
        for (i = 0; i < row_size - 1; i++)
        {
            newfile << row[i] << ",";
        }

        newfile << row[row_size - 1] << "\n";
    }

    if (count == 0)
    {
        cout << "Record not found\n";
    }

    ok.close();
    newfile.close();

    //
    remove("contactList.csv");
    rename("reportcardnew.csv", "contactList.csv");
}

void DeleteContactList()
{
        // 
    fstream fin;

    //open existing file
    fin.open("contactList.csv");

    //create new file to store non-delete data
    ofstream new_file("reportcardnew.csv");

    int rollnum, roll1, count = 0;
    string line, word;
    vector<string> row;

    //
    cout << "Enter ID Number to delete : ";
    cin >> rollnum;

    //
    while (getline(fin, line))
    {
        row.clear();   
        stringstream s(line);

        // string word;
        while (getline(s, word, ','))
        {
            row.push_back(word);
        }

        stringstream ss(row[0]);
        ss >> roll1;
        int row_size = row.size();

        //
        if (roll1 != rollnum)
        {
            for (size_t i = 0; i < row.size() - 1; i++)
            {
                new_file << row[i] << ", ";
            }
            new_file << row.back() << "\n";
        }
        else 
        {
            count = 1;
        }
    }

    if (count == 1)
    {
        cout << "Record deleted successfully.\n";
    }
    else 
    {
        cout << "Record not found.\n";
    }

    //
    fin.close();
    new_file.close();

    //
    remove("contactList.csv");

    //
    rename("reportcardnew.csv", "contactList.csv");
}

//
void CreateMovieList()
{
    ofstream Myfile("movieList.csv");
    
    int n;
    cout << "Enter N Movie : "; cin >> n;
    cout << endl;
    cout << "Enter Detail of Movie"<< endl;

    string id;
    string name, director, genre, release_year;  

    //read input
    for ( int i = 0; i < n; i++)
    {
        // cin >> id >> name >> phone_number >> email;
        cout << "========================================" << endl;
        cout << "Movie ID : "; cin >> id;
        cout << "Movie Name : ";
        cin.ignore(); 
        getline(cin,name);
        cout << "Director: "; getline(cin, director);
        // cin.ignore(); // Optional, in case there are leftover newlines in the input buffer
        // getline(cin, phone_number); // Use getline to capture the entire string including leading zeros

        cout << "Genre : "; cin >> genre;
        cout << "Release Year : "; 
        cin.ignore();  // To handle leftover newline from previous input
        getline(cin, release_year);

        //insert data to file
        Myfile << id << "," << name << "," << director << "," << genre << "," << release_year << endl;

    }
}

void SearchMovieList()
{
    ifstream Myfile("movieList.csv");

    if (!Myfile.is_open()) {
        cout << "Error opening file." << endl;
        return;
    }

    // Get the movie name to search
    string movieName;
    cout << "Enter Movie Name to display: ";
    cin.ignore(); // Clear input buffer
    getline(cin, movieName); // Get the full movie name

    vector<string> row;
    string line;

    bool found = false; // Flag to check if the movie was found

    // Read data from the file
    while (getline(Myfile, line))
    {
        row.clear();
        stringstream s(line);
        string word;

        while (getline(s, word, ','))
        {
            row.push_back(word);
        }

        // Ensure that we have enough columns in the row
        if (row.size() > 1 && row[1] == movieName)
        {
            found = true; // Movie found
            cout << endl;
            cout << "ID: " << row[0] << endl;
            cout << "Name: " << row[1] << endl;
            cout << "Director: " << row[2] << endl;
            cout << "Genre: " << row[3] << endl;
            cout << "Release Year: " << row[4] << endl;
            break; // Exit loop once found
        }
    }

    if (!found)
    {
        cout << "Data not found." << endl;
    }
    
    Myfile.close();
}

void UpdateMovieList()
{
    ifstream ok("movieList.csv");

    //new file
    ofstream newfile ("reportcardnew.csv");

    string rollnum, roll1;
    int count = 0, i;
    int index;
    string new_data;

    string line, word;
    vector<string> row;

    cout << "Enter Movie Name to update : ";
    cin.ignore();
    getline(cin, rollnum);

    char choice;
    cout << "What You want to Update Director/Genre/Release Year (D/G/R) : "; 
    // cout << "Name/Phone-Number/Email/Address";
    cin >> choice;

    if (choice == 'd' || choice == 'D')
    {
        index = 2;
    }
    else if (choice == 'g' || choice == 'G')
    {
        index = 3;
    }
    else if (choice == 'r' || choice == 'R')
    {
        index = 4;
    }
    // else if (choice == 'a' || choice == 'A')
    // {
    //     index = 4;
    // }
    else 
    {
        cout << "wrong input." << endl;
    }

    cout << "Enter New Data : "; 
    cin.ignore(); 
    getline(cin, new_data);

    //update loop 
    while (getline(ok, line))
    {
        row.clear();
        stringstream s(line);

        while (getline(s, word, ','))
        {
            row.push_back(word);
        }

        // stringstream ss(row[0]);
        // ss >> roll1;
        int row_size = row.size();

        if (row[1] == rollnum) //row1(start form name) == input
        {
            count = 1; 
            row[index] = new_data;  // Update the specific field with new data
        }

        //
        for (i = 0; i < row_size - 1; i++)
        {
            newfile << row[i] << ",";
        }

        newfile << row[row_size - 1] << "\n";
    }

    if (count == 0)
    {
        cout << "Record not found\n";
    }

    ok.close();
    newfile.close();

    //
    remove("movieList.csv");
    rename("reportcardnew.csv", "movieList.csv");
}

void DeleteMovieList()
{
    fstream fin("movieList.csv");
    if (!fin.is_open()) {
        cout << "Error opening file." << endl;
        return;
    }

     //create new file to store non-delete data
    ofstream new_file("reportcardnew.csv");

    string movieName;
    cout << "Enter Movie Name to delete: ";
    cin.ignore();
    getline(cin, movieName); // Get the full movie name to delete

    string line;
    vector<string> row;
    //bool deleted = false; // Flag to check if deletion occurred
    int count = 0;
    // Read each line and write to new file if not deleted
    while (getline(fin, line))
    {
        row.clear();
        stringstream s(line);
        string word;

        while (getline(s, word, ','))
        {
            row.push_back(word);
        }

        int row_size = row.size();
        // Check if the movie name matches for deletion
        if (row[1] != movieName)
        {
            // If not deleted, write the row to the new file
            for (size_t i = 0; i < row.size() - 1; i++)
            {
                new_file << row[i] << ",";
            }
            new_file << row.back() << "\n"; // Write last element without comma  
        }
        else 
        {
            count = 1;
            //deleted = true; // Set flag if we found a matching movie
            //continue; // Skip writing this row to the new file 
        }
    }

    if (count == 1)
    {
        cout << "Record deleted successfully.\n";
    }
    else 
    {
        cout << "Record not found.\n";
    }

    fin.close();
    new_file.close();

    // Replace old file with new file
    remove("movieList.csv");
    rename("reportcardnew.csv", "movieList.csv");
}

//
void CreateMusicPlayList()
{
    ofstream Myfile("musicplayList.csv");
    
    int n;
    cout << "Enter N Movie : "; cin >> n;
    cout << endl;
    cout << "Enter Detail of Movie"<< endl;

    string id;
    string name, artist, genre, release_year;  

    //read input
    for ( int i = 0; i < n; i++)
    {
        cout << "========================================" << endl;
        cout << "Music ID : "; cin >> id;
        cout << "Music Name : ";
        cin.ignore(); 
        getline(cin,name);
        cout << "Artist : "; getline(cin, artist);

        cout << "Genre : "; cin >> genre;
        cout << "Release Year : "; 
        cin.ignore();  // To handle leftover newline from previous input
        getline(cin, release_year);

        //insert data to file
        Myfile << id << "," << name << "," << artist << "," << genre << "," << release_year << endl;

    }
}

void SearchMusicPlayList()
{
    ifstream Myfile("musicplayList.csv");

    if (!Myfile.is_open()) {
        cout << "Error opening file." << endl;
        return;
    }

    // Get the movie name to search
    string musicName;
    cout << "Enter Music Name to display: ";
    cin.ignore(); // Clear input buffer
    getline(cin, musicName); // Get the full movie name

    vector<string> row;
    string line;

    bool found = false; // Flag to check if the movie was found

    // Read data from the file
    while (getline(Myfile, line))
    {
        row.clear();
        stringstream s(line);
        string word;

        while (getline(s, word, ','))
        {
            row.push_back(word);
        }

        // Ensure that we have enough columns in the row
        if (row.size() > 1 && row[1] == musicName)
        {
            found = true; // Movie found
            cout << endl;
            cout << "ID: " << row[0] << endl;
            cout << "Name: " << row[1] << endl;
            cout << "Artist: " << row[2] << endl;
            cout << "Genre: " << row[3] << endl;
            cout << "Release Year: " << row[4] << endl;
            break; // Exit loop once found
        }
    }

    if (!found)
    {
        cout << "Data not found." << endl;
    }
    
    Myfile.close();
}

void UpdateMusicPlayList()
{
    ifstream ok("musicplayList.csv");

    //new file
    ofstream newfile ("reportcardnew.csv");

    string rollnum, roll1;
    int count = 0, i;
    int index;
    string new_data;

    string line, word;
    vector<string> row;

    cout << "Enter Music Name to update : ";
    cin.ignore();
    getline(cin, rollnum);

    char choice;
    cout << "What You want to Update Artist/Genre/Release Year (A/G/R) : "; 
    cin >> choice;

    if (choice == 'a' || choice == 'A')
    {
        index = 2;
    }
    else if (choice == 'g' || choice == 'G')
    {
        index = 3;
    }
    else if (choice == 'r' || choice == 'R')
    {
        index = 4;
    }
    // else if (choice == 'a' || choice == 'A')
    // {
    //     index = 4;
    // }
    else 
    {
        cout << "wrong input." << endl;
    }

    cout << "Enter New Data : "; 
    cin.ignore(); 
    getline(cin, new_data);

    //update loop 
    while (getline(ok, line))
    {
        row.clear();
        stringstream s(line);

        while (getline(s, word, ','))
        {
            row.push_back(word);
        }

        // stringstream ss(row[0]);
        // ss >> roll1;
        int row_size = row.size();

        if (row[1] == rollnum) //row1(start form name) == input
        {
            count = 1; 
            row[index] = new_data;  // Update the specific field with new data
        }

        //
        for (i = 0; i < row_size - 1; i++)
        {
            newfile << row[i] << ",";
        }

        newfile << row[row_size - 1] << "\n";
    }

    if (count == 0)
    {
        cout << "Record not found\n";
    }

    ok.close();
    newfile.close();

    //
    remove("musicplayList.csv");
    rename("reportcardnew.csv", "musicplayList.csv");
}

void DeleteMusicPlayList()
{
    fstream fin("musicplayList.csv");
    if (!fin.is_open()) {
        cout << "Error opening file." << endl;
        return;
    }

     //create new file to store non-delete data
    ofstream new_file("reportcardnew.csv");

    string musicName;
    cout << "Enter Music Name to delete: ";
    cin.ignore();
    getline(cin, musicName); // Get the full movie name to delete

    string line;
    vector<string> row;
    //bool deleted = false; // Flag to check if deletion occurred
    int count = 0;
    // Read each line and write to new file if not deleted
    while (getline(fin, line))
    {
        row.clear();
        stringstream s(line);
        string word;

        while (getline(s, word, ','))
        {
            row.push_back(word);
        }

        int row_size = row.size();
        // Check if the movie name matches for deletion
        if (row[1] != musicName)
        {
            // If not deleted, write the row to the new file
            for (size_t i = 0; i < row.size() - 1; i++)
            {
                new_file << row[i] << ",";
            }
            new_file << row.back() << "\n"; // Write last element without comma  
        }
        else 
        {
            count = 1;
            //deleted = true; // Set flag if we found a matching movie
            //continue; // Skip writing this row to the new file 
        }
    }

    if (count == 1)
    {
        cout << "Record deleted successfully.\n";
    }
    else 
    {
        cout << "Record not found.\n";
    }

    fin.close();
    new_file.close();

    // Replace old file with new file
    remove("musicplayList.csv");
    rename("reportcardnew.csv", "musicplayList.csv");
}

//
void CreateInventoryItem()
{
    ofstream Myfile("inventoryitemList.csv");
    
    int n;
    cout << "Enter N Item : "; cin >> n;
    cout << endl;
    cout << "Enter Detail of Item"<< endl;

    string id;
    string name, category, quantity, unit_price;  

    //read input
    for ( int i = 0; i < n; i++)
    {
        cout << "========================================" << endl;
        cout << "Item ID : "; cin >> id;
        cout << "Item Name : ";
        cin.ignore(); 
        getline(cin,name);
        cout << "Category : "; getline(cin, category);

        cout << "Quantity in Stock : "; cin >> quantity;
        cout << "Price per Unit : "; 
        cin.ignore();  // To handle leftover newline from previous input
        getline(cin, unit_price);

        //insert data to file
        Myfile << id << "," << name << "," << category << "," << quantity << "," << unit_price << endl;

    }
}

void SearchInventoryItem()
{
    ifstream Myfile("inventoryitemList.csv");

    if (!Myfile.is_open()) {
        cout << "Error opening file." << endl;
        return;
    }

    // Get the movie name to search
    string itemName;
    cout << "Enter Item Name to display: ";
    cin.ignore(); // Clear input buffer
    getline(cin, itemName); // Get the full movie name

    vector<string> row;
    string line;

    bool found = false; // Flag to check if the movie was found

    // Read data from the file
    while (getline(Myfile, line))
    {
        row.clear();
        stringstream s(line);
        string word;

        while (getline(s, word, ','))
        {
            row.push_back(word);
        }

        // Ensure that we have enough columns in the row
        if (row.size() > 1 && row[1] == itemName)
        {
            found = true; // Movie found
            cout << endl;
            cout << "ID: " << row[0] << endl;
            cout << "Name: " << row[1] << endl;
            cout << "Category: " << row[2] << endl;
            cout << "Quantity in Stock: " << row[3] << endl;
            cout << "Price per Unit: " << row[4] << endl;
            break; // Exit loop once found
        }
    }

    if (!found)
    {
        cout << "Data not found." << endl;
    }
    
    Myfile.close();
}

void UpdateInventoryItem()
{
    ifstream ok("inventoryitemList.csv");

    //new file
    ofstream newfile ("reportcardnew.csv");

    string rollnum, roll1;
    int count = 0, i;
    int index;
    string new_data;

    string line, word;
    vector<string> row;

    cout << "Enter Item Name to update : ";
    cin.ignore();
    getline(cin, rollnum);

    char choice;
    cout << "What You want to Update Category/Quantity/Price (C/Q/P) : "; 
    cin >> choice;

    if (choice == 'c' || choice == 'C')
    {
        index = 2;
    }
    else if (choice == 'q' || choice == 'Q')
    {
        index = 3;
    }
    else if (choice == 'p' || choice == 'P')
    {
        index = 4;
    }
    else 
    {
        cout << "wrong input." << endl;
    }

    cout << "Enter New Data : "; 
    cin.ignore(); 
    getline(cin, new_data);

    //update loop 
    while (getline(ok, line))
    {
        row.clear();
        stringstream s(line);

        while (getline(s, word, ','))
        {
            row.push_back(word);
        }

        // stringstream ss(row[0]);
        // ss >> roll1;
        int row_size = row.size();

        if (row[1] == rollnum) //row1(start form name) == input
        {
            count = 1; 
            row[index] = new_data;  // Update the specific field with new data
        }

        //
        for (i = 0; i < row_size - 1; i++)
        {
            newfile << row[i] << ",";
        }

        newfile << row[row_size - 1] << "\n";
    }

    if (count == 0)
    {
        cout << "Record not found\n";
    }

    ok.close();
    newfile.close();

    //
    remove("inventoryitemList.csv");
    rename("reportcardnew.csv", "inventoryitemList.csv");
}

void DeleteInventoryItem()
{
    fstream fin("inventoryitemList.csv");
    if (!fin.is_open()) {
        cout << "Error opening file." << endl;
        return;
    }

     //create new file to store non-delete data
    ofstream new_file("reportcardnew.csv");

    string itemName;
    cout << "Enter Item Name to delete: ";
    cin.ignore();
    getline(cin, itemName); // Get the full movie name to delete

    string line;
    vector<string> row;
    //bool deleted = false; // Flag to check if deletion occurred
    int count = 0;
    // Read each line and write to new file if not deleted
    while (getline(fin, line))
    {
        row.clear();
        stringstream s(line);
        string word;

        while (getline(s, word, ','))
        {
            row.push_back(word);
        }

        int row_size = row.size();
        // Check if the movie name matches for deletion
        if (row[1] != itemName)
        {
            // If not deleted, write the row to the new file
            for (size_t i = 0; i < row.size() - 1; i++)
            {
                new_file << row[i] << ",";
            }
            new_file << row.back() << "\n"; // Write last element without comma  
        }
        else 
        {
            count = 1;
            //deleted = true; // Set flag if we found a matching movie
            //continue; // Skip writing this row to the new file 
        }
    }

    if (count == 1)
    {
        cout << "Record deleted successfully.\n";
    }
    else 
    {
        cout << "Record not found.\n";
    }

    fin.close();
    new_file.close();

    // Replace old file with new file
    remove("inventoryitemList.csv");
    rename("reportcardnew.csv", "inventoryitemList.csv");
}

//
void CreatePersonalJournal()
{
    ofstream Myfile("personaljournalList.csv");
    
    int n;
    cout << "Enter N Journal : "; cin >> n;
    cout << endl;
    cout << "Enter Detail of Journal"<< endl;

    string id;
    string name, date, title, mood;  

    //read input
    for ( int i = 0; i < n; i++)
    {
        cout << "========================================" << endl;
        cout << "Journal Number : " << i+1 << endl;
        cout << "Journal ID : "; cin >> id;
        cout << "User Name : ";
        cin.ignore(); 
        getline(cin,name);
        cout << "Date : "; getline(cin, date);

        cout << "Title : "; 
        // cin.ignore(); 
        getline(cin,title);
        cout << "Mood : "; 
        // cin.ignore();  // To handle leftover newline from previous input
        getline(cin, mood);

        //insert data to file
        Myfile << id << "," << name << "," << date << "," << title << "," << mood << endl;

    }
}

void SearchPersonalJournal()
{
    ifstream Myfile("personaljournalList.csv");

    if (!Myfile.is_open()) {
        cout << "Error opening file." << endl;
        return;
    }

    // Get the movie name to search
    string titleName;
    cout << "Enter Journal Title to display: ";
    cin.ignore(); // Clear input buffer
    getline(cin, titleName); // Get the full movie name

    vector<string> row;
    string line;

    bool found = false; // Flag to check if the movie was found

    // Read data from the file
    while (getline(Myfile, line))
    {
        row.clear();
        stringstream s(line);
        string word;

        while (getline(s, word, ','))
        {
            row.push_back(word);
        }

        // Ensure that we have enough columns in the row
        if (row.size() > 3 && row[3] == titleName)
        {
            found = true; // Movie found
            cout << endl;
            cout << "ID: " << row[0] << endl;
            cout << "Name: " << row[1] << endl;
            cout << "Date: " << row[2] << endl;
            cout << "Title: " << row[3] << endl;
            cout << "Mood: " << row[4] << endl;
            break; // Exit loop once found
        }
    }

    if (!found)
    {
        cout << "Data not found." << endl;
    }
    
    Myfile.close();
}

void UpdatePersonalJournal()
{
    ifstream ok("personaljournalList.csv");

    //new file
    ofstream newfile("reportcardnew.csv");

    string rollnum, roll1;
    int count = 0, i;
    int index;
    string new_data;

    string line, word;
    vector<string> row;

    cout << "Enter Journal Title to update: ";
    cin.ignore();
    getline(cin, rollnum);

    char choice;
    cout << "What You want to Update UserName/Date/Mood (N/D/M): "; 
    cin >> choice;

    if (choice == 'n' || choice == 'N')
    {
        index = 1; // Date is in row[2]
    }
    else if (choice == 'd' || choice == 'D')
    {
        index = 2; // Title is in row[3]
    }
    else if (choice == 'm' || choice == 'M')
    {
        index = 4; // Mood is in row[4]
    }
    else 
    {
        cout << "Wrong input." << endl;
        return;
    }

    cout << "Enter New Data: "; 
    cin.ignore(); 
    getline(cin, new_data);

    // Update loop 
    while (getline(ok, line))
    {
        row.clear();
        stringstream s(line);

        while (getline(s, word, ','))
        {
            row.push_back(word);
        }

        int row_size = row.size();

        // Compare journal name, which is in row[1]
        if (row[3] == rollnum) 
        {
            count = 1; 
            row[index] = new_data;  // Update the specific field with new data
        }

        // Write the updated data to the new file
        for (i = 0; i < row_size - 1; i++)
        {
            newfile << row[i] << ",";
        }

        newfile << row[row_size - 1] << "\n";
    }

    if (count == 0)
    {
        cout << "Record not found\n";
    }

    ok.close();
    newfile.close();

    // Replace the old file with the updated file
    remove("personaljournalList.csv");
    rename("reportcardnew.csv", "personaljournalList.csv");
}

void DeletePersonalJournal()
{
    fstream fin("personaljournalList.csv");
    if (!fin.is_open()) {
        cout << "Error opening file." << endl;
        return;
    }

    //create new file to store non-delete data
    ofstream new_file("reportcardnew.csv");

    string itemName;
    cout << "Enter Journal Title to delete: ";
    cin.ignore();
    getline(cin, itemName); // Get the full movie name to delete

    string line;
    vector<string> row;
    //bool deleted = false; // Flag to check if deletion occurred
    int count = 0;
    // Read each line and write to new file if not deleted
    while (getline(fin, line))
    {
        row.clear();
        stringstream s(line);
        string word;

        while (getline(s, word, ','))
        {
            row.push_back(word);
        }

        int row_size = row.size();
        // Check if the movie name matches for deletion
        if (row[3] != itemName)
        {
            // If not deleted, write the row to the new file
            for (size_t i = 0; i < row.size() - 1; i++)
            {
                new_file << row[i] << ",";
            }
            new_file << row.back() << "\n"; // Write last element without comma  
        }
        else 
        {
            count = 1;
            //deleted = true; // Set flag if we found a matching movie
            //continue; // Skip writing this row to the new file 
        }
    }

    if (count == 1)
    {
        cout << "Record deleted successfully.\n";
    }
    else 
    {
        cout << "Record not found.\n";
    }

    fin.close();
    new_file.close();

    // Replace old file with new file
    remove("personaljournalList.csv");
    rename("reportcardnew.csv", "personaljournalList.csv");
}

//
void CreateEventList()
{
    ofstream Myfile("eventplannerList.csv");
    
    int n;
    cout << "Enter N Events : "; cin >> n;
    cout << endl;
    cout << "Enter Detail of Event"<< endl;

    string id;
    string hostname, date, eventname, location;  

    //read input
    for ( int i = 0; i < n; i++)
    {
        cout << "========================================" << endl;
        cout << "Event Number : " << i+1 << endl;
        cout << "Event ID : "; cin >> id;
        cout << "Host Name : ";
        cin.ignore(); 
        getline(cin,hostname);
        cout << "Event Name : "; getline(cin, eventname);

        cout << "Event Date : "; 
        // cin.ignore(); 
        getline(cin,date);
        cout << "Location : "; 
        // cin.ignore();  // To handle leftover newline from previous input
        getline(cin, location);

        //insert data to file
        Myfile << id << "," << hostname << "," << eventname << "," << date << "," << location << endl;

    }
}

void SearchEventList()
{
    ifstream Myfile("eventplannerList.csv");

    if (!Myfile.is_open()) {
        cout << "Error opening file." << endl;
        return;
    }

    // Get the movie name to search
    string eventName;
    cout << "Enter Event Name to display: ";
    cin.ignore(); // Clear input buffer
    getline(cin, eventName); // Get the full movie name

    vector<string> row;
    string line;

    bool found = false; // Flag to check if the movie was found

    // Read data from the file
    while (getline(Myfile, line))
    {
        row.clear();
        stringstream s(line);
        string word;

        while (getline(s, word, ','))
        {
            row.push_back(word);
        }

        // Ensure that we have enough columns in the row
        if (row.size() > 2 && row[2] == eventName)
        {
            found = true; // Movie found
            cout << endl;
            cout << "ID: " << row[0] << endl;
            cout << "Host-Name: " << row[1] << endl;
            cout << "Event-Name: " << row[2] << endl;
            cout << "Date: " << row[3] << endl;
            cout << "Location: " << row[4] << endl;
            break; // Exit loop once found
        }
    }

    if (!found)
    {
        cout << "Data not found." << endl;
    }
    
    Myfile.close();
}

void UpdateEventList()
{
    ifstream ok("eventplannerList.csv");

    //new file
    ofstream newfile("reportcardnew.csv");

    string rollnum, roll1;
    int count = 0, i;
    int index;
    string new_data;

    string line, word;
    vector<string> row;

    cout << "Enter Event Name to update: ";
    cin.ignore();
    getline(cin, rollnum);

    char choice;
    cout << "What You want to Update Date/Location(D/L): "; 
    cin >> choice;

    if (choice == 'd' || choice == 'D')
    {
        index = 3;
    }
    else if (choice == 'l' || choice == 'L')
    {
        index = 4; 
    }
    // else if (choice == 'm' || choice == 'M')
    // {
    //     index = 4; // Mood is in row[4]
    // }
    else 
    {
        cout << "Wrong input." << endl;
        return;
    }

    cout << "Enter New Data: "; 
    cin.ignore(); 
    getline(cin, new_data);

    // Update loop 
    while (getline(ok, line))
    {
        row.clear();
        stringstream s(line);

        while (getline(s, word, ','))
        {
            row.push_back(word);
        }

        int row_size = row.size();

        // Compare event name, which is in row[1]
        if (row[2] == rollnum) 
        {
            count = 1; 
            row[index] = new_data;  // Update the specific field with new data
        }

        // Write the updated data to the new file
        for (i = 0; i < row_size - 1; i++)
        {
            newfile << row[i] << ",";
        }

        newfile << row[row_size - 1] << "\n";
    }

    if (count == 0)
    {
        cout << "Record not found\n";
    }

    ok.close();
    newfile.close();

    // Replace the old file with the updated file
    remove("eventplannerList.csv");
    rename("reportcardnew.csv", "eventplannerList.csv");
}

void DeleteEventList()
{
    fstream fin("eventplannerList.csv");
    if (!fin.is_open()) {
        cout << "Error opening file." << endl;
        return;
    }

    //create new file to store non-delete data
    ofstream new_file("reportcardnew.csv");

    string eventName;
    cout << "Enter Event Name to delete: ";
    cin.ignore();
    getline(cin, eventName); // Get the full movie name to delete

    string line;
    vector<string> row;
    //bool deleted = false; // Flag to check if deletion occurred
    int count = 0;
    // Read each line and write to new file if not deleted
    while (getline(fin, line))
    {
        row.clear();
        stringstream s(line);
        string word;

        while (getline(s, word, ','))
        {
            row.push_back(word);
        }

        int row_size = row.size();
        // Check if the movie name matches for deletion
        if (row[2] != eventName)
        {
            // If not deleted, write the row to the new file
            for (size_t i = 0; i < row.size() - 1; i++)
            {
                new_file << row[i] << ",";
            }
            new_file << row.back() << "\n"; // Write last element without comma  
        }
        else 
        {
            count = 1;
            //deleted = true; // Set flag if we found a matching movie
            //continue; // Skip writing this row to the new file 
        }
    }

    if (count == 1)
    {
        cout << "Record deleted successfully.\n";
    }
    else 
    {
        cout << "Record not found.\n";
    }

    fin.close();
    new_file.close();

    // Replace old file with new file
    remove("eventplannerList.csv");
    rename("reportcardnew.csv", "eventplannerList.csv");
}

//
void CreateToDoList()
{
    ofstream Myfile("todoList.csv");
    
    int n;
    cout << "Enter N List : "; cin >> n;
    cout << endl;
    cout << "Enter Detail of List"<< endl;

    string id;
    string name, task_description, task_date, task_process;  

    //read input
    for ( int i = 0; i < n; i++)
    {
        cout << "========================================" << endl;
        cout << "Task Number : " << i+1 << endl;
        cout << "Task ID : "; cin >> id;
        cout << "Name : ";
        cin.ignore(); 
        getline(cin,name);
        cout << "Task Description(type) : "; getline(cin, task_description);

        cout << "Task Date : "; 
        // cin.ignore(); 
        getline(cin,task_date);
        cout << "Process(%) : "; 
        // cin.ignore();  // To handle leftover newline from previous input
        getline(cin, task_process);

        //insert data to file
        Myfile << id << "," << name << "," << task_description << "," << task_date << "," << task_process << endl;

    }
}

void SearchToDoList()
{
    ifstream Myfile("todoList.csv");

    if (!Myfile.is_open()) {
        cout << "Error opening file." << endl;
        return;
    }

    // Get the movie name to search
    string name;
    cout << "Enter Name to display: ";
    cin.ignore(); // Clear input buffer
    getline(cin, name); // Get the full movie name

    vector<string> row;
    string line;

    bool found = false; // Flag to check if the movie was found

    // Read data from the file
    while (getline(Myfile, line))
    {
        row.clear();
        stringstream s(line);
        string word;

        while (getline(s, word, ','))
        {
            row.push_back(word);
        }

        // Ensure that we have enough columns in the row
        if (row.size() > 1 && row[1] == name)
        {
            found = true; // Movie found
            cout << endl;
            cout << "ID: " << row[0] << endl;
            cout << "Name: " << row[1] << endl;
            cout << "Task Description: " << row[2] << endl;
            cout << "Task Date: " << row[3] << endl;
            cout << "Process: " << row[4] << endl;
            break; // Exit loop once found
        }
    }

    if (!found)
    {
        cout << "Data not found." << endl;
    }
    
    Myfile.close();
}

void UpdateToDoList()
{
    ifstream ok("todoList.csv");

    //new file
    ofstream newfile("reportcardnew.csv");

    string rollnum, roll1;
    int count = 0, i;
    int index;
    string new_data;

    string line, word;
    vector<string> row;

    cout << "Enter Name to update: ";
    cin.ignore();
    getline(cin, rollnum);

    char choice;
    cout << "What You want to Update Description/Date/Process(1/2/3): "; 
    cin >> choice;

    if (choice == '1' || choice == '1')
    {
        index = 2;
    }
    else if (choice == '2' || choice == '2')
    {
        index = 3; 
    }
    else if (choice == '3' || choice == '3')
    {
        index = 4; 
    }
    else 
    {
        cout << "Wrong input." << endl;
        return;
    }

    cout << "Enter New Data: "; 
    cin.ignore(); 
    getline(cin, new_data);

    // Update loop 
    while (getline(ok, line))
    {
        row.clear();
        stringstream s(line);

        while (getline(s, word, ','))
        {
            row.push_back(word);
        }

        int row_size = row.size();

        // Compare event name, which is in row[1]
        if (row[1] == rollnum) 
        {
            count = 1; 
            row[index] = new_data;  // Update the specific field with new data
        }

        // Write the updated data to the new file
        for (i = 0; i < row_size - 1; i++)
        {
            newfile << row[i] << ",";
        }

        newfile << row[row_size - 1] << "\n";
    }

    if (count == 0)
    {
        cout << "Record not found\n";
    }

    ok.close();
    newfile.close();

    // Replace the old file with the updated file
    remove("todoList.csv");
    rename("reportcardnew.csv", "todoList.csv");
}

void DeleteToDoList()
{
    fstream fin("todoList.csv");
    if (!fin.is_open()) {
        cout << "Error opening file." << endl;
        return;
    }

    //create new file to store non-delete data
    ofstream new_file("reportcardnew.csv");

    string eventName;
    cout << "Enter Name to delete: ";
    cin.ignore();
    getline(cin, eventName); // Get the full movie name to delete

    string line;
    vector<string> row;
    //bool deleted = false; // Flag to check if deletion occurred
    int count = 0;
    // Read each line and write to new file if not deleted
    while (getline(fin, line))
    {
        row.clear();
        stringstream s(line);
        string word;

        while (getline(s, word, ','))
        {
            row.push_back(word);
        }

        int row_size = row.size();
        // Check if the movie name matches for deletion
        if (row[1] != eventName)
        {
            // If not deleted, write the row to the new file
            for (size_t i = 0; i < row.size() - 1; i++)
            {
                new_file << row[i] << ",";
            }
            new_file << row.back() << "\n"; // Write last element without comma  
        }
        else 
        {
            count = 1;
            //deleted = true; // Set flag if we found a matching movie
            //continue; // Skip writing this row to the new file 
        }
    }

    if (count == 1)
    {
        cout << "Record deleted successfully.\n";
    }
    else 
    {
        cout << "Record not found.\n";
    }

    fin.close();
    new_file.close();

    // Replace old file with new file
    remove("todoList.csv");
    rename("reportcardnew.csv", "todoList.csv");
}

int main()
{
    // bool condition = true;
    // while (condition)
    // {
    start:
        cout << "\n========================================" << endl;
        cout << "1. Birthday List Management System" << endl;
        cout << "2. Contact List Management System" << endl;
        cout << "3. Movie Collection Management System" << endl;
        cout << "4. Music List Management System" << endl;
        cout << "5. Inventory Management System" << endl;
        cout << "6. Personal Journal App System" << endl;
        cout << "7. Event Planner System" << endl;
        cout << "8. Todo List Management System" << endl;
        cout << "9. Exit" << endl;
        cout << "========================================" << endl;

        int option;
        cout << "Please Enter Your Choice : "; cin >> option;

        switch (option)
        {
        case 1:
        start1:
            cout << "\n========================================" << endl;
            cout << "ContactList System Menu" << endl << endl;
            cout << "1. Create Birthday Guess Data : " << endl;
            cout << "2. Search Birthday Guess by Id : " << endl;
            cout << "3. Update Birthday Guess Data : " << endl;
            cout << "4. Delete Birthday Guess Data : " << endl;
            cout << "5. Exit" << endl;
            cout << "========================================" << endl;
            int choose1;
            cout << "Please Choose : "; cin >> choose1;

            switch (choose1)
            {
                case 1:
                    CreateBirthdayList();
                    break;
                case 2:
                    SearchBirthdayList();
                    break;
                case 3:
                    UpdateBirthdayList();
                    break;
                case 4:
                    DeleteBirthdayList();
                    break;
                case 5:
                    cout << "Exit Menu.\n";
                    // break;
                    goto start;
                default:
                    cout << "Invalid Input.\n";
                    break;
                }
            // break;
        goto start1;
        //
        case 2:
        start2:
            cout << "\n========================================" << endl;
            cout << "ContactList System Menu" << endl << endl;
            cout << "1. Create Contact Data : " << endl;
            cout << "2. Search Contact by Id : " << endl;
            cout << "3. Update Contact Data : " << endl;
            cout << "4. Delete Contact Data : " << endl;
            cout << "5. Exit" << endl;
            cout << "========================================" << endl;
            int choose2;
            cout << "Please Choose : "; cin >> choose2;

            switch (choose2)
            {
                case 1:
                    CreateContactList();
                    break;
                case 2:
                    SearchContactList();
                    break;
                case 3:
                    UpdateContactList();
                    break;
                case 4:
                    DeleteContactList();
                    break;
                case 5:
                    cout << "Exit Menu.\n";
                    // break;
                    goto start;
                default:
                    cout << "Invalid Input.\n";
                    break;
                }
            // break;
        goto start2;
        //
        case 3:
        start3:
            cout << "\n========================================" << endl;
            cout << "Movie Collection System Menu" << endl << endl;
            cout << "1. Create Movie Data : " << endl;
            cout << "2. Search Movie by Name : " << endl;
            cout << "3. Update Movie Data : " << endl;
            cout << "4. Delete Movie Data : " << endl;
            cout << "5. Exit" << endl;
            cout << "========================================" << endl;
            int choose3;
            cout << "Please Choose : "; cin >> choose3;

            switch (choose3)
            {
                case 1:
                    CreateMovieList();
                    break;
                case 2:
                    SearchMovieList();
                    break;
                case 3:
                    UpdateMovieList();
                    break;
                case 4:
                    DeleteMovieList();
                    break;
                case 5:
                    cout << "Exit Menu.\n";
                    // break;
                    goto start;
                default:
                    cout << "Invalid Input.\n";
                    break;
                }
            // break;
        goto start3;
        //
        case 4:
        start4:
            cout << "\n========================================" << endl;
            cout << "Music Playlist System Menu" << endl << endl;
            cout << "1. Create Playlist : " << endl;
            cout << "2. Search Playlist by Name : " << endl;
            cout << "3. Update Playlist : " << endl;
            cout << "4. Delete Playlist : " << endl;
            cout << "5. Exit" << endl;
            cout << "========================================" << endl;
            int choose4;
            cout << "Please Choose : "; cin >> choose4;

            switch (choose4)
            {
                case 1:
                    CreateMusicPlayList();
                    break;
                case 2:
                    SearchMusicPlayList();
                    break;
                case 3:
                    UpdateMusicPlayList();
                    break;
                case 4:
                    DeleteMusicPlayList();
                    break;
                case 5:
                    cout << "Exit Menu.\n";
                    // break;
                    goto start;
                default:
                    cout << "Invalid Input.\n";
                    break;
                }
            // break;
        goto start4;
        //
        case 5:
        start5:
            cout << "\n========================================" << endl;
            cout << "Inventory Management System Menu" << endl << endl;
            cout << "1. Create Item : " << endl;
            cout << "2. Search Item by Name : " << endl;
            cout << "3. Update Item : " << endl;
            cout << "4. Delete Item : " << endl;
            cout << "5. Exit" << endl;
            cout << "========================================" << endl;
            int choose5;
            cout << "Please Choose : "; cin >> choose5;

            switch (choose5)
            {
                case 1:
                    CreateInventoryItem();
                    break;
                case 2:
                    SearchInventoryItem();
                    break;
                case 3:
                    UpdateInventoryItem();
                    break;
                case 4:
                    DeleteInventoryItem();
                    break;
                case 5:
                    cout << "Exit Menu.\n";
                    // break;
                    goto start;
                default:
                    cout << "Invalid Input.\n";
                    break;
                }
            // break;
        goto start5;
        //
        case 6:
        start6:
            cout << "\n========================================" << endl;
            cout << "Personal Journal System Menu" << endl << endl;
            cout << "1. Create Journal : " << endl;
            cout << "2. Search Journal by ID : " << endl;
            cout << "3. Update Journal : " << endl;
            cout << "4. Delete Journal : " << endl;
            cout << "5. Exit" << endl;
            cout << "========================================" << endl;
            int choose6;
            cout << "Please Choose : "; cin >> choose6;

            switch (choose6)
            {
                case 1:
                    CreatePersonalJournal();
                    break;
                case 2:
                    SearchPersonalJournal();
                    break;
                case 3:
                    UpdatePersonalJournal();
                    break;
                case 4:
                    DeletePersonalJournal();
                    break;
                case 5:
                    cout << "Exit Menu.\n";
                    // break;
                    goto start;
                default:
                    cout << "Invalid Input.\n";
                    break;
                }
            // break;
        goto start6;
        //
        case 7:
        start7:
            cout << "\n========================================" << endl;
            cout << "Event Planner System Menu" << endl << endl;
            cout << "1. Create Event List : " << endl;
            cout << "2. Search Event by Name : " << endl;
            cout << "3. Update Event : " << endl;
            cout << "4. Delete Event : " << endl;
            cout << "5. Exit" << endl;
            cout << "========================================" << endl;
            int choose7;
            cout << "Please Choose : "; cin >> choose7;

            switch (choose7)
            {
                case 1:
                    CreateEventList();
                    break;
                case 2:
                    SearchEventList();
                    break;
                case 3:
                    UpdateEventList();
                    break;
                case 4:
                    DeleteEventList();
                    break;
                case 5:
                    cout << "Exit Menu.\n";
                    // break;
                    goto start;
                default:
                    cout << "Invalid Input.\n";
                    break;
                }
            // break;
        goto start7;
        //
        case 8:
        start8:
            cout << "\n========================================" << endl;
            cout << "ToDo List System Menu" << endl << endl;
            cout << "1. Create ToDo List : " << endl;
            cout << "2. Search ToDo List by Name : " << endl;
            cout << "3. Update ToDo List : " << endl;
            cout << "4. Delete ToDo List : " << endl;
            cout << "5. Exit" << endl;
            cout << "========================================" << endl;
            int choose8;
            cout << "Please Choose : "; cin >> choose8;

            switch (choose8)
            {
                case 1:
                    CreateToDoList();
                    break;
                case 2:
                    SearchToDoList();
                    break;
                case 3:
                    UpdateToDoList();
                    break;
                case 4:
                    DeleteToDoList();
                    break;
                case 5:
                    cout << "Exit Menu.\n";
                    // break;
                    goto start;
                default:
                    cout << "Invalid Input.\n";
                    break;
            }
            // break;
        goto start8;
        //
        case 9:
            cout << "Exit Program.\n";
            break;
        default:
            cout << "Invalid Input.\n";
            break;
        }
        // break;
        // goto start;
    return 0;
}
