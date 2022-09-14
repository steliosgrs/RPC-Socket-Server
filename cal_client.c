/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "cal.h"


void
cal_prog_1(char *host,int client)
{
	CLIENT *clnt;
	float  *result_1;
	X_vec  mangi_1_arg;
	int  *result_2;
	product  x_y_1_arg;
	mean_table  *result_3;
	mean  cal_mean_1_arg;
	product_table  *result_4;
	r_product  r_xy_1_arg;

#ifndef	DEBUG
	clnt = clnt_create (host, CAL_PROG, ADD_VERS, "udp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
	}
#endif	/* DEBUG */

    int choice =0;
    int n; // Length of vector
    int *X,*Y;
    float r;

    do {



        recv(client,&choice,sizeof(int),0);
        printf("Choice from client: %d \n", choice);

        if (choice ==1) {

            recv(client,&n,sizeof(int),0);
            mangi_1_arg.n=n;
            mangi_1_arg.X.X_len=n;
            mangi_1_arg.X.X_val=(int *)malloc(n*sizeof(int));


            X = (int *)malloc(n*sizeof(int));

            recv(client,X,n*sizeof(int),0);

            for (int i = 0; i < n; i++) {
                mangi_1_arg.X.X_val[i]=X[i];
            }

            result_1 = mangi_1(&mangi_1_arg,clnt);

        	if (result_1 == (float *) NULL) {
        		clnt_perror (clnt, "call failed");
        	}else{
                send(client, result_1, sizeof(float), 0);

            }

            free(X);
            free(mangi_1_arg.X.X_val);

        }else if(choice ==2){

            recv(client,&n,sizeof(int),0);
            x_y_1_arg.n=n;
            x_y_1_arg.X.X_len=n;
            x_y_1_arg.Y.Y_len=n;
            x_y_1_arg.X.X_val=(int *)malloc(n*sizeof(int));
            x_y_1_arg.Y.Y_val=(int *)malloc(n*sizeof(int));


            X = (int *)malloc(n*sizeof(int));
            recv(client,X,n*sizeof(int),0);

            Y = (int *)malloc(n*sizeof(int));
            recv(client,Y,n*sizeof(int),0);

            for (int i = 0; i < n; i++) {
                x_y_1_arg.X.X_val[i]=X[i];
            }

            for (int i = 0; i < n; i++) {
                x_y_1_arg.Y.Y_val[i]=Y[i];
            }

            result_2 = x_y_1(&x_y_1_arg, clnt);
        	if (result_2 == (int *) NULL) {
        		clnt_perror (clnt, "call failed");
        	}else{
                send(client, result_2, sizeof(int), 0);

            }
            free(X);
            free(Y);
            free(x_y_1_arg.X.X_val);
            free(x_y_1_arg.Y.Y_val);

        }else if(choice ==3){

            recv(client,&n,sizeof(int),0);
            cal_mean_1_arg.n=n;
            cal_mean_1_arg.X.X_len=n;
            cal_mean_1_arg.Y.Y_len=n;
            cal_mean_1_arg.X.X_val=(int *)malloc(n*sizeof(int));
            cal_mean_1_arg.Y.Y_val=(int *)malloc(n*sizeof(int));

            X = (int *)malloc(n*sizeof(int));
            recv(client,X,n*sizeof(int),0);

            Y = (int *)malloc(n*sizeof(int));
            recv(client,Y,n*sizeof(int),0);

            for (int i = 0; i < n; i++) {
                cal_mean_1_arg.X.X_val[i]=X[i];
            }

            for (int i = 0; i < n; i++) {
                cal_mean_1_arg.Y.Y_val[i]=Y[i];
            }


            result_3 = cal_mean_1(&cal_mean_1_arg, clnt);
        	if (result_3 == (mean_table *) NULL) {
        		clnt_perror (clnt, "call failed");
        	}else{
                send(client, result_3, sizeof(float), 0);
                send(client, result_3, sizeof(float), 0);

            }
            free(X);
            free(Y);
            free(cal_mean_1_arg.X.X_val);
            free(cal_mean_1_arg.Y.Y_val);

        }else if(choice ==4){

            recv(client,&n,sizeof(int),0);
            r_xy_1_arg.n=n;
            r_xy_1_arg.X.X_len=n;
            r_xy_1_arg.Y.Y_len=n;
            r_xy_1_arg.X.X_val=(int *)malloc(n*sizeof(int));
            r_xy_1_arg.Y.Y_val=(int *)malloc(n*sizeof(int));



            X = (int *)malloc(n*sizeof(int));
            recv(client,X,n*sizeof(int),0);

            Y = (int *)malloc(n*sizeof(int));
            recv(client,Y,n*sizeof(int),0);

            for (int i = 0; i < n; i++) {
                r_xy_1_arg.X.X_val[i]=X[i];
            }

            for (int i = 0; i < n; i++) {
                r_xy_1_arg.Y.Y_val[i]=Y[i];
            }


            recv(client,&r,sizeof(float),0);
            r_xy_1_arg.r=r;

            result_4 = r_xy_1(&r_xy_1_arg, clnt);
        	if (result_4 == (product_table *) NULL) {
        		clnt_perror (clnt, "call failed");
        	}else{

                send(client, result_4->rXY.rXY_val, n*sizeof(float), 0);


            }

            free(X);
            free(Y);
            free(r_xy_1_arg.X.X_val);
            free(r_xy_1_arg.Y.Y_val);
        }else{
            printf("Exit. \n" );
        }

    } while(choice < 5);



#ifndef	DEBUG
	clnt_destroy (clnt);
#endif	 /* DEBUG */
}


int
main (int argc, char *argv[])
{
	char *host;
    struct sockaddr_in server_address;
	struct sockaddr_in client_address;
    int portno;
    int in_soc;
    int acc_soc;
    int client_size;
	if (argc < 3) {
		printf ("usage: %s server_host portno\n", argv[0]);
		exit (1);
	}
	host = argv[1];




    in_soc = socket(AF_INET, SOCK_STREAM, 0);
    bzero((char *) &server_address, sizeof(server_address));
    portno = atoi(argv[2]);

	server_address.sin_family=AF_INET;
    server_address.sin_port=htons(portno);
    server_address.sin_addr.s_addr=INADDR_ANY;

    bind(in_soc, (struct sockaddr *) &server_address, sizeof(server_address));

    listen(in_soc,1);

    	while(1){
    		printf("Connection...\n");
    		client_size=sizeof(client_address);
    		acc_soc=accept(in_soc, (struct sockaddr *) &client_address, &client_size);

    		cal_prog_1(host,acc_soc);
    	}

exit (0);
}
