START=$(($(date +%s%N)/1000000))
./$1
END=$(($(date +%s%N)/1000000))
DIFF=$(( $END - $START ))
echo "It took $DIFF milliseconds"
