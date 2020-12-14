./nanopb/generator/nanopb_generator.py message.proto
 
gcc main.c nanopb/pb_common.c nanopb/pb_encode.c message.pb.c  -I nanopb/
./a.out
