#ifndef TABLETENN_H_
#define TABLETENN_H_

class TableTennisplayer
{
    private:
        enum {LIM = 20};
        char firstname[LIM];
        char lastname[LIM];
        bool hastable;
    public:
        TableTennisplayer(const char *fn = "none", const char *ln = "none", bool ht = false);
        void Name() const;
        bool HasTable() const {return hastable;}
        void ResetTable(bool v) {hastable = v;}
};

class RatedPlayer: public TableTennisplayer
{
    private:
        unsigned int rating;
    public:
        RatedPlayer(unsigned int r = 0, const char *fn = "none", const char *ln = "none", bool ht = false);
        RatedPlayer(unsigned int r, const TableTennisplayer & tp);
        unsigned int Rating() {return rating;}
        void ResetRating(unsigned int r) {rating = r;}
};
#endif