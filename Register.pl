#!/usr/bin/perl
use strict;
use CGI ':standard';

$firstName = param('firstname');
$lastName = param('lastname');
$username = param('username');
$password = param('password');

sub main {
	print "$firstName $lastName";
}

main();