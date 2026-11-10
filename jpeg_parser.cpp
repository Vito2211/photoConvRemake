#include "jpeg_parser.h"
#include <unistd.h>


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