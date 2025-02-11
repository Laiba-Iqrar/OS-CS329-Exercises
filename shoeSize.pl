#!/usr/bin/perl
@family = (laiba,faiqa,hooriya);
%shoe_color = ("laiba" => 'Black' , "faiqa" => 'Brown', "hooriya" => 'Red');
%shoe_size = ("laiba" => 39 , "faiqa" => 40, "hooriya" => 24);
foreach $i (@family){
	if  ($shoe_size{$i} >10 ){
			print " $i wears large $shoe_color{$i} shoes size $shoe_size{$i} \n";
			next;
			}
	print " $i wears $shoe_color{$i} shoes size $shoe_size{$i} \n";}
