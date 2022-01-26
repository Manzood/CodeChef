for ((i=3;;i++)) do
	echo $i
	./gen $i > in
	diff -w <(./E < in) <(./correct < in) || break
done
