#include "proyectofinal.c"
#include <string.h>
#include "ProyectoFinal.h"

datos_cliente * dataClnt(){
    datos_cliente *datos_client;
    datos_client = (datos_cliente*)malloc(20* sizeof(datos_cliente));
    datos_client[1].name=(char*)malloc(3 * sizeof(char));
    datos_client[0].name=(char*)malloc(3 * sizeof(char));
    datos_client[0].name= "Gregory";
    datos_client[0].ID_client= malloc(10 * sizeof(char));
    datos_client[0].ID_client= "20180367" ;
    datos_client[0].address =malloc(10 * sizeof(char));
    datos_client[0].address = "Santiago,RD" ;
    datos_client[0].telephone =malloc(10 * sizeof(char));
    datos_client[0].telephone = "8092001962";
    datos_client[0].mail =malloc(10 * sizeof(char));
    datos_client[0].mail = "20100012@pucmm.edud.do";
    datos_client[0].factCntd =1;
    datos_client[0].fact =(facturas*)malloc(30* sizeof(facturas));
    datos_client[0].fact =(facturas*)malloc(30* sizeof(facturas));
    datos_client[0].fact[0].dia = 27;
    datos_client[0].fact[0].mes = 7;
    datos_client[0].fact[0].annio = 2019;
    datos_client[0].fact[0].ID = (char*)malloc(30* sizeof(char));
    datos_client[0].fact[0].ID ="F-001";
    datos_client[0].fact[1].ID ="F-010";
    datos_client[0].fact[0]. Total_product_price = 120.00;
    datos_client[0].fact[0]. Total_product_weigh = 1200.00;
    datos_client[0].fact[0]. Total_fact_cant_ = 12;
    datos_client[0].fact[0]. n_productos = 1;
    datos_client[0].fact[0].productos=(prod*)malloc(6* sizeof(prod));
    datos_client[0].fact[0].productos[0].Id_product = (char*)malloc(6* sizeof(char));
    datos_client[0].fact[0].productos[0].Id_product = "1212mng";
    datos_client[0].fact[0].productos[0].N_product = (char*)malloc(6* sizeof(char));
    datos_client[0].fact[0].productos[0].Id_product = "Mango_verde";
    datos_client[0].fact[0].Total_fact_weigh_ = 120.00;
    datos_client[0].fact[0].productos[0].cant = 10;


    datos_client[1].name= "Maria";
    datos_client[1].ID_client= malloc(10 * sizeof(char));
    datos_client[1].ID_client= "20122367" ;
    datos_client[1].address =malloc(10 * sizeof(char));
    datos_client[1].address = "Moca,RD" ;
    datos_client[1].telephone =malloc(10 * sizeof(char));
    datos_client[1].telephone = "809655555";
    datos_client[1].mail =malloc(10 * sizeof(char));
    datos_client[1].mail = "20122367@pucmm.edud.do";
    datos_client[1].factCntd =1;
    datos_client[1].fact =(facturas*)malloc(30* sizeof(facturas));
    datos_client[1].fact =(facturas*)malloc(30* sizeof(facturas));
    datos_client[1].fact[0].dia = 30;
    datos_client[1].fact[0].mes = 12;
    datos_client[1].fact[0].annio = 2012;
    datos_client[1].fact[0].ID = (char*)malloc(30* sizeof(char));
    datos_client[1].fact[0].ID = (char*)malloc(30* sizeof(char));
    datos_client[1].fact[0].ID ="F-011";
    datos_client[1].fact[0].ID ="F-022";
    datos_client[1].fact[2].ID ="F-030";
    datos_client[1].fact[0]. Total_product_price = 10.00;
    datos_client[1].fact[0]. Total_product_weigh = 120.00;
    datos_client[1].fact[0]. Total_fact_cant_ = 3;
    datos_client[1].fact[0]. n_productos = 1;
    datos_client[1].fact[0].productos=(prod*)malloc(6* sizeof(prod));
    datos_client[1].fact[0].productos[0].Id_product = (char*)malloc(6* sizeof(char));
    datos_client[1].fact[0].productos[0].Id_product = "12er";
    datos_client[1].fact[0].productos[0].N_product = (char*)malloc(6* sizeof(char));
    datos_client[1].fact[0].productos[0].Id_product = "Peras";
    datos_client[1].fact[0].Total_fact_weigh_ = 11.00;
    datos_client[1].fact[0].productos[0].cant = 3;
    return datos_client;
}

facturas*fact(){
    facturas *facturas1;
    facturas1 =(facturas*)malloc(10* sizeof(facturas));
    facturas1[0].ID = malloc(20 * sizeof(char));

}

//Prueba Busqueda de cliente
//Aqui prueba que existen los nombres Gregory, maria y PUCMM en la estructura;
//Chequea que el algoritmo de busqueda de facturas funcione correctamente;
MU_TEST(test_check_busqueda_no1) {
        mu_assert_int_eq(busqueda_nombre_cliente(dataClnt(),3,"Gregory"),0);
}
MU_TEST(test_check_busqueda_no2) {
    mu_assert_int_eq(busqueda_nombre_cliente(dataClnt(),0,"Maria"),0);
}
MU_TEST(test_check_busqueda_nombre3) {
    mu_assert_int_eq(busqueda_nombre_cliente(dataClnt(),0,"PUCMM"),0);
}
//Chequea que el algoritmo de busqueda de facturas funcione correctamente;
MU_TEST(test_check_busqueda_fact) {
    mu_assert_int_eq(busqueda_factura(dataClnt(),0,0,"F-001"),0);
}
MU_TEST(test_check_busqueda_fact2) {
    mu_assert_int_eq(busqueda_factura(dataClnt(),0,1,"F-010"),0);
}
MU_TEST(test_check_busqueda_fact3) {
    mu_assert_int_eq(busqueda_factura(dataClnt(),1,0,"F-011"),0);
}//comprueba que ninguna variable sea = NULL en la tabla de datos personales de la factura;
MU_TEST(test_check_busqueda_imprime1) {
    mu_assert_int_eq(imprime_titulo(dataClnt(),0,0),0);
}
MU_TEST(test_check_busqueda_imprime2) {
    mu_assert_int_eq(imprime_titulo(dataClnt(),1,0),0);
}
//comprueba que ninguna variable sea = NULL;
MU_TEST(test_check_totales1) {
    mu_assert_int_eq(totales(dataClnt(),1,0,2),0);
}
//comprueba que ningun valor sea cero;
MU_TEST(test_fondo1) {
    mu_assert_int_eq(imprime_fondo(dataClnt(),1,0),1);
}
MU_TEST(test_fondo2) {
    mu_assert_int_eq(imprime_fondo(dataClnt(),0,0),1);
}
MU_TEST_SUITE(test_suite) {
        MU_RUN_TEST(test_check_busqueda_no1);
        MU_RUN_TEST(test_check_busqueda_no2);
        MU_RUN_TEST(test_check_busqueda_nombre3);
        MU_RUN_TEST(test_check_busqueda_fact);
        MU_RUN_TEST(test_check_busqueda_fact2);
        MU_RUN_TEST(test_check_busqueda_fact3);
        MU_RUN_TEST(test_check_busqueda_imprime1);
        MU_RUN_TEST(test_check_busqueda_imprime2);
        MU_RUN_TEST(test_fondo1);
        MU_RUN_TEST(test_check_totales1);
        MU_RUN_TEST(test_fondo2);


}

int main()
{
    MU_RUN_SUITE(test_suite);
    MU_REPORT();
    return 0;
}

