#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <unistd.h>
#include <sys/socket.h>
#include <linux/netlink.h>

#define UEVENT_BUFFER_SIZE 2048

int main()
{
    struct sockaddr_nl sa;
    int nl_socket;
    int ret;

    // Create a netlink socket
    nl_socket = socket(AF_NETLINK, SOCK_RAW, NETLINK_KOBJECT_UEVENT);
    if (nl_socket < 0)
    {
        std::cerr << "Failed to create netlink socket" << std::endl;
        return 1;
    }

    // Prepare the sockaddr_nl structure
    memset(&sa, 0, sizeof(sa));
    sa.nl_family = AF_NETLINK;
    sa.nl_pid = getpid();
    sa.nl_groups = 1; // Receive broadcast messages from the kernel

    // Bind the socket to the netlink address
    ret = bind(nl_socket, (struct sockaddr *)&sa, sizeof(sa));
    if (ret < 0)
    {
        std::cerr << "Failed to bind netlink socket" << std::endl;
        close(nl_socket);
        return 1;
    }

    // Buffer to store the events
    char buffer[UEVENT_BUFFER_SIZE];

    std::cout << "Monitoring device events..." << std::endl;

    // Event loop
    while (true)
    {
        // Receive data from the socket
        ret = recv(nl_socket, &buffer, sizeof(buffer), 0);
        if (ret < 0)
        {
            std::cerr << "Failed to receive from socket" << std::endl;
            close(nl_socket);
            return 1;
        }

        // Null-terminate the buffer and print the event
        buffer[ret] = '\0';

        std::cout << "Event received:" << std::endl;

        // Parse the message (key-value pairs)
        char *current = buffer;
        while (current < buffer + ret)
        {
            std::cout << current << std::endl;
            current += strlen(current) + 1; // Move to the next key-value pair
        }

        std::cout << std::endl; // Add a blank line between events
    }

    // Cleanup
    close(nl_socket);
    return 0;
}
