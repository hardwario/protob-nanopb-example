#include "nanopb/pb_encode.h"
#include "message.pb.h"

#include "nanopb/pb.h"

#include <stdio.h>

bool Counter_repeat(pb_ostream_t *stream, const pb_field_t *field, void * const *arg)
{
        int item_count = 36;
        char array[item_count];

        for (int i = 0; i < item_count; i++)
        {
            array[i] = i;
        }

        return pb_encode_tag_for_field(stream, field) &&
        pb_encode_string(stream, array, sizeof(array));
}

uint8_t buffer[200];

bool pb_callback_string(pb_ostream_t *stream, const pb_field_t *field, void * const *arg)
{
    char str[32];
    int index = *((int*)arg[0]); // Get index from array of arguments
    snprintf(str, sizeof(str), "Input_%d", index);
    return pb_encode_tag_for_field(stream, field) && pb_encode_string(stream, str, strlen(str));
}

bool pb_callback_inputs(pb_ostream_t *stream, const pb_field_t *field, void * const *arg)
{
    for (int i = 0; i < 3; i++)
    {
        pb_input_t msg_input;

        msg_input.state = true;
        msg_input.name.funcs.encode = pb_callback_string;
        msg_input.name.arg = &i; // Set index parameter to callback

         if(pb_encode_tag_for_field(stream, field) == false || pb_encode_submessage(stream, pb_input_t_fields, &msg_input) == false)
         {
             return false;
         }
    }

    return true;
}

int main()
{
    pb_packet_t msg = pb_packet_t_init_default;

    msg.luminance = 300;
/*
    msg.hw_revision = pb_revision_t_PB_REV1_2;

    msg.has_voltage = true;
    msg.voltage.battery = 630;
    msg.voltage.external = 1230;

    msg.inputs.funcs.encode = pb_callback_inputs;
*/
    pb_ostream_t stream = pb_ostream_from_buffer(buffer, sizeof(buffer));

    pb_encode(&stream, pb_packet_t_fields, &msg);

    printf("Length: %d\n", (int)stream.bytes_written);
    for (int i = 0; i < stream.bytes_written; i++)
    {
        printf("%02X", buffer[i]);
    }

    printf("\n");
}

// ./nanopb/generator/nanopb_generator.py message.proto

// gcc main.c nanopb/pb_common.c nanopb/pb_encode.c message.pb.c  -I nanopb/

// pip3 install --upgrade protobuf
