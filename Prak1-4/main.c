#include <stdio.h>
#include "db.h"
#include "analyse.h"
#include <stdlib.h>

int main() {

    initialize_db();
    int eingabe, eingabe2, shutdown = 1;
    extern patient patienten_db[];
    int check_patientnumber();
    void zurueck();

    printf("Willkommen!\n");
    while (shutdown) {
       // system("cls");
        printf("Bitte geben sie die Nummer der Funktion ein die sie aufrufen wollen!\n\n");
        printf("1: Alle Risikopatienten ausgeben\n");
        printf("2: Alle Risikopatienten ausgeben (ab bestimmter Patientennummer)\n");
        printf("3: Alle schwangeren Patienten ausgeben\n");
        printf("4: Alle Patienten die noch keine Vorsorgeuntersuchung hatten ausgeben\n");
        printf("5: Patient in der Datenbank suchen\n");

        scanf("%d", &eingabe);
       // system("cls");
        switch (eingabe) {
            case 1:
                identify_risks();
                zurueck();
                break;

            case 2:
                eingabe2 = check_patientnumber();
                identify_risk_group((&patienten_db[eingabe2]), (arraysize - eingabe));
                zurueck();
                break;

            case 3:
                identify_pregnant();
                zurueck();
                break;

            case 4:
                vorsorge_check();
                zurueck();
                break;

            case 5:
                printf("bitte Namen eingeben!\n");
                search_name();
                zurueck();
                break;

            case 6:
                eingabe2 = check_patientnumber();
                //system("cls");
                printf("%f", (compute_bmip(&patienten_db[eingabe2 - 1])));
                zurueck();
                break;

            default:
                printf("Wiedersehen!\n");
                shutdown = 0;
                break;

        }
    }
}

int check_patientnumber(){  //Eingabe der Patientennummer
    int eingabe;
    printf("bitte Patientennummer eingeben!\n");
    scanf("%d",&eingabe);
    //system("cls");
    return eingabe;
}

void zurueck(){  //"Pausiert" den aktuellen Bildschirm bis zu einem Input
    int eingabe;
    printf("\n              \nzurueck\n");
    scanf("%d", &eingabe);
}
