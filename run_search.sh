#!/bin/bash

# just a menu driven script to run all the search algorithms
declare files=(
  [1]="1_bms.cpp"
  [2]="2_bfs.cpp"
  [3]="3_dfs.cpp"
  [4]="4_bfs_dfs.cpp"
  [5]="5_bfs_history.cpp"
  [6]="6_dfs_history.cpp"
  [7]="7_hc.cpp"
  [8]="8_beam_search.cpp"
  [9]="9_hc_history.cpp"
  [10]="10_beam_search_history.cpp"
  [11]="11_oracle.cpp"
  [12]="12_bnb.cpp"
  [13]="13_bnb_eh.cpp"
  [14]="14_bnb_el.cpp"
  [15]="15_a_star.cpp"
)

while true; do
    echo "=============================="
    echo " Search Algorithm Runner Menu "
    echo "=============================="
    for i in {1..15}; do
        echo "$i) ${files[$i]}"
    done
    echo "0) Exit"
    echo -n "Enter your choice: "
    read choice

    if [[ "$choice" == "0" ]]; then
        echo "Exiting..."
        break
    elif [[ -n "${files[$choice]}" ]]; then
        src="${files[$choice]}"
        exe="${src%.cpp}.out"
        echo "Compiling $src..."
        g++ "$src" -o "$exe"
        if [[ $? -eq 0 ]]; then
            echo "Running $exe..."
            echo "---------------------------------"
            "./$exe"
            echo "---------------------------------"
        else
            echo "Compilation failed for $src"
        fi
    else
        echo "Invalid choice. Please try again."
    fi
done

#cleanup
rm -f ./*.out
