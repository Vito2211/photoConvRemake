#include <iostream>
#include <fcntl.h> 


#include "jpeg_parser.h"

using namespace std;

int main(int argc, char** argv) {

    if(argc < 2) return 1;

    int fd = open(argv[1], O_RDONLY);

    read_header(fd);

    return 0;
}


