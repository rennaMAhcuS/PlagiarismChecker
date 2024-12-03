#!/bin/bash

# The build directory
BUILDDIR=$HOME/build
GRADERDIR=$BUILDDIR/autograder

a=0
b=0

mkdir -p $GRADERDIR

# Phase 1
(cd phase1
make
$GRADERDIR/phase1 | tee $GRADERDIR/one.txt
make clean)
a=`cat $GRADERDIR/one.txt | grep "Total" | awk '{print $3}'`

# Phase 2
(cd phase2
make
$GRADERDIR/phase2 | tee $GRADERDIR/two.txt
make clean)
b=`cat $GRADERDIR/two.txt | grep "Total" | awk '{print $3}'`

# Total
result=$(python3 -c "print($a + $b)")
echo "RESULT: $result / 9"
