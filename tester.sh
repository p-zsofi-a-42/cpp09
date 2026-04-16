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
	echo -e "${YELLOW_B}Which exercise to test? [00][01][02]: ${RESET}"
	read -p "" PROJECT
	case $PROJECT in
		00 ) PROGRAM=./ex00/btc; 		TEST_DIR=tests/tests_ex00; break;;
		01 ) PROGRAM=./ex01/RPN; 		TEST_DIR=tests/tests_ex01; break;;
		02 ) PROGRAM=./ex02/PmergeMe;	TEST_DIR=tests/tests_ex02; break;;
	esac
done

# Creating test program util executable
make re -C tests/tests_ex$PROJECT
# Creating program executable
make re -C ex$PROJECT

pass_counter=0
fail_counter=0

for input in $TEST_DIR/*.input; do
	name=$(basename "$input" .input)
	expected="$TEST_DIR/$name.expected"

	# Read input as arguments
	args=$(cat "$input")
	#args="$(cat "$input")"

	# Create the expected output with calling STL algorithm
	./$TEST_DIR/expected_generator "${args[@]}" > "$expected"

	# Run program, store the prints in the variable output
	output=$($PROGRAM $args 2>/dev/null)
	#utput=$($PROGRAM "${args[@]}" 2>/de/null)
	# Ignore last 4 lines of the output (which is comparison counter and time taken
	output_sort=$(echo "$output" | awk 'NR==2')
	output_counter=$(echo "$output" | tail -n 1)
	
	# save content of expected file
	expected_output=$(cat "$expected")
	expected_output_sort=$(echo "$expected_output" | awk 'NR==2')
	max_limit=$(echo "$expected_output" | tail -n 1)
	num_of_args=$(echo "$expected_output" | tail -n 3 | head -n 1)

	echo -e "--------------------------------------------------------------------"
	if [ "$output_sort" == "$expected_output_sort" ]; then
		echo -e -n "${YELLOW_B}"	"\b$name ✅" "${RESET}"
		if [ "$expected_output_sort" != "ERROR" ]; then
			if [ "$output_counter" -le "$max_limit" ]; then
				echo "✅"
				echo -e "${GREEN}"	"\b\tNumber of elements: $num_of_args" \
									"max limit: $max_limit" \
									"program: $output_counter"
				((pass_counter++))
			else
				echo "❌"
				echo -e "${RED}"	"\b\tNumber of elements: $num_of_args" \
									"max limit: $max_limit" \
									"program: $output_counter"
				((fail_counter++))
			fi
		else
			((pass_counter++))
			echo ""
		fi
		echo -e	"${WHITE_B}"	"\b\tInput:\n"		"\b${WHITE}"		"\b$args"	"\b${RESET}"
		echo -e	"${WHITE_B}"	"\b\tGot:\n"		"\b${WHITE}"		"\b$output_sort"	"\b${RESET}"
	else
		echo -e "${YELLOW_B}"	"\b$name ❌"
		echo -e	"${WHITE_B}"	"\b\tInput:\n"		"\b${WHITE}"		"\b$args"	"\b${RESET}"
		echo -e "${WHITE_B}""\b\tExpected:\n"	"\b${WHITE}"	"\b$expected_output_sort"
		echo -e	"${RED_B}"	"\b\tGot:\n"		"\b${RED}"		"\b$output_sort"	"\b${RESET}"
		((fail_counter++))
	fi
done

echo
echo -e "${YELLOW_B}"	"\bPassed: $pass_counter"
echo -e 				"Failed: $fail_counter"		"\b${RESET}"