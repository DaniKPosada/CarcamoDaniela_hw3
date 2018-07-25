/*
 * =====================================================================================
 *
 *       Filename:  readData.cpp
 *
 *    Description:  Programa para almacenar valores numericos tomados de un fichero
 *                  Soporta notacion cientifica (e-01) y lineas comentadas.
 *
 *        Version:  1.0
 *        Created:  10/01/13 10:57:22
 *       Revision:  0
 *       Compiler:  g++
 *
 *         Author:  Samuel Rodriguez Bernabeu (srodrb), srodrb@gmail.com
 *   Organization:  University of Leon (Spain)
 *
 * =====================================================================================
 */
 
#include <iostream>
#include <fstream>
#include <string>
#include <math.h>  // necesaria para pow
#include <cstdlib> // para atof en c++
using namespace std;
 
int main(int argc, const char *argv[])
{
//============================== Variables modificables por el usuario
string commentSymbol = "#";
const char* filename = "forceCoeffs/0/forceCoeffs.dat";
//============================== fin de las variables modificables por el usuario
 
string STRING;
string value;
string exp; //contiene el numero
int expValue = 0;
int numberOfLines = 0;
string previousLine="";
int numberOfValues = 1;
 
ifstream infile;
infile.open (filename);
if(!infile){printf("ERROR: cannot open %s\n", filename );}
 
// Contaremos las lineas que hay en el fichero, para poder reservar memoria adecuadamente
while(!infile.eof())
{
    getline(infile,STRING);
 
    if ((STRING != previousLine) && (STRING[0] != commentSymbol[0]))
    {
        numberOfLines++; // Contador del numero de lineas no comentadas
 
        if(numberOfLines == 1)
        {
            // Este bucle nos permite contar el numero de columnas que tiene el fichero.
            for (int i = 0; i < STRING.size()-1; i++) {
                // Mi formato solo tiene un espacio, de lo contrario modifica esta parte.
                if( isspace(STRING.at(i)) )
                {
                    numberOfValues++;
                }
            }
        }
 
        previousLine=STRING;
    }
}

infile.close();
 
float values[numberOfLines][numberOfValues];
int column = 0;
int row = 0;
 
infile.open (filename);
if(!infile){printf("ERROR: cannot open %s\n", filename );}
 
// Volvemos a abrir el fichero para empezar a leer desde cero.
while(!infile.eof())
{
    getline(infile,STRING);
    if (STRING != previousLine)
    {

                    endLoop:
 
                    values[row-1][column] =
                                     (double)strtod(value.c_str(),NULL)*
                                     (pow(10,expValue));
                    expValue = 0;
                    column++;
                    value.clear();
                    exp.clear();
 
                    }
            }
        }
        column = 0;
        row++;
    }
}
 
row = row-1; // Restamos 1 para no salirnos de la indexacion
             // el mismo problema de antes.
return 0;
}
