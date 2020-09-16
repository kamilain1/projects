#race problem occurs here

i=0
while [ $i -le 999 ]
do
	num=$(grep -Eo '^[0-9]+$' file.txt | tail -1)
	expr $num + 1 >> file.txt
	i=$(($i+1))
done
