#!/bin/bash

# Color codes
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color

# Compile the program
echo -e "${BLUE}Compiling RPN...${NC}"
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
    local test_input="$2"
    local expected_output="$3"
    local should_fail="$4"
    
    total_tests=$((total_tests + 1))
    echo -e "${YELLOW}Test $total_tests: $test_name${NC}"
    echo -e "Input: \"$test_input\""
    
    output=$(./rpn "$test_input" 2>&1)
    exit_code=$?
    
    if [ "$should_fail" = "true" ]; then
        if [ $exit_code -ne 0 ]; then
            echo -e "${GREEN}✓ PASSED (correctly failed)${NC}"
            echo -e "Output: $output"
            passed_tests=$((passed_tests + 1))
        else
            echo -e "${RED}✗ FAILED (should have failed but got: $output)${NC}"
        fi
    else
        if [ $exit_code -eq 0 ]; then
            # For floating point comparison, we'll just check if output is close enough
            if [ -n "$expected_output" ]; then
                # Compare with some tolerance for floating point
                result=$(echo "$output" | awk '{print $1}')
                diff=$(echo "$result - ($expected_output)" | bc -l 2>/dev/null | sed 's/-//')
                
                # Check if difference is very small (< 0.0001)
                is_close=$(echo "$diff < 0.0001" | bc -l 2>/dev/null)
                
                if [ "$is_close" = "1" ] || [ "$result" = "$expected_output" ]; then
                    echo -e "${GREEN}✓ PASSED${NC}"
                    echo -e "Expected: $expected_output, Got: $output"
                    passed_tests=$((passed_tests + 1))
                else
                    echo -e "${RED}✗ FAILED${NC}"
                    echo -e "Expected: $expected_output, Got: $output"
                fi
            else
                echo -e "${GREEN}✓ PASSED${NC}"
                echo -e "Output: $output"
                passed_tests=$((passed_tests + 1))
            fi
        else
            echo -e "${RED}✗ FAILED (exit code: $exit_code)${NC}"
            echo -e "Output: $output"
        fi
    fi
    echo ""
}

echo -e "${BLUE}=== Starting RPN Calculator Tests ===${NC}\n"

# Valid test cases
echo -e "${BLUE}--- Valid Expression Tests ---${NC}\n"

run_test "Simple addition" "3 4 +" "7" "false"
run_test "Simple subtraction" "10 5 -" "5" "false"
run_test "Simple multiplication" "6 7 *" "42" "false"
run_test "Simple division" "20 4 /" "5" "false"

run_test "Multiple operations" "3 4 + 2 *" "14" "false"
run_test "Complex expression 1" "8 9 * 9 - 9 - 9 - 4 - 1 +" "42" "false"
run_test "Complex expression 2" "7 7 * 7 -" "42" "false"
run_test "Complex expression 3" "1 2 * 2 / 2 * 2 4 - +" "0" "false"

run_test "Three operands" "1 2 + 3 +" "6" "false"
run_test "Four operands" "1 2 + 3 + 4 +" "10" "false"

run_test "Negative result" "5 10 -" "-5" "false"
run_test "Negative operand" "-5 3 +" "-2" "false"
run_test "Two negatives" "-5 -3 +" "-8" "false"

run_test "Division with fraction" "5 2 /" "2.5" "false"
run_test "Large numbers" "1000 999 +" "1999" "false"

run_test "Single digit operations" "1 1 +" "2" "false"
run_test "Zero in calculation" "0 5 +" "5" "false"
run_test "Result is zero" "5 5 -" "0" "false"

run_test "Chained operations" "2 3 + 4 5 + *" "45" "false"
run_test "Nested operations" "15 7 1 1 + - / 3 * 2 1 1 + + -" "5" "false"

# Subject examples (if any)
run_test "Example from subject 1" "8 9 * 9 - 9 - 9 - 4 - 1 +" "42" "false"

# Invalid test cases
echo -e "${BLUE}--- Invalid Expression Tests ---${NC}\n"

run_test "No arguments" "" "" "true"
run_test "Division by zero" "5 0 /" "" "true"
run_test "Insufficient operands" "1 +" "" "true"
run_test "Too many operands" "1 2 3 +" "" "true"
run_test "Only operator" "+" "" "true"
run_test "Only number" "42" "" "true"
run_test "Invalid token" "1 2 $ 3" "" "true"
run_test "Letters in expression" "1 2 a +" "" "true"
run_test "Empty spaces only" "   " "" "true"

run_test "Operator at start" "+ 1 2" "" "true"
run_test "Multiple operators" "1 + + 2" "" "true"
run_test "Missing operand" "1 2 + +" "" "true"

run_test "Invalid characters" "1 2 @ 3 +" "" "true"
run_test "Parentheses (not supported)" "(1 2 +)" "" "true"
run_test "Comma separator" "1,2 +" "" "true"

run_test "Expression with equals" "1 2 + = 3" "" "true"
run_test "Incomplete expression 1" "1 2" "" "true"
run_test "Incomplete expression 2" "1 2 3 + +" "" "true"

# Edge cases
echo -e "${BLUE}--- Edge Case Tests ---${NC}\n"

run_test "Very small result" "1 1000000 /" "0.000001" "false"
run_test "Decimal operands" "3.5 2.5 +" "6" "false"
run_test "Negative multiplication" "-2 3 *" "-6" "false"
run_test "Negative division" "-10 2 /" "-5" "false"
run_test "Complex with negatives" "-5 -3 * 2 +" "17" "false"

# Test with multiple arguments (should fail - only 1 arg allowed)
echo -e "${BLUE}--- Argument Count Tests ---${NC}\n"

echo -e "${YELLOW}Test: Multiple arguments (should fail)${NC}"
./rpn "1 2" "+" > /dev/null 2>&1
if [ $? -ne 0 ]; then
    echo -e "${GREEN}✓ PASSED (correctly rejected multiple arguments)${NC}"
    passed_tests=$((passed_tests + 1))
else
    echo -e "${RED}✗ FAILED (should reject multiple arguments)${NC}"
fi
total_tests=$((total_tests + 1))
echo ""

echo -e "${YELLOW}Test: No arguments (should fail)${NC}"
./rpn > /dev/null 2>&1
if [ $? -ne 0 ]; then
    echo -e "${GREEN}✓ PASSED (correctly rejected no arguments)${NC}"
    passed_tests=$((passed_tests + 1))
else
    echo -e "${RED}✗ FAILED (should reject no arguments)${NC}"
fi
total_tests=$((total_tests + 1))
echo ""

# Summary
echo -e "${BLUE}=== Test Summary ===${NC}"
echo -e "Total tests: $total_tests"
echo -e "${GREEN}Passed: $passed_tests${NC}"
echo -e "${RED}Failed: $((total_tests - passed_tests))${NC}"

if [ $passed_tests -eq $total_tests ]; then
    echo -e "\n${GREEN}All tests passed! 🎉${NC}"
    exit 0
else
    echo -e "\n${RED}Some tests failed.${NC}"
    exit 1
fi
