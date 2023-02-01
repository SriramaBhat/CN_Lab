BEGIN{
count1=0
count2=0
pack1=0
pack2=0
time1=0
time2=0
}
{
if($1=="r" && $3=="__1__" && $4=="RTR"){
count1++
pack1=pack1+$8
time1=$2
}
if($1=="r" && $3=="__2__" && $4=="RTR"){
count2++
pack2=pack2+$8
time2=$2
}
}
END{
printf("The throughput from n0 to n1: %f Mbps\n",((count1*pack1*8)/(time1*1000000)));
printf("The throughput from n1 to n2: %f Mbps\n",((count2*pack2*8)/(time2*1000000)));
}
