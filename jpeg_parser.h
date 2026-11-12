#ifndef JPEG_PARSER_H
#define JPEG_PARSER_H

#include <cstdint>


void read_header(int fd);
uint16_t read_segment(int fd);
void skip_segment(int fd);

#endif
