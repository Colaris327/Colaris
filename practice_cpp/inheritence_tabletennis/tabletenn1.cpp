#include "tabletenn.h"
#include <iostream>
#include <cstring>

TableTennisplayer::TableTennisplayer(const char *fn, const char *ln, bool ht)
{
    std::strncpy(firstname, fn, LIM - 1);
    firstname[LIM - 1] = '\0';
    std::strncpy(lastname, ln, LIM - 1);
    lastname[LIM - 1] = '\0';
    hastable = ht;
}

void TableTennisplayer::Name() const
{
    std::cout << lastname << ", " << firstname;
}

RatedPlayer::RatedPlayer(unsigned int r, const char *fn, const char *ln, bool ht): TableTennisplayer(fn, ln, ht)
{
    rating = r;
}

RatedPlayer::RatedPlayer(unsigned int r, const TableTennisplayer & tp): TableTennisplayer(tp), rating(r)
{
}