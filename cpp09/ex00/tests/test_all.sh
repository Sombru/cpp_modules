#!/bin/bash

# Color codes
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

echo -e "${YELLOW}=== Bitcoin Exchange Test Suite ===${NC}\n"

# Test 1: Original input
echo -e "${GREEN}Test 1: Original input file${NC}"
echo "Expected: Mix of valid and invalid entries"
./btc test1.txt
echo -e "\n---\n"

# Test 2: Edge dates
echo -e "${GREEN}Test 2: Edge dates (very early, very late dates)${NC}"
echo "Expected: Should handle dates outside DB range"
./btc test2_edge_dates.txt
echo -e "\n---\n"

# Test 3: Invalid dates
echo -e "${GREEN}Test 3: Invalid dates${NC}"
echo "Expected: All should fail with error messages"
./btc test3_invalid_dates.txt
echo -e "\n---\n"

# Test 4: Invalid values
echo -e "${GREEN}Test 4: Invalid values (negative, too large)${NC}"
echo "Expected: Mix of valid and invalid based on range"
./btc test4_invalid_values.txt
echo -e "\n---\n"

# Test 5: Invalid format
echo -e "${GREEN}Test 5: Invalid format${NC}"
echo "Expected: Various format errors"
./btc test5_invalid_format.txt
echo -e "\n---\n"

# Test 6: Whitespace handling
echo -e "${GREEN}Test 6: Whitespace handling${NC}"
echo "Expected: Should handle various whitespace correctly"
./btc test6_whitespace.txt
echo -e "\n---\n"

# Test 7: Decimal values
echo -e "${GREEN}Test 7: Decimal values${NC}"
echo "Expected: Should handle various decimal values"
./btc test7_decimal_values.txt
echo -e "\n---\n"

# Test 8: Boundary values
echo -e "${GREEN}Test 8: Boundary values (around 471150 and max)${NC}"
echo "Expected: Should reject values > 471150.93"
./btc test8_boundary_values.txt
echo -e "\n---\n"

# Test 9: Empty lines
echo -e "${GREEN}Test 9: Empty lines and special cases${NC}"
echo "Expected: Should skip empty lines"
./btc test9_empty_and_special.txt
echo -e "\n---\n"

# Test 10: Leap years
echo -e "${GREEN}Test 10: Leap year dates${NC}"
echo "Expected: Should validate leap years correctly"
./btc test10_leap_years.txt
echo -e "\n---\n"

echo -e "${YELLOW}=== All tests completed ===${NC}"
