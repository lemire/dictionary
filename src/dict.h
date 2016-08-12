#ifndef DICT_DICT_H
#define DICT_DICT_H

#include <cstdint>
#include <cstddef>
#include <cstring>

class dictionary_coded_t {
public:
    uint64_t * dictionary;
    uint32_t dictionary_size;

    char *compressed_data;
    size_t array_length;// uncompressed length in 64-bit words
    uint32_t compressed_data_size;// compressed data in bytes
    int bit_width;

    dictionary_coded_t() :
        dictionary ( NULL),
        dictionary_size (0),
        compressed_data (NULL),
        array_length (0),
        compressed_data_size(0),
        bit_width (0)
    {
    }

    dictionary_coded_t(const dictionary_coded_t & s) :
        dictionary ( NULL),
        dictionary_size (0),
        compressed_data (NULL),
        array_length ( 0),
        compressed_data_size(0),
        bit_width ( 0)
    {
        *this = s; // does a deep copy
    }

    dictionary_coded_t(const dictionary_coded_t && s) :
        dictionary (std::move(s.dictionary)),
        dictionary_size (std::move(dictionary_size)),
        compressed_data (std::move(compressed_data)),
        array_length (std::move(array_length)),
        compressed_data_size(std::move(compressed_data_size)),
        bit_width (std::move(bit_width))
    {
        *this = s; // does a deep copy
    }


    virtual ~dictionary_coded_t() {
        delete[] dictionary;
        delete[] compressed_data;
        init();
    }

    // does a deep copy
    dictionary_coded_t& operator=(const dictionary_coded_t & s) {
        delete[] dictionary;
        delete[] compressed_data;
        dictionary = new uint64_t[s.dictionary_size];
        memcpy(dictionary,s.dictionary,sizeof(uint64_t)*s.dictionary_size);
        dictionary_size = s.dictionary_size;
        compressed_data = new char[s.compressed_data_size];
        memcpy(compressed_data,s.compressed_data,s.compressed_data_size);

        compressed_data_size = s.compressed_data_size;
        array_length = s.array_length;
        bit_width = s.bit_width;
        return *this;
    }

private:

    void init() {
        dictionary = NULL;
        compressed_data = NULL;
        dictionary_size = 0;
        array_length = 0;
        compressed_data_size = 0;
        bit_width = 0;
    }


};

#endif
