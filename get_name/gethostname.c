#include <stdio.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main() {
    struct hostent *he;
    struct in_addr **addr_list;
    struct in_addr addr;

    // get the addresses of stackoverflow.com:

    he = gethostbyname("stackoverflow.com");
    if (he == NULL) { // do some error checking
        herror("gethostbyname"); // herror(), NOT perror()
        return -1;
    }

    // print information about this host:
    printf("Official name is: %s\n", he->h_name);
    printf("IP address: %s\n", inet_ntoa(*(struct in_addr*)he->h_addr));
    printf("All addresses: ");
    addr_list = (struct in_addr **)he->h_addr_list;
    for(int i = 0; addr_list[i] != NULL; i++) {
        printf("%s ", inet_ntoa(*addr_list[i]));
    }
    printf("\n");
    return 0;
}