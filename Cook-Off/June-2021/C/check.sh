for ((i=1;;i++)) do
	echo $i
	./gen $i > in
    ./B < in > out
	# diff -w <(./a < in) <(./correct < in) || break
    ./checker < out
done
