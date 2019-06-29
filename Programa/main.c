#include "funciones.h"
#include "test.h"
int end;
int main()
{
    do{
    int selec;
    imprime_menu();
    scanf("%d",&selec);
switch (selec) {
case 1:
    seccion_Clientes();
    imprime_salir();
    scanf("%d",&end);
    system("cls");
    break;
case 2:
    seccion_productos_y_peso();
    imprime_salir();
    scanf("%d",&end);
    system("cls");
    break;
case 3:
    system("cls");
    imprime_titulo(cliente.nom,cliente.app,cliente.dir,cliente.tel,cliente.ID,3);
    imprime_cabecera_del_cuerpo();
    imprime_salir();
    scanf("%d",&end);
    system("cls");
    break;
    case 4:
    imprime_salir();
    seccion_Archivo_factura();
    scanf("%d",&end);
    system("cls");
    break;}
} while (end != 0);
  return 0;
}
