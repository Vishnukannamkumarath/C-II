#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
# define port 5000
void main(){
struct sockaddr_in serveraddr,newaddr;
int sersocket,newsocket,s,size;
char buffer[100];
sersocket=socket(PF_INET,SOCK_STREAM,0);
if(sersocket>0){
printf("socket is created\n");
}
serveraddr.sin_port=htons(port);
serveraddr.sin_family=PF_INET;
serveraddr.sin_addr.s_addr=htonl(INADDR_ANY);
s=bind(sersocket,(struct sockaddr*)&serveraddr,sizeof(serveraddr));
if(s==0){
printf("bind success\n");
}
listen(sersocket,1);
size=sizeof(newaddr);
printf("server ready\n");
newsocket=accept(sersocket,(struct sockaddr*)&newaddr,&size);
if(newsocket>0){
printf("accept is success\n");
}
recv(newsocket,buffer,sizeof(buffer),0);
printf("IP:%s\n",buffer);
recv(newsocket,buffer,sizeof(buffer),0);
printf("MAC:%s\n",buffer);
close(sersocket);
}
