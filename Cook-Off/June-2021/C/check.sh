for ((i=1;;i++)) do
	echo $i
	./gen $i > in
    # ./C < in > out
    diff -w <(./C < in) <(./correct < in) || break
    # ./checker < out
done
