type=$1
total=0
for x in 'find ./* -type f -name "$type"';
do
	single='cat $x | wc -l'
	total=$total+$single
done

echo $total
