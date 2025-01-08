for ((i=1;;i++)) do
	echo $i
	./Graph_Generator $i > in
	./E < in || break
done
