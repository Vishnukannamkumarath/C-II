#include<stdio.h>
#include<string.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<sys/ioctl.h>
#include<net/if.h>
#include<netinet/in.h>
#define port 5000
void main(){
struct sockaddr_in serveraddr;
struct ifreq ifr;
char *iface="eth0";
char *mac;
int clisocket,size;
char ipaddr[100],macaddr[32]={0};
clisocket=socket(PF_INET,SOCK_STREAM,0);
if(clisocket>0){
printf("socket is created\n");
}
serveraddr.sin_port=htons(port);
serveraddr.sin_family=PF_INET;
serveraddr.sin_addr.s_addr=inet_addr("127.0.0.1");
connect(clisocket,(struct sockaddr*)&serveraddr,sizeof(serveraddr));
strcpy(ipaddr,inet_ntoa(serveraddr.sin_addr));
send(clisocket,ipaddr,sizeof(ipaddr),0);
printf("Ip is send\n");
ifr.ifr_addr.sa_family=PF_INET;
strncpy((char*)ifr.ifr_name,(const char*)iface,IFNAMSIZ-1);
ioctl(clisocket,SIOCGIFHWADDR,&ifr);
mac=ifr.ifr_hwaddr.sa_data;
sprintf((char*)macaddr,(const char*)"%.2hhx:%.2hhx:%.2hhx:%.2hhx:%.2hhx:%.2hhx\n",mac[0],mac[1],mac[2],mac[3],mac[4],mac[5]);
send(clisocket,macaddr,sizeof(macaddr),0);
close(clisocket);
}

