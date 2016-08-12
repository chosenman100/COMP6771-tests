#!/bin/bash

DICT_NAME="EnglishWords.dat"
OUT_EXEC_FILE="out-exec.txt"
OUT_TEST_FILE="out-test.txt"
HEADER="Enter start word (RETURN to quit): Enter destination word: Found ladder: "

if [[ $# -ne 1 ]]
then
    echo "Usage: test.sh EXECUTABLE_PATH"
    exit
fi

#Extract test names.
TEST_CASES=`echo in-* | sed -e 's/in-//g'`
EXECUTABLE_PATH="$1"

for TEST_CASE in $TEST_CASES
do
    echo "Running test: $TEST_CASE"

    # Check potential non default dict.
    if [[ -e "dict-${TEST_CASE}" ]]
    then
        echo "Using custom dictionary file."
        cp "dict-$TEST_CASE" "$DICT_NAME"
    else
        cp "dict-default" "$DICT_NAME"
    fi

    # Format output test file to include the heading.
    echo -n "$HEADER" > "$OUT_TEST_FILE"
    cat "out-$TEST_CASE" >> "$OUT_TEST_FILE"

    # Run the test.
    $EXECUTABLE_PATH < "in-$TEST_CASE" > "$OUT_EXEC_FILE"
    diff -b -B "$OUT_TEST_FILE" "$OUT_EXEC_FILE"
    echo "Done"
done

if [ -x "${EXECUTABLE_PATH}_ref" ]; then
    echo "Running fuzzer with default dict"

    echo "Fuzzing with same length source and dest."
    ./fuzzer.sh sameLength 100 dict-default.txt "$EXECUTABLE_PATH"
    echo "Fuzzing with same source and dest. Potential failures on correct code."
    echo "See: http://webapps.cse.unsw.edu.au/webcms2/course/index.php?cid=2448&color=lavendar"
    ./fuzzer.sh sourceIsDest 5 dict-default.txt "$EXECUTABLE_PATH"
    echo "Fuzzing with random words."
    ./fuzzer.sh random 5 dict-default.txt "$EXECUTABLE_PATH"
fi

# Cleanup everything.
rm $OUT_EXEC_FILE
rm $OUT_TEST_FILE
rm $DICT_NAME
