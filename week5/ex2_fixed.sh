#fixing the race problem with lock

i=0
while [ $i -le 999 ]
do
	if ln file.txt file.txt.lock
	then
		var1=$(grep -Eo '^[0-9]+$' file.txt.lock | tail -1)
		expr $var1 + 1 >> file.txt.lock
		rm file.txt.lock
	else
		i=$(($i-1))
	fi
	i=$(($i+1))
done
