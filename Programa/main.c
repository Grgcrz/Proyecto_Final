#include "funciones.h"

int main()
{
    //Esta estructura es un ejemplo para corregir la funcion imprime_titulo();
    struct client
    {
        char nom[20];
        char app[20];
        char dir[100];
        char tel[200];
    }cliente = {
    "PUCMM",
    "Exportaciones CxA",
    "Autopista Duarte,km 7,Santiago de los Caballeros,Rep.Dom",
    "Tel: 809-824-0210,Email:expoPUCMM@gmail.com"
    };
    //Aqui termina;
    imprime_titulo(cliente.nom,cliente.app,cliente.dir,cliente.tel,3);
    return 0;
}
