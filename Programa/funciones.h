#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
void imprime_salir(){
getch();
printf("\n\nDesea salir?\n");
printf("0 - si\n1 - regresar al inicio\n");
}
void imprime_menu(){
    system("color 8f");
for (int n = 0; n < 25; n++){
printf("%c",176);
}
printf("\tFacturadora 1.0.0\t");
for (int k = 0; k < 25; k++){
printf("%c",176);
}
puts("\n\n");
printf("\t%s\t\n\t%s\t\n\t%s\n\t%s\n","1 - Clientes y datos de envio","2 - Productos y unidades","3 - Generar factura","4 - Archivo de facturas");
puts("\n\n\tIngrese el numero con la funcion deseada: ");
}
void imprime_titulo(char name[],char nomber[],char direccion[],char telefono[],int ID[],int n){
    system("color f0");
    for(int i = 0; i < 20; i++){
    printf("%c",177);}
    printf("\t%s %s \t","PUCMM EXPORTACIONES","CXA");
    for(int i = 0; i < 20; i++){
    printf("%c",177);}
    printf("\n\t%s"," Edificios 'El matadero', Autopista Duarte Km 1 1/2 Santiago, RD.");
    printf("\n\t %s\t%s","Tel: 809-201-8036","Email:ventasMATADERO@pucmm.edu.do");
    printf(" \n\n\t\t\t%s\t","Factura comercial final");
    puts("\n");//barra de abajo
    printf("%c",218);//-|
    for(int k = 0; k < 75; k++){
        printf("%c",196);
    }
    printf("%c\n%cCliente:%s",191,179,name);
    printf("%\tNo.Factura:%s","12345");
    printf("\t Fecha:%s\t    %c","33434343",179);
    //printf("%c",179);
    printf("\n%cDirecci%cn:%s",179,162,direccion);
    printf("\t    %c\n%cTel:%s\tEmail:%s\tID/RNC:%s",179,179,telefono,"ejemploemail@ejemplo.com",ID);
    printf("  %c\n%c",179,192);
    for(int k = 0; k < 75; k++){
        printf("%c",196);
        }
    printf("%c",217);
    printf("\n");
}
void imprime_cabecera_del_cuerpo(){
puts("\n");//barra de abajo
    printf("%c",218);//-|
    for(int k = 0; k < 75; k++){
        if (k == 7 || k == 20 || k == 55 || k == 64 ){
        printf("%c",194);}else {
    printf("%c",196);}
    }
    printf("%c",191);
    printf("\n%c   ID\t",179);
    printf("%c  Cantidad  ",179);
    printf("%c\t\tProducto\t\t",179);
    printf("%c Precio ",179);
    printf("%c   Peso   %c",179,179);
    printf("\n%c",192);
    for(int k = 0; k < 75; k++){
        if (k == 7 || k == 20 || k == 55 || k == 64 ){
        printf("%c",193);}else {
    printf("%c",196);}
    }
    printf("%c",217);//-|
}

void seccion_productos_y_peso(){
system("cls");
system("color f0");
printf("\t\t\t\t\Productos y peso\t\t\t\t");
}
void seccion_Archivo_factura(){
system("cls");
system("color f0");
printf("\t\t\t\t\Productos y peso\t\t\t\t");
}
void seccion_Clientes(){
system("cls");
system("color 0f");
printf("\t\t\t\t\Clientes y direcci%cn\t\t\t\t",161);
}
//system("f0") fondo blanco, letras negras. 9, 22, 57,67.
