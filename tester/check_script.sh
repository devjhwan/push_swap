#!/bin/bash

# Function to generate permutations recursively
function generate_permutations {
    local prefix=$1
    local remaining=$2

    # Base case: if there are no remaining elements, print the permutation
    if [ -z "$remaining" ]; then
        ARG=$(echo $prefix | sed "s/ $//")
        echo -n "\"$ARG\" "
        start_time=$(date +%s.%N)
        ./push_swap $ARG > actions.txt
        end_time=$(date +%s.%N)
        execution_time=$( echo "$end_time - $start_time" | bc -l )
		echo -n "$(cat actions.txt | wc -l) "
		echo "$(cat actions.txt | ./checker_linux $ARG | tr -d '\n') $execution_time"
    else
        # Generate permutations by fixing one element at a time
        for ((i=0; i<${#remaining}; i++))
		do
            local next_prefix=$prefix${remaining:$i:1}
            local next_remaining=${remaining:0:$i}${remaining:$((i+1))}
			local index=$i
            generate_permutations "$next_prefix " "$next_remaining"
			i=$index
        done
    fi
}

n=$1
# Generate permutations and split numbers with space
generate_permutations "" "$(seq 1 $n | tr -d '\n')"
