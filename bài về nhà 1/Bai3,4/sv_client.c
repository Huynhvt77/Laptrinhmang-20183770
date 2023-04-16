#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>


typedef struct 
{
    char id[10];
    char hoten[50];
    char ngaySinh[20];
    char diemtb[5];
} Sinhvien;

int len_sv(Sinhvien sv){
    return strlen(sv.id) + strlen(sv.diemtb) + strlen(sv.hoten) + strlen(sv.ngaySinh);
}

int main( int argc, char *argv[]){
    // Khai bao socket
    int client = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    
    // Khai bao dia chi cua server
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(argv[1]);
    addr.sin_port = htons(atoi(argv[2]));

    // Ket noi den server
    int res = connect(client, (struct sockaddr *)&addr, sizeof(addr));
    if (res == -1) {
        printf("Khong ket noi duoc den server!");
        return 1;
    }

    // Gui tin nhan den server
    char buf[300] = "",x[100];
    Sinhvien sv;
    // printf("Nhap id: ");
    // scanf("%s", sv.id);fflush(stdin);
    // printf("\n");

    // printf("Nhap ho ten: ");
    // fgets(sv.hoten, sizeof(sv.hoten), stdin);
    // // int a = strcspn(sv.hoten, "\n");
    // // strncpy(x, sv.hoten, a);
    // // x[a] = '\0';
    // //x= 
    // printf("\n");
    // printf("Nhap ngay sinh: ");
    // scanf("%s",sv.ngaySinh);
    // printf("\n");
    // printf("Nhap diem: ");
    // scanf("%s",sv.diemtb);
    // printf("\n");

    printf("Nhap id: ");
    fgets(sv.id, sizeof(sv.id), stdin);
    fflush(stdin);
    int a = strcspn(sv.id, "\n");
    strncpy(x, sv.id, a);
    x[a] = '\0';
    strcat(buf, x);
    strcat(buf, " ");

    printf("Nhap ho ten: ");
    fgets(sv.hoten, sizeof(sv.hoten), stdin);
    fflush(stdin);
    a = strcspn(sv.hoten, "\n");
    strncpy(x, sv.hoten, a);
    x[a] = '\0';
    strcat(buf, x);
    strcat(buf, " ");

    printf("Nhap ngay sinh: ");
    fgets(sv.ngaySinh, sizeof(sv.ngaySinh), stdin);
    fflush(stdin);
    a = strcspn(sv.ngaySinh, "\n");
    strncpy(x, sv.ngaySinh, a);
    x[a] = '\0';
    strcat(buf, x);
    strcat(buf, " ");

    printf("Nhap diem: ");
    fgets(sv.diemtb, sizeof(sv.diemtb), stdin);
    fflush(stdin);
    a = strcspn(sv.diemtb, "\n");
    strncpy(x, sv.diemtb, a);
    x[a] = '\0';    
    strcat(buf, x);
    strcat(buf, " ");

    send(client, buf, sizeof(buf), 0);
    // Dong ket noi
    close(client);
    return 0;
}