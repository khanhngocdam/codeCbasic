#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include "ext/io.h"
char keyword[20]; // tu khoa nhap de loc//
    int year_cmp=0;// nam sang tac nguoi dung nhap de loc//
    int* idx;
typedef struct data_song{   //Khai bao cau truc thong tin bai hat//
char *name;
char *singer;
char *musician;
int year;
}*data_song_t;
//Khai bao node luu tru thong tin bai hat//
typedef struct node_song{
    data_song_t data;
      struct node_song* next;    
}*node_song_t;
//Khai bao cau truc list song//
typedef struct sll_listsong{
  node_song_t front;
  node_song_t back;
} *sll_listsong_t;
//ham tao list song//
sll_listsong_t Creat_listsong(){
  sll_listsong_t list=malloc(sizeof(struct sll_listsong));
  list->front=NULL;
  list->back=NULL;
  return list;
}
//Ham tao node //
node_song_t Creat_node_song(data_song_t info){
    node_song_t q =  malloc(sizeof(struct node_song));
    data_song_t tmp=malloc(sizeof(struct data_song));
    tmp->name=strdup(info->name);
    tmp->singer=strdup(info->singer);
    tmp->musician=strdup(info->musician);
    tmp->year=info->year;
    q->data =tmp;
    q->next = NULL;
    return q;
}
// them node//
void insertLastlist(sll_listsong_t list, data_song_t info){
node_song_t q =Creat_node_song(info);
if(list->front==NULL) 
 {
   list->front=list->back=q;
 }
 else{
   list->back->next=q;
   list->back=q;
 }
}
// in ra list//
void printfList(sll_listsong_t list){
    int i=1;
    if(list==NULL) printf("Danh sach rong!!\n");
    else{
node_song_t p = list->front;
 printf("   %-25s | %-15s | %-15s | %s   \n","Ten bai hat","Ten ca si","Ten nhac si","Nam sang tac");
 printf("_______________________________________________________________________________\n");
while(p != NULL)
{
printf("%d. %-25s | %-15s | %-15s | %d   \n",i,p->data->name, p->data->singer,p->data->musician,p->data->year);
p = p->next;
i++;
}
    }
}
//xoa noi dung trong file//
void clearFileContent(const char *filePath) {
    FILE *f = fopen(filePath, "w");
    if (f == NULL) {
        printf("Khong the mo file %s de xoa\n", filePath);
        return;
    }
    fclose(f);
}
//ham xoa 1 node khoi list//
int deletesong(sll_listsong_t list, node_song_t p){
  int i; node_song_t cur = list->front;

  if(list==NULL||p==NULL) return 0;
  else{
     if(list->front==p&&list->back==p) {
        list->front=list->back=NULL;
     }
      else if(p==list->back){
            while(cur->next!=list->back)
            {
              cur=cur->next;
            }
            cur->next=NULL;
            list->back=cur;
      }
      else if(list->front==p) 
         {
           list->front = p->next; 
         }
      else{
    node_song_t cur = list->front;
    while(cur->next!=p)
    {
      cur=cur->next;
    }
    cur->next = p->next;
      }
  }    
      free(p->data->musician);
      free(p->data->name);
      free(p->data->singer);
      free(p->data);
       free(p);
}
// ham loc danh sach theo ten//
int filtername(sll_listsong_t list, char* word){
  int i=0,count=0;
   idx=calloc(1000,sizeof(int*));
   for(node_song_t cur=list->front;cur!=NULL;cur=cur->next)
   {
     count++;
     if(strstr(cur->data->name,word)!=NULL) 
     {
       printf("%d. %-25s | %-10s | %-10s | %d   \n",i+1,cur->data->name, cur->data->singer,cur->data->musician,cur->data->year);
       idx[i]=count; i++;
     }
   }
   if(i==0) return 0;
   return i;
}
// ham loc danh sach theo ca si//
int filtersinger(sll_listsong_t list, char* word){
  int i=0,count=0;
  idx=calloc(1000,sizeof(int*)); 
   for(node_song_t cur=list->front;cur!=NULL;cur=cur->next)
   {
     count++;
     if(strstr(cur->data->singer,word)!=NULL) 
     {
       printf("%d. %-25s | %-10s | %-10s | %d   \n",i+1,cur->data->name, cur->data->singer,cur->data->musician,cur->data->year);
       idx[i]=count; i++;
     }
   }
   if(i==0) return 0;
   return i;
}
// ham loc theo ten nhac si//
int filtermusician(sll_listsong_t list, char* word){
  int i=0,count=0; idx=calloc(1000,sizeof(int*)); 
   for(node_song_t cur=list->front;cur!=NULL;cur=cur->next)
   {
     count++;
     if(strstr(cur->data->musician,word)!=NULL) 
     {
       printf("%d. %-25s | %-10s | %-10s | %d   \n",i+1,cur->data->name, cur->data->singer,cur->data->musician,cur->data->year);
       idx[i]=count; 
       i++;      
     }
   }
  if(i==0)  return 0;
   return i;
}
//ham loc theo nam sang tac//
int filteryear(sll_listsong_t list, int year_cmp){
  int i=0,count=0; idx=calloc(1000,sizeof(int*));
   for(node_song_t cur=list->front;cur!=NULL;cur=cur->next)
   {
     count++;
     if(cur->data->year>=year_cmp) 
     {
       printf("%d. %-25s | %-10s | %-10s | %d   \n",i+1,cur->data->name, cur->data->singer,cur->data->musician,cur->data->year);
       idx[i]=count; i++;       
     }
   }
   if(i==0) return 0;
   return i;
}
//Ham hoan doi vi tri 2 node//
void swap_info_song(node_song_t p1,node_song_t p2){
  if(p1==NULL||p2==NULL) printf("Loi hoan doi\n");
else{
   data_song_t tmp=malloc(sizeof(struct data_song));
  tmp=p1->data;
  p1->data=p2->data;
  p2->data=tmp;

}
 }

