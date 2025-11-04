#ifndef TDATE_H
#define TDATE_H

#include "tmonth.h"

typedef struct {

    unsigned day;
    TMonth month;
    unsigned year;

} TDate;

unsigned getDay(TDate* date);
void setDay(TDate* date, unsigned day);

TMonth getMonth(TDate* date );
void setMonth(TDate* date, TMonth month );

unsigned getYear(TDate* date);
void setYear(TDate* date, unsigned year);

void setDate(TDate* date, unsigned day, TMonth month, unsigned year);

char* printDate(TDate* date);
char* printLongDate(TDate* date);

#endif