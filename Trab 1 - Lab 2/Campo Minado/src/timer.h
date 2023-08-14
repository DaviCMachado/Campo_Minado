#ifndef TIMER_H_INCLUDED
#define TIMER_H_INCLUDED
#include <time.h>

#define tempo 1000
#define timX 580
#define timY 20


void timer (double a)
{
    int m, s, m2, s2;

    m = (int) a / 60;
    m2 = (int) a / 600;
    s = (int) a / 10;
    s2 = (int) a % 600;

    if (s2 > 9)
        s2 = s2 % 10;
    if (s > 5)
        s = s % 6;

    if (m > 9)
        m = m % 10;
    if (m2 > 5)
        m2 = m2 % 6;

    CV::rect(timX, timY + 10, timX + 80, timY + 50);   // BOTAO DO TIMER

    CV::text(timX + 10, timY + 20, m2);
    CV::text(timX + 20, timY + 20, m);
    CV::text(timX + 30, timY + 20, ":");
    CV::text(timX + 40, timY + 20, s);
    CV::text(timX + 50, timY + 20, s2);
}

#endif