//ham choice=2//
int choice2(sll_listsong_t list){
    printf("1. Loc theo ten bai hat\n");
        printf("2. Loc theo ten ca sy\n");
        printf("3. Loc theo ten nhac sy\n");
        printf("4. Loc theo nam sang tac\n");
        int filter_choice,result=0;
        scanf("%d",&filter_choice);
        while (filter_choice<1||filter_choice>4)
        {
          printf("Vui long nhap lua chon tu 1-4: "); scanf("%d",&filter_choice);
        }
        
            if(filter_choice==1){
              printf("Nhap tu khoa: "); scanf(" %[^\n]%*c",keyword);
             result= filtername(list,keyword);
            }
            if(filter_choice==2){
             printf("Nhap tu khoa: "); scanf(" %[^\n]%*c",keyword);
                 result= filtersinger(list,keyword);
            }
            if(filter_choice==3){
           printf("Nhap tu khoa: "); scanf(" %[^\n]%*c",keyword);
                result =filtermusician(list,keyword);
            }
            if(filter_choice==4){
           printf("Nhap nam: "); scanf("%d",&year_cmp); 
                result= filteryear(list,year_cmp);
            }
            return result;
}
//Ham sap xep theo ten bai hat//
void sort_name(sll_listsong_t list){
  for(node_song_t cur1=list->front;cur1!=NULL;cur1=cur1->next)
      for(node_song_t cur2=cur1->next;cur2!=NULL;cur2=cur2->next)
       {
            if(strcmp(cur1->data->name,cur2->data->name)>0) swap_info_song(cur1,cur2);
       }
       printfList(list);
}
//Ham sap xep theo ten ca si//
void sort_singer(sll_listsong_t list){
  for(node_song_t cur1=list->front;cur1!=NULL;cur1=cur1->next)
      for(node_song_t cur2=cur1->next;cur2!=NULL;cur2=cur2->next)
       {
            if(strcmp(cur1->data->singer,cur2->data->singer)>0) swap_info_song(cur1,cur2);
       }
       printfList(list);
}
//ham sap xep theo ten nhac si//
void sort_musician(sll_listsong_t list){
  for(node_song_t cur1=list->front;cur1!=NULL;cur1=cur1->next)
      for(node_song_t cur2=cur1->next;cur2!=NULL;cur2=cur2->next)
       {
            if(strcmp(cur1->data->musician,cur2->data->musician)>0) swap_info_song(cur1,cur2);
       }
       printfList(list);
}
//Ham sap xep theo nam sang tac//
void sort_year(sll_listsong_t list){
  for(node_song_t cur1=list->front;cur1!=NULL;cur1=cur1->next)
      for(node_song_t cur2=cur1->next;cur2!=NULL;cur2=cur2->next)
       {
            if(cur1->data->year>cur2->data->year) swap_info_song(cur1,cur2);
       }
       printfList(list);
}
//Ham free list//
void freelist(sll_listsong_t list){
  if(list!=NULL&&list->front!=NULL)
  {
    node_song_t cur=list->front;
    while (cur->next!=NULL)
    {
     deletesong(list,cur);
     cur=cur->next;
    }
    deletesong(list,list->front);    
  }

  free(list);
}
//ham main//
int main(int argc, char* argv[])
{
     FILE *f=fopen(argv[1],"r+w");
     data_song_t info=malloc(sizeof(struct data_song));
         char *line = NULL;
          
   sll_listsong_t list=Creat_listsong();
   // doc tach du lieu//
  while (cgetline(&line, 0, f)) {
           char *token =strtok(line,"*#*");
           info->name=token; 
           token=strtok(NULL,"*#*");
           info->singer=token;
            token=strtok(NULL,"*#*");
           info->musician=token;
           token=strtok(NULL,"*#*");
           info->year=atoi(token);
           insertLastlist(list,info);           
     }
    //menu chinh//
    printf("Menu:\n");
    printf("1. Xem danh sach bai hat\n");
    printf("2. Loc danh sach bai hat\n");
    printf("3. Them bai hat\n");
    printf("4. Xoa bai hat\n");
    printf("5. Thoat chuong trinh\n");
    int menu_choice;
    scanf("%d",&menu_choice);
      while(menu_choice<1||menu_choice>5){
        printf("Vui long nhap tu lua chon tu 1-5:"); scanf("%d",&menu_choice);
      }
    while(menu_choice!=5){
      if(menu_choice==1) {
        printf("1.Sap xep thep ten bai hat\n");
        printf("2.Sap xep theo ten ca si\n");
        printf("3.Sap xem theo ten nhac si\n");
        printf("4.Sap xem theo nam sang tac\n");
        int sort_choice;
         scanf(" %d",&sort_choice);
         while(sort_choice<1||sort_choice>4)
         {
           printf("Vui long nhap tu 1-4\n");
           scanf(" %d",&sort_choice);
         }
         if(sort_choice==1) sort_name(list);
         if(sort_choice==2) sort_singer(list);
         if (sort_choice==3) sort_musician(list);
         if(sort_choice==4) sort_year(list);        

      }
      if(menu_choice==2)  {
        if(choice2(list)==0) printf("Khong co ket qua!\n"); 
        }
     if(menu_choice==3){
        printf("Nhap ten bai hat: "); scanf(" %[^\n]%*c",keyword); info->name=strdup(keyword);
        printf("Nhap ten ca si:"); scanf(" %[^\n]%*c",keyword); info->singer=strdup(keyword);
        printf("Nhap ten nhac si:"); scanf(" %[^\n]%*c",keyword); info->musician=strdup(keyword);
        printf("Nhap nam sang tac:"); int y0; scanf("%d",&y0); info->year=y0;
        insertLastlist(list,info);
      }
      if(menu_choice==4){
        int result=choice2(list);
        if(result==0)      printf("Khong co ket qua voi tu khoa !\n");
        else {
          printf("Ban muon xoa bai hat so ?. Nhap lua chon: ");
          int choice_song;
           scanf(" %d",&choice_song);
             while (choice_song>result||choice_song<1)
             {
               printf("Khong hop le. Vui long nhap lai\n");
               scanf(" %d",&choice_song);
             }             
           node_song_t cur=list->front;
           int cout=1;
           while (cout<idx[choice_song-1])
           {
             cout++;
             cur=cur->next;
           }
           printf("Xac nhan muon xoa bai hat nay !!\n");
           printf("Ten bai hat: %s\nTen ca si: %s\nTen nhac si: %s\nNam sang tac: %d   \n",cur->data->name, cur->data->singer,cur->data->musician,cur->data->year);
           printf("Nhap 1 de xac nhan xoa | Nhap 0 de huy xoa \n"); 
           int x; scanf(" %d",&x);
           if(x==1)  deletesong(list,cur);           
        } 
        }
        printf("_______________________________________________________________________________\n");
    printf("Menu:\n");
    printf("1. Xem danh sach bai hat\n");
    printf("2. Loc danh sach bai hat\n");
    printf("3. Them bai hat\n");
    printf("4. Xoa bai hat\n");
    printf("5. Thoat chuong trinh\n");
    scanf("%d",&menu_choice);
    }     
    // cap nhat lai danh sau sau khi xoa hoac them bai hat moi//
     clearFileContent("songs.txt");
     rewind(f);
     for(node_song_t cur=list->front;cur!=NULL;cur=cur->next)
     {
       fprintf(f,"%s#*#%s#*#%s#*#%d\n",cur->data->name, cur->data->singer,cur->data->musician,cur->data->year);
     }     
     fclose(f);
     // giai phong bo nho//
      free(idx);  free(line); freelist(list); free(info);
   return 0;       
}
// cau lenh bien dich gcc -o prog song.c -I /home/khanhdam/cgen (/home/khanhdam/cgen - thay băng đường dẫn tới cgen trên máy của bạn)
