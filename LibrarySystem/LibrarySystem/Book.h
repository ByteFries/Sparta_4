#pragma once
#include "framework.h"

class Book {
public:
    Book(const string& title, const string& author)
        : title(title), author(author) 
    {}

    string title;
    string author;
};
