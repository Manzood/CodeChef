for ((i=1;;i++)) do
	echo $i
	./gen $i > in
	diff -w <(./old_E < in) <(./correct < in) || break
done