#ifndef COLA_H_INCLUDED
#define COLA_H_INCLUDED

#define SALTO 4

struct Elemento{
    int prioridad;
    char comando[50];
};

class Cola{
    Elemento *tabla;
    int inicio, fin, tamano;

    void optimizar();
    void desfragmentar();
    void escalarTabla(int cantidad);
    void ampliar();
    void reducir();
public:
    Cola();
    ~Cola();
    void encolar(Elemento e);
    void desencolar();
    Elemento primero();
    bool esVacia();
    int longitud();

    void dibujar();
};

#endif // COLA_H_INCLUDED
