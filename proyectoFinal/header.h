#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

//Esta seccion es para probar el codigo, luego de hecho el codigo final, se debe borrar.
//struct datos_cliente *data_client;
//malloc(10* size_of(data_client)
int dia;
int mes;
int year;

typedef struct {
    char*Id_product;
    float  peso;
    float price;
    int cant;
    char*N_product;
}prod;
typedef struct {
    int dia;
    int mes;
    int annio;
    char *ID;
    float  Total_product_price;
    float  Total_product_weigh;
    int  Total_fact_cant_;
    float  Total_fact_weigh_;
    float  Total_fact_price_;
    int n_productos;
    prod*productos;
}facturas;
typedef struct {
    char *ID_client;
    char *name;
    char *address;
    char *telephone;
    char *mail;
    float deuda;
    int factCntd;
    int factCntd2;
    facturas * fact;
}datos_cliente;
//Esta estructura es un ejemplo para corregir la funcion imprime_titulo();
struct client
{
    char nom[22];
    char app[10];
    char dir[100];
    char tel[200];
    char ID[13];
    char fecha[13];
    char factura[80];
} cliente = {
        "sabaneta","limites","Autopista Duarte,km 7,Santiago de los Caballeros,Rep.Dom","809-824-0210","123456","23-12-18","231218A"
};
//Aqui termina seccion de estructuras;
//--------------------------------------------------------==---------------------------=------------------=-----------------=------------------------=----------------------------=----------------------------------=---------------------------
char * leer(){

    char c, *prt;

    int i=0;

    prt = (char *) malloc(1 * sizeof(char));

    *prt = '\0';

    while ((c=getchar())!='\n') {

        prt = (char *) realloc(prt, (i + 2) * sizeof(char));

        prt[i++] = c;

        prt[i] = '\0';

    }

    return prt;

}
datos_cliente*leer_produtos(datos_cliente*client,int noClnt,int facCntr,int j){
    fflush(stdin);
    if(client[noClnt].fact == NULL){
        realloc(client[noClnt].fact, 10* sizeof(client[noClnt].fact));

    }
    realloc(client[noClnt].fact[facCntr].productos[j].N_product, 100* sizeof(client[noClnt].fact));
    realloc(client[noClnt].fact[facCntr].productos[j].Id_product, 100* sizeof(client[noClnt].fact));
    system("cls");
    printf("Ingrese ID del %d producto\n",j+1);
    client[noClnt].fact[facCntr].productos[j].Id_product = leer();
    puts("Ingrese nombre del producto: \n");
    client[noClnt].fact[facCntr].productos[j].N_product = leer();
    puts("Ingrese cantidad (unidades): \n");
    scanf("%d",&client[noClnt].fact[facCntr].productos[j].cant);
    puts("Ingrese Precio por klg: \n");
    scanf("%f",&client[noClnt].fact[facCntr].productos[j].price);
    puts("Ingrese Peso en klg: \n");
    scanf("%f",&client[noClnt].fact[facCntr].productos[j].peso);
    return client;
}
datos_cliente*leer_clientes(datos_cliente*client,int n){
        puts("Ingrese ID, RNC o documento de identidad\n");
        scanf("%s",client[n].ID_client);
        puts("Ingrese Nombre: \n");
        scanf("%s",client[n].name);
        puts("Ingrese Direccion: \n");
        scanf("%s",client[n].address);
        puts("Ingrese telefono: \n");
        scanf("%s",client[n].telephone);
        puts("Ingrese e-mail: \n");
        scanf("%s",client[n].mail);
        printf("Listo!!!");

        return client;
}
datos_cliente*leer_fecha(datos_cliente*client,int noClnt,int facCntr){
    puts("\nInsertar fecha: formato DD/MM/AAAA\n");
    puts("Ingrese dia\n");
    scanf("%d",&client[noClnt].fact[facCntr].dia);
    puts("Ingrese mes: \n");
    scanf("%d",&client[noClnt].fact[facCntr].mes);
    printf("Ingrese a%co: \n",164);
    scanf("%d",&client[noClnt].fact[facCntr].annio);
    printf("Listo!!!");
    return client;
}
void totales(datos_cliente*client,int noClnt,int facCntr,int j){
    int cant = 0;
    float klg = 0, money = 0;
    for (int i = 0; i < j ; i++) {
        cant += client[noClnt].fact[facCntr].productos[i].cant;
    }
    for (int i = 0; i < j ; i++) {
        klg += client[noClnt].fact[facCntr].productos[i].peso;
    }
    for (int i = 0; i < j ; i++) {
        money += (client[noClnt].fact[facCntr].productos[i].price*client[noClnt].fact[facCntr].productos[i].peso);
    }
    client[noClnt].fact[facCntr].Total_fact_cant_ = cant;
    client[noClnt].fact[facCntr].Total_fact_weigh_ = klg;
    client[noClnt].fact[facCntr].Total_product_price = money;
}
int busqueda_nombre_cliente(datos_cliente *clientee, int n)
{
    char *nom;
    fflush(stdin);
    printf("\n\nInserte el nombre del cliente: ");
    nom=leer();
    int i;
    for(i=0;i<n;i++)
    {
        if(stricmp(clientee[i].name,nom)==0)
            return i;
    }
    return 0;
}
int busqueda_factura(datos_cliente *clientee, int n)
{
    char *nom;
    fflush(stdin);
    printf("\n\nInserte el ID de la factura: ");
    nom=leer();
    int i;
    for(i=0;i<n;i++)
    {
        if(stricmp(clientee[n].fact[i].ID,nom)==0)
            return i;
    }
    return 0;
}
void imprime_titulo(datos_cliente * data_cl ,int noClnt, int fac)
{
    system("color f0");
    for(int xe = 0; xe < 20; ++xe)
    {
        printf("%c",177);
    }
    printf("\t%s %s \t","PUCMM EXPORTACIONES","CXA");
    for(int i1 = 0; i1 < 20; ++i1)
    {
        printf("%c",177);
    }
    printf("\n\t%s"," Edificios 'El matadero', Autopista Duarte Km 1 1/2 Santiago, RD.");
    printf("\n\t %s\t%s","Tel: 809-201-8036","Email:ventasMATADERO@pucmm.edu.do");
    printf(" \n\n\t\t\t%s\t","Factura comercial final");
    puts("\n");//barra de abajo
    printf("%c",218);//-|
    for(int k2 = 0; k2 < 75; k2++)
    {
        printf("%c",196);
    }

    printf("%c\n%cCliente: %s",191,179,data_cl[noClnt].name);
    //--------------------Seccion auto linea--------------------
    for(int j2 = 0; j2 <(22 - strlen(data_cl[noClnt].name)); j2++)
    {printf("%c",' ');
    }

    //-----------------------------------------------------------
    printf("No.Factura:%s",data_cl[noClnt].fact[fac].ID);
    printf("  Fecha:%d\\%d\\%d",data_cl[noClnt].fact[fac].dia,data_cl[noClnt].fact[fac].mes,data_cl[noClnt].fact[fac].annio);
    //--------------------Seccion auto linea (ESPECIAL)--------------------
    //----------------------------------------------------------------------
    for(int j3 = 0; j3 <(26 - 11 + strlen(data_cl[noClnt].name)+strlen(data_cl[noClnt].fact[fac].ID)); j3++)
    {printf("%c",' ');
    }
    //-----------------------------------------------------------
    //-----------------------------------------------------------
    printf("%c",179);
    printf("\n%cDirecci%cn:%s",179,162,data_cl[noClnt].address);
    //--------------------Seccion auto linea--------------------
    for(int l = 0; l <(65 - strlen(data_cl[noClnt].address)); l++)
    {printf("%c",' ');
    }
    //-----------------------------------------------------------
    printf("%c",179);
    printf("\n%cTel:%s\tEmail:%s\tID/RNC:%s",179,data_cl[noClnt].telephone,data_cl[noClnt].mail,data_cl[noClnt].ID_client);
    //--------------------Seccion auto linea--------------------
    for(int m = 0; m <(37 - strlen(data_cl[noClnt].telephone)+strlen(data_cl[noClnt].mail)+strlen(data_cl[noClnt].ID_client)); m++)
    {printf("%c",' ');
    }
    //-----------------------------------------------------------
    printf("%c\n%c",179,192);
    for(int k6 = 0; k6 < 75; k6++)
    {
        printf("%c",196);
    }
    printf("%c",217);
    printf("\n");
}
void file_imprime_titulo(FILE*print,datos_cliente * data_cl ,int noClnt, int fac)
{
    system("color f0");
    for(int xe = 0; xe < 20; ++xe)
    {
        fprintf(print,"%c",'#');
    }
    fprintf(print,"\t%s %s \t","PUCMM EXPORTACIONES","CXA");
    for(int i1 = 0; i1 < 20; ++i1)
    {
        fprintf(print,"%c",'#');
    }
    fprintf(print,"\n\t%s"," Edificios 'El matadero', Autopista Duarte Km 1 1/2 Santiago, RD.");
    fprintf(print,"\n\t %s\t%s","Tel: 809-201-8036","Email:ventasMATADERO@pucmm.edu.do");
    fprintf(print," \n\n\t\t\t%s\t\n","Factura comercial final");
    puts("\n");//barra de abajo
    fprintf(print,"%c",'+');//-|
    for(int k2 = 0; k2 < 75; k2++)
    {
        fprintf(print,"%c",'-');
    }

    fprintf(print,"%c\n%cCliente: %s",'+','|',data_cl[noClnt].name);
    //--------------------Seccion auto linea--------------------
    for(int j2 = 0; j2 <(22 - strlen(data_cl[noClnt].name)); j2++)
    {fprintf(print,"%c",' ');
    }

    //-----------------------------------------------------------
    fprintf(print,"No.Factura:%s",data_cl[noClnt].fact[fac].ID);
    fprintf(print,"  Fecha:%d\\%d\\%d",data_cl[noClnt].fact[fac].dia,data_cl[noClnt].fact[fac].mes,data_cl[noClnt].fact[fac].annio);
    //--------------------Seccion auto linea (ESPECIAL)--------------------
    //----------------------------------------------------------------------
    for(int j3 = 0; j3 <(26 - 11 + strlen(data_cl[noClnt].name)+strlen(data_cl[noClnt].fact[fac].ID)); j3++)
    {fprintf(print,"%c",' ');
    }
    //-----------------------------------------------------------
    //-----------------------------------------------------------
    fprintf(print,"%c",'|');
    fprintf(print,"\n%cDireccion:%s",'|',data_cl[noClnt].address);
    //--------------------Seccion auto linea--------------------
    for(int l = 0; l <(65 - strlen(data_cl[noClnt].address)); l++)
    {fprintf(print,"%c",' ');
    }
    //-----------------------------------------------------------
    fprintf(print,"%c",'|');
    fprintf(print,"\n%cTel:%s\tEmail:%s\tID/RNC:%s",'|',data_cl[noClnt].telephone,data_cl[noClnt].mail,data_cl[noClnt].ID_client);
    //--------------------Seccion auto linea--------------------
    for(int m = 0; m <(37 - strlen(data_cl[noClnt].telephone)+strlen(data_cl[noClnt].mail)+strlen(data_cl[noClnt].ID_client)); m++)
    {fprintf(print,"%c",' ');
    }
    //-----------------------------------------------------------
    fprintf(print,"%c\n%c",'|','+');
    for(int k6 = 0; k6 < 75; k6++)
    {
        fprintf(print,"%c",'-');
    }
    fprintf(print,"%c",'+');
    fprintf(print,"\n");
}
void imprime_cabecera_del_cuerpo()
{

    puts("\n");//barra de abajo
    printf("%c",218);//-|
    for(int k4 = 0; k4 < 75; k4++)
    {
        if (k4 == 7 || k4 == 20 || k4 == 55 || k4 == 64 )
        {
            printf("%c",194);
        }
        else
        {
            printf("%c",196);
        }
    }
    printf("%c",191);
    printf("\n%c   ID\t",179);
    printf("%c  Cantidad  ",179);
    printf("%c\t\tProducto\t\t",179);
    printf("%c Precio ",179);
    printf("%c   Peso   %c",179,179);
    printf("\n%c",192);
    for(int k5 = 0; k5 < 75; k5++)
    {
        if (k5 == 7 || k5 == 20 || k5 == 55 || k5 == 64 )
        {
            printf("%c",193);
        }
        else
        {
            printf("%c",196);
        }
    }
    printf("%c",217);//-|
}
void file_imprime_cabecera_del_cuerpo(FILE*print) {
    fprintf(print,"\n");//barra de abajo
    fprintf(print,"%c",'+');//-|
    for(int k4 = 0; k4 < 75; k4++)
    {
        if (k4 == 7 || k4 == 20 || k4 == 55 || k4 == 64 )
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
    for(int k5 = 0; k5 < 75; k5++)
    {
        if (k5 == 7 || k5 == 20 || k5 == 55 || k5 == 64 )
        {
            fprintf(print,"%c",'+');
        }
        else
        {
            fprintf(print,"%c",'-');
        }
    }
    fprintf(print,"%c",'+');//-|
}
void file_imprime_productos(datos_cliente*data_clients,int noClnt,int facCntr,FILE*print){
    //=============================================================================================================
    //Imprime en consola
    //for(int z1 = 0; z1 < data_clients[noClnt].fact[facCntr].n_productos ; z1++)
    //{
    for (int z = 0; z < data_clients[noClnt].fact[facCntr].n_productos; z++) {

        fprintf(print,"\n %s", data_clients[noClnt].fact[facCntr].productos[z].Id_product);
        //--------------------Seccion auto linea--------------------
        for (int k = 0; k < (8 - strlen(data_clients[noClnt].fact[facCntr].productos[z].Id_product)); k++) {
            fprintf(print,"%c", ' ');
        }
        //-----------------------------------------------------------
        fprintf(print," %d", data_clients[noClnt].fact[facCntr].productos[z].cant);
        //--------------------Seccion auto linea--------------------
        for (int k = 0; k < (12 - sizeof(data_clients[noClnt].fact[facCntr].productos[z].cant)); k++) {
            fprintf(print,"%c", ' ');
        }
        //-----------------------------------------------------------
        fprintf(print,"   %s", data_clients[noClnt].fact[facCntr].productos[z].N_product);
        //--------------------Seccion auto linea--------------------
        for (int k = 0; k < (34 - strlen(data_clients[noClnt].fact[facCntr].productos[z].N_product)); k++) {
            fprintf(print,"%c", ' ');
        }
        //-----------------------------------------------------------
        fprintf(print,"%.2f", data_clients[noClnt].fact[facCntr].productos[z].price);
        //--------------------Seccion auto linea--------------------
        for (int k = 0; k < (8 - sizeof(data_clients[noClnt].fact[facCntr].productos[z].price)); k++) {
            fprintf(print,"%c", ' ');
        }
        //-----------------------------------------------------------
        fprintf(print,"  %.2f", data_clients[noClnt].fact[facCntr].productos[z].peso);
        fprintf(print,"\n");
    }
    //=============================================================================================================================
    //end of products
}
void imprime_productos(datos_cliente*data_clients,int noClnt,int facCntr){
    //=============================================================================================================
    //Imprime en consola
    //for(int z1 = 0; z1 < data_clients[noClnt].fact[facCntr].n_productos ; z1++)
    //{
    for (int z = 0; z < data_clients[noClnt].fact[facCntr].n_productos; z++) {

        printf("\n %s", data_clients[noClnt].fact[facCntr].productos[z].Id_product);
        //--------------------Seccion auto linea--------------------
        for (int k = 0; k < (8 - strlen(data_clients[noClnt].fact[facCntr].productos[z].Id_product)); k++) {
            printf("%c", ' ');
        }
        //-----------------------------------------------------------
        printf(" %d", data_clients[noClnt].fact[facCntr].productos[z].cant);
        //--------------------Seccion auto linea--------------------
        for (int k = 0; k < (12 - sizeof(data_clients[noClnt].fact[facCntr].productos[z].cant)); k++) {
            printf("%c", ' ');
        }
        //-----------------------------------------------------------
        printf("   %s", data_clients[noClnt].fact[facCntr].productos[z].N_product);
        //--------------------Seccion auto linea--------------------
        for (int k = 0; k < (34 - strlen(data_clients[noClnt].fact[facCntr].productos[z].N_product)); k++) {
            printf("%c", ' ');
        }
        //-----------------------------------------------------------
        printf("%.2f", data_clients[noClnt].fact[facCntr].productos[z].price);
        //--------------------Seccion auto linea--------------------
        for (int k = 0; k < (8 - sizeof(data_clients[noClnt].fact[facCntr].productos[z].price)); k++) {
            printf("%c", ' ');
        }
        //-----------------------------------------------------------
        printf("  %.2f", data_clients[noClnt].fact[facCntr].productos[z].peso);
        printf("\n");
    }
    //=============================================================================================================================
    //end of products
}
void file_imprime_fondo(FILE*print,datos_cliente*client,int noClnt,int facCntr){
    fprintf(print,"\n");
    for(int k = 0; k < 77; k++)
    {
        fprintf(print,"%c",'-');
    }
    fprintf(print,"\n Cantidad total: %d Unidades",client[noClnt].fact[facCntr].Total_fact_cant_);
    //--------------------Seccion auto linea--------------------
    for(int j11 = 0; j11 <(22 - 19 /*strlen(name)*/); j11++)
    {fprintf(print,"%c",' ');
    }
    //-----------------------------------------------------------
    fprintf(print,"\n Total Peso :%.2f KLG",client[noClnt].fact[facCntr].Total_fact_weigh_);
    fprintf(print,"\n Total RDS$:%.2f",client[noClnt].fact[facCntr].Total_product_price);
    fprintf(print,"\n\n Gracias por su preferencia, vuelva pronto!!!!");
}
void imprime_fondo(datos_cliente*client,int noClnt,int facCntr){
    printf("\n");
    for(int k = 0; k < 77; k++)
    {
        printf("%c",196);
    }
    printf("\n Cantidad total: %d Unidades",client[noClnt].fact[facCntr].Total_fact_cant_);
    //--------------------Seccion auto linea--------------------
    for(int j11 = 0; j11 <(22 - 19 /*strlen(name)*/); j11++)
    {printf("%c",' ');
    }
    //-----------------------------------------------------------
    printf("\n Total Peso :%.2f KLG",client[noClnt].fact[facCntr].Total_fact_weigh_);
    printf("\n Total RDS$:%.2f",client[noClnt].fact[facCntr].Total_product_price);
    printf("\n\n La factura fue generada correctamente!");
}
void imprime_salir2(){
    getch();
    printf("\n\nDesea volver al menu anterior?\n");
    printf("0 - no\n1 - si\n");
}
void imprime_salir()
{
    getch();
    printf("\n\nDesea salir del programa?\n");
    printf("0 - si\n1 - regresar al inicio\n");
}
void imprime_menu()
{
    system("color 8f");
    for (int n7 = 0; n7 < 25; n7++)
    {
        printf("%c",176);
    }
    printf("\tFacturadora 1.0.0\t");
    for (int k = 0; k < 25; k++)
    {
        printf("%c",176);
    }
    puts("\n\n");
    printf("\t%s\t\n\t%s\t\n\t%s\n\t%s\n\t%s\n","1 - Clientes y datos de envio","2 - Generar factura","3 - Ver facturas generadas","4 - Archivo de facturas","5 - Deudas de clientes");
    puts("\n\n\tIngrese el numero con la funcion deseada: ");
}
void seccion_productos_y_peso()
{
    system("cls");
    system("color f0");
    printf("----------Productos y peso-----------");
}
void seccion_Archivo_factura()
{
    system("cls");
    system("color f0");
    printf("\t\t\t\t Archivo de facturas \t\t\t\t\n\n");
}
void seccionDudasClientes()
{
    system("cls");
    system("color 0f");
    printf("\t\t\t\t\t\tDeudas de clientes\t\t\t\t\n\n");
}
void busquedaCliente(datos_cliente * data_clients ,int k) {
    for (int nomber = 0; nomber < k; ++nomber) {
        if (k == 0) {
            puts("No hay clientes para mostrar, intente agregando uno.\n");
        }
    }
}