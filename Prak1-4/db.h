//
// Created by Andreas Ramsauer on 23.11.2019.
//

#ifndef UNTITLED6_DB_H
#define UNTITLED6_DB_H
#define arraysize 100
#endif //UNTITLED6_DB_H


typedef struct patient{
char Vorname[32];
char Nachname[32];
int  Alter;
int  Gewicht;
int  Koerpergroesse;
char Geschlecht[9];
union {
    int letzteLymphknotenUntersuchung;
    struct {
        int IstSchwanger;
        int letzteBrustUntersuchung;
    };
};
}patient;

void initialize_db();
