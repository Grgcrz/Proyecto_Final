//
// Created by grego on 31/7/2019.
//
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "miunit.h"
//Esta seccion es para probar el codigo, luego de hecho el codigo final, se debe borrar.
//struct datos_cliente *data_client;
//malloc(10* size_of(data_client)
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
        "santiago","limites","Autopista Duarte,km 7,Santiago de los Caballeros,Rep.Dom","809-824-0210","123456","23-12-18","231218A"};

int totales(datos_cliente*client,int noClnt,int facCntr,int j){
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
    if(client[noClnt].fact[facCntr].Total_fact_cant_>0&&
       client[noClnt].fact[facCntr].Total_fact_weigh_>0&&
       client[noClnt].fact[facCntr].Total_product_price > 0){
        return 1;
    }else{
        return 0;
    }//Lo correcto es que devuelva 1;
}
int busqueda_nombre_cliente(datos_cliente *clientee, int n, char*nom)
{
    int i;
    for(i = 0; i < n ;i++)
    {
        if(stricmp(clientee[i].name,nom)== 0){
            return i;
        }
    else{
        return -1;
    }
}}
int busqueda_factura(datos_cliente *clientee,int cln, int n, char*nom1)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(stricmp(clientee[cln].fact[n].ID,nom1)==0){
            return i;}
        else{
            return -1;
        }
    }
}
int imprime_titulo(datos_cliente * data_cl ,int noClnt, int fac)
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

    printf("%c\n Cliente: %s",191,data_cl[noClnt].name);
    //--------------------Seccion auto linea--------------------
    for(int j2 = 0; j2 <(22 - strlen(data_cl[noClnt].name)); j2++)
    {printf("%c",' ');
    }

    //-----------------------------------------------------------
    printf("No.Factura:%s",data_cl[noClnt].fact[fac].ID);
    printf("  Fecha:%d\\%d\\%d",data_cl[noClnt].fact[fac].dia,data_cl[noClnt].fact[fac].mes,data_cl[noClnt].fact[fac].annio);
    //--------------------Seccion auto linea (ESPECIAL)--------------------
    //----------------------------------------------------------------------
    for(int j3 = 0; j3 <(12 + strlen(data_cl[noClnt].name)+strlen(data_cl[noClnt].fact[fac].ID)); j3++)
    {printf("%c",' ');
    }
    //-----------------------------------------------------------
    //-----------------------------------------------------------

    printf("\n%cDirecci%cn:%s",179,162,data_cl[noClnt].address);
    //--------------------Seccion auto linea--------------------
    for(int l = 0; l <(65 - strlen(data_cl[noClnt].address)); l++)
    {printf("%c",' ');
    }
    //-----------------------------------------------------------
    printf("%c",179);
    printf("\n Tel:%s\tEmail:%s\tID/RNC:%s",data_cl[noClnt].telephone,data_cl[noClnt].mail,data_cl[noClnt].ID_client);
    //--------------------Seccion auto linea--------------------
    for(int m = 0; m <(75 - strlen(data_cl[noClnt].telephone)+strlen(data_cl[noClnt].mail)+strlen(data_cl[noClnt].ID_client)); m++)
    {printf("%c",' ');
    }
    //-----------------------------------------------------------
    printf("\n%c",192);
    for(int k6 = 0; k6 < 75; k6++)
    {
        printf("%c",196);
    }
    printf("%c",217);
    printf("\n");

    if(data_cl[noClnt].telephone == NULL ||data_cl[noClnt].name==NULL||data_cl[noClnt].ID_client==NULL||data_cl[noClnt].address==NULL){
        return -1;
    }else{
        return 0;
    }

}
int imprime_fondo(datos_cliente*client,int noClnt,int facCntr){
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
    if(client[noClnt].fact[facCntr].Total_fact_weigh_==0||client[noClnt].fact[facCntr].Total_product_price==0){
        return 0;
    }else{
        return 1;
    }
    //Lo correcto es que devuelva 1;
}


