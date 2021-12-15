#ifndef DMA_H_
#define DMA_H_
#include <iostream>

class baseDMA
{
    private:
        char *label;
        int rating;
    public:
        baseDMA(const char *l = "null", const int r = 0);
        baseDMA(const baseDMA & rs);
        virtual ~baseDMA();
        baseDMA & operator=(const baseDMA & rs);
        friend std::ostream & operator<<(std::ostream & os, const baseDMA & rs);
};

// derived class without DMA
// no destructor needed
// use implicit copy constructor
// uses implicit assignment operator
class lacksDMA: public baseDMA
{
    private:
        enum {COL_LEN = 40};
        char color[COL_LEN]; // no-need to use new/delete
    public:
        lacksDMA(const char *c = "blank", const char *l = "null", const int r = 0);
        lacksDMA(const char *c, const baseDMA & rs);
        friend std::ostream & operator<<(std::ostream & os, const lacksDMA & ls);
};

// derived class with DMA
class hasDMA: public baseDMA
{
    private:
        char *style; // use new/delete
    public:
        hasDMA(const char *s = "none", const char *l = "null", const int r = 0);
        hasDMA(const char *s, const baseDMA & rs);
        hasDMA(const hasDMA & hs);
        hasDMA & operator=(const hasDMA & hs);
        ~hasDMA();
        friend std::ostream & operator<<(std::ostream & os, const hasDMA & hs);
};

#endif