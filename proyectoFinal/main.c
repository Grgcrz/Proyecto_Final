#include "header.h"

int end,i,ene,n,x,k=0,m,f,no_clientes = 0,noClnt,y,o3;
float deuda = 0.0;
int n2 = 0;
int main() {
    char *address = malloc(50 * sizeof(char *));
    char *direcc = malloc(50 * sizeof(char *));
    datos_cliente *data_clients = (datos_cliente *) malloc(100 * sizeof(data_clients));
    data_clients[noClnt].fact = (facturas *) calloc(10, sizeof(facturas));
    facturas *facturaN = (facturas *) malloc(10 * sizeof(facturas *));
    prod *products = (prod *) malloc(10 * sizeof(prod *));
    do {
        int selec;
        int facCntr = 0;
        imprime_menu();
        scanf("%d", &selec);
        switch (selec) {

            //-------------------------------------------------case 1-----------------------------------------
            case 1:
                do {
                    system("cls");
                    system("color 0f");
                    printf("\t\t\t\t Clientes y direccion\t\t\t\t");
                    puts("\n1. Ingresar clientes y datos:\n2. Ver clientes y datos\n0. Salir. ");
                    scanf("%d", &n);
                    //----------------------------------------------------------------------------------------------------------
                    switch (n) {

                        case 1:
                            if (data_clients == NULL || data_clients[k].name == NULL ||
                                data_clients[k].ID_client == NULL) {
                                realloc(data_clients, sizeof(data_clients) * 20);
                                realloc(data_clients[k].name, sizeof(char) * 20);
                                realloc(data_clients[k].ID_client, 10 * sizeof(char));
                                realloc(data_clients[k].telephone, 10 * sizeof(char));
                                realloc(data_clients[k].mail, 10 * sizeof(char));
                                realloc(data_clients[k].address, 10 * sizeof(char));
                            }
                            data_clients[k].name = (char *) malloc(100 * sizeof(char));
                            data_clients[k].ID_client = (char *) malloc(100 * sizeof(char));
                            data_clients[k].telephone = (char *) malloc(100 * sizeof(char));
                            data_clients[k].mail = (char *) malloc(100 * sizeof(char));
                            data_clients[k].address = (char *) malloc(100 * sizeof(char));
                            leer_clientes(data_clients, k);

                            //printf("\n \t \tdata_clients[%d].fact[%d]",noClnt,facCntr);
                            k++;
                            no_clientes = k;
                            imprime_salir2();
                            scanf("%d", &x);
                            break;
                        case 2:
                            system("cls");
                            puts("Clientes y datos: \n");
                            if (no_clientes == 0) {
                                puts("No hay clientes para mostrar, intente agregando uno.\n");
                            } else {
                                for (int nomber = 0; nomber < k; ++nomber) {
                                    printf("Cliente: %d ----------- %s\n", nomber, data_clients[nomber].name);
                                }
                                f = busqueda_nombre_cliente(data_clients, k);
                                system("cls");
                                printf("||||| Datos encontrados de %s:\nID: %s\nNombre: %s\nDireccion: %s\nTelefono: %s\nCorreo electronico: %s\n",
                                       data_clients[f].name, data_clients[f].ID_client,
                                       data_clients[f].name, data_clients[f].address,
                                       data_clients[f].telephone,
                                       data_clients[f].mail);
                            }
                            break;
                        case 0 :
                            break;
                    }
                    imprime_salir();
                    scanf("%d", &x);
                } while (x != 0);

                imprime_salir();
                scanf("%d", &end);
                system("cls");
                break;
                //--------------------------------------------------------------------case 2 ---------------------------------------------------------
            case 2:
                seccion_productos_y_peso();
                system("cls");
                puts("Clientes guardados:\n\n");
                if (k == 0) {
                    puts("No hay clientes para mostrar, intente agregando uno.\n");
                } else {
                    fflush(stdin);
                    for (int nomber = 0; nomber < k; nomber++) {
                        printf("Cliente: %d ----------- %s\n", nomber, data_clients[nomber].name);
                    }
                    if(data_clients[noClnt+1].fact == NULL ){
                        data_clients[noClnt+1].fact = (facturas *) calloc(10, sizeof(facturas));
                    }
                    noClnt = busqueda_nombre_cliente(data_clients, k);
                    facCntr = data_clients[noClnt].factCntd;
                    data_clients[noClnt].fact[facCntr].ID = (char *) malloc(10 * sizeof(char));
                    data_clients[noClnt].fact[facCntr].productos = (prod *) malloc(100 * sizeof(prod));

                        //realloc(data_clients[noClnt].fact[facCntr].ID, sizeof(data_clients[noClnt].fact[facCntr].ID)*3);
                        puts("\nInserte el numero de factura:");
                        scanf("%s", data_clients[noClnt].fact[facCntr].ID);
                        puts("Ingrese cantidad de productos a agregar");
                        scanf("%d", &data_clients[noClnt].fact[facCntr].n_productos);
                        puts("\nInsertar fecha: formato DD/MM/AAAA\n");
                        puts("Ingrese dia\n");
                        scanf("%d", &data_clients[noClnt].fact[facCntr].dia);
                        puts("Ingrese mes: \n");
                        scanf("%d", &data_clients[noClnt].fact[facCntr].mes);
                        printf("Ingrese a%co: \n", 164);
                        scanf("%d", &data_clients[noClnt].fact[facCntr].annio);
                        fflush(stdin);
                        printf("Listo!!!");
                    //}
                    for (int j = 0; j < data_clients[noClnt].fact[facCntr].n_productos; j++) {
                        data_clients[noClnt].fact[facCntr].productos[j].Id_product = (char *) malloc(
                                data_clients[noClnt].fact[facCntr].n_productos * sizeof(char));
                        data_clients[noClnt].fact[facCntr].productos[j].N_product = (char *) malloc(
                                data_clients[noClnt].fact[facCntr].n_productos * sizeof(char));
                        leer_produtos(data_clients, noClnt, facCntr, j);
                    }
                    printf("Listo!!!");
                    system("cls");
                    fflush(stdin);
                    imprime_titulo(data_clients, noClnt, facCntr);
                    imprime_cabecera_del_cuerpo();
                    imprime_productos(data_clients, noClnt, facCntr);
                    totales(data_clients, noClnt, facCntr, data_clients[noClnt].fact[facCntr].n_productos);
                    imprime_fondo(data_clients, noClnt, facCntr);
                    data_clients[noClnt].deuda += data_clients[noClnt].fact[facCntr].Total_fact_price_;
                    address = "C:\\Users\\grego\\Desktop\\Facturas_generadas\\factura.txt";
                    FILE *print;
                    print = fopen(address, "w");
                    if ((print = fopen(address, "w")) != NULL) {
                        file_imprime_titulo(print, data_clients, noClnt, facCntr);
                        file_imprime_cabecera_del_cuerpo(print);
                        for (int xr = 0; xr < data_clients[noClnt].fact[facCntr].n_productos; xr++) {
                            file_imprime_productos(data_clients, noClnt, facCntr, print);
                        }
                        file_imprime_fondo(print, data_clients, noClnt, facCntr);
                        puts("La factura se genero correctamente!!!");
                    } else {
                        puts("ERROR: no se pudo generar la factura imprimible");
                    }
                    fclose(print);
                }
                m++;
                if(m>0){
                    data_clients[noClnt].factCntd++;
                }
                imprime_salir();
                scanf("%d", &end);
                system("cls");
                break;
            case 3:
                fflush(stdin);
                system("cls");
                printf("Clientes disponibles para generar factura: \n");
                if (k == 0) {
                    puts("No hay clientes para mostrar, intente agregando uno.\n");
                } else {
                    for (int nomber = 0; nomber < k; nomber++) {
                        printf("Cliente: %d ----------- %s\n", nomber, data_clients[nomber].name);
                    }
                    noClnt = busqueda_nombre_cliente(data_clients, k);
                    if (data_clients[noClnt].factCntd == 0) {
                        puts("No hay facturas para mostrar, intente agregando uno.\n");
                    } else {
                        for (int no = 0; no < data_clients[noClnt].factCntd; no++) {
                            printf("factura %d ----------- ID: %s\n", no,
                                   data_clients[noClnt].fact[no].ID);
                        }
                        int factEnc = busqueda_factura(data_clients, noClnt);
                        fflush(stdin);
                        system("cls");
                        imprime_titulo(data_clients, noClnt, factEnc);
                        imprime_cabecera_del_cuerpo();
                        imprime_productos(data_clients, noClnt, factEnc);
                        totales(data_clients, noClnt, facCntr, data_clients[noClnt].fact[factEnc].n_productos);
                        imprime_fondo(data_clients, noClnt, factEnc);
                        getchar();
                    }
                    imprime_salir();
                    scanf("%d", &end);
                    system("cls");
                    break;
                    //aqui termina seccion 3;
                    case 4:
                        system("cls");
                    printf("Clientes disponibles para generar factura: \n");
                    if (k == 0) {
                        puts("No hay clientes para mostrar, intente agregando uno.\n");
                    } else {
                        for (int nomber = 0; nomber < k; nomber++) {
                            printf("Cliente: %d ----------- %s\n", nomber, data_clients[nomber].name);
                        }
                        noClnt = busqueda_nombre_cliente(data_clients, k);
                            seccion_Archivo_factura();
                            puts("\n");
                            puts(" Fecha\t       IDfactura                     cliente");
                            for (int v = 0; v < data_clients[noClnt].factCntd; v++) {
                                if (facCntr < data_clients[noClnt].factCntd) {
                                    printf(" %d/%d/%d          %s     ----------------   %s\n\n",
                                           data_clients[noClnt].fact[v].dia,
                                           data_clients[noClnt].fact[v].mes, data_clients[noClnt].fact[v].annio,
                                           data_clients[noClnt].fact[v].ID, data_clients[noClnt].name);
                                } else {
                                    puts("Ocurrio un error");
                                }
                            }
                        }
                    }
                getchar();
                imprime_salir();
                scanf("%d", &end);
                system("cls");
                break;
            case 5:
                seccionDudasClientes();
                printf("Clientes disponibles : \n");
                if (k == 0) {
                    puts("No hay clientes para mostrar, intente agregando uno.\n");
                } else {
                    for (int nomber = 0; nomber < k; nomber++) {
                        printf("Cliente: %d ----------- %s\n", nomber, data_clients[nomber].name);
                    }
                    noClnt = busqueda_nombre_cliente(data_clients, k);
                    for (int v = 0; v < data_clients[noClnt].factCntd; v++) {
                        data_clients[noClnt].deuda += data_clients[noClnt].fact[v].Total_product_price;
                        }
                        printf("La deuda de %s es de RD$: %.2f", data_clients[noClnt].name,data_clients[noClnt].deuda);}
                getchar();
                imprime_salir();
                scanf("%d", &end);
                system("cls");
                break;

        }
    } while (end != 0);
    return 0;
}


