#!/bin/bash

# Configuration
PROGRAM="./PmergeMe"
NUM_TESTS=500        # How many times to run the test
COUNT=21          # How many numbers to sort per test
RANGE=1000       # Max value of numbers
ALLOW_DUPLICATES=0    # 1 = Yes (shuf -r), 0 = No (shuf)

# Colors
GREEN='\033[0;32m'
RED='\033[0;31m'
NC='\033[0m'

echo "Starting verification..."

for ((i=1; i<=NUM_TESTS; i++))
do
    # 1. Generate Input
    if [ $ALLOW_DUPLICATES -eq 1 ]; then
        ARG=$(shuf -r -i 0-$RANGE -n $COUNT | tr "\n" " ")
    else
        ARG=$(shuf -i 0-$RANGE -n $COUNT | tr "\n" " ")
    fi

    # 2. Get Your Output (Extract the line starting with "After:")
    # We use sed to remove "After: " and keep just the numbers
    YOUR_OUTPUT=$($PROGRAM $ARG | grep "After:" | sed 's/After: //')

    # 3. Get Expected Output (Sort the input using Linux sort)
    # tr spaces to newlines -> sort -> tr newlines back to spaces
    EXPECTED_OUTPUT=$(echo $ARG | tr " " "\n" | sort -n | tr "\n" " ")

    # 4. Normalize (Remove trailing spaces for comparison)
    YOUR_CLEAN=$(echo $YOUR_OUTPUT | xargs)
    EXPECTED_CLEAN=$(echo $EXPECTED_OUTPUT | xargs)

    # 5. Compare
    if [ "$YOUR_CLEAN" == "$EXPECTED_CLEAN" ]; then
        echo -e "Test $i: ${GREEN}[OK]${NC}"
    else
        echo -e "Test $i: ${RED}[FAIL]${NC}"
        echo "Input:    $ARG"
        echo "Expected: $EXPECTED_CLEAN"
        echo "Got:      $YOUR_CLEAN"
        exit 1
    fi
done

echo "All $NUM_TESTS tests passed successfully!"