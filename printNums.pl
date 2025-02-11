#!/usr/bin/perl
@num = (1,2,3,4,5,6,238 ,237);
foreach $n (@num) {
	if ($n > 237){
		next;
		}
	if ($n %2  ==0){
		print " $n \n";
	
		}
		
}
		


