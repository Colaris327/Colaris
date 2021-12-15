#ifndef WORKER0_H_
#define WORKER0_H_
#include <string>

class Worker // an abstract base class
{
    private:
        std::string fullname;
        long id;
    public:
        Worker(): fullname("no one"), id(0L) {}
        Worker(const std::string & s, long n): fullname(s), id(n) {}
        virtual ~Worker() = 0;
        virtual void Set();
        virtual void Show() const;
};

class Waiter: public Worker
{
    private:
        int panache;
    public:
        Waiter(): Worker(), panache(0) {}
        Waiter(const std::string & s, long n, int p): Worker(s, n), panache(p) {}
        Waiter(const Worker & wk, int p): Worker(wk), panache(p) {}
        void Set();
        void Show() const;
};

class Singer: public Worker
{
    protected:
        enum {other, alto, contralto, soprano, bass, baritone, tenor};
        enum {Vtype = 7};
    private:
        static char *pv[Vtype]; // string equivs of voice types
        int voice;
    public:
        Singer(): Worker(), voice(other) {}
        Singer(const std::string & s, long n, int v = other): Worker(s, n), voice(v) {}
        Singer(const Worker & wk, int v = other): Worker(wk), voice(other) {}
        void Set();
        void Show() const;
};
#endif