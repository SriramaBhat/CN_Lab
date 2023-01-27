set opt(title) zero ;

set opt(stop) 100 ;

set opt(ecn) 0 ;



set opt(type) umts  ;

set opt(secondDelay) 55  ;





set opt(minth) 30  ;

set opt(maxth)  0  ;

set opt(adaptive) 1  ;



set opt(flows) 0  ;

set opt(window) 30  ;

set opt(web) 2  ;



set opt(quiet) 0  ;

set opt(wrap) 100  ;

set opt(srcTrace) is  ;



set opt(dstTrace) bs2  ;

set opt(umtsbf) 10  ;



set bwDL(umts) 384000  



set bwUL(umts) 64000  



set propDL(umts) .150



set propUL(umts) .150



set buf(umts) 20





set ns [new Simulator]

set tf [open 6.tr w]

$ns trace-all $tf



set nodes(is) [$ns node]

set nodes(ms) [$ns node]

set nodes(bs1) [$ns node]

set nodes(bs2) [$ns node]

set nodes(lp) [$ns node]



proc cell_topo { } {

global ns nodes

$ns duplex-link $nodes(lp) $nodes(bs1) 3Mbps 10ms DropTail

$ns duplex-link $nodes(bs1) $nodes(ms) 1 1 RED

$ns duplex-link $nodes(ms) $nodes(bs2) 1 1 RED

$ns duplex-link $nodes(bs2) $nodes(is) 3Mbps 50ms DropTail

puts "Cell Topology"

}



proc set_link_params {t} {

global ns nodes bwUL bwDL propUL propDL buf

$ns bandwidth $nodes(bs1) $nodes(ms) $bwDL($t) simplex

$ns bandwidth $nodes(ms) $nodes(bs1) $bwUL($t) simplex

$ns delay $nodes(bs1) $nodes(ms) $propDL($t) simplex

$ns delay $nodes(ms) $nodes(bs1) $propDL($t) simplex

$ns queue-limit $nodes(bs1) $nodes(ms) $buf($t)

$ns queue-limit $nodes(ms) $nodes(bs1) $buf($t)

$ns bandwidth $nodes(bs2) $nodes(ms) $bwDL($t) simplex

$ns bandwidth $nodes(ms) $nodes(bs2) $bwUL($t) simplex

$ns delay $nodes(bs2) $nodes(ms) $propDL($t) simplex

$ns delay $nodes(ms) $nodes(bs2) $propDL($t) simplex

$ns queue-limit $nodes(bs2) $nodes(ms) $buf($t)

$ns queue-limit $nodes(ms) $nodes(bs2) $buf($t)

}



Queue/RED set summarystats_ true

Queue/DropTail set summarystats_ true

Queue/RED set adaptive_ $opt(adaptive)

Queue/RED set q_weight_ 0.0

Queue/RED set thresh_ $opt(minth)

Queue/RED set maxthresh_ $opt(maxth)

Queue/DropTail set shrink_drops_ true

Agent/TCP set ecn_ $opt(ecn)

Agent/TCP set window_ $opt(window)

DelayLink set avoidReordering_ true



source web.tcl

