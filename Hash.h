typedef Lista *TablaH;

TablaH consTH(int n)
{
    int i;
    TablaH t = (TablaH)malloc(sizeof(Lista) * n);
    for (i = 0; i < n; i++)
        t[i] = vacia();
    return t;
}

TablaH InsElem(Elem e, TablaH t, int n)
{
    t[Llave(e) % n] = cons(e, t[Llave(e) % n]);

    return t;
}

void ImpTablaH(TablaH t, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        ImpElems(t[i]);
        puts("\n--------------");
    }
}

void Consulta(Elem e, TablaH t, int n)
{
    if (EstaEn(e, t[Llave(e) % n]))
        ImpElem(DevuelveElem(e, t[Llave(e) % n]));
    else
        puts("Elemento no encontrado");
}

void Borra(Elem e, TablaH t, int n)
{
    if (EstaEn(e, t[Llave(e) % n]))
    {
        printf("Elemento elimnado:\n");
        ImpElem(DevuelveElem(e, t[Llave(e) % n]));
        t[Llave(e) % n] = EliminaElem(e, t[Llave(e) % n]);
    }
    else
        puts("Elemento no encontrado");
}