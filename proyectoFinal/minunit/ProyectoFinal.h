#ifndef proyectoFinal_h
int busqueda_nombre_cliente(datos_cliente *clientee, int n,char*nom);
int busqueda_factura(datos_cliente *clientee,int cln, int n,char*nom);
int totales(datos_cliente*client,int noClnt,int facCntr,int j);
int imprime_titulo(datos_cliente * data_cl ,int noClnt, int fac);
int imprime_productos(datos_cliente*data_clients,int noClnt,int facCntr);
#endif // proyectoFinal_h