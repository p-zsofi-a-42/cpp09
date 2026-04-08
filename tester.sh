#!/bin/bash

# Define color codes for output formatting
RED_B="\e[1;31m"
RED="\e[0;31m"
GREEN_B="\e[1;32m"
GREEN="\e[0;32m"
LILA_B="\e[1;35m"
LILA="\e[0;35m"
YELLOW_B="\e[1;33m"
YELLOW="\e[0;33m"
CYAN_B="\e[1;96m"
CYAN="\e[0;96m"
MAGENTA_B="\e[1;35m"
MAGENTA="\e[0;35m"
WHITE_B="\e[1;37m"
WHITE="\e[0;37m"
RESET="\e[0m"

while true; do
	echo -e "${YELLOW_B}Which prgram to test? [00][01][02]: ${RESET}"
	read -p "" PROJECT
	case $PROJECT in
		00 ) PROGRAM=./ex00/btc; 		TEST_DIR=tests/tests_ex00; break;;
		01 ) PROGRAM=./ex01/RPN; 		TEST_DIR=tests/tests_ex01; break;;
		02 ) PROGRAM=./ex02/PmergeMe;	TEST_DIR=tests/tests_ex02; break;;
	esac
done

pass_counter=0
fail_counter=0

for input in $TEST_DIR/*.input; do
	name=$(basename "$input" .input)
	expected="$TEST_DIR/$name.expected"

	# Read input as arguments
	args=$(cat "$input")

	# Create the expected output with calling STL algorithm
	./$TEST_DIR/expected_generator "${args[@]}" > "$expected"

	# Run program, store the prints in the variable output
	output=$($PROGRAM $args)

	# Normalize whitespace (optional but helpful)
	expected_output=$(cat "$expected")

	echo -e "--------------------------------------------------------------------"
	if [ "$output" == "$expected_output" ]; then
		echo -e "${YELLOW_B}"	"\b$name ✅"
		((pass_counter++))
	else
		echo -e "${YELLOW_B}"	"\b$name ❌"
		echo -e "${WHITE_B}""\t\bExpected:\n"	"\b${WHITE}"	"\b$expected_output"
		echo -e	"${RED_B}"	"\t\bGot:\n"		"\b${RED}"	"\b$output"			"\b${RESET}"
		((fail_counter++))
	fi
done

echo
echo -e "${YELLOW_B}"	"\bPassed: $pass_counter"
echo -e 				"Failed: $fail_counter"		"\b${RESET}"