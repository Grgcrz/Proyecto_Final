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
    imprime_titulo(cliente.nom,cliente.app,cliente.dir,cliente.tel,cliente.ID,3,cliente.fecha,cliente.factura);
    imprime_cabecera_del_cuerpo();

    //Imprime la factura en txt
   FILE *print;
   print = fopen("factura_0.txt","w");
   if ((print = fopen("factura_0.txt","w")) != NULL)
   {
       //Imprime encabezado de los datos de la compañnia.
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
    //--------------------Seccion auto linea--------------------
    for(int j = 0; j <(20 - strlen(cliente.nom)); j++)
    {fprintf(print,"%c",' ');
    }
    fprintf(print,"No.Factura:%s",cliente.factura);
    fprintf(print,"  Fecha:%s",cliente.fecha,'|');
    //---------------------------------------------------------------------------------------------------------------------
    for(int j = 0; j <(28 - (strlen(cliente.fecha)+ strlen(cliente.nom)+strlen(cliente.factura))+strlen(cliente.nom)); j++)
    {fprintf(print,"%c",' ');
    }
    //-----------------------------------------------------------
    fprintf(print,"%c",'|');
    fprintf(print,"\n%cDirecci%cn:%s",'|','o',cliente.dir);
    fprintf(print,"\t    %c\n%cTel:%s\tEmail:%s\tID/RNC:%s",'|','|',cliente.tel,"ejemploemail@ejemplo.com",cliente.ID);
    //--------------------Seccion auto linea--------------------
    for(int k = 0; k <(13 - strlen(cliente.ID)); k++)
    {fprintf(print,"%c",' ');
    }
    //-----------------------------------------------------------
    fprintf(print,"%c\n%c",'|','+');
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

    // imprime final de factura
    fprintf(print,"\n");
 for(int k = 0; k < 77; k++)
    {
        fprintf(print,"%c",'-');
    }
    fprintf(print,"\nTotal:%d","23");
    //--------------------Seccion auto linea--------------------
    for(int j = 0; j <(22 - 19/*strlen(name)*/); j++)
    {fprintf(print,"%c",' ');
    }
    //-----------------------------------------------------------
    fprintf(print,"\nTotal Peso :%d KLG ","2334");
    fprintf(print,"\nTotal RDS$:%.2f","2332.33");
    fprintf(print,"\n\n%c","Gracias por preferirnos!!!");
    //-----------------------------FINAL------------------------------
   } else{
    printf("ERROR: La factura no se ha generado.");
   }
   fclose(print);
   imprime_fondo();

   //Aqui deja de imprimir en .TXT
    imprime_salir();
    scanf("%d",&end);
    system("cls");
    break;
    //aqui termina seccion 3;
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



