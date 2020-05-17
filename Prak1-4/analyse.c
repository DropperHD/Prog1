//
// Created by Andreas Ramsauer on 23.11.2019.
//
#include <string.h>
#include "analyse.h"
#include <stdio.h>
#include "db.h"
#include <stdlib.h>

extern patient patienten_db[]; //Globales Array

void printdatum(int x); // unten defieniert

float compute_bmi(patient p) { //BMI für bestimmten Patient

    return p.Gewicht / ((p.Koerpergroesse / 100.00) * (p.Koerpergroesse / 100.00));

}

void identify_risks() { //Alle Risikopatienten ausgeben
    for (int i = 0; i < 100; i++) {
        if (compute_bmi(patienten_db[i]) > 25 || compute_bmi(patienten_db[i]) < 20) {
            printf("[%d] %s %s\n", i, patienten_db[i].Vorname, patienten_db[i].Nachname);
        }
    }
}

float compute_bmip(patient *ptr) { // BMI mit Pointer zu Patient

    return (float)((*ptr).Gewicht / (((*ptr).Koerpergroesse / 100.00) * (*ptr).Koerpergroesse / 100.00)); // Gewicht/Größe in Metern^2


}


void identify_risk_group(patient *patients, int size) { //Risikogruppen ab bestimmten Pointer
    for (int i = 0; i <= size; i++)
        if (compute_bmip((patients + i)) > 25 || compute_bmip(((patients + i))) < 20) { //Falls BMI kleiner 20 oder größer 25
            printf("[%d] %s %s\n", arraysize-size+i-1
                   ,(patients + i)->Vorname, (patients + i)->Nachname);
        }
}

void identify_pregnant() { //Schwangere Ausgeben
    for (int i = 0; i < 100; i++) {
        if (patienten_db[i].IstSchwanger == 1) {
            printf("[%d] %s %s\n", i, patienten_db[i].Vorname, patienten_db[i].Nachname);
        }
    }
}

void vorsorge_check() { //Ausgabe des Patienten falls keine Vorsorge Untersuchung gemacht wurde
    for (int i = 0; i < 100; i++) {
        //für Männer
        if (stricmp(patienten_db[i].Geschlecht, "Maennlich") == 0) {
            if (patienten_db[i].letzteLymphknotenUntersuchung == 0) {
                printf("[%d] %s %s\n", i, patienten_db[i].Vorname, patienten_db[i].Nachname);
            }
        }
        //für Frauen
        if (stricmp(patienten_db[i].Geschlecht, "Weiblich") == 0) {
            if (patienten_db[i].letzteBrustUntersuchung == 0) {
                printf("[%d] %s %s\n", i, patienten_db[i].Vorname, patienten_db[i].Nachname);
            }
        }
    }
}

void search_name() { //Nach Nachnamen suchen in der Datenbank
    char eingabe[30];
    scanf("%s", eingabe);
    system("cls");
    for (int i = 0; i < arraysize; i++) { //Komplette Datenbank durchgehen
        if (strcmp(eingabe, patienten_db[i].Nachname) == 0) {
            printf("Vorname: %s\nNachname: %s\nAlter: %d\nGewicht: %d\nKoerpergroesee: %d\nGeschlecht: %s\n",
                   patienten_db[i].Vorname,
                   patienten_db[i].Nachname,
                   patienten_db[i].Alter,
                   patienten_db[i].Gewicht,
                   patienten_db[i].Koerpergroesse,
                   patienten_db[i].Geschlecht
                   );
            //Geschlechtsspezifische Eigenschaften
            if (strcmp(patienten_db[i].Geschlecht, "Maennlich") == 0) { //Männer
                printf("Letzte Lymphknotenuntersuchung: ");
                printdatum(patienten_db[i].letzteLymphknotenUntersuchung);
            } else {
                printf("Letzte Brustuntersuchung: "); //Frauen
                printdatum(patienten_db[i].letzteBrustUntersuchung);
                if (patienten_db[i].IstSchwanger == 1) {
                    printf("Schwangerschaftsstatus: Ist Schwanger\n");
                } else {
                    printf("Schwangerschaftsstatus: Ist nicht Schwanger\n");
                }
            }
        }

        }
    }

void printdatum(int x) { //Ausgabe des Datums in TT.MM.JJJJ
    if(x!=0) {
        printf("%d.%d.%d\n", x / 1000000, (x / 10000) % 100, x % 10000);
        return;
    }
    printf("noch keine Untersuchung!");
}
