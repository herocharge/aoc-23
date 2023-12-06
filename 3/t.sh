cat input2 | cut -f1 -d" " --complement | cut -f1 -d" " --complement | grep -v -e 20 -e 19 -e 18 -e 17 -e 16 -e 15 -e "14 red" -e "14 green" -e "13 red"
