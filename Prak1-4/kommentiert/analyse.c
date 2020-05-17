//
// Created by Andreas Ramsauer on 23.11.2019.
//
#include <string.h>
#include "analyse.h"
#include <stdio.h>
#include "db.h"
#include <stdlib.h>

extern patient patienten_db[]; //Externes globales Array
void printdatum(int x); // unten defieniert (gibt ein Datum aus)


float compute_bmi(patient p) //BMI für bestimmten Patient
{

    return (float)(p.Gewicht / ((p.Koerpergroesse / 100.00) * (p.Koerpergroesse / 100.00)));  // Gewicht/Größe in Metern^2
}


float compute_bmip(patient *ptr)  // BMI mit Pointer zu Patient
{

    return (float)((*ptr).Gewicht / (((*ptr).Koerpergroesse / 100.00) * (*ptr).Koerpergroesse / 100.00));  // Gewicht/Größe in Metern^2
}


void identify_risks() { //Alle Risikopatienten ausgeben
    for (int i = 0; i < 100; i++) {
        if (compute_bmi(patienten_db[i]) > 25 || compute_bmi(patienten_db[i]) < 20) {  //falls der BMI eines Patienten über 25 oder unter 25 ist
            printf("[%d] %s %s\n", i+1, patienten_db[i].Vorname, patienten_db[i].Nachname);  //print Nummer, Vorname, Nachname
        }
    }
}


void identify_risk_group(patient *patients, int size) { //Risikogruppen ab bestimmten Pointer
    for (int i = 0; i <= size; i++)
        if (compute_bmip((patients + i)) > 25 || compute_bmip(((patients + i))) < 20) {  //falls der BMI eines Patienten über 25 oder unter 25 ist
            printf("[%d] %s %s\n", arraysize-size+i-1 ,(patients + i)->Vorname, (patients + i)->Nachname);  //print Nummer, Vorname, Nachname
        }
}


void identify_pregnant() { //Schwangere Ausgeben
    for (int i = 0; i < arraysize; i++) {
        if (patienten_db[i].IstSchwanger == 1) {  //falls die Patientin Schwanger ist
            printf("[%d] %s %s\n", i+1, patienten_db[i].Vorname, patienten_db[i].Nachname);  //print Nummer, Vorname, Nachname
        }
    }
}


void vorsorge_check() { //Ausgabe des Patienten falls keine Vorsorge Untersuchung gemacht wurde
    for (int i = 0; i < 100; i++) {

        if (stricmp(patienten_db[i].Geschlecht, "Maennlich") == 0) {   //für Männer
            if (patienten_db[i].letzteLymphknotenUntersuchung == 0) {
                printf("[%d] %s %s\n", i+1, patienten_db[i].Vorname, patienten_db[i].Nachname);
            }
        }

        if (stricmp(patienten_db[i].Geschlecht, "Weiblich") == 0) {   //für Frauen
            if (patienten_db[i].letzteBrustUntersuchung == 0) {
                printf("[%d] %s %s\n", i+1, patienten_db[i].Vorname, patienten_db[i].Nachname);
            }

        }
    }
}

void search_name() { //Nach Nachnamen in der Datenbank suchen
    char eingabe[32];
    printf("bitte Namen eingeben!\n");
    scanf("%s", eingabe);
    system("cls");

    for (int i = 0; i < arraysize; i++) { //Komplette Datenbank durchgehen
        if (strcmp(eingabe, patienten_db[i].Nachname) == 0) {
            printf("Vorname: %s\nNachname: %s\nAlter: %d\nGewicht: %d\nKoerpergroesee: %d\nGeschlecht: %s\n", //alle Daten ausgeben
                   patienten_db[i].Vorname,
                   patienten_db[i].Nachname,
                   patienten_db[i].Alter,
                   patienten_db[i].Gewicht,
                   patienten_db[i].Koerpergroesse,
                   patienten_db[i].Geschlecht
            );

            //Geschlechtsspezifische Eigenschaften
            if (strcmp(patienten_db[i].Geschlecht, "Maennlich") == 0) { //Für Männer
                printf("Letzte Lymphknotenuntersuchung: ");
                printdatum(patienten_db[i].letzteLymphknotenUntersuchung);
            }

            if (strcmp(patienten_db[i].Geschlecht, "Weiblich") == 0) { //Für Frauen
                printf("Letzte Brustuntersuchung: ");
                printdatum(patienten_db[i].letzteBrustUntersuchung);

                if (patienten_db[i].IstSchwanger == 1) {  //Schwangerschafts-Status
                    printf("Schwangerschaftsstatus: Ist Schwanger\n");
                } else {
                    printf("Schwangerschaftsstatus: Ist nicht Schwanger\n");
                }
            }
        }
    }
}

void printdatum(int x) { //Ausgabe des Datums
    if(x!=0) {
        printf("%d.%d.%d\n", x / 1000000, (x / 10000) % 100, x % 10000); //TT.MM.JJJJ
        return;
    }
    printf("noch keine Untersuchung!");
}
