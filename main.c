#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./Elem.h"
#include "./LIsta.h"
#include "./Hash.h"

int game(char *, char *, int);

int main()
{

   Elem paises[10];
   char opcion[20];

   printf("Elige el nivel:\nA1\nA2\nB1\nB2\nC1\n\n");
   scanf("%s", opcion);
   strcat(opcion, ".txt");

   FILE *ent = fopen(opcion, "r");

   int aciertos = 0;
   int n = 223;
   TablaH t = consTH(n);
   Elem e;
   char english_word[80];
   int i;

   for (i = 1; i <= 10; i++)
   {
      e = LeeElem(ent);
      t = InsElem(e, t, n);
      aciertos = game(e.english, e.spanish, aciertos);
   }

   printf("LISTO, tu score fue de: %d\n", aciertos);
   return 0;
}

int game(char *en, char *es, int aciertos)
{
   char spanish_word[80];
   char tmp[80];

   printf("Cual es el significado de la palabra %s?\n", en);
   scanf("%s", spanish_word);
   strcpy(tmp, es);

   if (!strcmp(spanish_word, tmp))
   {
      aciertos += 1;
   }
   printf("\n");

   return aciertos;
}