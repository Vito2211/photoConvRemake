#include <iostream>
#include <fcntl.h> 
#include <unistd.h>

#include "jpeg_parser.h"

using namespace std;

int main(int argv, char** argc) {

    if(argv < 2) return 1;

    int fd = open(argc[1], O_RDONLY);

    while (true) {
        uint16_t marker = read_segment(fd);

        if(marker == 0) break;

        cout << "marker: 0x" << hex << marker << dec << endl;

        

        if (marker != 0xFFD8 && marker != 0xFFD9 && !(marker >= 0xFFD0 && marker <= 0xFFD7)) {
            skip_segment(fd);
        }

        if(marker == 0xFFDA) break;

        
    }
    

    return 0;
}


