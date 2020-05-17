//
// Created by Andreas Ramsauer on 23.11.2019.
//
#include "db.h"
#include <string.h>

patient patienten_db[arraysize] = {}; //globales Array

void initialize_db() { //Liste an Patienten (evtl in eigener txt Datei)

    patient Patient1;
    strcpy(Patient1.Vorname,"Rainer");
    strcpy(Patient1.Nachname,"Zufall");
    Patient1.Alter = 43;
    strcpy(Patient1.Geschlecht,"Maennlich");
    Patient1.Gewicht = 72;
    Patient1.Koerpergroesse = 180;
    Patient1.letzteLymphknotenUntersuchung = 12042018;

    patient Patient2;
    strcpy(Patient2.Vorname,"Anne");
    strcpy(Patient2.Nachname,"Hartmann");
    Patient2.Alter = 24;
    strcpy(Patient2.Geschlecht,"Weiblich");
    Patient2.Gewicht = 45;
    Patient2.Koerpergroesse = 166;
    Patient2.IstSchwanger = 1;
    Patient2.letzteBrustUntersuchung = 11122019;

    patient Patient3;
    strcpy(Patient3.Vorname,"Michael");
    strcpy(Patient3.Nachname,"Wittmann");
    Patient3.Alter = 26;
    strcpy(Patient3.Geschlecht,"Maennlich");
    Patient3.Gewicht = 90;
    Patient3.Koerpergroesse = 166;
    Patient3.letzteLymphknotenUntersuchung = 0;

    patient Patient4;
    strcpy(Patient4.Vorname,"Hilde");
    strcpy(Patient4.Nachname,"Maier");
    Patient4.Alter = 72;
    strcpy(Patient4.Geschlecht,"Weiblich");
    Patient4.Gewicht = 60;
    Patient4.Koerpergroesse = 170;
    Patient4.letzteBrustUntersuchung = 19062017;
    Patient4.IstSchwanger = 0;

    patient Patient5;
    strcpy(Patient5.Vorname,"Herbert");
    strcpy(Patient5.Nachname,"Mueller");
    Patient5.Alter = 43;
    strcpy(Patient5.Geschlecht,"Maennlich");
    Patient5.Gewicht = 42;
    Patient5.Koerpergroesse = 180;
    Patient5.letzteLymphknotenUntersuchung = 12042018;

    //Patienten dem Array zuweisen
    patienten_db[0] = Patient1;
    patienten_db[1] = Patient2;
    patienten_db[2] = Patient3;
    patienten_db[3] = Patient4;
    patienten_db[4] = Patient5;
}
