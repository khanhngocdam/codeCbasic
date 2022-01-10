#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include<time.h>


typedef struct mat_hang{
    char maso[20];
    float gia;
}mat_hang;
#define to_string(x) (((mat_hang*)x)->maso)
int compare_s(const void *a, const void *b){ // so sánh string

    return strcmp(to_string(a), to_string(b));
}
typedef struct don_hang{
    char masodon[20];
    int sl;
     long double total;
}don_hang;
#define to_double(x) (((don_hang*)x)->total)
int cmp_o(const void* a, const void* b){
    return to_double(a)-to_double(b);
}
/*int cmp_o(const void* a, const void* b) {
        don_hang*oa=(don_hang*)a;
        don_hang*ob=(don_hang*)b;
    return oa->total - ob->total;
}*/


 int binsearch(int l, int r, mat_hang *sp, char* buff) {
  if (l >= r) {
    return 0;
  }
  int i = (l + r) / 2;
  if (strcmp(sp[i].maso,buff)>0) {
    return binsearch(l,i,sp,buff);
  } else if (strcmp(sp[i].maso,buff)<0) {
    return binsearch(i + 1, r, sp, buff);
  }
  return i;
}
int main(int argc, char* argv[]){
    clock_t start = clock();
    FILE *f1=fopen(argv[1],"r");
    FILE *f2=fopen(argv[2],"r");
    int n1,n2;
    fscanf(f1,"%d",&n1);
    mat_hang *sp=calloc(n1,sizeof(struct mat_hang));
        for(int i=0;i<n1;i++){
            fscanf(f1,"%s",sp[i].maso);
            fscanf(f1,"%f",&sp[i].gia);
        }
       qsort(sp,n1,sizeof( struct mat_hang),compare_s);

    fscanf(f2,"%d",&n2);
    don_hang*don=calloc(n2,sizeof(struct don_hang));
        char buff[20]; int sl_hang;
        for(int i=0;i<n2;i++){
            don[i].total=0;
            fscanf(f2,"%s",don[i].masodon);
            fscanf(f2,"%d",&don[i].sl);
                for(int j=0;j<don[i].sl;j++){
                    fscanf(f2,"%s",buff);
                    fscanf(f2,"%d",&sl_hang);
                    don[i].total+=sp[binsearch(0,n1,sp,buff)].gia*sl_hang;
                }
        }
       qsort(don,n2,sizeof(struct don_hang),cmp_o);
       
        for(int i=n2-1;i>=n2-3;i--)
        {
            printf("%s %Lf\n",don[i].masodon,don[i].total);
        }
    fclose(f1);
    fclose(f2);
    clock_t end = clock();
    double time_process = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Thoi gian xu li: %lf\n",time_process);
    free(sp); free(don); 
    return 0;
}

//Câu lệnh biên dịch: gcc -o prog baitap1.c 
// ./prog products.txt orders.txt