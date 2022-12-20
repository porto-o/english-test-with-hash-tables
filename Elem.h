typedef struct
{
    char *english;
    char *spanish;
} Elem;

Elem LeeElem(FILE *ent)
{
    Elem e;
    e.english = (char *)malloc(20);
    e.spanish = (char *)malloc(20);
    fscanf(ent, "%s", e.english);
    fscanf(ent, "%s", e.spanish);
    return e;
}

Elem LeeElemCons()
{
    Elem e;
    e.english = (char *)malloc(sizeof(char) * 20);
    e.spanish = (char *)malloc(20);
    scanf("%s", e.english);
    scanf("%s", e.spanish);
    return e;
}

void ImpElemF(FILE *sal, Elem e)
{
    fprintf(sal, "%s\n", e.english);
    fprintf(sal, "%s\n", e.spanish);
}

void ImpElem(Elem e)
{
    printf("%s\t", e.english);
    printf("%s\t", e.spanish);
}

int EsIgual(Elem e1, Elem e2) { return !strcmp(e1.english, e2.english); }

int Llave(Elem e)
{
    int n = 0, i = 0;
    char *p = e.english;
    while (e.english[i])
        n = n + e.english[i++];

    return n;
}