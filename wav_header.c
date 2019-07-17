#include <stdio.h>
#include "wav_header.h"

    void generate_wav_header(int sample_rate, int num_samples)
    {

        FILE* wav_header_file;
        unsigned short int num_channels = 1;
        unsigned short int bytes_per_sample = 2;

        unsigned int file_size = 36 + bytes_per_sample * num_samples * num_channels;
        unsigned short int bits_per_sample = 8 * bytes_per_sample;
        unsigned short int fmt_type = 1;
        unsigned int byte_rate = (sample_rate * bits_per_sample * num_channels) / 8;
        unsigned int fmt_len = 16;
        unsigned int data_len = bytes_per_sample * num_samples * num_channels;


        wav_header_file = fopen("header.wav", "wb");

        /* write RIFF header */
        fwrite("RIFF", 1, 4, wav_header_file);
        fwrite(&file_size, 4, 1, wav_header_file);
        fwrite("WAVE", 1, 4, wav_header_file);

        /* write fmt  subchunk */
        fwrite("fmt ", 1, 4, wav_header_file);
        fwrite(&fmt_len, 4, 1, wav_header_file);   /* SubChunk1Size is 16 */
        fwrite(&fmt_type, 2, 1, wav_header_file);
        fwrite(&num_channels, 2, 1, wav_header_file);
        fwrite(&sample_rate, 4, 1, wav_header_file);
        fwrite(&byte_rate, 4, 1, wav_header_file);
        fwrite(&bytes_per_sample, 2, 1, wav_header_file);
        fwrite(&bits_per_sample, 2, 1, wav_header_file);
        fwrite("data", 1, 4, wav_header_file);
        fwrite(&data_len, 4, 1, wav_header_file);



        fclose(wav_header_file);
    }


