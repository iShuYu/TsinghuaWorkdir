for i in $(seq 0 13)
do
        ./ErrorMUL ${i} >/dev/null 2>&1 & 
done
