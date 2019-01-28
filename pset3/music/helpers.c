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
    int fv = atoi(&fraction[0]);
    int sv = atoi(&fraction[2]);
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
    char c = note[0];
    switch(c){
        case 'A':
            df = 440 * pow(2.00, 0);

        break;
        case 'B':
            df = 440 * pow(2.00, 2.00/12.00);
        break;
        case 'C':
            df = 440 * pow(2.00, (-9.00)/12.00);
        break;
        case 'D':
            df = 440 * pow(2.00, (-7.00)/12.00);
        break;
        case 'E':
            df = 440 * pow(2.00, (-5.00)/12.00);
        break;
        case 'F':
            df = 440 * pow(2.00, (-4.00)/12.00);
        break;
        case 'G':
            df = 440 * pow(2.00, (-2.00)/12.00);
        break;
    }

    //check and changes frequences if there are # or b
    if(len > 2){
        if(note[1] == '#'){
            df = df * pow(2.00, (1.00/12.00));
        } else if(note[1] == 'b'){
            df = df * pow(2.00, (-1.00/12.00));
        }
    }

    //change the Octave
    double octave = atoi(&note[len - 1]) - 4;
    df = pow(2.00, octave) * df;

    //return an Hz in an int
    int f = (int) round(df);
    return f;
}

// Determines whether a string represents a rest
bool is_rest(string s)
{
    if(!strcmp(s, "")){
        return true;
    }
    return false;
}
