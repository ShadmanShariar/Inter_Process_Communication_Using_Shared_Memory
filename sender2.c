#include<stdio.h>  
#include<stdlib.h>  
#include<unistd.h>  
#include<sys/shm.h>  
#include<string.h>  
int main()  
{  

char str[100]; int i;  
void *shared_memory;  
char buff[100];  
int shmid;

shmid=shmget((key_t)2345, 1024, 0666|IPC_CREAT);    
printf("Key of shared memory is %d\n",shmid);  
shared_memory=shmat(shmid,NULL,0);   
printf("Process attached at %p\n",shared_memory); 

printf("Enter Your Name : \n"); 
read(0,str,100);
  
printf("Enter Your message\n");  
read(0,buff,100);
 
strcat(str,buff); 
 
strcpy(shared_memory,str); 

printf("Sended By : %s\n",(char *)shared_memory);  

}  
