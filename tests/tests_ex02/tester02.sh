#!/bin/bash

# Ignore last 4 lines of the output (which is comparison counter and time taken
output_sort=$(echo "$output" | awk 'NR==2')
output_counter=$(echo "$output" | tail -n 1)

# save content of expected file
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