#include<stdio.h>
#include<string.h>
#include <stdlib.h>
typedef struct don_hang{
    char maso[20];
    char ten[30];
    float gia;
    int soluong;
}don_hang;
int main(int argc, char* argv[]){
    FILE *f=fopen(argv[1],"r+w");
    int n;
    fscanf(f,"%d",&n);
    don_hang sp[1000];
    char buff[30];
    for(int i=0;i<n;i++)
        {
            fscanf(f, "%s",buff);
            strcpy(sp[i].maso, buff);
            fscanf(f,"%s",buff);
            strcpy(sp[i].ten, buff);
            fscanf(f,"%f",&sp[i].gia);
            fscanf(f,"%d",&sp[i].soluong);
        }
        printf("Menu\n");
        printf("1. Xem thong tin mat hang\n");
        printf("2. Tao don hang\n");
        printf("3. Thoat\n");
        int choice; 
        char id[20];
        scanf("%d",&choice);
    while(choice!=3)
        {
            if(choice==1){
                printf("Nhap ma so mat hang:");
                scanf(" %[^\n]%*c",id);
                int kq=0;
               for(int i=0;i<n;i++)
               {
                   if(strcmp(sp[i].maso,id)==0)
                     {
                         printf("Ten mat hang: %s\n",sp[i].ten);
                         printf("Gia: %f\n",sp[i].gia);
                         printf("So luong: %d\n",sp[i].soluong);
                         kq=1;
                     }
               }
               if(kq==0) printf("Khong co mat hang co ma so %s ! \n",id);
            }
            if(choice==2){
                printf("Nhap ma so mat hang:");
                scanf(" %[^\n]%*c",id);
                int count=0 ,bill[1000],sl[1000]={0},sl1;
               while(strcmp(id,"STOP")!=0)
        {
                 int kq=0;
               for(int i=0;i<n;i++)
               {
                   if(strcmp(sp[i].maso,id)==0)
                     {
                         printf("Ten mat hang: %s\n",sp[i].ten);
                         printf("Gia: %f\n",sp[i].gia);
                         printf("So luong: %d\n",sp[i].soluong);
                         bill[count]=i; 
                         printf("Nhap so luong muon mua: ");
                         scanf("%d",&sl1);
                  
                             while(sl1>sp[i].soluong)
                               {
                                   printf("Trong kho chi con %d san pham. Vui long nhap lai so luong:",sp[i].soluong);
                                   scanf("%d",&sl1);
                               }
                         count++;
                         kq=1;
                     }
               }
               if(kq==0) printf("Khong co mat hang co ma so nay! \n");
               printf("Nhap ma so mat hang:");
                scanf(" %[^\n]%*c",id);
        }
        printf("\n_________________________________________\n");
        float sum=0;
        for(int i=0;i<count;i++)
           {
               printf("%d %-20s %-20f %-5d %-30f\n",i+1,sp[bill[i]].ten,sp[bill[i]].gia,sl[i], sl[i]*sp[bill[i]].gia);
               sum+=sl[i]*sp[bill[i]].gia;
           }
           printf("_________________________________________\n");
           printf("Tong tien: %f\n",sum);
            }
            choice=3;
        }
    return 0;
}