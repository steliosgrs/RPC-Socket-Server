#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>

void error(char *msg) {
    perror(msg);
    exit(0);
}

int choice=0;
int i;
int elem;
int n;              // Length of vector
int *X,*Y;          // Vectors
float magni;        //1 Magnitude
int product;        //2 Inner product
float meanxy[2];    //3 Mean of X and Y
float *product_r;   //4 Product of r*(X+Y)
float r;

float  result_1;
int  result_2;
float  result_3[2];
float  *result_4;


int main(int argc, char const *argv[]) {

    int sockfd, portno;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[100];

    if (argc < 3) {
       fprintf(stderr,"usage %s hostname port\n", argv[0]);
       exit(0);
    }

    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0)
        error("ERROR opening socket");

    server = gethostbyname(argv[1]);

    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr,
         (char *)&serv_addr.sin_addr.s_addr,
         server->h_length);
    serv_addr.sin_port = htons(portno);


    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
        error("ERROR connecting");

    printf("Connected.\n");

    do {

        printf("Press 1 - Calculate the metric of vector X.\n" );
        printf("Press 2 - Calculate the product of X,Y vectors\n" );
        printf("Press 3 - Calculate the mean of vector X,Y.\n" );
        printf("Press 4 - Calculate the product r*(X+Y).\n" );
        printf("Press 5 - EXIT \n" );

        scanf("%d",&choice);
        send(sockfd,&choice,sizeof(int),0);

        if (choice ==1) {
            printf("Give the length of vector X:\n ");
            scanf("%d",&n );
            send(sockfd, &n, sizeof(int), 0);
            // mangi_1_arg.n=n;
            // mangi_1_arg.X.X_len=n;
            // mangi_1_arg.X.X_val=(int *)malloc(n*sizeof(int));
            X = (int *)malloc(n*sizeof(int));
            printf("\nGive the values of vector X:\n ");
            for (int i = 0; i < n; i++) {
                printf("X[%d]= ", i);
                scanf("%d", &X[i]);
            }
            send(sockfd, X, n*sizeof(int), 0);
            // result_1 = mangi_1(&mangi_1_arg,clnt);

            recv(sockfd,&result_1,sizeof(float),0);

            printf("The magnitude of X is: %f\n", result_1);

            free(X);

        }else if(choice ==2){
            printf("Give the length of vector X: ");
            scanf("%d",&n );
            send(sockfd, &n, sizeof(int), 0);
            // x_y_1_arg.n=n;
            // x_y_1_arg.X.X_len=n;
            // x_y_1_arg.Y.Y_len=n;
            // x_y_1_arg.X.X_val=(int *)malloc(n*sizeof(int));
            // x_y_1_arg.Y.Y_val=(int *)malloc(n*sizeof(int));
            X = (int *)malloc(n*sizeof(int));
            printf("\nGive the values of vector X:\n ");
            for (int i = 0; i < n; i++) {
                printf("X[%d]= ", i);
                scanf("%d", &X[i]);
            }

            send(sockfd, X, sizeof(int), 0);

            Y = (int *)malloc(n*sizeof(int));
            printf("\nGive the values of vector Y:\n ");
            for (int i = 0; i < n; i++) {
                printf("Y[%d]= ", i);
                scanf("%d", &Y[i]);
            }

            send(sockfd, Y, sizeof(int), 0);

            // result_2 = x_y_1(&x_y_1_arg, clnt);
            recv(sockfd,&result_2,sizeof(int),0);

            printf("The inner product of X and Y is: %d\n",  result_2);

            free(X);
            free(Y);

        }else if(choice ==3){
            printf("Give the length of vector X: ");
            scanf("%d",&n );
            send(sockfd, &n, sizeof(int), 0);
            // cal_mean_1_arg.n=n;
            // cal_mean_1_arg.X.X_len=n;
            // cal_mean_1_arg.Y.Y_len=n;
            // cal_mean_1_arg.X.X_val=(int *)malloc(n*sizeof(int));
            // cal_mean_1_arg.Y.Y_val=(int *)malloc(n*sizeof(int));
            X = (int *)malloc(n*sizeof(int));
            printf("\nGive the values of vector X:\n ");
            for (int i = 0; i < n; i++) {
                printf("X[%d]= ", i);
                scanf("%d", &X[i]);
            }
            send(sockfd, X, n*sizeof(int), 0);

            Y = (int *)malloc(n*sizeof(int));
            printf("\nGive the values of vector Y:\n ");
            for (int i = 0; i < n; i++) {
                printf("Y[%d]= ", i);
                scanf("%d", &Y[i]);
            }
            send(sockfd, Y, n*sizeof(int), 0);


            // result_3 = cal_mean_1(&cal_mean_1_arg, clnt);

            recv(sockfd,&result_3[0],sizeof(float),0);
            recv(sockfd,&result_3[1],sizeof(float),0);

            printf("The mean of X is: %f\n",  result_3[0]);
            printf("The mean of Y is: %f\n",  result_3[1]);

            free(X);
            free(Y);

        }else if(choice ==4){
            printf("Give the length of vector X:\n ");
            scanf("%d",&n );
            send(sockfd, &n, sizeof(int), 0);

            // r_xy_1_arg.n=n;
            // r_xy_1_arg.X.X_len=n;
            // r_xy_1_arg.Y.Y_len=n;
            // r_xy_1_arg.X.X_val=(int *)malloc(n*sizeof(int));
            // r_xy_1_arg.Y.Y_val=(int *)malloc(n*sizeof(int));
            X = (int *)malloc(n*sizeof(int));
            printf("\nGive the values of vector X:\n ");
            for (int i = 0; i < n; i++) {
                printf("X[%d]= ", i);
                scanf("%d", &X[i]);
            }
            send(sockfd, X, n*sizeof(int), 0);
            Y = (int *)malloc(n*sizeof(int));
            printf("\nGive the values of vector Y:\n ");
            for (int i = 0; i < n; i++) {
                printf("Y[%d]= ", i);
                scanf("%d", &Y[i]);
            }
            send(sockfd, Y, n*sizeof(int), 0);

            printf("\nGive the number r: ");
            scanf("%f",&r );
            send(sockfd, &r, sizeof(float), 0);
            // r_xy_1_arg.r=r;

            // result_4 = r_xy_1(&r_xy_1_arg, clnt);
            recv(sockfd,&result_4,n*sizeof(float),0);
            result_4 = (float *)malloc(n*sizeof(float));

            for (int i = 0; i < n; i++) {
                printf("The product of r*(X+Y): %f\n",  result_4[i]);
            }

            free(X);
            free(Y);

        }else{
            printf("Exit. \n" );
        }

    } while(choice < 5);



    return 0;
}
