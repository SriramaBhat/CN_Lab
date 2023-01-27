switch $opt(type) {

umts {cell_topo}

}



set_link_params $opt(type)

$ns insert-delayer $nodes(ms) $nodes(bs1) [new Delayer]

$ns insert-delayer $nodes(bs1) $nodes(ms) [new Delayer]

$ns insert-delayer $nodes(ms) $nodes(bs2) [new Delayer]

$ns insert-delayer $nodes(bs2) $nodes(ms) [new Delayer]



if {$opt(flows)==0} {

set tcp1 [$ns create-connection TCP/Sack1 $nodes(is) TCPSink/Sack1 $nodes(lp) 0]

set ftp1 [[set tcp1] attach-app FTP]

$ns at 0.8 "[set ftp1] start"

}



#if {$opt(flows)>0} {

#set tcp1 [$ns create-connection TCP/Sack1 $nodes(is) TCPSink/Sack1 $nodes(lp) 0]

#set ftp1 [[set tcp1] attach-app FTP]

#$tcp1 set window_ 100

#$ns at 0.8 "[set ftp1] start"

#$ns at 3.5 "[set ftp1] stop"

#set tcp2 [$ns create-connection TCP/Sack1 $nodes(is) TCPSink/Sack1 $nodes(lp) 0]

#set ftp2 [[set tcp2] attach-app FTP]

#$tcp1 set window_ 3

#$ns at 1.0 "[set ftp2] start"

#$ns at 8.0 "[set ftp2] stop"

#}



proc stop { } {

global nodes opt nf

set wrap $opt(wrap)

set sid [$nodes($opt(srcTrace)) id]

set did [$nodes($opt(dstTrace)) id]

if {$opt(srcTrace) == "is"} {

   set a "-a 6.tr"

} else {

   set a "6.tr"

}



set GETRC "~/Downloads/ns-allinone-2.35/ns-2.35/bin/getrc"

set RAW2XG "~/Downloads/ns-allinone-2.35/ns-2.35/bin/raw2xg"



exec $GETRC -s $sid -d $did -f 0 6.tr | \

$RAW2XG -s 0.01 -m $wrap -r > plot.xgr

exec $GETRC -s $did -d $sid -f 0 6.tr | \

$RAW2XG -a -s 0.01 -m $wrap -r >> plot.xgr



exec $GETRC -s $sid -d $did -f 1 6.tr | \

$RAW2XG -s 0.01 -m $wrap -r >>plot.xgr

exec $GETRC -s $did -d $sid -f 1 6.tr | \

$RAW2XG -s 0.01 -m $wrap -a >> plot.xgr



exec ~/Downloads/ns-allinone-2.35/ns-2.35/tcl/ex/wireless-scripts/xg2gp.awk plot.xgr

if {!$opt(quiet)} {

exec xgraph -bb -tk -nl -m -x time -y packets plot.xgr &

}



exit 0



}

$ns at $opt(stop) "stop"

$ns run
