#include <iostream>
using std::ostream;
using std::istream;

#ifndef STRING_H_
#define STRING_H_

class String
{
    private:
        char *str;
        int len;
        static int num_strings; // number of objects
        static const int CINLIM = 80; // cin input limit
    
    public:
    // constructor and other method
        String(const char *s); // constructor
        String(); // default constructor
        String(const String &); // copy constructor, see c++primer chapter 12
        ~String();
        int length() {return len;}
    // overloaded operator methods
        String & operator=(const String &);
        String & operator=(const char *);
        char & operator[](int i);
        const char & operator[](int i) const;
    // overloaded operator friends
        friend bool operator<(const String & st, const String & st2);
        friend bool operator>(const String & st1, const String & st2);
        friend bool operator==(const String & st, const String & st2);
        friend ostream & operator<<(ostream & os, const String & st);
        friend istream & operator>>(istream & is, String & st);
    // static function
        static int Howmany();
};
#endif