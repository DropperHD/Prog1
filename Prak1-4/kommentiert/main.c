
#include <stdio.h>
#include "db.h"
#include "analyse.h"
#include <stdlib.h>

int main() {

    int eingabe, eingabe2, shutdown = 1; //Hilfsvariablen
    extern patient patienten_db[]; //Globales Array
    void check_patientnumber(),zurueck(); //Main.c Hilfsfunktionen (unten definiert)

    initialize_db(); //Datenbank laden
    printf("Willkommen!\n");

    while (shutdown) {
        system("cls"); //Menü ausgeben
        printf("Bitte geben sie die Nummer der Funktion ein die sie aufrufen wollen!\n\n");
        printf("1: Alle Risikopatienten ausgeben\n");
        printf("2: Alle Risikopatienten ausgeben (ab bestimmter Patientennummer)\n");
        printf("3: Alle schwangeren Patienten ausgeben\n");
        printf("4: Alle Patienten die noch keine Vorsorgeuntersuchung hatten ausgeben\n");
        printf("5: Patient in der Datenbank suchen\n");

        scanf("%d", &eingabe); //Eingabe
       // system("cls"); //reinigt den Screen

        //Fallunterscheidung der Eingabe
        switch (eingabe) {
            case 1:
                identify_risks(); //Risikopatienten ausgeben
                zurueck();
                break;

            case 2: //Risikopatienten ausgeben ab n
                check_patientnumber(&eingabe2);
                identify_risk_group((&patienten_db[eingabe2-1]), (arraysize - eingabe2-1)); //-1 weil Patient1 = Array[0]
                zurueck();
                break;

            case 3: //Schwangere ausgeben
                identify_pregnant();
                zurueck();
                break;

            case 4: //Vorsorge Untersuchungen Anzeigen
                vorsorge_check();
                zurueck();
                break;

            case 5: //Suche nach Namen
                search_name();
                zurueck();
                break;

            case 0: //Exit
                shutdown = 0;
                break;

            default:
                printf("Falsche Eingabe!\n");
                zurueck();
                break;

        }
    }
}

void check_patientnumber(int *ptr){  //Speichert Partientennummer in Eingabe
    printf("bitte Patientennummer eingeben!\n");
    scanf("%d",ptr);
   // system("cls");
}

void zurueck(){  //"Pausiert" den aktuellen Bildschirm bis zu einem Input
    int eingabe;
    printf("\n              \nzurueck\n");
    scanf("%d", &eingabe);
}

