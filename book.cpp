#include "book.h"
#include <iostream>
#include <sstream>

using namespace std;

// Default constructor
Book::Book()
    : title(""), author(""), isbn(""), isAvailable(true), borrowerName("") {}

// Parameterized constructor
Book::Book(const string& title, const string& author, const string& isbn)
    : title(title), author(author), isbn(isbn), isAvailable(true), borrowerName("") {}

// Getters
string Book::getTitle() const { return title; }
string Book::getAuthor() const { return author; }
string Book::getISBN() const { return isbn; }
bool Book::getAvailability() const { return isAvailable; }
string Book::getBorrowerName() const { return borrowerName; }


// Setters
void Book::setTitle(const string& title) { this->title = title; }
void Book::setAuthor(const string& author) { this->author = author; }
void Book::setISBN(const string& isbn) { this->isbn = isbn; }
void Book::setAvailability(bool isAvailable) { this->isAvailable = isAvailable; }
void Book::setBorrowerName(const string& borrowerName) { this->borrowerName = borrowerName; }

//Methods
void Book::checkOut(const string& borrower){
    if (isAvailable) {
        isAvailable = false;
        borrowerName = borrower;
    }
}

void Book::returnBook(){
    isAvailable = true;
    borrowerName.clear();
}


string Book::toString() const {
    string result = "Titre: " + title + 
                    "\nAuteur: " + author + 
                    "\nISBN: " + isbn + 
                    "\nDisponible: " + string(isAvailable ? "oui": "non");
    
    if (!isAvailable && !borrowerName.empty()) {
        result += "\nEmprunteur: " + borrowerName;
    }

    return result; 
}

string Book::toFileFormat() const {
    string result = title + "|" + author + "|" + isbn + "|" + (isAvailable ? "1" : "0") + ";" + borrowerName;
}

void Book::fromFileFormat(const string& line) {
    stringstream ss(line);
    string token;

    getline(ss, title, '|');
    getline(ss, author, '|');
    getline(ss, isbn, '|');

    getline(ss, token, '|');
    isAvailable = (token == "1");

    getline(ss, borrowerName, '|');
}