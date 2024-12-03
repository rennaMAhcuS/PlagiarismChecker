#!/bin/bash
# This is for you, the student to execute

BUILDDIR=$HOME/build

a=0
b=0

# Phase 1
(cd phase1
if ! make; then
    make clean
    a=0
else
    $BUILDDIR/phase1 | tee $BUILDDIR/one.txt
    make clean
    a=`cat $BUILDDIR/one.txt | grep "Total" | awk '{print $3}'`
fi)

# Phase 2
(cd phase2
make
$BUILDDIR/phase2 | tee $BUILDDIR/two.txt
make clean
b=`cat $BUILDDIR/two.txt | grep "Total" | awk '{print $3}'`)

# Total
result=$(echo $a+$b | bc -l)
echo "RESULT: $result / 9"
