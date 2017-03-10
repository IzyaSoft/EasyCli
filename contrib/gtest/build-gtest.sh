#! /bin/bash
GTEST_DIR=.
#../../contrib/gtests
#=.

rm -rf ${GTEST_DIR}/libgtest*
rm -rf ${GTEST_DIR}/*.o
g++ -isystem ${GTEST_DIR}/include -I${GTEST_DIR} -pthread -c ${GTEST_DIR}/src/gtest-all.cc
ar -rv ${GTEST_DIR}/libgtest.a gtest-all.o
