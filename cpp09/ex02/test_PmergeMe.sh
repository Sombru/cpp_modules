#!/bin/bash

# Color codes
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color

# Compile the program
echo -e "${BLUE}Compiling PmergeMe...${NC}"
make re
if [ $? -ne 0 ]; then
    echo -e "${RED}Compilation failed!${NC}"
    exit 1
fi
echo -e "${GREEN}Compilation successful!${NC}\n"

# Test counter
total_tests=0
passed_tests=0

# Function to run a test
run_test() {
    local test_name="$1"
    local test_args="$2"
    local should_fail="$3"
    
    total_tests=$((total_tests + 1))
    echo -e "${YELLOW}Test $total_tests: $test_name${NC}"
    echo -e "Command: ./PmergeMe $test_args"
    
    output=$(./PmergeMe $test_args 2>&1)
    exit_code=$?
    
    if [ "$should_fail" = "true" ]; then
        if [ $exit_code -ne 0 ]; then
            echo -e "${GREEN}✓ PASSED (correctly failed)${NC}"
            passed_tests=$((passed_tests + 1))
        else
            echo -e "${RED}✗ FAILED (should have failed but didn't)${NC}"
        fi
    else
        if [ $exit_code -eq 0 ]; then
            echo -e "${GREEN}✓ PASSED${NC}"
            passed_tests=$((passed_tests + 1))
        else
            echo -e "${RED}✗ FAILED (exit code: $exit_code)${NC}"
        fi
    fi
    echo "$output"
    echo ""
}

echo -e "${BLUE}=== Starting PmergeMe Tests ===${NC}\n"

# Valid test cases
echo -e "${BLUE}--- Valid Input Tests ---${NC}\n"

run_test "Simple sequence" "3 5 9 7 4" "false"
run_test "Already sorted" "1 2 3 4 5 6 7 8 9 10" "false"
run_test "Reverse sorted" "10 9 8 7 6 5 4 3 2 1" "false"
run_test "Two elements" "5 3" "false"
run_test "Single element" "42" "true"
run_test "Three elements" "3 1 2" "false"
run_test "With duplicates" "5 2 8 2 9 1 5 3" "false"
run_test "Large numbers" "2147483647 1000000 500 100 50" "false"
run_test "Small sequence" "4 2 9 3 1" "false"
run_test "Ten elements" "10 7 3 15 2 19 5 11 1 8" "false"

# Medium size tests
run_test "20 random numbers" "47 23 91 15 82 7 63 38 54 29 71 18 95 42 66 13 79 34 88 56" "false"
run_test "Even count" "8 4 6 2 10 12 14 16" "false"
run_test "Odd count" "9 5 7 3 11 13 15" "false"

# Large sequence test
echo -e "${YELLOW}Large sequence test (100 elements)${NC}"
large_seq=$(shuf -i 1-1000 -n 100 | tr '\n' ' ')
run_test "100 random elements" "$large_seq" "false"

# Very large sequence test
echo -e "${YELLOW}Very large sequence test (1000 elements)${NC}"
very_large_seq=$(shuf -i 1-10000 -n 1000 | tr '\n' ' ')
run_test "1000 random elements" "$very_large_seq" "false"

# Invalid input tests
echo -e "${BLUE}--- Invalid Input Tests ---${NC}\n"

run_test "No arguments" "" "true"
run_test "Negative number" "5 -3 8 2" "true"
run_test "Non-numeric input" "5 abc 3" "true"
run_test "Float number" "5 3.14 8" "true"
run_test "Zero" "5 0 8 2" "false"
run_test "Special characters" "5 @ 8 2" "true"
run_test "Plus sign prefix" "5 +3 8 2" "true"
run_test "Mixed invalid" "1 2 three 4" "true"
run_test "Empty string argument" "1 2 '' 4" "true"
run_test "Number too large" "5 2147483648 3" "true"
run_test "Negative sign only" "5 - 3" "true"
run_test "Expression" "1 2+3 4" "true"
run_test "Whitespace only" "   " "true"

# Edge cases
echo -e "${BLUE}--- Edge Case Tests ---${NC}\n"

# run_test "Maximum int value" "2147483647" "false"
run_test "Mix of small and large" "1 2147483647 2 2147483646 3" "false"
run_test "All same values" "5 5 5 5 5" "false"
run_test "Two same values" "7 7" "false"

# Summary
echo -e "${BLUE}=== Test Summary ===${NC}"
echo -e "Total tests: $total_tests"
echo -e "${GREEN}Passed: $passed_tests${NC}"
echo -e "${RED}Failed: $((total_tests - passed_tests))${NC}"

if [ $passed_tests -eq $total_tests ]; then
    echo -e "\n${GREEN}All tests passed! ${NC}"
    exit 0
else
    echo -e "\n${RED}Some tests failed.${NC}"
    exit 1
fi
