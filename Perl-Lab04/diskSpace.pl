#!/usr/bin/perl
use strict;
use warnings;
use Filesys::Df;

my $dir = "/home";  # Directory to check

# Get filesystem usage information
my $ref = df($dir);

# Check if df() returned valid data
if (defined $ref) {
    my $used  = $ref->{used};    # Used space
    my $avail = $ref->{bavail};  # Available space (excluding reserved blocks)

    # Ensure we don't divide by zero
    my $df_free = ($avail + $used) ? ($avail / ($avail + $used)) * 100.00 : 0;

    # Print results
    print "Available space: $avail\n";
    print "Used space: $used\n";
    printf("Percentage disk space available on %s: %.2f%%\n", $dir, $df_free);
} else {
    print "Error: Unable to get disk space information for $dir\n";
}

