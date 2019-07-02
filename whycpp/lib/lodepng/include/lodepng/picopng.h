#ifndef WHYCPP_PICOPNG_H
#define WHYCPP_PICOPNG_H

#include <vector>
#include <cstdlib>
#include <cstdint>

int decodePNG(std::vector<uint8_t>& out_image, uint64_t & image_width, uint64_t& image_height, const uint8_t* in_png, size_t in_size, bool convert_to_rgba32 = true);

#endif //WHYCPP_PICOPNG_H
