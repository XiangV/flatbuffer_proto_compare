
set -x
FLATC=$1
#PROTOC=$2

${FLATC} --cpp -o flat_sample schema/sample.fbs
${FLATC} --cpp -o flat_sample schema/sample2.fbs

#g++ -O2 -g -std=c++11 -Iflat_sample -I/Users/xiangwei/Project/flatbuffers/include flat_sample/sample.cc flat_sample/libflatbuffers.a
