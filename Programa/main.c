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
    //Imprime la factura en txt
   FILE *print;
   print = fopen("factura_0.txt","w");
   if ((print = fopen("factura_0.txt","w")) != NULL)
   {
       for(int i = 0; i < 20; i++)
    {
        fprintf(print,"#");
    }
    fprintf(print,"\t%s %s \t","PUCMM EXPORTACIONES","CXA");
    for(int i = 0; i < 20; i++)
    {
        fprintf(print,"#");
    }
    fprintf(print,"\n\t%s"," Edificios 'El matadero', Autopista Duarte Km 1 1/2 Santiago, RD.");
    fprintf(print,"\n\t %s\t%s","Tel: 809-201-8036","Email:ventasMATADERO@pucmm.edu.do");
    fprintf(print," \n\n\t\t\t%s\t","Factura comercial final");
    fprintf(print,"\n");//barra de abajo
    fprintf(print,"%c",'+');
    for(int k = 0; k < 75; k++)
    {
        fprintf(print,"%c",'-');
    }
    fprintf(print,"%c\n%cCliente:%s",'+','|',cliente.nom);
    fprintf(print,"%\tNo.Factura:%s","12345");
    fprintf(print,"\t Fecha:%s\t    %c","33434343",'|');
    //printf("%c",179);
    fprintf(print,"\n%cDirecci%cn:%s",'|','o',cliente.dir);
    fprintf(print,"\t    %c\n%cTel:%s\tEmail:%s\tID/RNC:%s",'|','|',cliente.tel,"ejemploemail@ejemplo.com",cliente.ID);
    fprintf(print,"  %c\n%c",'|','+');
    for(int k = 0; k < 75; k++)
    {
        fprintf(print,"%c",'-');
    }
    fprintf(print,"%c",'+');
    fprintf(print,"\n");

// Encabezado descripcion de la caja de productos
fprintf(print,"\n");//barra de abajo
    fprintf(print,"%c",'+');//-|
    for(int k = 0; k < 75; k++)
    {
        if (k == 7 || k == 20 || k == 55 || k == 64 )
        {
            fprintf(print,"%c",'+');
        }
        else
        {
            fprintf(print,"%c",'-');
        }
    }
    fprintf(print,"%c",'+');
    fprintf(print,"\n%c   ID\t",'|');
    fprintf(print,"%c  Cantidad  ",'|');
    fprintf(print,"%c\t\tProducto\t\t",'|');
    fprintf(print,"%c Precio ",'|');
    fprintf(print,"%c   Peso   %c",'|','|');
    fprintf(print,"\n%c",'+');
    for(int k = 0; k < 75; k++)
    {
        if (k == 7 || k == 20 || k == 55 || k == 64 )
        {
            fprintf(print,"%c",'+');
        }
        else
        {
            fprintf(print,"%c",'-');
        }
    }
    fprintf(print,"%c",'+');

       printf("\n\nLa factura fue generada correctamente!");
   } else{
    printf("ERROR: La factura no se ha generado.");
   }
   fclose(print);
    imprime_salir();
    scanf("%d",&end);
    system("cls");
    break;
    case 4:
    imprime_salir();
    seccion_Archivo_factura();
    scanf("%d",&end);
    system("cls");
    break;
case 5:
    seccion_ventas_mes();
    imprime_salir();
    scanf("%d",&end);
    system("cls");
    break;}
} while (end != 0);
  return 0;
}



