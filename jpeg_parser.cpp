#include "jpeg_parser.h"
#include <unistd.h>
#include <iostream>
#include <unistd.h>

using namespace std;

void read_header(int fd) {
    while (true) {
        uint16_t marker = read_segment(fd);

        if(marker == 0) break;

        cout << "marker: 0x" << hex << marker << dec << endl;
        
        if (marker != 0xFFD8 && marker != 0xFFD9 && !(marker >= 0xFFD0 && marker <= 0xFFD7)) {
            skip_segment(fd);
        }
        if(marker == 0xFFDA) break;
    }
}

uint16_t read_segment(int fd) {
    uint8_t bit1 = 0;
    uint8_t bit2 = 0;

    if (read(fd, &bit1, 1) < 1 || read(fd, &bit2, 1) < 1) return 0;
    
    return bit1 << 8 | bit2;
}

void skip_segment(int fd) {
    uint16_t length = read_segment(fd);
    if(length > 2) {
        lseek(fd, length - 2, SEEK_CUR);
    }
}