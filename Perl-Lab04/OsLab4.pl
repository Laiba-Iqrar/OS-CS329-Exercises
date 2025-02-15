#!/usr/bin/perl
$item_price = 5 ;
$item_name = "Apple" ;
print "The price of $item_name is $item_price gold coins.\n";
@p_list = (5,8,4);
@n_list  = ("Apple","Banana", "Mushroom");
print "the price of $n_list[0] is $p_list[0]";

%c = ("Apple" => 5 ,"Banana" => 6 , "Mushroom" => 9);
print " $c{\"Apple\"}" ;

#if we want to hash all the keys of the hash 
@food = keys %c;
#hashsize returns the no of elements in array
$hashsize = @food;
print "the no. of foods is $hashsize \n";

#Adding the couple of more foods
$c{"Bread"} = 56;
$c{"Egg"} = 43;
print "the no. of foods is $hashsize \n";

$x = 10;
$a = $x++;
print "$a \n" ;
#increments X first 
# x = 11 
# a = 10


$a = ++$x;
print "$a \n" ;#increments a first 
# x = 12
# a = 12
