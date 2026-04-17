#!/bin/bash

echo -e "--------------------------------------------------------------------"
if [ "$output" == "$expected_output" ]; then
	echo -e -n "${YELLOW_B}"	"\b$name ✅\n" "${RESET}"
	((pass_counter++))
	echo -e	"${WHITE_B}"	"\b\tInput:\n"		"\b${WHITE}"		"\b$args"	"\b${RESET}"
	echo -e	"${WHITE_B}"	"\b\tGot:\n"		"\b${WHITE}"		"\b$expected_output"	"\b${RESET}"
else
	((fail_counter++))
	echo -e "${YELLOW_B}"	"\b$name ❌"
	echo -e	"${WHITE_B}"	"\b\tInput:\n"		"\b${WHITE}"		"\b$args"	"\b${RESET}"
	echo -e "${WHITE_B}"	"\b\tExpected:\n"	"\b${WHITE}"	"\b$expected_output"
	echo -e	"${RED_B}"		"\b\tGot:\n"		"\b${RED}"		"\b$output"	"\b${RESET}"
fi