// Helper functions for music

#include <cs50.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "helpers.h"

// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    //char *cha = "2";
    //int fv = atoi(cha);
    //int fv = atoi(char t);
    //int sv = atoi("%s", fraction[2]);
    //int sv = (int) (fraction - "0");
    int fv = atoi(fraction[0]);
    int sv = atoi(fraction[2]);
    fv = (8 / sv) * fv;
    return fv;


}

// Calculates frequency (in Hz) of a note
int frequency(string note)
{
    //A#4   A5
    double df = 440;
    int len = strlen(note);

    //changes frequences on the same Octave to that Letter
    switch(note[0]){
        case "A":
            df = 440 * pow(2, 0);
        break;
        case "B":
            df = 440 * pow(2, 2/12);
        break;
        case "C":
            df = 440 * pow(2, (-9)/12);
        break;
        case "D":
            df = 440 * pow(2, (-7)/12);
        break;
        case "E":
            df = 440 * pow(2, (-5)/12);
        break;
        case "F":
            df = 440 * pow(2, (-4)/12);
        break;
        case "G":
            df = 440 * pow(2, (-2)/12);
        break;
    }

    //check and changes frequences if there are # or b
    if(len > 2){
        if(strcmp(note[1], "#") == 0){
            df = df * pow(2, (1/12));
        } else if(strcmp(note[1], "b") == 0){
            df = df / pow(2, (1/12));
        }
    }

    //change the Octave
    int octave = atoi(note[len - 1]) - 4;
    df = pow(2, octave) * 440;

    //return an Hz in an int
    int f = (int) df;
    return len;
}

// Determines whether a string represents a rest
bool is_rest(string s)
{
    if(!s){
        return true;
    }
    return false;
}
